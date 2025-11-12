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
#include "common/systems/sysuniversegenerator.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <string>

<<<<<<< HEAD
#include "common/actions/economy/markethelpers.h"
#include "common/actions/factoryconstructaction.h"
    == == ==
    =
>>>>>>> pr-292
#include "common/actions/shiplaunchaction.h"
#include "common/components/area.h"
#include "common/components/bodies.h"
        <<<<<<< HEAD
#include "common/components/coordinates.h"
#include "common/components/market.h"
#include "common/components/name.h"
        == == ==
    =
#include "common/components/movement.h"
        >>>>>>> pr_8
#include "common/components/organizations.h"
#include "common/components/player.h"
#include "common/components/population.h"
#include "common/components/resource.h"
#include "common/components/ships.h"
            < < < < < < < HEAD
#include "common/components/surface.h"
            <<<<<<< HEAD ==
        == ==
    =
#include "common/actions/economy/markethelpers.h"
#include "common/actions/factoryconstructaction.h"
        >>>>>>> pr-292
#include "common/util/random/stdrandom.h"
        == == ==
    =
>>>>>>> pr_4

<<<<<<< HEAD
        namespace cqsp::common::systems::universegenerator {

<<<<<<< HEAD
    namespace bodies = components::bodies;
    namespace ships = components::ships;
    namespace types = components::types;
    == == == = namespace cqsp::common::systems::universegenerator {
        namespace bodies = components::bodies;
        namespace ships = components::ships;
        namespace types = components::types;

        void ScriptUniverseGenerator::Generate(Universe & universe) {
            script_engine["goods"] = universe.goods;
            script_engine["recipes"] = universe.recipes;
            script_engine["terrain_colors"] = universe.terrain_data;
            script_engine["fields"] = universe.fields;
            script_engine["technologies"] = universe.technologies;
            script_engine["countries"] = universe.countries;
            SPDLOG_INFO("Set goods");
            // Create player
            // Set player
            // Set to country
            auto player = universe.countries["usa"];
            //universe.emplace<components::Civilization>(player);
            universe.emplace<components::Player>(player);
>>>>>>> pr-303

            void ScriptUniverseGenerator::Generate(Universe & universe) {
                == == == = void conquerspace::common::systems::universegenerator::ScriptUniverseGenerator::Generate(
                             conquerspace::common::components::Universe & universe) {
                    namespace cqspb = conquerspace::common::components::bodies;
                    namespace cqsps = conquerspace::common::components::ships;
                    namespace cqspt = conquerspace::common::components::types;
                    namespace cqspc = conquerspace::common::components;

                    // Init civilization script
                    script_engine.set_function("create_star_system", [&]() {
                        entt::entity ent = universe.create();
                        universe.emplace<cqspb::StarSystem>(ent);
                        return ent;
                    });

                    // RNG
                    boost::mt19937 gen;
                    script_engine.set_function("random", [&gen](int low, int high) {
                        boost::random::uniform_int_distribution<> dist(low, high);
                        return dist(gen);
                    });

                    script_engine.set_function("random_normal_int", [&gen](int mean, int sd) {
                        boost::normal_distribution<> nd(mean, sd);
                        boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > var_nor(gen, nd);
                        return static_cast<int>(round(var_nor()));
                    });

                    script_engine.set_function("add_planet", [&](entt::entity system) {
                        entt::entity planet = universe.create();
                        auto& body = universe.emplace<cqspb::Body>(planet);
                        body.star_system = system;
                        universe.emplace<cqspb::Planet>(planet);
                        universe.get<cqspb::StarSystem>(system).bodies.push_back(planet);
                        return planet;
                    });

                    script_engine.set_function("add_star", [&](entt::entity system) {
                        entt::entity star = universe.create();
                        universe.emplace<cqspb::Star>(star);
                        auto& body = universe.emplace<cqspb::Body>(star);
                        body.star_system = system;

                        universe.emplace<cqspb::LightEmitter>(star);

<<<<<<< HEAD
                        universe.get<cqspb::StarSystem>(system).bodies.push_back(star);
                        return star;
                    });
                    == == == = script_engine.set_function("set_orbit", [&](entt::entity orbital_entity, double distance,
                                                                           double theta, double eccentricity,
                                                                           double argument) {
                        cqspt::Orbit& orb =
                            universe.emplace<cqspt::Orbit>(orbital_entity, theta, distance, eccentricity, argument, 40);
                        universe.emplace<cqspt::Kinematics>(orbital_entity);
                        cqspt::findPeriod(orb);
                    });
>>>>>>> pr_8

                    script_engine.set_function("set_orbit", [&](entt::entity orbital_entity, double distance,
                                                                double theta, double eccentricity, double argument) {
                        cqspt::Orbit& orb =
                            universe.emplace<cqspt::Orbit>(orbital_entity, theta, distance, eccentricity, argument, 40);
                        cqspt::findPeriod(orb);
                    });

                    script_engine.set_function("set_radius", [&](entt::entity body, int radius) {
                        cqspb::Body& bod = universe.get<cqspb::Body>(body);
                        bod.radius = radius;
                    });

                    script_engine.set_function("add_civilization", [&]() {
                        entt::entity civ = universe.create();
                        universe.emplace<cqspc::Organization>(civ);
                        return civ;
                    });

                    script_engine.set_function("set_civilization_planet", [&](entt::entity civ, entt::entity planet) {
                        universe.emplace<cqspc::Civilization>(civ, planet);
                    });

                    script_engine.set_function("get_civilization_planet", [&](entt::entity civ) {
                        return universe.get<cqspc::Civilization>(civ).starting_planet;
                    });

                    script_engine.set_function("is_player", [&](entt::entity civ) {
                        return static_cast<bool>(universe.all_of<cqspc::Player>(civ));
                    });

                    script_engine.set_function("add_planet_habitation", [&](entt::entity planet) {
                        universe.emplace<cqspc::Habitation>(planet);
                    });

                    script_engine.set_function("add_planet_settlement", [&](entt::entity planet) {
                        entt::entity settlement = universe.create();
                        universe.emplace<cqspc::Settlement>(settlement);
                        // Add to planet list
                        universe.get<cqspc::Habitation>(planet).settlements.push_back(settlement);
                        return settlement;
                    });

                    script_engine.set_function(
                        "add_population_segment", [&](entt::entity settlement, uint64_t popsize) {
                            entt::entity population = universe.create();
                            universe.emplace<cqspc::PopulationSegment>(population, popsize);
                            // Add to planet list
                            universe.get<cqspc::Settlement>(settlement).population.push_back(population);

                            return population;
                        });

                    // Configure the population
                    script_engine.set_function("set_name", [&](entt::entity entity, std::string name) {
                        universe.emplace_or_replace<cqspc::Name>(entity, name);
                    });

                    script_engine.set_function("create_industries",
                                               [&](entt::entity city) { universe.emplace<cqspc::Industry>(city); });

                    script_engine.set_function("create_factory",
                                               [&](entt::entity city, entt::entity recipe, float productivity) {
                                                   entt::entity factory = universe.create();
                                                   auto& gen = universe.emplace<cqspc::ResourceConverter>(factory);
                                                   universe.emplace<cqspc::Factory>(factory);

                                                   // Add producivity
                                                   auto& prod = universe.emplace<cqspc::FactoryProductivity>(factory);
                                                   prod.productivity = productivity;

                                                   universe.emplace<cqspc::ResourceStockpile>(factory);

                                                   // Add recipes and stuff
                                                   gen.recipe = recipe;
                                                   universe.get<cqspc::Industry>(city).industries.push_back(factory);

                                                   return factory;
                                               });

                    script_engine.set_function(
                        "create_mine", [&](entt::entity city, entt::entity resource, int amount, float productivity) {
                            entt::entity mine = universe.create();
                            auto& gen = universe.emplace<cqspc::ResourceGenerator>(mine);
                            universe.emplace<cqspc::Mine>(mine);

                            gen.emplace(resource, amount);
                            universe.get<cqspc::Industry>(city).industries.push_back(mine);

                            // Add producivity
                            auto& prod = universe.emplace<cqspc::FactoryProductivity>(mine);
                            prod.productivity = productivity;

                            universe.emplace<cqspc::ResourceStockpile>(mine);
                            return mine;
                        });

                    script_engine.set_function("create_terrain", [&](entt::entity planet, int seed) {
                        universe.emplace<cqspb::Terrain>(planet, seed);
                    });

                    script_engine.set_function(
                        "create_ship", [&](entt::entity civ, entt::entity orbit, entt::entity starsystem) {
                            entt::entity ship = universe.create();
                            universe.emplace<cqsps::Ship>(ship);
                            cqspt::Orbit orb = universe.get<cqspt::Orbit>(orbit);
                            cqspt::Orbit& orbship = universe.emplace<cqspt::Orbit>(ship, orb.theta, orb.semiMajorAxis,
                                                                                   orb.eccentricity, orb.argument, 80);
                            universe.get<cqspb::StarSystem>(starsystem).bodies.push_back(ship);
                            cqspt::findPeriod(orbship);
                        });

<<<<<<< HEAD
>>>>>>> pr_4
                    script_engine["goods"] = universe.goods;
                    script_engine["recipes"] = universe.recipes;
                    script_engine["terrain_colors"] = universe.terrain_data;
                    script_engine["fields"] = universe.fields;
                    script_engine["technologies"] = universe.technologies;
                    script_engine["countries"] = universe.countries;
                    SPDLOG_INFO("Set goods");
                    // Create player
                    // Set player
                    // Set to country
                    auto player = universe.countries["usa"];
                    //universe.emplace<components::Civilization>(player);
                    universe.emplace<components::Player>(player);
                    == == == = universe.emplace<cqspc::ResourceStockpile>(mine);
                    return mine;
                });

                script_engine.set_function("create_terrain", [&](entt::entity planet, int seed) {
                    universe.emplace<cqspb::Terrain>(planet, seed);
                });

                script_engine.set_function("create_ship",
                                           [&](entt::entity civ, entt::entity orbit, entt::entity starsystem) {
                                               entt::entity ship = universe.create();
                                               universe.emplace<cqsps::Ship>(ship);
                                               universe.emplace<cqspt::Kinematics>(ship);
                                               //cqspt::Kinematics orb = universe.get<cqspt::Kinematics>(orbit);
                                               //cqspt::updatePos(orb);
                                               universe.get<cqspb::StarSystem>(starsystem).bodies.push_back(ship);
                                               return ship;
                                           });

                script_engine["goods"] = universe.goods;
                script_engine["recipes"] = universe.recipes;

                // Create player
                auto player = universe.create();
                universe.emplace<cqspc::Organization>(player);
                universe.emplace<cqspc::Player>(player);

                for (int i = 0; i < 9; i++) {
                    auto civ = universe.create();
                    universe.emplace<cqspc::Organization>(civ);
                }
>>>>>>> pr_8

                // Add top level fleet
                /*
    auto playerFleet = universe.create();
    universe.emplace<components::Name>(playerFleet, "navy");
    universe.emplace<components::ships::Fleet>(playerFleet, player);
    universe.get<components::Civilization>(player).top_level_fleet = playerFleet;
    // Add a subfleet
    auto playerSubFleet = universe.create();
    universe.emplace<components::Name>(playerSubFleet, "vice-navy");
    universe.emplace<components::ships::Fleet>(playerSubFleet, playerFleet, player, 1);
    universe.get<ships::Fleet>(universe.get<components::Civilization>(player).top_level_fleet)
        .subfleets.push_back(playerSubFleet);
        */
                /*
    sol::optional<sol::table> generator = script_engine["generators"]["data"][1];
    if (generator) {
        (*generator)["civ_init"]();
        //script_engine["civilizations"] = sol::as_table(universe.view<components::Civilization>());
        (*generator)["universe_gen"]();
        auto view = universe.view<components::Civilization>();
        SPDLOG_INFO("Initing planets");
        for (auto ent : view) {
            (*generator)["planets"](ent);
        }
    } else {
        SPDLOG_ERROR("No generator");
    }*/
                SPDLOG_INFO("Done generating");
            }
        }  // namespace cqsp::common::systems::universegenerator
