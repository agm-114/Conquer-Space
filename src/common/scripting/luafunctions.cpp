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
#include "common/scripting/luafunctions.h"

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "common/actions/cityactions.h"
#include "common/actions/economy/markethelpers.h"
#include "common/actions/factoryconstructaction.h"
#include "common/actions/science/labs.h"
#include "common/actions/shiplaunchaction.h"
#include "common/components/area.h"
#include "common/components/bodies.h"
#include "common/components/coordinates.h"
#include "common/components/event.h"
#include "common/components/infrastructure.h"
#include "common/components/market.h"
#include "common/components/name.h"
#include "common/components/orbit.h"
#include "common/components/organizations.h"
#include "common/components/player.h"
#include "common/components/population.h"
#include "common/components/resource.h"
#include "common/components/science.h"
#include "common/components/ships.h"
#include "common/components/surface.h"
#include "common/loading/technology.h"
#include "common/scripting/functionreg.h"
<<<<<<< HEAD == == == =
#include "common/actions/cityactions.h"
#include "common/actions/economy/markethelpers.h"
#include "common/actions/factoryconstructaction.h"
#include "common/actions/science/labs.h"
#include "common/actions/shiplaunchaction.h"
#include "common/loading/technology.h"
    >>>>>>> pr - 292
#include "common/util/nameutil.h"
#include "common/util/random/stdrandom.h"
#include "common/util/utilnumberdisplay.h"

                <<<<<<< HEAD < < < < < < <
    HEAD
    /**
 * Notes:
 * If you want to return arrays you need to encapsulate it on sol::as_table
 */
    namespace cqsp::common::scripting {
    namespace bodies = components::bodies;
    namespace types = components::types;
    namespace infrastructure = components::infrastructure;
    == == == =

                 /**
 * Notes:
 * If you want to return arrays you need to encapsulate it on sol::as_table
 */
        namespace cqsp::common::scripting {
        namespace bodies = components::bodies;
        namespace types = components::types;
        namespace infrastructure = components::infrastructure;
        namespace actions = systems::actions;

        using bodies::Body;
        using components::Governed;
        using components::Habitation;
        using components::IndustrialZone;
        using components::Market;
        using components::Player;
        using components::PopulationSegment;
        using components::Price;
        using components::ResourceStockpile;
        using components::Settlement;
        using components::Wallet;
        using components::science::ScientificResearch;

        /// <summary>
        /// Initializes functions for RNG
        /// </summary>
        /// <param name="app"></param>
        void FunctionRandom(Universe & universe, ScriptInterface & script_engine) {
            // RNG
            // Make namespace
            CREATE_NAMESPACE(core);
>>>>>>> pr-290

<<<<<<< HEAD
            using bodies::Body;
            using components::Governed;
            using components::Habitation;
            using components::IndustrialZone;
            using components::Market;
            using components::Player;
            using components::PopulationSegment;
            using components::Price;
            using components::ResourceStockpile;
            using components::Settlement;
            using components::Wallet;
            using components::science::ScientificResearch;
            == == == = namespace bodies = components::bodies;
            namespace types = components::types;
            namespace infrastructure = components::infrastructure;
>>>>>>> pr-292

            == == == = namespace components = cqsp::common::components;
            namespace bodies = components::bodies;
            namespace ships = components::ships;
            namespace types = components::types;
            namespace actions = cqsp::common::systems::actions;
            namespace infrstructure = components::infrastructure;
            using bodies::Body;
            using entt::entity;

<<<<<<< HEAD
            namespace cqsp::common::scripting {
>>>>>>> pr_254
            /// <summary>
            /// Initializes functions for RNG
            /// </summary>
            /// <param name="app"></param>
            void FunctionRandom(Universe& universe, ScriptInterface& script_engine) {
                // RNG
                // Make namespace
                CREATE_NAMESPACE(core);

                REGISTER_FUNCTION("random",
                                  [&](int low, int high) { return universe.random->GetRandomInt(low, high); });

                REGISTER_FUNCTION("random_normal_int",
                                  [&](int mean, int sd) { return universe.random->GetRandomNormalInt(mean, sd); });
            }
            == == == = void FunctionUniverseBodyGen(Universe & universe, ScriptInterface& script_engine) {
                CREATE_NAMESPACE(core);

                REGISTER_FUNCTION("add_planet", [&]() {
                    entt::entity planet = universe.create();
                    Body& body = universe.emplace<Body>(planet);
                    universe.emplace<bodies::Planet>(planet);
                    return planet;
                });

                REGISTER_FUNCTION("add_star", [&]() {
                    entt::entity star = universe.create();
                    universe.emplace<bodies::Star>(star);
                    Body& body = universe.emplace<Body>(star);
                    universe.emplace<bodies::LightEmitter>(star);
                    return star;
                });
>>>>>>> pr-290

                void FunctionUniverseBodyGen(Universe & universe, ScriptInterface & script_engine) {
                    CREATE_NAMESPACE(core);

                    REGISTER_FUNCTION("add_planet", [&]() {
<<<<<<< HEAD
                        entt::entity planet = universe.create();
                        Body& body = universe.emplace<Body>(planet);
                        == == == = entity planet = universe.create();
                        universe.emplace<Body>(planet);
>>>>>>> pr_254
                        universe.emplace<bodies::Planet>(planet);
                        return planet;
                    });

                    REGISTER_FUNCTION("add_star", [&]() {
                        entt::entity star = universe.create();
                        universe.emplace<bodies::Star>(star);
<<<<<<< HEAD
                        Body& body = universe.emplace<Body>(star);
                        == == == = universe.emplace<Body>(star);
>>>>>>> pr_254
                        universe.emplace<bodies::LightEmitter>(star);
                        return star;
                    });

<<<<<<< HEAD
<<<<<<< HEAD
    REGISTER_FUNCTION("set_orbit", [&](entt::entity orbital_entity, double semi_major_axis, double eccentricity,
=======
    REGISTER_FUNCTION("set_orbit", [&](entity orbital_entity, double semi_major_axis, double eccentricity,
>>>>>>> pr_254
                                       double inclination, double LAN, double w, double M0) {
<<<<<<< HEAD
                        types::Orbit& orb = universe.emplace<types::Orbit>(orbital_entity);
                        orb.eccentricity = eccentricity;
                        orb.semi_major_axis = semi_major_axis;
                        orb.inclination = inclination;
                        orb.LAN = LAN;
                        orb.w = w;
                        orb.M0 = M0;
                        auto& kinematics = universe.emplace<types::Kinematics>(orbital_entity);
                        types::UpdatePos(kinematics, orb);
<<<<<<< HEAD
                        == == ==
                            = REGISTER_FUNCTION("set_orbit", [&](entt::entity orbital_entity, double distance,
                                                                 double theta, double eccentricity, double argument) {
                                  cqspt::Orbit& orb = universe.emplace<cqspt::Orbit>(orbital_entity, theta, distance,
                                                                                     eccentricity, argument, 40);
                                  cqspt::findPeriod(orb);
                                  universe.emplace<cqspt::Kinematics>(orbital_entity);
>>>>>>> pr_28
                              });

                        REGISTER_FUNCTION("set_system_position", [&](entt::entity orbital_ent, double x, double y) {
                            auto& coord = universe.get_or_emplace<types::GalacticCoordinate>(orbital_ent);
                            coord.x = x;
                            coord.y = y;
                        });

                        REGISTER_FUNCTION("set_radius", [&](entt::entity body, int radius) {
                            Body& bod = universe.get<Body>(body);
                            bod.radius = radius;
                        });

                        REGISTER_FUNCTION(
                            "create_terrain", [&](entt::entity planet, int seed, entt::entity terrain_type) {
                                static_cast<void>(universe.emplace<bodies::Terrain>(planet, seed, terrain_type));
                            });
}

void FunctionCivilizationGen(Universe& universe, ScriptInterface& script_engine) {
                        CREATE_NAMESPACE(core);

                        REGISTER_FUNCTION("add_civilization", [&]() {
                            entt::entity civ = universe.create();
                            universe.emplace<components::Organization>(civ);
                            return civ;
                        });

                        REGISTER_FUNCTION("set_owner", [&](entt::entity entity, entt::entity owner) {
                            auto& gov = universe.get_or_emplace<Governed>(entity);
                            gov.governor = owner;
                        });

                        REGISTER_FUNCTION("get_governed", [&](entt::entity governor) {
                            auto view = universe.view<Governed>();
                            // this is probably an antiBpattern but ah well
                            std::vector<entt::entity> governed;
                            for (auto entity : view) {
                                if (universe.get<Governed>(entity).governor == governor) {
                                    governed.push_back(entity);
                                }
                            }
                            return sol::as_table(governed);
                        });

                        REGISTER_FUNCTION("get_owned_cities", [&](entt::entity player) {
                            return sol::as_table(universe.get<components::CountryCityList>(player).province_list);
                        });

                        REGISTER_FUNCTION("is_player", [&](entt::entity civ) {
                            return static_cast<bool>(universe.all_of<Player>(civ));
                        });

                        REGISTER_FUNCTION("add_planet_habitation",
                                          [&](entt::entity planet) { universe.emplace<Habitation>(planet); });

<<<<<<< HEAD
<<<<<<< HEAD
                        REGISTER_FUNCTION("add_planet_settlement", [&](entt::entity planet, double lat, double longi) {
                            Node planet_node(universe, planet);
                            return actions::CreateCity(planet_node, lat, longi);
                        });
                        == == == = REGISTER_FUNCTION("add_planet_settlement",
                                                     [&](entt::entity planet, double lat, double longi) {
                                                         Node planet_node(universe, planet);
                                                         return actions::CreateCity(planet_node, lat, longi);
                                                     });
>>>>>>> pr-309
                        == == == = REGISTER_FUNCTION("add_planet_settlement",
                                                     [&](entt::entity planet, double lat, double longi) {
                                                         return actions::CreateCity(universe, planet, lat, longi);
                                                     });
>>>>>>> pr-292
}

void FunctionEconomy(Universe& universe, ScriptInterface& script_engine) {
                        CREATE_NAMESPACE(core);

                        REGISTER_FUNCTION("create_industries",
                                          [&](entt::entity city) { universe.emplace<IndustrialZone>(city); });

                        REGISTER_FUNCTION("add_industry", [&](entt::entity city, entt::entity entity) {
                            universe.get<IndustrialZone>(city).industries.push_back(entity);
                        });

<<<<<<< HEAD
<<<<<<< HEAD
                        REGISTER_FUNCTION("create_factory", [&](entt::entity city, entt::entity recipe,
                                                                int productivity) {
                            Node city_node(universe, city);
                            Node recipe_node(universe, recipe);
                            Node factory = actions::CreateFactory(city_node, recipe_node, productivity);
                            return factory;
                            == == == = REGISTER_FUNCTION(
                                         "add_planet_settlement", [&](entt::entity planet, double lat, double longi) {
                                             entt::entity settlement = universe.create();
                                             universe.emplace<cqspc::Settlement>(settlement);
                                             // Add to planet list
                                             universe.get<cqspc::Habitation>(planet).settlements.push_back(settlement);
                                             universe.emplace<cqspt::SurfaceCoordinate>(settlement, lat, longi, planet);
                                             universe.emplace<cqspt::Kinematics>(settlement);
                                             return settlement;
>>>>>>> pr_28
                                         });
                            == == == = REGISTER_FUNCTION("create_factory", [&](entt::entity city, entt::entity recipe,
                                                                               int productivity) {
                                Node city_node(universe, city);
                                Node recipe_node(universe, recipe);
                                Node factory = actions::CreateFactory(city_node, recipe_node, productivity);
                                return factory;
                            });
>>>>>>> pr-303

                            REGISTER_FUNCTION("add_production", [&](entt::entity factory) {
                                // Factory will produce in the first tick
                                universe.emplace<components::FactoryProducing>(factory);
                            });

                            REGISTER_FUNCTION(
                                "set_power_consumption", [&](entt::entity factory, double max, double min) {
                                    universe.emplace<infrastructure::PowerConsumption>(factory, max, min, 0.f);
                                    return factory;
                                });

                            REGISTER_FUNCTION("add_power_plant", [&](entt::entity city, double productivity) {
                                entt::entity entity = universe.create();
                                universe.emplace<infrastructure::PowerPlant>(entity, productivity);
                                universe.get<IndustrialZone>(city).industries.push_back(entity);
                                return entity;
                            });

<<<<<<< HEAD
                            REGISTER_FUNCTION("create_commercial_area", [&](entt::entity city) {
                                Node city_node(universe, city);
                                return actions::CreateCommercialArea(city_node);
                            });
                            == == == = REGISTER_FUNCTION("create_commercial_area", [&](entt::entity city) {
                                Node city_node(universe, city);
                                return actions::CreateCommercialArea(city_node);
                            });
>>>>>>> pr-303

                            REGISTER_FUNCTION("set_resource_consume", [&](entt::entity entity, entt::entity good,
                                                                          double amount) {
                                auto& consumption = universe.get_or_emplace<components::ResourceConsumption>(entity);
                                consumption[good] = amount;
                            });

                            REGISTER_FUNCTION(
                                "set_resource", [&](entt::entity planet, entt::entity resource, int seed) {
                                    auto& dist = universe.get_or_emplace<components::ResourceDistribution>(planet);
                                    dist.dist[resource] = seed;
                                });
                            == == == =
                        });

                        REGISTER_FUNCTION("set_system_position", [&](entt::entity orbital_ent, double x, double y) {
                            auto& coord = universe.get_or_emplace<types::GalacticCoordinate>(orbital_ent);
                            coord.x = x;
                            coord.y = y;
                        });

                        REGISTER_FUNCTION("set_radius", [&](entity body, int radius) {
                            Body& bod = universe.get<Body>(body);
                            bod.radius = radius;
                        });

                        REGISTER_FUNCTION("create_terrain", [&](entity planet, int seed, entity terrain_type) {
                            static_cast<void>(universe.emplace<bodies::Terrain>(planet, seed, terrain_type));
                        });
}

void FunctionCivilizationGen(Universe& universe, ScriptInterface& script_engine) {
                        CREATE_NAMESPACE(core);

<<<<<<< HEAD
                        REGISTER_FUNCTION("add_civilization", [&]() {
                            entity civ = universe.create();
                            universe.emplace<components::Organization>(civ);
                            return civ;
                        });

                        REGISTER_FUNCTION("set_owner", [&](entity owned, entity owner) {
                            auto& gov = universe.get_or_emplace<components::Governed>(owned);
                            gov.governor = owner;
                        });
                        == == == = REGISTER_FUNCTION("create_industries", [&](entt::entity city) {
                            universe.emplace<cqspc::IndustrialZone>(city);
                        });

                        REGISTER_FUNCTION("add_industry", [&](entt::entity city, entt::entity entity) {
                            universe.get<cqspc::IndustrialZone>(city).industries.push_back(entity);
                        });
>>>>>>> pr_191

                        REGISTER_FUNCTION("is_player", [&](entity civ) {
                            return static_cast<bool>(universe.all_of<components::Player>(civ));
                        });

                        REGISTER_FUNCTION("add_planet_habitation",
                                          [&](entity planet) { universe.emplace<components::Habitation>(planet); });

                        REGISTER_FUNCTION("add_planet_settlement", [&](entity planet, double lat, double longi) {
                            return actions::CreateCity(universe, planet, lat, longi);
                        });
}

<<<<<<< HEAD
void FunctionEconomy(Universe& universe, ScriptInterface& script_engine) {
                        CREATE_NAMESPACE(core);
                        == == == = REGISTER_FUNCTION("add_power_plant", [&](entt::entity city, double productivity) {
                            entt::entity entity = universe.create();
                            universe.emplace<cqspc::infrastructure::PowerPlant>(entity, productivity);
                            universe.get<cqspc::IndustrialZone>(city).industries.push_back(entity);
                            return entity;
                        });
>>>>>>> pr_191

                        REGISTER_FUNCTION("create_industries",
                                          [&](entity city) { universe.emplace<components::IndustrialZone>(city); });

                        REGISTER_FUNCTION("add_industry", [&](entity city, entity entity) {
                            universe.get<components::IndustrialZone>(city).industries.push_back(entity);
                        });

                        REGISTER_FUNCTION("create_factory", [&](entity city, entity recipe, float productivity) {
                            entity factory = actions::CreateFactory(universe, city, recipe, productivity);
                            return factory;
                        });

                        REGISTER_FUNCTION("add_production", [&](entity factory) {
                            // Factory will produce in the first tick
                            universe.emplace<components::FactoryProducing>(factory);
                        });

                        REGISTER_FUNCTION("set_power_consumption", [&](entity factory, double max, double min) {
                            universe.emplace<components::infrastructure::PowerConsumption>(factory, max, min, 0.f);
                            return factory;
                        });

                        REGISTER_FUNCTION("add_power_plant", [&](entity city, double productivity) {
                            entt::entity entity = universe.create();
                            universe.emplace<components::infrastructure::PowerPlant>(entity, productivity);
                            universe.get<components::IndustrialZone>(city).industries.push_back(entity);
                            return entity;
                        });

                        REGISTER_FUNCTION("create_commercial_area",
                                          [&](entity city) { return actions::CreateCommercialArea(universe, city); });

                        REGISTER_FUNCTION("set_resource_consume", [&](entity consumer, entity good, double amount) {
                            auto& consumption = universe.get_or_emplace<components::ResourceConsumption>(consumer);
                            consumption[good] = amount;
                        });

                        REGISTER_FUNCTION("set_resource", [&](entity planet, entity resource, int seed) {
                            auto& dist = universe.get_or_emplace<components::ResourceDistribution>(planet);
                            dist.dist[resource] = seed;
                        });
>>>>>>> pr_254

                        // TODO(EhWhoAmI): Will have to fix the documentation for this so that it looks neater
                        // The macro cannot take lambadas that contain templates that contain commas
                        auto lambda = [&]() {
                            /*entt::entity entity = universe.create();
=======
        types::Orbit& orb = universe.emplace<types::Orbit>(orbital_entity);
        orb.eccentricity = eccentricity;
        orb.semi_major_axis = semi_major_axis;
        orb.inclination = inclination;
        orb.LAN = LAN;
        orb.w = w;
        orb.M0 = M0;
        auto& kinematics = universe.emplace<types::Kinematics>(orbital_entity);
        types::UpdatePos(kinematics, orb);
    });

    REGISTER_FUNCTION("set_system_position", [&](entt::entity orbital_ent, double x, double y) {
        auto& coord = universe.get_or_emplace<types::GalacticCoordinate>(orbital_ent);
        coord.x = x;
        coord.y = y;
    });

    REGISTER_FUNCTION("set_radius", [&](entt::entity body, int radius) {
        Body& bod = universe.get<Body>(body);
        bod.radius = radius;
    });

    REGISTER_FUNCTION("create_terrain", [&](entt::entity planet, int seed, entt::entity terrain_type) {
        static_cast<void>(universe.emplace<bodies::Terrain>(planet, seed, terrain_type));
    });
}

void FunctionCivilizationGen(Universe& universe, ScriptInterface& script_engine) {
    CREATE_NAMESPACE(core);

    REGISTER_FUNCTION("add_civilization", [&]() {
        entt::entity civ = universe.create();
        universe.emplace<components::Organization>(civ);
        return civ;
    });

    REGISTER_FUNCTION("set_owner", [&](entt::entity entity, entt::entity owner) {
        auto& gov = universe.get_or_emplace<Governed>(entity);
        gov.governor = owner;
    });

    REGISTER_FUNCTION("get_governed", [&](entt::entity governor) {
        auto view = universe.view<Governed>();
        // this is probably an antiBpattern but ah well
        std::vector<entt::entity> governed;
        for (auto entity : view) {
            if (universe.get<Governed>(entity).governor == governor) {
                governed.push_back(entity);
            }
        }
        return sol::as_table(governed);
    });

    REGISTER_FUNCTION("get_owned_cities", [&](entt::entity player) {
        return sol::as_table(universe.get<components::CountryCityList>(player).province_list);
    });

    REGISTER_FUNCTION("is_player", [&](entt::entity civ) { return static_cast<bool>(universe.all_of<Player>(civ)); });

    REGISTER_FUNCTION("add_planet_habitation", [&](entt::entity planet) { universe.emplace<Habitation>(planet); });

    REGISTER_FUNCTION("add_planet_settlement", [&](entt::entity planet, double lat, double longi) {
        return systems::actions::CreateCity(universe, planet, lat, longi);
    });
}

void FunctionEconomy(Universe& universe, ScriptInterface& script_engine) {
    CREATE_NAMESPACE(core);

    REGISTER_FUNCTION("create_industries", [&](entt::entity city) { universe.emplace<IndustrialZone>(city); });

    REGISTER_FUNCTION("add_industry", [&](entt::entity city, entt::entity entity) {
        universe.get<IndustrialZone>(city).industries.push_back(entity);
    });

    REGISTER_FUNCTION("create_factory", [&](entt::entity city, entt::entity recipe, float productivity) {
        entt::entity factory = actions::CreateFactory(universe, city, recipe, productivity);
        return factory;
    });

    REGISTER_FUNCTION("add_production", [&](entt::entity factory) {
        // Factory will produce in the first tick
        universe.emplace<components::FactoryProducing>(factory);
    });

    REGISTER_FUNCTION("set_power_consumption", [&](entt::entity factory, double max, double min) {
        universe.emplace<infrastructure::PowerConsumption>(factory, max, min, 0.f);
        return factory;
    });

    REGISTER_FUNCTION("add_power_plant", [&](entt::entity city, double productivity) {
        entt::entity entity = universe.create();
        universe.emplace<infrastructure::PowerPlant>(entity, productivity);
        universe.get<IndustrialZone>(city).industries.push_back(entity);
        return entity;
    });

    REGISTER_FUNCTION("create_commercial_area",
                      [&](entt::entity city) { return actions::CreateCommercialArea(universe, city); });

    REGISTER_FUNCTION("set_resource_consume", [&](entt::entity entity, entt::entity good, double amount) {
        auto& consumption = universe.get_or_emplace<components::ResourceConsumption>(entity);
        consumption[good] = amount;
    });

    REGISTER_FUNCTION("set_resource", [&](entt::entity planet, entt::entity resource, int seed) {
        auto& dist = universe.get_or_emplace<components::ResourceDistribution>(planet);
        dist.dist[resource] = seed;
    });

    // TODO(EhWhoAmI): Will have to fix the documentation for this so that it looks neater
    // The macro cannot take lambadas that contain templates that contain commas
    auto lambda = [&]() {
        /*entt::entity entity = universe.create();
>>>>>>> pr-290
        auto& market = universe.emplace<components::Market>(entity);
        universe.emplace<components::ResourceStockpile>(entity);
        // Set the market prices
        // TODO(EhWhoAmI): This is a bandaid solution, please fix this

        auto view = universe.view<components::Good, components::Price>();
        for (entt::entity entity : view) {
            // Assign price to market
            market.prices[entity] = universe.get<components::Price>(entity);
        }*/
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                            entt::entity market_entity = actions::CreateMarket(universe);
                            // Set prices of market
                            auto view = universe.view<components::Good, Price>();
                            auto& market = universe.get<Market>(market_entity);
                            for (entt::entity entity : view) {
                                // Assign price to market
                                market.market_information[entity].price = universe.get<Price>(entity);
                                == == == = entt::entity market_entity = systems::economy::CreateMarket(universe);
                                // Set prices of market
                                auto& market = universe.get<components::Market>(market_entity);
                                for (entt::entity entity : universe.view<components::Good, components::Price>()) {
                                    // Assign price to market
                                    market.market_information[entity].price = universe.get<components::Price>(entity);
                                }
                                return market_entity;
                                // return entity;
                            };
                            REGISTER_FUNCTION("create_market", lambda);
                            == == == = entt::entity market_entity = actions::CreateMarket(universe);
                            // Set prices of market
                            auto view = universe.view<components::Good, Price>();
                            auto& market = universe.get<Market>(market_entity);
                            for (entt::entity entity : view) {
                                // Assign price to market
                                market.market_information[entity].price = universe.get<Price>(entity);
                            }
                            return market_entity;
                            // return entity;
                        };
                        REGISTER_FUNCTION("create_market", lambda);
>>>>>>> pr-292

                        REGISTER_FUNCTION("place_market", [&](entity market, entity planet) {
                            universe.emplace<components::MarketCenter>(planet, market);
                        });

<<<<<<< HEAD
<<<<<<< HEAD
                        REGISTER_FUNCTION("attach_market", [&](entity market_entity, entity participant) {
                            systems::economy::AddParticipant(universe, market_entity, participant);
                        });
                        == == == = REGISTER_FUNCTION("attach_market",
                                                     [&](entt::entity market_entity, entt::entity participant) {
                                                         Node market_node(universe, market_entity);
                                                         Node participant_node(universe, participant);
                                                         actions::AddParticipant(market_node, participant_node);
                                                     });
>>>>>>> pr-303
                        == == == = REGISTER_FUNCTION("attach_market",
                                                     [&](entt::entity market_entity, entt::entity participant) {
                                                         actions::AddParticipant(universe, market_entity, participant);
                                                     });
>>>>>>> pr-292

<<<<<<< HEAD
                        REGISTER_FUNCTION("add_cash", [&](entity participant, double balance) {
                            universe.get_or_emplace<components::Wallet>(participant) += balance;
                        });
                        == == == = REGISTER_FUNCTION("add_cash", [&](entt::entity participant, double balance) {
                            universe.get_or_emplace<cqspc::Wallet>(participant) += balance;
                        });
                }

            void
            FunctionUser(cqsp::common::Universe & universe, cqsp::scripting::ScriptInterface & script_engine) {
                        CREATE_NAMESPACE(core);

                        REGISTER_FUNCTION("set_name", [&](entt::entity entity, std::string name) {
                            universe.emplace_or_replace<cqspc::Name>(entity, name);
                        });

                        REGISTER_FUNCTION("to_human_string",
                                          [&](int64_t number) { return cqsp::util::LongToHumanString(number); });

                        REGISTER_FUNCTION("get_name",
                                          [&](entt::entity entity) { return universe.get<cqspc::Name>(entity).name; });
                        == == == = entt::entity market_entity = systems::economy::CreateMarket(universe);
                        // Set prices of market
                        auto view = universe.view<components::Good, Price>();
                        auto& market = universe.get<Market>(market_entity);
                        for (entt::entity entity : view) {
                            // Assign price to market
                            market.market_information[entity].price = universe.get<Price>(entity);
                        }
                        return market_entity;
                        // return entity;
    };
    REGISTER_FUNCTION("create_market", lambda);

    REGISTER_FUNCTION("place_market", [&](entt::entity market, entt::entity planet) {
                        universe.emplace<components::MarketCenter>(planet, market);
    });

    REGISTER_FUNCTION("attach_market", [&](entt::entity market_entity, entt::entity participant) {
                        systems::economy::AddParticipant(universe, market_entity, participant);
    });

    REGISTER_FUNCTION("get_balance", [&](entt::entity participant) {
                        return universe.get_or_emplace<Wallet>(participant).GetBalance();
    });

    REGISTER_FUNCTION("add_balance", [&](entt::entity participant, double balance) {
                        universe.get_or_emplace<Wallet>(participant) += balance;
    });

    auto get_planetary_markets = [&]() {
                        auto view = universe.view<Market, components::PlanetaryMarket>();
                        std::vector<entt::entity> markets;
                        for (entt::entity entity : view) {
                            markets.push_back(entity);
                        }
                        return sol::as_table(markets);
    };
    REGISTER_FUNCTION("get_planetary_markets", get_planetary_markets);
                }

                void FunctionUser(Universe & universe, ScriptInterface & script_engine) {
                    CREATE_NAMESPACE(core);

                    REGISTER_FUNCTION("set_name", [&](entt::entity entity, const std::string& name) {
                        universe.emplace_or_replace<components::Name>(entity, name);
                    });
>>>>>>> pr-290

                    REGISTER_FUNCTION("get_random_name", [&](const std::string& name_gen, const std::string& rule) {
                        return universe.name_generators[name_gen].Generate(rule);
                    });
                }

<<<<<<< HEAD
                void FunctionPopulation(cqsp::common::Universe & universe,
                                        cqsp::scripting::ScriptInterface & script_engine) {
                    CREATE_NAMESPACE(core);
                    == == == = REGISTER_FUNCTION("get_name",
                                                 [&](entt::entity entity) { return util::GetName(universe, entity); });
>>>>>>> pr-290

                    REGISTER_FUNCTION("add_population_segment", [&](entt::entity settlement, uint64_t popsize) {
                        entt::entity population = universe.create();
                        universe.emplace<cqspc::PopulationSegment>(population, popsize);
                        universe.emplace<cqspc::ResourceStockpile>(population);
                        universe.emplace<cqspc::Employee>(population);
                        // Add to planet list
                        universe.get<cqspc::Settlement>(settlement).population.push_back(population);

<<<<<<< HEAD
                        return population;
                    });

                    REGISTER_FUNCTION("get_segment_size", [&](entt::entity segment) {
                        return universe.get<cqspc::PopulationSegment>(segment).population;
                    });
                    == == == = void FunctionPopulation(Universe & universe, ScriptInterface & script_engine) {
                        CREATE_NAMESPACE(core);

    REGISTER_FUNCTION("add_population_segment", [&](entt::entity settlement, uint64_t popsize) {
                            entt::entity population = universe.create();
                            universe.emplace<PopulationSegment>(population, popsize);
                            universe.emplace<components::ResourceStockpile>(population);
                            universe.emplace<components::LaborInformation>(population);
                            // Add to planet list
                            universe.get<Settlement>(settlement).population.push_back(population);
>>>>>>> pr-290

                            // Get population segments of a planet
                            REGISTER_FUNCTION("get_segments", [&](entt::entity planet) {
                                return universe.get<cqspc::Settlement>(planet).population;
                            });

<<<<<<< HEAD
                            // Get cities of a planet
                            REGISTER_FUNCTION("get_cities", [&](entt::entity planet) {
                                return universe.get<cqspc::Habitation>(planet).settlements;
                            });
            }

            void FunctionShips(cqsp::common::Universe & universe, cqsp::scripting::ScriptInterface & script_engine) {
                            CREATE_NAMESPACE(core);

                            REGISTER_FUNCTION(
                                "create_ship", [&](entt::entity civ, entt::entity orbit, entt::entity starsystem) {
                                    return cqsp::common::systems::actions::CreateShip(universe, civ, orbit, starsystem);
                                });
            }
=======
    REGISTER_FUNCTION("get_segment_size",
                      [&](entt::entity segment) {
                            return universe.get<PopulationSegment>(segment).population; });

    // Get population segments of a planet
    REGISTER_FUNCTION("get_segments", [&](entt::entity planet) {
                            return universe.get<Settlement>(planet).population; });

    // Get cities of a planet
    REGISTER_FUNCTION("get_cities", [&](entt::entity planet) {
                            return universe.get<Habitation>(planet).settlements; });
>>>>>>> pr-290

<<<<<<< HEAD
            void FunctionEvent(cqsp::common::Universe & universe, cqsp::scripting::ScriptInterface & script_engine) {
                            CREATE_NAMESPACE(core);
                            == == == = REGISTER_FUNCTION("get_city", [&](const std::string& planet) {
                                return universe.cities[planet];
                            });
            }

<<<<<<< HEAD
            void FunctionShips(cqsp::common::Universe & universe, ScriptInterface & script_engine) {
                            CREATE_NAMESPACE(core);

                            REGISTER_FUNCTION("create_ship",
                                              [&](entt::entity civ, entt::entity orbit, entt::entity starsystem) {
                                                  Node civ_node(universe, civ);
                                                  Node orbit_node(universe, orbit);
                                                  Node starsystem_node(universe, orbit);
                                                  return actions::CreateShip(civ_node, orbit_node, starsystem_node);
                                              });
            }

            void FunctionEvent(Universe & universe, ScriptInterface & script_engine) {
                            CREATE_NAMESPACE(core);
>>>>>>> pr-309

    REGISTER_FUNCTION("push_event", [&](entt::entity entity, sol::table event_table) {
                                auto& queue = universe.get_or_emplace<cqsp::common::event::EventQueue>(entity);
                                auto event = std::make_shared<cqsp::common::event::Event>();
                                event->title = event_table["title"];
                                SPDLOG_INFO("Parsing event \"{}\"", event->title);
                                event->content = event_table["content"];
                                event->image = event_table["image"];
                                sol::optional<std::vector<sol::table>> optional = event_table["actions"];
                                if (optional) {
                                    for (auto& action : *optional) {
                                        if (action == sol::nil) {
                                            continue;
                                        }
                                        auto event_result = std::make_shared<cqsp::common::event::EventResult>();
                                        event_result->name = action["name"];
                                        sol::optional<std::string> tooltip = action["tooltip"];
                                        if (tooltip) {
                                            event_result->tooltip = *tooltip;
>>>>>>> pr_191
                                        }
                                        == == == = void FunctionShips(cqsp::common::Universe & universe,
                                                                      ScriptInterface & script_engine) {
                                            CREATE_NAMESPACE(core);

                                            REGISTER_FUNCTION("create_ship", [&](entt::entity civ, entt::entity orbit,
                                                                                 entt::entity starsystem) {
                                                return actions::CreateShip(universe, civ, orbit, starsystem);
                                            });
                                        }

                                        void FunctionEvent(Universe & universe, ScriptInterface & script_engine) {
                                            CREATE_NAMESPACE(core);

    REGISTER_FUNCTION("push_event", [&](entt::entity entity, sol::table event_table) {
                                                auto& queue = universe.get_or_emplace<event::EventQueue>(entity);
                                                auto event = std::make_shared<cqsp::common::event::Event>();
                                                event->title = event_table["title"];
                                                SPDLOG_INFO("Parsing event \"{}\"", event->title);
                                                event->content = event_table["content"];
                                                event->image = event_table["image"];
                                                sol::optional<std::vector<sol::table>> optional =
                                                    event_table["actions"];
                                                if (optional) {
                                                    for (auto& action : *optional) {
                                                        if (action == sol::nil) {
                                                            continue;
                                                        }
                                                        auto event_result =
                                                            std::make_shared<cqsp::common::event::EventResult>();
                                                        event_result->name = action["name"];
                                                        sol::optional<std::string> tooltip = action["tooltip"];
                                                        if (tooltip) {
                                                            event_result->tooltip = *tooltip;
                                                        }
>>>>>>> pr-290

                                                        void FunctionUser(Universe & universe,
                                                                          ScriptInterface & script_engine) {
                                                            CREATE_NAMESPACE(core);

                                                            REGISTER_FUNCTION(
                                                                "set_name", [&](entity entity, std::string name) {
                                                                    universe.emplace_or_replace<components::Name>(
                                                                        entity, name);
                                                                });

                                                            REGISTER_FUNCTION("to_human_string", [&](int64_t number) {
                                                                return util::LongToHumanString(number);
                                                            });

                                                            REGISTER_FUNCTION("get_name", [&](entity entity) {
                                                                return universe.get<components::Name>(entity).name;
                                                            });

                                                            REGISTER_FUNCTION(
                                                                "get_random_name", [&](const std::string& name_gen,
                                                                                       const std::string& rule) {
                                                                    return universe.name_generators[name_gen].Generate(
                                                                        rule);
                                                                });
                                                        }

                                                        void FunctionPopulation(Universe & universe,
                                                                                ScriptInterface & script_engine) {
                                                            CREATE_NAMESPACE(core);

                                                            REGISTER_FUNCTION(
                                                                "add_population_segment",
                                                                [&](entity settlement, uint64_t popsize) {
                                                                    entt::entity population = universe.create();
                                                                    universe.emplace<components::PopulationSegment>(
                                                                        population, popsize);
                                                                    universe.emplace<components::ResourceStockpile>(
                                                                        population);
                                                                    universe.emplace<components::LaborInformation>(
                                                                        population);
                                                                    // Add to planet list
                                                                    universe.get<components::Settlement>(settlement)
                                                                        .population.push_back(population);

                                                                    return population;
                                                                });

                                                            REGISTER_FUNCTION("get_segment_size", [&](entity segment) {
                                                                return universe
                                                                    .get<components::PopulationSegment>(segment)
                                                                    .population;
                                                            });

                                                            // Get population segments of a planet
                                                            REGISTER_FUNCTION("get_segments", [&](entity planet) {
                                                                return universe.get<components::Settlement>(planet)
                                                                    .population;
                                                            });

                                                            // Get cities of a planet
                                                            REGISTER_FUNCTION("get_cities", [&](entity planet) {
                                                                return universe.get<components::Habitation>(planet)
                                                                    .settlements;
                                                            });
                                                        }

                                                        void FunctionShips(Universe & universe,
                                                                           ScriptInterface & script_engine) {
                                                            CREATE_NAMESPACE(core);

                                                            REGISTER_FUNCTION(
                                                                "create_ship",
                                                                [&](entity civ, entity orbit, entity starsystem) {
                                                                    return actions::CreateShip(universe, civ, orbit,
                                                                                               starsystem);
                                                                });
                                                        }

                                                        void FunctionEvent(Universe & universe,
                                                                           ScriptInterface & script_engine) {
                                                            CREATE_NAMESPACE(core);

    REGISTER_FUNCTION("push_event", [&](entity entity, sol::table event_table) {
                                                                auto& queue =
                                                                    universe.get_or_emplace<event::EventQueue>(entity);
                                                                auto event = std::make_shared<event::Event>();
                                                                event->title = event_table["title"];
                                                                SPDLOG_INFO("Parsing event \"{}\"", event->title);
                                                                event->content = event_table["content"];
                                                                event->image = event_table["image"];
                                                                sol::optional<std::vector<sol::table>> optional =
                                                                    event_table["actions"];
                                                                if (optional) {
                                                                    for (auto& action : *optional) {
                                                                        if (action == sol::nil) {
                                                                            continue;
                                                                        }
                                                                        auto event_result = std::make_shared<
                                                                            cqsp::common::event::EventResult>();
                                                                        event_result->name = action["name"];
                                                                        sol::optional<std::string> tooltip =
                                                                            action["tooltip"];
                                                                        if (tooltip) {
                                                                            event_result->tooltip = *tooltip;
>>>>>>> pr_254
                                                                        }
                                                                        return market_entity;
                                                                        // return entity;
                                                                    };
                                                                    REGISTER_FUNCTION("create_market", lambda);

                                                                    REGISTER_FUNCTION(
                                                                        "place_market",
                                                                        [&](entt::entity market, entt::entity planet) {
                                                                            universe.emplace<components::MarketCenter>(
                                                                                planet, market);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "attach_market", [&](entt::entity market_entity,
                                                                                             entt::entity participant) {
                                                                            Node market_node(universe, market_entity);
                                                                            Node participant_node(universe,
                                                                                                  participant);
                                                                            actions::AddParticipant(market_node,
                                                                                                    participant_node);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "get_balance", [&](entt::entity participant) {
                                                                            return universe
                                                                                .get_or_emplace<Wallet>(participant)
                                                                                .GetBalance();
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "add_balance",
                                                                        [&](entt::entity participant, double balance) {
                                                                            universe.get_or_emplace<Wallet>(
                                                                                participant) += balance;
                                                                        });

                                                                    auto get_planetary_markets = [&]() {
                                                                        auto view = universe.view<
                                                                            Market, components::PlanetaryMarket>();
                                                                        std::vector<entt::entity> markets;
                                                                        for (entt::entity entity : view) {
                                                                            markets.push_back(entity);
                                                                        }
                                                                        return sol::as_table(markets);
                                                                    };
                                                                    REGISTER_FUNCTION("get_planetary_markets",
                                                                                      get_planetary_markets);
                                                                }

                                                                void FunctionUser(Universe & universe,
                                                                                  ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION(
                                                                        "set_name", [&](entt::entity entity,
                                                                                        const std::string& name) {
                                                                            universe
                                                                                .emplace_or_replace<components::Name>(
                                                                                    entity, name);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "to_human_string", [&](int64_t number) {
                                                                            return cqsp::util::NumberToHumanString(
                                                                                number);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "get_name", [&](entt::entity entity) {
                                                                            return util::GetName(universe, entity);
                                                                        });

                                                                    REGISTER_FUNCTION("get_random_name",
                                                                                      [&](const std::string& name_gen,
                                                                                          const std::string& rule) {
                                                                                          return universe
                                                                                              .name_generators[name_gen]
                                                                                              .Generate(rule);
                                                                                      });
                                                                }

                                                                void FunctionPopulation(
                                                                    Universe & universe,
                                                                    ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION(
                                                                        "add_population_segment",
                                                                        [&](entt::entity settlement, uint64_t popsize) {
                                                                            entt::entity population = universe.create();
                                                                            universe.emplace<PopulationSegment>(
                                                                                population, popsize);
                                                                            universe
                                                                                .emplace<components::ResourceStockpile>(
                                                                                    population);
                                                                            universe
                                                                                .emplace<components::LaborInformation>(
                                                                                    population);
                                                                            // Add to planet list
                                                                            universe.get<Settlement>(settlement)
                                                                                .population.push_back(population);

                                                                            return population;
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "get_segment_size", [&](entt::entity segment) {
                                                                            return universe
                                                                                .get<PopulationSegment>(segment)
                                                                                .population;
                                                                        });

                                                                    // Get population segments of a planet
                                                                    REGISTER_FUNCTION(
                                                                        "get_segments", [&](entt::entity planet) {
                                                                            return universe.get<Settlement>(planet)
                                                                                .population;
                                                                        });

                                                                    // Get cities of a planet
                                                                    REGISTER_FUNCTION(
                                                                        "get_cities", [&](entt::entity planet) {
                                                                            return universe.get<Habitation>(planet)
                                                                                .settlements;
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "get_city", [&](const std::string& planet) {
                                                                            return universe.cities[planet];
                                                                        });
                                                                }

                                                                void FunctionShips(cqsp::common::Universe & universe,
                                                                                   ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION(
                                                                        "create_ship",
                                                                        [&](entt::entity civ, entt::entity orbit,
                                                                            entt::entity starsystem) {
                                                                            Node civ_node(universe, civ);
                                                                            Node orbit_node(universe, orbit);
                                                                            Node starsystem_node(universe, orbit);
                                                                            return actions::CreateShip(
                                                                                civ_node, orbit_node, starsystem_node);
                                                                        });
                                                                }

                                                                void FunctionEvent(Universe & universe,
                                                                                   ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION(
                                                                        "push_event", [&](entt::entity entity,
                                                                                          sol::table event_table) {
                                                                            auto& queue =
                                                                                universe
                                                                                    .get_or_emplace<event::EventQueue>(
                                                                                        entity);
                                                                            auto event = std::make_shared<
                                                                                cqsp::common::event::Event>();
                                                                            event->title = event_table["title"];
                                                                            SPDLOG_INFO("Parsing event \"{}\"",
                                                                                        event->title);
                                                                            event->content = event_table["content"];
                                                                            event->image = event_table["image"];
                                                                            sol::optional<std::vector<sol::table>>
                                                                                optional = event_table["actions"];
                                                                            if (optional) {
                                                                                for (auto& action : *optional) {
                                                                                    if (action == sol::nil) {
                                                                                        continue;
                                                                                    }
                                                                                    auto event_result =
                                                                                        std::make_shared<
                                                                                            cqsp::common::event::
                                                                                                EventResult>();
                                                                                    event_result->name = action["name"];
                                                                                    sol::optional<std::string> tooltip =
                                                                                        action["tooltip"];
                                                                                    if (tooltip) {
                                                                                        event_result->tooltip =
                                                                                            *tooltip;
                                                                                    }

                                                                                    event->table = event_table;
                                                                                    sol::optional<sol::function> f =
                                                                                        action["action"];
                                                                                    event_result->has_event =
                                                                                        f.has_value();
                                                                                    if (f) {
                                                                                        event_result->action = *f;
                                                                                    }
                                                                                    event->actions.push_back(
                                                                                        event_result);
                                                                                }
                                                                            }
                                                                            queue.events.push_back(event);
                                                                        });
                                                                }

                                                                void FunctionResource(Universe & universe,
                                                                                      ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION(
                                                                        "add_resource",
                                                                        [&](entt::entity storage, entt::entity resource,
                                                                            int amount) {
                                                                            // Add resources to the resource stockpile
                                                                            universe.get<ResourceStockpile>(
                                                                                storage)[resource] += amount;
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "get_resource_count",
                                                                        [&](entt::entity stockpile,
                                                                            entt::entity resource) {
                                                                            return universe.get<ResourceStockpile>(
                                                                                stockpile)[resource];
                                                                        });
                                                                }

                                                                void FunctionCivilizations(
                                                                    Universe & universe,
                                                                    ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION("get_player", [&]() {
                                                                        return universe.view<components::Player>()
                                                                            .front();
                                                                    });
                                                                    REGISTER_FUNCTION(
                                                                        "get_capital_city", [&](entt::entity civ) {
                                                                            return universe
                                                                                .get<components::Country>(civ)
                                                                                .capital_city;
                                                                        });
                                                                }

                                                                void FunctionScience(Universe & universe,
                                                                                     ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION("create_lab", [&]() {
                                                                        return actions::CreateLab(universe);
                                                                    });

                                                                    REGISTER_FUNCTION(
                                                                        "add_science",
                                                                        [&](entt::entity lab, entt::entity research,
                                                                            double progress) {
                                                                            Node lab_node(universe, lab);
                                                                            Node research_node(universe, research);
                                                                            actions::AddScienceResearch(
                                                                                lab_node, research_node, progress);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "add_tech_progress", [&](entt::entity entity) {
                                                                            universe.emplace<components::science::
                                                                                                 TechnologicalProgress>(
                                                                                entity);
                                                                            universe.emplace<ScientificResearch>(
                                                                                entity);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "complete_technology",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            Node civilization(universe, entity);
                                                                            Node tech_node(universe, tech);
                                                                            actions::ResearchTech(civilization,
                                                                                                  tech_node);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "research_technology",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            auto& res =
                                                                                universe.get<ScientificResearch>(
                                                                                    entity);
                                                                            res.current_research[tech] = 0;
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "add_potential_tech",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            auto& res =
                                                                                universe.get<ScientificResearch>(
                                                                                    entity);
                                                                            res.potential_research.insert(tech);
                                                                        });
                                                                }

                                                                // this is just meant for debugging and is not performant at all
                                                                sol::table GetMarketTable(
                                                                    Universe & universe,
                                                                    ScriptInterface & script_engine,
                                                                    entt::entity market) {
                                                                    sol::table market_table =
                                                                        script_engine.create_table_with();

                                                                    Market& market_component =
                                                                        universe.get<Market>(market);
                                                                    auto goods_view =
                                                                        universe.view<components::Price>();
                                                                    for (entt::entity good : goods_view) {
                                                                        sol::table good_table =
                                                                            script_engine.create_table_with();
                                                                        good_table["price"] =
                                                                            market_component.price[good];
                                                                        good_table["supply"] =
                                                                            market_component.supply()[good];
                                                                        good_table["demand"] =
                                                                            market_component.demand()[good];
                                                                        good_table["sd_ratio"] =
                                                                            market_component.sd_ratio[good];
                                                                        good_table["consumption"] =
                                                                            market_component.consumption[good];
                                                                        good_table["production"] =
                                                                            market_component.production[good];
                                                                        good_table["trade"] =
                                                                            market_component.trade[good];
                                                                        market_table.set(good, good_table);
                                                                        // Now get all the values for goods
                                                                    }
                                                                    return market_table;
                                                                }

<<<<<<< HEAD
                                                                void FunctionTrade(Universe & universe,
                                                                                   ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION(
                                                                        "get_market_table", [&](entt::entity market) {
                                                                            return GetMarketTable(
                                                                                universe, script_engine, market);
                                                                        });
                                                                }

                                                                void LoadFunctions(Universe & universe,
                                                                                   ScriptInterface & script_engine) {
                                                                    FunctionCivilizationGen(universe, script_engine);
                                                                    FunctionCivilizations(universe, script_engine);
                                                                    FunctionEconomy(universe, script_engine);
                                                                    FunctionPopulation(universe, script_engine);
                                                                    FunctionRandom(universe, script_engine);
                                                                    FunctionUniverseBodyGen(universe, script_engine);
                                                                    FunctionUser(universe, script_engine);
                                                                    FunctionEvent(universe, script_engine);
                                                                    FunctionShips(universe, script_engine);
                                                                    FunctionResource(universe, script_engine);
                                                                    FunctionScience(universe, script_engine);
                                                                    FunctionTrade(universe, script_engine);
                                                                }
}  // namespace cqsp::common::scripting
=======
void FunctionResource(Universe& universe, ScriptInterface& script_engine) {
                                                                CREATE_NAMESPACE(core);

                                                                REGISTER_FUNCTION(
                                                                    "add_resource",
                                                                    [&](entity storage, entity resource, int amount) {
                                                                        // Add resources to the resource stockpile
                                                                        universe.get<components::ResourceStockpile>(
                                                                            storage)[resource] += amount;
                                                                    });

                                                                REGISTER_FUNCTION(
                                                                    "get_resource_count",
                                                                    [&](entity stockpile, entity resource) {
                                                                        return universe
                                                                            .get<components::ResourceStockpile>(
                                                                                stockpile)[resource];
                                                                    });
}

<<<<<<< HEAD
void FunctionCivilizations(Universe& universe, ScriptInterface& script_engine) {
                                                                CREATE_NAMESPACE(core);

                                                                REGISTER_FUNCTION("get_player", [&]() {
                                                                    return universe.view<components::Player>().front();
                                                                });
}

void FunctionScience(Universe& universe, ScriptInterface& script_engine) {
                                                                CREATE_NAMESPACE(core);

<<<<<<< HEAD
                                                                REGISTER_FUNCTION("create_lab", [&]() {
                                                                    return systems::science::CreateLab(universe);
                                                                });

<<<<<<< HEAD
                                                                REGISTER_FUNCTION(
                                                                    "add_science",
                                                                    [&](entity lab, entity research, double progress) {
                                                                        systems::science::AddScienceResearch(
                                                                            universe, lab, research, progress);
                                                                    });
                                                                == == == = REGISTER_FUNCTION(
                                                                             "add_science", [&](entt::entity lab,
                                                                                                entt::entity research,
                                                                                                double progress) {
                                                                                 Node lab_node(universe, lab);
                                                                                 Node research_node(universe, research);
                                                                                 actions::AddScienceResearch(
                                                                                     lab_node, research_node, progress);
                                                                             });
>>>>>>> pr-309
                                                                == == == = REGISTER_FUNCTION("create_lab", [&]() {
                                                                    return actions::CreateLab(universe);
                                                                });

                                                                REGISTER_FUNCTION(
                                                                    "add_science",
                                                                    [&](entt::entity lab, entt::entity research,
                                                                        double progress) {
                                                                        actions::AddScienceResearch(universe, lab,
                                                                                                    research, progress);
                                                                    });
>>>>>>> pr-292

                                                                REGISTER_FUNCTION(
                                                                    "add_tech_progress", [&](entity entity) {
                                                                        universe.emplace<
                                                                            components::science::TechnologicalProgress>(
                                                                            entity);
                                                                        universe.emplace<
                                                                            components::science::ScientificResearch>(
                                                                            entity);
                                                                    });

<<<<<<< HEAD
<<<<<<< HEAD
                                                                REGISTER_FUNCTION("complete_technology",
                                                                                  [&](entity civ, entity tech) {
                                                                                      systems::science::ResearchTech(
                                                                                          universe, civ, tech);
                                                                                  });
                                                                == == ==
                                                                    = REGISTER_FUNCTION(
                                                                        "complete_technology",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            Node civilization(universe, entity);
                                                                            Node tech_node(universe, tech);
                                                                            actions::ResearchTech(civilization,
                                                                                                  tech_node);
                                                                        });
>>>>>>> pr-303
                                                                == == ==
                                                                    = REGISTER_FUNCTION(
                                                                        "complete_technology",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            actions::ResearchTech(universe, entity,
                                                                                                  tech);
                                                                        });
>>>>>>> pr-292

                                                                REGISTER_FUNCTION(
                                                                    "research_technology",
                                                                    [&](entity researcher, entity tech) {
                                                                        auto& res = universe.get<
                                                                            components::science::ScientificResearch>(
                                                                            researcher);
                                                                        res.current_research[tech] = 0;
                                                                    });

                                                                REGISTER_FUNCTION(
                                                                    "add_potential_tech",
                                                                    [&](entt::entity researcher, entt::entity tech) {
                                                                        auto& res = universe.get<
                                                                            components::science::ScientificResearch>(
                                                                            researcher);
                                                                        res.potential_research.insert(tech);
                                                                    });
}

void LoadFunctions(Universe& universe, ScriptInterface& script_engine) {
                                                                FunctionCivilizationGen(universe, script_engine);
                                                                FunctionCivilizations(universe, script_engine);
                                                                FunctionEconomy(universe, script_engine);
                                                                FunctionPopulation(universe, script_engine);
                                                                FunctionRandom(universe, script_engine);
                                                                FunctionUniverseBodyGen(universe, script_engine);
                                                                FunctionUser(universe, script_engine);
                                                                FunctionEvent(universe, script_engine);
                                                                FunctionShips(universe, script_engine);
                                                                FunctionResource(universe, script_engine);
                                                                FunctionScience(universe, script_engine);
                                                                == == == = void FunctionResource(
                                                                             Universe & universe,
                                                                             ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION(
                                                                        "add_resource",
                                                                        [&](entt::entity storage, entt::entity resource,
                                                                            int amount) {
                                                                            // Add resources to the resource stockpile
                                                                            universe.get<ResourceStockpile>(
                                                                                storage)[resource] += amount;
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "get_resource_count",
                                                                        [&](entt::entity stockpile,
                                                                            entt::entity resource) {
                                                                            return universe.get<ResourceStockpile>(
                                                                                stockpile)[resource];
                                                                        });
                                                                }

                                                                void FunctionCivilizations(
                                                                    Universe & universe,
                                                                    ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION("get_player", [&]() {
                                                                        return universe.view<components::Player>()
                                                                            .front();
                                                                    });
                                                                    REGISTER_FUNCTION(
                                                                        "get_capital_city", [&](entt::entity civ) {
                                                                            return universe
                                                                                .get<components::Country>(civ)
                                                                                .capital_city;
                                                                        });
                                                                }

                                                                void FunctionScience(Universe & universe,
                                                                                     ScriptInterface & script_engine) {
                                                                    CREATE_NAMESPACE(core);

                                                                    REGISTER_FUNCTION("create_lab", [&]() {
                                                                        return systems::science::CreateLab(universe);
                                                                    });

                                                                    REGISTER_FUNCTION(
                                                                        "add_science",
                                                                        [&](entt::entity lab, entt::entity research,
                                                                            double progress) {
                                                                            systems::science::AddScienceResearch(
                                                                                universe, lab, research, progress);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "add_tech_progress", [&](entt::entity entity) {
                                                                            universe.emplace<components::science::
                                                                                                 TechnologicalProgress>(
                                                                                entity);
                                                                            universe.emplace<ScientificResearch>(
                                                                                entity);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "complete_technology",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            systems::loading::ResearchTech(
                                                                                universe, entity, tech);
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "research_technology",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            auto& res =
                                                                                universe.get<ScientificResearch>(
                                                                                    entity);
                                                                            res.current_research[tech] = 0;
                                                                        });

                                                                    REGISTER_FUNCTION(
                                                                        "add_potential_tech",
                                                                        [&](entt::entity entity, entt::entity tech) {
                                                                            auto& res =
                                                                                universe.get<ScientificResearch>(
                                                                                    entity);
                                                                            res.potential_research.insert(tech);
                                                                        });
>>>>>>> pr-290
                                                                }
                        }  // namespace cqsp::common::scripting

<<<<<<< HEAD

>>>>>>> pr_254
=======
// this is just meant for debugging and is not performant at all
sol::table GetMarketTable(Universe& universe, ScriptInterface& script_engine, entt::entity market) {
                                                                sol::table market_table =
                                                                    script_engine.create_table_with();

                                                                Market& market_component = universe.get<Market>(market);
                                                                auto goods_view = universe.view<components::Price>();
                                                                for (entt::entity good : goods_view) {
                                                                    sol::table good_table =
                                                                        script_engine.create_table_with();
                                                                    good_table["price"] = market_component.price[good];
                                                                    good_table["supply"] =
                                                                        market_component.supply()[good];
                                                                    good_table["demand"] =
                                                                        market_component.demand()[good];
                                                                    good_table["sd_ratio"] =
                                                                        market_component.sd_ratio[good];
                                                                    good_table["consumption"] =
                                                                        market_component.consumption[good];
                                                                    good_table["production"] =
                                                                        market_component.production[good];
                                                                    good_table["trade"] = market_component.trade[good];
                                                                    market_table.set(good, good_table);
                                                                    // Now get all the values for goods
                                                                }
                                                                return market_table;
}

void FunctionTrade(Universe& universe, ScriptInterface& script_engine) {
                                                                CREATE_NAMESPACE(core);

                                                                REGISTER_FUNCTION(
                                                                    "get_market_table", [&](entt::entity market) {
                                                                        return GetMarketTable(universe, script_engine,
                                                                                              market);
                                                                    });
}

void LoadFunctions(Universe& universe, ScriptInterface& script_engine) {
                                                                FunctionCivilizationGen(universe, script_engine);
                                                                FunctionCivilizations(universe, script_engine);
                                                                FunctionEconomy(universe, script_engine);
                                                                FunctionPopulation(universe, script_engine);
                                                                FunctionRandom(universe, script_engine);
                                                                FunctionUniverseBodyGen(universe, script_engine);
                                                                FunctionUser(universe, script_engine);
                                                                FunctionEvent(universe, script_engine);
                                                                FunctionShips(universe, script_engine);
                                                                FunctionResource(universe, script_engine);
                                                                FunctionScience(universe, script_engine);
                                                                FunctionTrade(universe, script_engine);
}
                                                        }  // namespace cqsp::common::scripting
>>>>>>> pr-290
