/* Conquer Space
 * Copyright (C) 2021-2023 Conquer Space
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "common/systems/economy/sysfactory.h"

#include <spdlog/spdlog.h>

#include <tracy/Tracy.hpp>

#include "common/components/area.h"
#include "common/components/economy.h"
#include "common/components/infrastructure.h"
#include "common/components/name.h"
#include "common/components/organizations.h"
#include "common/components/surface.h"
#include "common/node.h"
#include "common/util/profiler.h"

namespace components = cqsp::common::components;
using components::IndustrySize;
using components::Production;
using components::Recipe;
using components::ResourceLedger;
using entt::entity;

namespace cqsp::common::systems {
<<<<<<< HEAD
<<<<<<< HEAD
== == == = namespace cqspc = cqsp::common::components;
namespace {
>>>>>>> pr_191
== == == =
>>>>>>> pr-290
             /// <summary>
    /// Runs the production cycle
    /// Consumes material from the market based on supply and then sells the manufactured goods on the market.
    /// </summary>
    /// <param name="current_registry">Registry used for searching for components</param>
    /// <param name="entity">Entity containing an Inudstries that need to be processed</param>
    /// <param name="market">The market the industry uses.</param>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    void ProcessIndustries(Universe & universe, entity entity) {
    auto& market = universe.get<components::Market>(entity);
    == == == = void ProcessIndustries(common::Universe & universe, entt::entity entity, cqspc::Market & market) {
>>>>>>> pr_191
        // Get the transport cost
        auto& infrastructure = universe.get<components::infrastructure::CityInfrastructure>(entity);
        // Calculate the infrastructure cost
        double infra_cost = infrastructure.default_purchase_cost - infrastructure.improvement;

<<<<<<< HEAD
        auto& population_wallet = universe.get_or_emplace<components::Wallet>(
            universe.get<components::Settlement>(entity).population.front());
        for (entt::entity productionentity : universe.get<components::IndustrialZone>(entity).industries) {
            // Process imdustries
            // Industries MUST have production and a linked recipe
            if (!universe.all_of<Production>(productionentity)) continue;
            Recipe recipe = universe.get_or_emplace<Recipe>(universe.get<Production>(productionentity).recipe);
            IndustrySize& size = universe.get_or_emplace<IndustrySize>(productionentity, 1000.0);
            // Calculate resource consumption
            ResourceLedger capitalinput = recipe.capitalcost * (0.01 * size.size);
            ResourceLedger input = (recipe.input + size.utilization) + capitalinput;
            == == == = void ProcessIndustries(Node & node) {
                auto& universe = node.universe();
                auto& market = node.get<components::Market>();
                // Get the transport cost
                auto& infrastructure = node.get<components::infrastructure::CityInfrastructure>();
                // Calculate the infrastructure cost
                double infra_cost = infrastructure.default_purchase_cost - infrastructure.improvement;
                == == == = void ProcessIndustries(Node & industrynode) {
                    components::Market& market = industrynode.get<components::Market>();
                    // Get the transport cost
                    auto& infrastructure = industrynode.get<components::infrastructure::CityInfrastructure>();
                    // Calculate the infrastructure cost
                    double infra_cost = infrastructure.default_purchase_cost - infrastructure.improvement;

                    auto& industries = industrynode.get<components::IndustrialZone>();
                    auto& population_wallet = industrynode.get_or_emplace<components::Wallet>(
                        industrynode.get<components::Settlement>().population.front());
                    for (Node productionnode : industrynode.Convert(industries.industries)) {
                        // Process imdustries
                        // Industries MUST have production and a linked recipe
                        if (!productionnode.all_of<components::Production>()) continue;
                        components::Recipe recipe = productionnode.get_or_emplace<components::Recipe>(
                            productionnode.get<components::Production>().recipe);
                        components::IndustrySize& size = productionnode.get<components::IndustrySize>();
                        // Calculate resource consumption
                        components::ResourceLedger capitalinput = recipe.capitalcost * (size.size);
                        components::ResourceLedger input = (recipe.input * size.utilization) + capitalinput;
>>>>>>> pr-290

                        auto& industries = node.get<components::IndustrialZone>();
                        Node populationnode = node.Convert(node.get<components::Settlement>().population.front());
                        auto& population_wallet = populationnode.get_or_emplace<components::Wallet>();
                        for (Node industrynode : node.Convert(industries.industries)) {
                            // Process imdustries
                            // Industries MUST have production and a linked recipe
                            if (!industrynode.all_of<components::Production>()) continue;
                            Node recipenode = industrynode.Convert(industrynode.get<components::Production>().recipe);
                            components::Recipe recipe = recipenode.get_or_emplace<components::Recipe>();
                            components::IndustrySize& size = industrynode.get<components::IndustrySize>();
                            // Calculate resource consumption
                            components::ResourceLedger capitalinput = recipe.capitalcost * (size.size);
                            components::ResourceLedger input = (recipe.input * size.utilization) + capitalinput;
>>>>>>> pr-291

                            // Calculate the greatest possible production
                            ResourceLedger output;  // * ratio.output;
                            output[recipe.output.entity] = recipe.output.amount * size.utilization;

                            // Figure out what's throttling production and maintenance
                            double limitedinput = CopyVals(input, market.history.back().sd_ratio).Min();
                            double limitedcapitalinput = CopyVals(capitalinput, market.history.back().sd_ratio).Min();

                            // Log how much manufacturing is being throttled by input
                            market[recipe.output.entity].inputratio = limitedinput;

                            if (market.sd_ratio[recipe.output.entity] < 1.1) {
                                size.utilization *= 1 + (0.01) * std::fmin(limitedcapitalinput, 1);
                            } else {
                                size.utilization *= 0.99;
                            }
                            size.utilization = std::clamp(size.utilization, 0., size.size);

                            if (limitedinput < 1) {  // If an input good is undersupplied on
                                                     // the market, throttle production
                                input *= limitedinput;
                                output *= limitedinput;
                                // Industry
                            }

                            market.demand += input;
                            market.supply += output;

                            double output_transport_cost = output.GetSum() * infra_cost;
                            double input_transport_cost = input.GetSum() * infra_cost;
                            // Next time need to compute the costs along with input and
                            // output so that the factory doesn't overspend. We sorta
                            // need a balanced economy
                            components::CostBreakdown& costs =
                                universe.get_or_emplace<components::CostBreakdown>(productionentity);

                            // Maintenance costs will still have to be upkept, so if
                            // there isnt any resources to upkeep the place, then stop
                            // the production
                            costs.materialcosts = (recipe.input * size.utilization * market.price).GetSum();
                            costs.revenue = (recipe.output * market.price).GetSum();
                            if (market.sd_ratio[recipe.output.entity] > 1) {
                                costs.revenue /= market.sd_ratio[recipe.output.entity];
                            }
                            costs.wages = size.size * recipe.workers * size.wages;
                            costs.profit = costs.revenue - costs.maintenance - costs.materialcosts - costs.wages;
                            costs.transport = output_transport_cost + input_transport_cost;
                            double& price = market.price[recipe.output.entity];
                            if (costs.profit > 0) {
                                price += (-0.1 + price * -0.01f);
                                == == == = auto& industries = universe.get<cqspc::IndustrialZone>(entity);
                                for (entt::entity productionentity : industries.industries) {
                                    // Process imdustries
                                    // Industries MUST have production and a linked recipe
                                    if (!universe.all_of<components::Production>(productionentity)) continue;
                                    components::Recipe recipe = universe.get_or_emplace<components::Recipe>(
                                        universe.get<components::Production>(productionentity).recipe);
                                    components::IndustrySize& size =
                                        universe.get_or_emplace<components::IndustrySize>(productionentity, 1000.0);
                                    // Calculate resource consumption
                                    components::ResourceLedger capitalinput = recipe.capitalcost * (0.01 * size.size);
                                    components::ResourceLedger input = (recipe.input + size.size) + capitalinput;

                                    // Calculate the greatest possible production
                                    components::ResourceLedger output;  // * ratio.output;
                                    output[recipe.output.entity] = recipe.output.amount * size.size;

                                    // Figure out what's throttling production and maintaince
                                    double limitedinput = CopyVals(input, market.history.back().sd_ratio).Min();
                                    double limitedcapitalinput =
                                        CopyVals(capitalinput, market.history.back().sd_ratio).Min();

                                    // Log how much manufacturing is being throttled by input
                                    market[recipe.output.entity].inputratio = limitedinput;

                                    if (market.history.back().sd_ratio[recipe.output.entity] < 1.1) {
                                        if (limitedcapitalinput > 1) limitedcapitalinput = 1;
                                        size.size *= 1 + (0.01) * std::fmin(limitedcapitalinput, 1);
>>>>>>> pr_191
                                    } else {
                                        price += (0.2 + price * 0.01f);
                                    }
                                    if (limitedinput < 1) {  // If an input good is undersupplied on
                                                             // the market, throttle production
                                        input *= limitedinput;
                                        output *= limitedinput;
                                        // Industry
                                    }

<<<<<<< HEAD
                                    // Pay the workers
                                    population_wallet += costs.wages;
                                }
                            }
                            void SysProduction::DoSystem() {
                                ZoneScoped;
                                Universe& universe = GetUniverse();
                                auto view = universe.view<components::IndustrialZone, components::Market>();
                                // Each industrial zone is a a market
                                BEGIN_TIMED_BLOCK(INDUSTRY);
                                int factories = 0;
                                // Loop through the markets
                                == == == = market.demand += input;
                                market.supply += output;

                                double output_transport_cost = output.GetSum() * infra_cost;
                                double input_transport_cost = input.GetSum() * infra_cost;
                                // Next time need to compute the costs along with input and
                                // output so that the factory doesn't overspend. We sorta
                                // need a balanced economy
                                components::CostBreakdown& costs =
                                    universe.get_or_emplace<components::CostBreakdown>(productionentity);

                                // Maintainence costs will still have to be upkept, so if
                                // there isnt any resources to upkeep the place, then stop
                                // the production
                                costs.materialcosts = (recipe.input * size.size * market.price).GetSum();
                                costs.profit = (recipe.output * market.price).GetSum();
                                if (market.sd_ratio[recipe.output.entity] > 1) {
                                    costs.profit /= market.sd_ratio[recipe.output.entity];
                                }
                                costs.wages = size.size * recipe.workers * 50000;
                                costs.net = costs.profit - costs.maintenance - costs.materialcosts - costs.wages;
                                costs.transport = output_transport_cost + input_transport_cost;
                                double& price = market.price[recipe.output.entity];
                                if (costs.net > 0) {
                                    price += (-0.1 + price * -0.01f);
                                } else {
                                    price += (0.2 + price * 0.01f);
                                }

                                // ratio.ratio = recipe.input.UnitLeger(size.size);
                                // ratio.output = recipe.output.UnitLeger(size.size);
                            }
                        }
                    }  // namespace

<<<<<<< HEAD
                    void SysProduction::DoSystem() {
                        ZoneScoped;
                        Universe& universe = GetUniverse();
                        auto view = universe.view<components::IndustrialZone>();
                        BEGIN_TIMED_BLOCK(INDUSTRY);
                        int factories = 0;
                        // Loop through the markets
                        auto market_view = universe.view<cqspc::Habitation>();
>>>>>>> pr_191
                        int settlement_count = 0;
                        // Get the markets and process the values?
                        for (entity entity : view) {
                            ProcessIndustries(universe, entity);
                        }
                        END_TIMED_BLOCK(INDUSTRY);
                        SPDLOG_TRACE("Updated {} factories, {} industries", factories, view.size());
                    }
                    == == == = market.consumption += input;
                    market.production += output;

                    double output_transport_cost = output.GetSum() * infra_cost;
                    double input_transport_cost = input.GetSum() * infra_cost;
                    // Next time need to compute the costs along with input and
                    // output so that the factory doesn't overspend. We sorta
                    // need a balanced economy
                    components::CostBreakdown& costs = industrynode.get_or_emplace<components::CostBreakdown>();

                    // Maintenance costs will still have to be upkept, so if
                    // there isnt any resources to upkeep the place, then stop
                    // the production
                    costs.materialcosts = (input * market.price).GetSum();
                    costs.wages = size.size * recipe.workers * size.wages;

                    costs.revenue = (recipe.output * market.price).GetSum();
                    costs.profit = costs.revenue - costs.maintenance - costs.materialcosts - costs.wages;
                    costs.transport = output_transport_cost + input_transport_cost;

                    // Now try to maximize profit
                    // Maximizing profit is a two fold thing
                    // If the S/D ratio is < 1, and the profit is negative, that means that this factory is not supplying enough
                    // This could be either the good that we are producing is not profitable, or the fact that our base costs
                    // are too high.

                    // For the former option, we should reduce production because our goods are not making a profit and cut costs
                    // until we can make a profit, either by squeezing out the market. If we're not big enough to change the market
                    // we will just go out of business.
                    // and for the second production, we should increase our production because we just need more production so
                    // that we can get to profitability

                    // If S/D ratio is > 1, and we are still making negative profit, we are producing too much, or paying the workers
                    // too much. There are so many knobs that we have to tune, so I'm not sure how we can simplify this into a few
                    // simple knobs (more like one)

                    // I think one of the issues that we have is what if all the businesses go out of business at one time, and end
                    // up just killing off the specific market for a good?
                    // Do we need to prop things out
                    // or have a stage where it stays hibernated for a while, and then ramps up production if it can become profitable

                    // Right now we should naively modify the price then to maximize profit
                    // Now let's target profit only
                    // If we're making more money, increase utilization, if we're making less money, reduce utilization
                    // We can only reduce and increase production by a certain amount, let's say a maximum of 5%

                    // Then the other thing is in that case, it would just have boom and busts
                    // If we make the time that a business dies random, then perhaps we could tune it more
                    // Now what's the goal
                    // The more profit we have the less we increase until some level
                    // Let's just make it a log level
                    // TODO(EhWhoAmI): This should just be some sort of setting tbh
                    float profit_multiplier = 0.001;
                    // but if we have close to zero profit, we want to take risks and move in a certain direction.

                    // So we will add a random chance to increase or decrease profit
                    double diff = std::clamp(log(fabs(costs.profit) * profit_multiplier), 0., 0.05);
                    diff += 1 + universe.random->GetRandomNormal(0, 0.075);
                    diff *= (costs.profit < 0) ? -1 : 1;
                    size.utilization = std::clamp(size.utilization * diff, 0.1 * size.size, size.size);
                    // Now diff it by that much
                    // Let the minimum the factory can produce be like 10% of the
                    // Pay the workers
                    population_wallet += costs.wages;
                }
<<<<<<< HEAD
            }

            void SysProduction::DoSystem() {
                ZoneScoped;
                Universe& universe = GetUniverse();
                // Each industrial zone is a a market
                BEGIN_TIMED_BLOCK(INDUSTRY);
                int factories = 0;
                // Loop through the markets
                int settlement_count = 0;
                // Get the markets and process the values?
                for (Node entity : universe.nodes<components::IndustrialZone, components::Market>()) {
                    ProcessIndustries(entity);
                }
                END_TIMED_BLOCK(INDUSTRY);
                SPDLOG_TRACE("Updated {} factories, {} industries", factories, view.size());
                == == == = size.utilization = std::clamp(size.utilization, 0., size.size);

                market.consumption += input;
                market.production += output;

                double output_transport_cost = output.GetSum() * infra_cost;
                double input_transport_cost = input.GetSum() * infra_cost;
                // Next time need to compute the costs along with input and
                // output so that the factory doesn't overspend. We sorta
                // need a balanced economy
                components::CostBreakdown& costs = productionnode.get_or_emplace<components::CostBreakdown>();

                // Maintenance costs will still have to be upkept, so if
                // there isnt any resources to upkeep the place, then stop
                // the production
                costs.materialcosts = (input * market.price).GetSum();
                costs.wages = size.size * recipe.workers * size.wages;

                costs.revenue = (recipe.output * market.price).GetSum();
                costs.profit = costs.revenue - costs.maintenance - costs.materialcosts - costs.wages;
                costs.transport = output_transport_cost + input_transport_cost;

                // Now try to maximize profit
                // Maximizing profit is a two fold thing
                // If the S/D ratio is < 1, and the profit is negative, that means that this factory is not supplying enough
                // This could be either the good that we are producing is not profitable, or the fact that our base costs
                // are too high.

                // For the former option, we should reduce production because our goods are not making a profit and cut costs
                // until we can make a profit, either by squeezing out the market. If we're not big enough to change the market
                // we will just go out of business.
                // and for the second production, we should increase our production because we just need more production so
                // that we can get to profitability

                // If S/D ratio is > 1, and we are still making negative profit, we are producing too much, or paying the workers
                // too much. There are so many knobs that we have to tune, so I'm not sure how we can simplify this into a few
                // simple knobs (more like one)

                // I think one of the issues that we have is what if all the businesses go out of business at one time, and end
                // up just killing off the specific market for a good?
                // Do we need to prop things out
                // or have a stage where it stays hibernated for a while, and then ramps up production if it can become profitable

                // Right now we should naively modify the price then to maximize profit
                // Now let's target profit only
                // If we're making more money, increase utilization, if we're making less money, reduce utilization
                // We can only reduce and increase production by a certain amount, let's say a maximum of 5%

                // Then the other thing is in that case, it would just have boom and busts
                // If we make the time that a business dies random, then perhaps we could tune it more
                // Now what's the goal
                // The more profit we have the less we increase until some level
                // Let's just make it a log level
                // TODO(EhWhoAmI): This should just be some sort of setting tbh
                float profit_multiplier = 0.001;
                // but if we have close to zero profit, we want to take risks and move in a certain direction.

                // So we will add a random chance to increase or decrease profit
                double diff = std::clamp(log(fabs(costs.profit) * profit_multiplier), 0., 0.05);
                //diff += 1 + productionnode.current_registry.random->GetRandomNormal(0, 0.075);
                diff *= (costs.profit < 0) ? -1 : 1;
                size.utilization = std::clamp(size.utilization * diff, 0.1 * size.size, size.size);
                // Now diff it by that much
                // Let the minimum the factory can produce be like 10% of the
                // Pay the workers
                population_wallet += costs.wages;
            }
        }

        void SysProduction::DoSystem() {
            ZoneScoped;
            Universe& universe = GetUniverse();
            // Each industrial zone is a a market
            BEGIN_TIMED_BLOCK(INDUSTRY);
            int factories = 0;
            // Loop through the markets
            int settlement_count = 0;
            // Get the markets and process the values?
            auto view = universe.view<components::IndustrialZone, components::Market>();
            for (entt::entity entity : view) {
                Node node(entity, universe);
                ProcessIndustries(node);
            }

            for (Node node : universe.nodes<components::IndustrialZone, components::Market>()) {
                ProcessIndustries(node);
>>>>>>> pr-290
            }
>>>>>>> pr-291
        }  // namespace cqsp::common::systems
