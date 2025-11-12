/* Conquer Space
 * Copyright (C) 2021-2025 Conquer Space
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
#include "common/systems/economy/sysmarket.h"

#include <algorithm>
#include <fstream>
#include <limits>
#include <utility>

#include <tracy/Tracy.hpp>

#include "common/components/market.h"
#include "common/components/name.h"
<<<<<<< HEAD
#include "common/components/spaceport.h"

    <<<<<<< HEAD namespace cqsp::common::systems {

    using components::Market;
    == == == = namespace cqsp::common::systems {
        using components::Market;

        void SysMarket::DoSystem() {
            ZoneScoped;
            auto marketview = GetUniverse().view<Market>();
            SPDLOG_INFO("Processing {} market(s)", marketview.size());
            TracyPlot("Market Count", (int64_t)marketview.size());
            auto goodsview = GetUniverse().view<components::Price>();
            Universe& universe = GetUniverse();

            for (entt::entity entity : marketview) {
                // Get the resources and process the price
                // Get demand
                Market& market = universe.get<Market>(entity);
>>>>>>> pr-290

<<<<<<< HEAD
                void SysMarket::DoSystem() {
                    ZoneScoped;
                    auto marketview = GetUniverse().nodes<Market>(entt::exclude<components::PlanetaryMarket>);

                    auto goodsview = GetUniverse().nodes<components::Price>();

                    for (Node market_node : marketview) {
                        // Get the resources and process the price
                        // Get demand
                        Market& market = market_node.get<Market>();

                        // Add a supply if there is a space port
                        if (market_node.any_of<components::infrastructure::SpacePort>()) {
                            // Then add output resources to the market
                            auto& space_port = market_node.get<components::infrastructure::SpacePort>();
                            market.supply() += space_port.output_resources_rate;
                            == == == = void SysMarket::DoSystem() {
                                ZoneScoped;
                                auto marketview =
                                    GetUniverse().nodes<Market>(entt::exclude<components::PlanetaryMarket>);

                                auto goodsview = GetUniverse().nodes<components::Price>();

                                for (Node market_node : marketview) {
                                    // Get the resources and process the price
                                    // Get demand
                                    Market& market = market_node.get<Market>();

                                    // Add a supply if there is a space port
                                    if (market_node.any_of<components::infrastructure::SpacePort>()) {
                                        // Then add output resources to the market
                                        auto& space_port = market_node.get<components::infrastructure::SpacePort>();
                                        market.supply() += space_port.output_resources_rate;
>>>>>>> pr-303

                                        // Remove the ones that are less than zero
                                        space_port.output_resources -= space_port.output_resources_rate;
                                        // If they're higher we set the output resouurces to zero
                                        for (auto& [good, value] : space_port.output_resources) {
                                            if (value < 0) {
                                                space_port.output_resources_rate[good] = 0;
                                            }
                                        }
                                    }
                                    == == == = using cqsp::common::systems::SysMarket;

                                    namespace components = cqsp::common::components;
                                    using components::Market;
                                    using components::Price;
                                    using entt::entity;

                                    void SysMarket::DoSystem() {
                                        ZoneScoped;
                                        // Get all the new and improved (tm) markets
                                        auto marketview = GetUniverse().view<Market>();
                                        SPDLOG_INFO("Processing {} market(s)", marketview.size());
                                        TracyPlot("Market Count", (int64_t)marketview.size());
                                        auto goodsview = GetUniverse().view<Price>();
                                        Universe& universe = GetUniverse();
                                        // Calculate all the things
                                        for (entt::entity entity : marketview) {
                                            // Get the resources and process the price, then do things, I guess
                                            // Get demand
                                            Market& market = universe.get<Market>(entity);
>>>>>>> pr_254

<<<<<<< HEAD
                                            // TODO(EhWhoAmI): GDP Calculations
                                            // market.gdp = market.volume* market.price;
                                            == == == = for (Node good_node : goodsview) {
                                                DeterminePrice(market, good_node);
                                            }
>>>>>>> pr-303

                                            // Calculate Supply and demand
                                            // Add combined supply and demand to compute S/D ratio
                                            market.supply() = market.production;
                                            market.demand() = market.consumption;
                                            market.supply().AddPositive(market.trade);
                                            market.demand().AddNegative(market.trade);
                                            market.sd_ratio = (market.supply()).SafeDivision(market.demand());

<<<<<<< HEAD
                                            for (Node good_node : goodsview) {
                                                DeterminePrice(market, good_node);
                                            }

                                            components::ResourceLedger& market_supply = market.supply();
                                            components::ResourceLedger& market_demand = market.demand();
                                            for (auto iterator = market_supply.begin(); iterator != market_supply.end();
                                                 iterator++) {
                                                const double& demand = market_demand[iterator->first];
                                                const double& supply = iterator->second;
                                                double shortage_level = (demand - supply) / demand;
                                                if (demand == 0) {
                                                    shortage_level = 0;
                                                }
                                                if (shortage_level > 0.8) {
                                                    // The demand vs supply ratio should be below a certain amount
                                                    market.chronic_shortages[iterator->first] += shortage_level;
                                                } else if (shortage_level > 0) {
                                                    if (market.chronic_shortages.contains(iterator->first)) {
                                                        market.chronic_shortages[iterator->first] += shortage_level;
                                                    }
                                                } else {
                                                    market.chronic_shortages[iterator->first] -= (1 - shortage_level);
                                                }
                                                if (market.chronic_shortages[iterator->first] < 0) {
                                                    market.chronic_shortages[iterator->first] = 0;
                                                }
                                            }
                                        }
                                    }

<<<<<<< HEAD
                                    void SysMarket::DeterminePrice(Market & market, Node & good_entity) {
                                        const double sd_ratio = market.sd_ratio[good_entity];
                                        const double supply = market.supply()[good_entity];
                                        const double demand = market.demand()[good_entity];
                                        double& price = market.price[good_entity];
                                        // Get parent market price
                                        // Now just adjust cost
                                        // Get parent market
                                        price = base_prices[good_entity] *
                                                (1. + GetUniverse().economy_config.market_config.base_price_deviation *
                                                          std::clamp((demand - supply) /
                                                                         (std::max(0.001, std::min(demand, supply))),
                                                                     -1., 1.));
                                    }

                                    void SysMarket::Init() {
                                        auto goodsview = GetUniverse().nodes<components::Price>();
                                        == == == = void SysMarket::InitializeMarket(Game & game) {
                                            auto marketview = game.GetUniverse().view<Market>();
                                            auto goodsview = game.GetUniverse().view<Price>();
>>>>>>> pr_254

                                            // Calculate all the things
                                            for (entt::entity entity : GetUniverse().nodes<Market>()) {
                                                // Get the resources and process the price, then do things, I guess
                                                // Get demand
<<<<<<< HEAD
                                                Market& market = GetUniverse().get<Market>(entity);

                                                // Initialize the price
                                                for (Node good_node : goodsview) {
                                                    market.price[good_node] = good_node.get<components::Price>();
                                                    == == == = Market& market = universe.get<Market>(entity);

                                                    // Initialize the price
                                                    for (entt::entity goodenity : goodsview) {
                                                        market.price[goodenity] = universe.get<Price>(goodenity);
>>>>>>> pr_254
                                                        // Set the supply and demand things as 1 so that they sell for
                                                        // now
                                                        market.previous_demand()[good_node] = 1;
                                                        market.previous_supply()[good_node] = 1;
                                                        market.supply()[good_node] = 1;
                                                        market.demand()[good_node] = 1;
                                                        market.market_access[good_node] = 0.8;
                                                    }
                                                    market.sd_ratio = market.supply().SafeDivision(market.demand());
                                                    market.history.push_back(market);
                                                }
                                                for (Node good_node : goodsview) {
                                                    base_prices[good_node] = good_node.get<components::Price>();
                                                }
                                            }
                                        }  // namespace cqsp::common::systems
                                        == == == =
                                                     // Initialize the price
                                            for (entt::entity goodenity : goodsview) {
                                            market.price[goodenity] = universe.get<components::Price>(goodenity);
                                            // Set the supply and demand things as 1 so that they sell for
                                            // now
                                            market.previous_demand[goodenity] = 1;
                                            market.previous_supply[goodenity] = 1;
                                            market.supply[goodenity] = 1;
                                            market.demand[goodenity] = 1;
                                        }
                                        market.sd_ratio = market.supply.SafeDivision(market.demand);
                                        market.history.push_back(market);
                                    }
                                }
<<<<<<< HEAD
>>>>>>> pr_191
                                == == == =
                            }
                        }

<<<<<<< HEAD
                        void SysMarket::DeterminePrice(Market & market, Node & good_entity) {
                            const double sd_ratio = market.sd_ratio[good_entity];
                            const double supply = market.supply()[good_entity];
                            const double demand = market.demand()[good_entity];
                            double& price = market.price[good_entity];
                            // Get parent market price
                            // Now just adjust cost
                            // Get parent market
                            price =
                                base_prices[good_entity] *
                                (1. + GetUniverse().economy_config.market_config.base_price_deviation *
                                          std::clamp((demand - supply) / (std::max(0.001, std::min(demand, supply))),
                                                     -1., 1.));
                        }
                        == == == = void SysMarket::DeterminePrice(Market & market, entt::entity good_entity) {
                            const double sd_ratio = market.sd_ratio[good_entity];
                            double& price = market.price[good_entity];
                            // If supply and demand = 0, then it will be undefined
                            if (sd_ratio < 1) {
                                // Too much demand, so we will increase the price
                                // Later increase it based on SD ratio
                                price += (0.02 + price * 0.01f);
                                //price = 0.5;
                            } else if (sd_ratio > 1 || sd_ratio == std::numeric_limits<double>::infinity()) {
                                // Too much supply, so we will decrease the price
                                price += (-0.01 + price * -0.01f);
>>>>>>> pr-290

                                void SysMarket::Init() {
                                    auto goodsview = GetUniverse().nodes<components::Price>();

<<<<<<< HEAD
                                    // Calculate all the things
                                    for (entt::entity entity : GetUniverse().nodes<Market>()) {
                                        // Get the resources and process the price, then do things, I guess
                                        // Get demand
                                        Market& market = GetUniverse().get<Market>(entity);

                                        // Initialize the price
                                        for (Node good_node : goodsview) {
                                            market.price[good_node] = good_node.get<components::Price>();
                                            // Set the supply and demand things as 1 so that they sell for
                                            // now
                                            market.previous_demand()[good_node] = 1;
                                            market.previous_supply()[good_node] = 1;
                                            market.supply()[good_node] = 1;
                                            market.demand()[good_node] = 1;
                                            market.market_access[good_node] = 0.8;
                                        }
                                        market.sd_ratio = market.supply().SafeDivision(market.demand());
                                        market.history.push_back(market);
                                    }
                                    for (Node good_node : goodsview) {
                                        base_prices[good_node] = good_node.get<components::Price>();
                                    }
                                }
                            }  // namespace cqsp::common::systems
>>>>>>> pr-303
                            == == == = void SysMarket::InitializeMarket(Game & game) {
                                auto marketview = game.GetUniverse().view<Market>();
                                auto goodsview = game.GetUniverse().view<components::Price>();

                                Universe& universe = game.GetUniverse();
                                // Calculate all the things
                                for (entt::entity entity : marketview) {
                                    // Get the resources and process the price, then do things, I guess
                                    // Get demand
                                    Market& market = universe.get<Market>(entity);

                                    // Initialize the price
                                    for (entt::entity good_entity : goodsview) {
                                        market.price[good_entity] = universe.get<components::Price>(good_entity);
                                        // Set the supply and demand things as 1 so that they sell for
                                        // now
                                        market.previous_demand()[good_entity] = 1;
                                        market.previous_supply()[good_entity] = 1;
                                        market.supply()[good_entity] = 1;
                                        market.demand()[good_entity] = 1;
                                    }
                                    market.sd_ratio = market.supply().SafeDivision(market.demand());
                                    market.history.push_back(market);
                                }
                            }
                        }  // namespace cqsp::common::systems
>>>>>>> pr-290
