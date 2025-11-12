/* Conquer Space
<<<<<<< HEAD
 * Copyright (C) 2021-2025 Conquer Space
=======
 * Copyright (C) 2021-2023 Conquer Space
>>>>>>> pr-292
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
#include "common/actions/factoryconstructaction.h"

#include <spdlog/spdlog.h>

#include <limits>
#include <map>

<<<<<<< HEAD
#include "common/actions/economy/markethelpers.h"
#include "common/components/area.h"
#include "common/components/market.h"
#include "common/components/resource.h"

    namespace cqsp::common::actions {
    Node OrderConstructionFactory(Node & city, Node & market, Node & recipe, Node & builder, int productivity) {
        Node factory = CreateFactory(city, recipe, productivity);
        if (factory.entity() == entt::null) {
            return Node(city.universe(), entt::null);
        }
        AddParticipant(market, factory);
        auto cost = GetFactoryCost(city, recipe, productivity);

        // Buy the goods on the market
        PurchaseGood(builder, cost);
        return factory;
    }

    Node CreateFactory(Node & city, Node & recipe, int productivity, double wages) {
        // Make the factory
        if (city == entt::null || recipe == entt::null) {
            SPDLOG_WARN("City or recipe is null");
            return Node(city.universe(), entt::null);
        }
        if (!city.valid() || !recipe.valid()) {
            SPDLOG_WARN("City or recipe is invalid");
            return Node(city.universe(), entt::null);
        }
        if (!city.any_of<components::IndustrialZone>()) {
            SPDLOG_WARN("City {} has no industry", city.entity());
            return Node(city.universe(), entt::null);
        }

        if (!recipe.any_of<components::Recipe>()) {
            SPDLOG_WARN("Recipe {} has no recipe", recipe.entity());
            return Node(city.universe(), entt::null);
        }

        Node factory(city.universe());
        //auto& factory_converter = universe.emplace<components::ResourceConverter>(factory);
        auto& production = factory.emplace<components::Production>();
        // Add recipes and stuff
        production.recipe = recipe;
        city.get<components::IndustrialZone>().industries.push_back(factory);

        // Add capacity
        // Add producivity
        auto& prod = factory.emplace<components::IndustrySize>();
        prod.size = productivity;
        prod.utilization = productivity;
        prod.wages = wages;
        const auto& recipe_comp = recipe.get<components::Recipe>();
        switch (recipe_comp.type) {
            case components::mine:
                factory.emplace<components::Mine>();
                break;
            case components::service:
                factory.emplace<components::Service>();
                break;
            default:
                factory.emplace<components::Factory>();
        }

        auto& employer = factory.emplace<components::Employer>();
        == == == =
#include "common/actions/economy/markethelpers.h"
#include "common/components/area.h"
#include "common/components/economy.h"
#include "common/components/resource.h"

                     < < < < < < < <
                     HEAD : src / common / systems / actions / factoryconstructaction.cpp using cqsp::common::Universe;
        namespace components = cqsp::common::components;
        using components::Factory;
        using components::Recipe;
        using components::ResourceLedger;

        using entt::entity;

        namespace cqsp::common::systems::actions {
        entity OrderConstructionFactory(Universe& universe, entity city, entity market, entity recipe, int productivity,
                                        entity builder) {
            == == == == namespace cqsp::common::actions {
                entt::entity OrderConstructionFactory(Universe & universe, entt::entity city, entt::entity market,
                                                      entt::entity recipe, int productivity, entt::entity builder) {
                    >>>>>>>> pr - 292 : src / common / actions / factoryconstructaction.cpp entt::entity factory =
                        CreateFactory(universe, city, recipe, productivity);
                    if (factory == entt::null) {
                        return entt::null;
                    }
                    AddParticipant(universe, market, factory);
                    auto cost = GetFactoryCost(universe, city, recipe, productivity);

                    // Buy the goods on the market
                    PurchaseGood(universe, builder, cost);
                    return factory;
                }

                entt::entity CreateFactory(Universe & universe, entity city, entity recipe, int productivity) {
                    // Make the factory
<<<<<<< HEAD
                    if (city == entt::null || recipe == entt::null) {
                        SPDLOG_WARN("City or recipe is null");
                        return entt::null;
                    }
                    if (!universe.valid(city) || !universe.valid(recipe)) {
                        SPDLOG_WARN("City or recipe is invalid");
                        return entt::null;
                    }
                    if (!universe.any_of<components::IndustrialZone>(city)) {
                        == == == = if (!universe.any_of<cqspc::IndustrialZone>(city)) {
>>>>>>> pr_191
                            SPDLOG_WARN("City {} has no industry", city);
                            return entt::null;
                        }

                        if (!universe.any_of<components::Recipe>(recipe)) {
                            SPDLOG_WARN("Recipe {} has no recipe", recipe);
                            return entt::null;
                        }

                        entity factory = universe.create();
                        //auto& factory_converter = universe.emplace<cqspc::ResourceConverter>(factory);
                        auto& production = universe.emplace<components::Production>(factory);
                        // Add recipes and stuff
                        production.recipe = recipe;
<<<<<<< HEAD
                        universe.get<components::IndustrialZone>(city).industries.push_back(factory);

                        // Add capacity
                        // Add producivity
                        auto& prod = universe.emplace<components::IndustrySize>(factory);
                        prod.size = productivity;
                        prod.utilization = productivity;
                        const auto& recipe_comp = universe.get<components::Recipe>(recipe);
                        switch (recipe_comp.type) {
                            case components::mine:
                                universe.emplace<components::Mine>(factory);
                                == == == = universe.get<cqspc::IndustrialZone>(city).industries.push_back(factory);

                                // Add capacity
                                // Add producivity
                                auto& prod = universe.emplace<cqspc::IndustrySize>(factory);
                                prod.size = productivity;
                                prod.utilization = 1;

                                switch (universe.get<cqspc::Recipe>(recipe).type) {
                                    case cqspc::mine:
                                        universe.emplace<cqspc::Mine>(factory);
>>>>>>> pr_191
                                        break;
                                    case components::service:
                                        universe.emplace<components::Service>(factory);
                                        break;
                                    default:
                                        universe.emplace<components::Factory>(factory);
                                }

                                auto& employer = universe.emplace<components::Employer>(factory);
                                // Set the employment amount, next time we can add other services like HR, tech, etc.
                                employer.population_fufilled = 0;
                                employer.population_needed = recipe_comp.workers * productivity;
                                employer.segment = entt::null;
                                return factory;
                        }

                        ResourceLedger GetFactoryCost(Universe & universe, entity city, entity recipe,
                                                      int productivity) {
                            ResourceLedger ledger;
                            // Get the recipe and things
                            if (universe.any_of<components::RecipeCost>(recipe)) {
                                auto& cost = universe.get<components::RecipeCost>(recipe);
                                ledger.MultiplyAdd(cost.scaling, productivity);
                                ledger += cost.fixed;
                            }
                            return ledger;
                        }

<<<<<<< HEAD
                        entity CreateCommercialArea(common::Universe & universe, entity city) {
                            entity commercial = universe.create();

                            universe.emplace<components::Employer>(commercial);
                            universe.emplace<components::Commercial>(commercial, city, 0);

                            universe.get<components::IndustrialZone>(city).industries.push_back(commercial);
                            return commercial;
                        }

                    }  // namespace cqsp::common::systems::actions
                    == == == =

                                 entt::entity cqsp::common::systems::actions::CreateCommercialArea(
                                     cqsp::common::Universe & universe, entt::entity city) {
                        namespace cqspc = cqsp::common::components;
                        entt::entity commercial = universe.create();

                        universe.emplace<cqspc::Employer>(commercial);
                        universe.emplace<cqspc::Commercial>(commercial, city, 0);

                        universe.get<cqspc::IndustrialZone>(city).industries.push_back(commercial);
                        return commercial;
                    }

                    < < < < < < < < HEAD : src / common / systems / actions / factoryconstructaction.cpp
>>>>>>> pr_191
                        == == == == if (!universe.any_of<components::Recipe>(recipe)) {
                        SPDLOG_WARN("Recipe {} has no recipe", recipe);
                        return entt::null;
                    }

                    entt::entity factory = universe.create();
                    //auto& factory_converter = universe.emplace<components::ResourceConverter>(factory);
                    auto& production = universe.emplace<components::Production>(factory);
                    // Add recipes and stuff
                    production.recipe = recipe;
                    universe.get<components::IndustrialZone>(city).industries.push_back(factory);

                    // Add capacity
                    // Add producivity
                    auto& prod = universe.emplace<components::IndustrySize>(factory);
                    prod.size = productivity;
                    prod.utilization = productivity;
                    const auto& recipe_comp = universe.get<components::Recipe>(recipe);
                    switch (recipe_comp.type) {
                        case components::mine:
                            universe.emplace<components::Mine>(factory);
                            break;
                        case components::service:
                            universe.emplace<components::Service>(factory);
                            break;
                        default:
                            universe.emplace<components::Factory>(factory);
                    }

                    auto& employer = universe.emplace<components::Employer>(factory);
>>>>>>> pr-292
                    // Set the employment amount, next time we can add other services like HR, tech, etc.
                    employer.population_fufilled = 0;
                    employer.population_needed = recipe_comp.workers * productivity;
                    employer.segment = entt::null;
                    return factory;
                }

<<<<<<< HEAD
                components::ResourceLedger GetFactoryCost(Node & city, Node & recipe, int productivity) {
                    components::ResourceLedger ledger;
                    // Get the recipe and things
                    if (recipe.any_of<components::RecipeCost>()) {
                        auto& cost = recipe.get<components::RecipeCost>();
                        == == == = components::ResourceLedger GetFactoryCost(Universe & universe, entt::entity city,
                                                                             entt::entity recipe, int productivity) {
                            components::ResourceLedger ledger;
                            // Get the recipe and things
                            if (universe.any_of<components::RecipeCost>(recipe)) {
                                auto& cost = universe.get<components::RecipeCost>(recipe);
>>>>>>> pr-292
                                ledger.MultiplyAdd(cost.scaling, productivity);
                                ledger += cost.fixed;
                            }
                            return ledger;
                        }

<<<<<<< HEAD
                        Node CreateCommercialArea(Node & city) {
                            Node commercial(city.universe());

                            commercial.emplace<components::Employer>();
                            commercial.emplace<components::Commercial>(city, 0);

                            city.get<components::IndustrialZone>().industries.push_back(commercial);
                            return commercial;
                        }
                    }  // namespace cqsp::common::actions
                    == == == = entt::entity CreateCommercialArea(Universe & universe, entt::entity city) {
                        entt::entity commercial = universe.create();

                        universe.emplace<components::Employer>(commercial);
                        universe.emplace<components::Commercial>(commercial, city, 0);

                        universe.get<components::IndustrialZone>(city).industries.push_back(commercial);
                        return commercial;
                    }
                }  // namespace cqsp::common::actions
                >>>>>>>> pr - 292 : src / common / actions / factoryconstructaction.cpp
>>>>>>> pr-292
