/* Conquer Space
<<<<<<< HEAD
=======
<<<<<<<< HEAD:src/common/systems/loading/loadcities.cpp
* Copyright (C) 2021 Conquer Space
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
#include "common/systems/loading/loadcities.h"
== == == ==
>>>>>>> pr-292
        *Copyright(C) 2021 - 2025 Conquer Space** This program is free software : you can redistribute it and /
    or modify* it under the terms of the GNU General Public License as published by* the Free Software Foundation,
    either version 3 of the License,
    or *(at your option)any later version.** This program is distributed in the hope that it will be useful,
    *but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "common/loading/loadcities.h"
<<<<<<< HEAD
=======
>>>>>>>> pr-292:src/common/loading/loadcities.cpp
>>>>>>> pr-292

#include <spdlog/spdlog.h>

#include <string>
<<<<<<< HEAD
#include <vector>

#include "common/actions/factoryconstructaction.h"
#include "common/components/area.h"
#include "common/components/coordinates.h"
#include "common/components/infrastructure.h"
#include "common/components/market.h"
#include "common/components/name.h"
#include "common/components/organizations.h"
#include "common/components/population.h"
#include "common/components/spaceport.h"
#include "common/components/surface.h"
#include "common/util/nameutil.h"

<<<<<<< HEAD:src/common/loading/loadcities.cpp namespace cqsp::common::loading { namespace {
    == == == = using cqsp::common::systems::loading::CityLoader;
using entt::entity;

<<<<<<< HEAD
namespace cqsp::common::systems::loading {
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
struct ConnectedCities {
    // Holder class for the names of all the cities connected to this particular city
    std::vector<std::string> entities;
};
<<<<<<< HEAD:src/common/loading/loadcities.cpp
}  // namespace

bool CityLoader::LoadValue(const Hjson::Value& values, Node& node) {
    //SPDLOG_INFO("Load the city);
    std::string planet = values["planet"].to_string();
    double longi = values["coordinates"]["longitude"].to_double();
    double lat = values["coordinates"]["latitude"].to_double();
    auto& sc = node.emplace<components::types::SurfaceCoordinate>(lat, longi);
    Node planet_node(node, universe.planets[planet]);
    sc.planet = planet_node;
    == == == =
}  // namespace cqsp::common::systems::loading
bool CityLoader::LoadValue(const Hjson::Value& values, entity cityentity) {
    // Load the city
    std::string planet = values["planet"].to_string();
    double longi = values["coordinates"]["longitude"].to_double();
    double lat = values["coordinates"]["latitude"].to_double();
    auto& sc = universe.emplace<components::types::SurfaceCoordinate>(cityentity, lat, longi);
    sc.planet = universe.planets[planet];

    universe.get_or_emplace<components::Habitation>(universe.planets[planet]).settlements.push_back(cityentity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp

    planet_node.get_or_emplace<components::Habitation>().settlements.push_back(node);
    //SPDLOG_INFO("Load Timezone");
    if (!values["timezone"].empty()) {
<<<<<<< HEAD:src/common/loading/loadcities.cpp
        entt::entity tz = universe.time_zones[values["timezone"].to_string()];
        node.emplace<components::CityTimeZone>(tz);
    }

    //SPDLOG_INFO("Load Population");
    auto& settlement = node.emplace<components::Settlement>();
    std::string identifier = node.get<components::Identifier>().identifier;
    == == == = entity tz = universe.time_zones[values["timezone"].to_string()];
    universe.emplace<components::CityTimeZone>(cityentity, tz);
}

auto& settlement = universe.emplace<components::Settlement>(cityentity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
== == == = bool CityLoader::LoadValue(const Hjson::Value& values, Node& node) {
    //SPDLOG_INFO("Load the city);
    std::string planet = values["planet"].to_string();
    double longi = values["coordinates"]["longitude"].to_double();
    double lat = values["coordinates"]["latitude"].to_double();
    auto& sc = node.emplace<components::types::SurfaceCoordinate>(lat, longi);
    Node planet_node(node, universe.planets[planet]);
    sc.planet = planet_node;

    planet_node.get_or_emplace<components::Habitation>().settlements.push_back(node);
    //SPDLOG_INFO("Load Timezone");
    if (!values["timezone"].empty()) {
        entt::entity tz = universe.time_zones[values["timezone"].to_string()];
        node.emplace<components::CityTimeZone>(tz);
    }

    //SPDLOG_INFO("Load Population");
    auto& settlement = node.emplace<components::Settlement>();
    std::string identifier = node.get<components::Identifier>().identifier;
>>>>>>> pr-303
    // Load population
    if (!values["population"].empty()) {
        Hjson::Value population = values["population"];
        for (int i = 0; i < population.size(); i++) {
            Hjson::Value population_seg = population[i];
<<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/loadcities.cpp
            Node pop_node(universe);
            == == == = entity pop_ent = universe.create();
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
            == == == = Node pop_node(universe);
>>>>>>> pr-303

            auto size = population_seg["size"].to_int64();
            double standard_of_living = 0;
            if (!population_seg["sol"].empty()) {
                standard_of_living = population_seg["sol"].to_double();
            }

            double balance = 0;
            if (!population_seg["balance"].empty()) {
                balance = population_seg["balance"].to_double();
            }

            int64_t labor_force = size / 2;
            if (!population_seg["labor_force"].empty()) {
                labor_force = population_seg["labor_force"].to_int64();
            }

            auto& segment = pop_node.emplace<components::PopulationSegment>();
            segment.population = size;
            segment.labor_force = labor_force;
            segment.standard_of_living = standard_of_living;
            pop_node.emplace<components::LaborInformation>();
            auto& wallet = pop_node.emplace<components::Wallet>();
            wallet = balance;
            settlement.population.push_back(pop_node);
        }
    } else {
<<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/loadcities.cpp
        Node pop_node(universe);
        == == == = entity pop_ent = universe.create();
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
        == == == = Node pop_node(universe);
>>>>>>> pr-303

        auto size = 50000;
        int64_t labor_force = size / 2;

        auto& segment = pop_node.emplace<components::PopulationSegment>();
        segment.population = size;
        segment.labor_force = labor_force;
<<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/loadcities.cpp
        == == == =
>>>>>>> pr-303
                     pop_node.emplace<components::LaborInformation>();
        settlement.population.push_back(pop_node);
        SPDLOG_WARN("City {} does not have any population", identifier);
    }
    //SPDLOG_INFO("Load Industry");
    node.emplace<components::ResourceLedger>();

    // Industry and economy
    auto& industry = node.emplace<components::IndustrialZone>();
    auto& market = node.emplace<components::Market>();
    market.parent_market = universe.planets[planet];
    == == == = universe.emplace<components::LaborInformation>(pop_ent);
    settlement.population.push_back(pop_ent);
    SPDLOG_WARN("City {} does not have any population", universe.get<components::Identifier>(cityentity).identifier);
}

universe.emplace<components::ResourceLedger>(cityentity);

// Industry and economy
auto& industry = universe.emplace<components::IndustrialZone>(cityentity);
auto& market = universe.emplace<components::Market>(cityentity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
// Get the connected markets
if (!values["connections"].empty() && values["connections"].type() == Hjson::Type::Vector) {
    // Get connected cities and then see if they're done
    Hjson::Value connected = values["connections"];
    if (!connected.empty()) {
<<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/loadcities.cpp
        auto& conn = node.emplace<ConnectedCities>();
        == == == = auto& conn = universe.emplace<ConnectedCities>(cityentity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
        == == == = auto& conn = node.emplace<ConnectedCities>();
>>>>>>> pr-303
        for (int i = 0; i < connected.size(); i++) {
            Hjson::Value& val = connected[i];
            conn.entities.push_back(val.to_string());
        }
    }
}
// Commercial area
<<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/loadcities.cpp
Node commercial_node(universe);

commercial_node.emplace<components::Employer>();
commercial_node.emplace<components::Commercial>(node, 0);
== == == = entity commercial = universe.create();

universe.emplace<components::Employer>(commercial);
universe.emplace<components::Commercial>(commercial, cityentity, 0);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
== == == = Node commercial_node(universe);

commercial_node.emplace<components::Employer>();
commercial_node.emplace<components::Commercial>(node, 0);
>>>>>>> pr-303

industry.industries.push_back(commercial_node);
== == == =
#include "common/components/area.h"
#include "common/components/coordinates.h"
#include "common/components/economy.h"
#include "common/components/infrastructure.h"
#include "common/components/name.h"
#include "common/components/organizations.h"
#include "common/components/population.h"
#include "common/components/surface.h"
             < < < < < < < < HEAD : src / common / systems / loading /
                                    loadcities.cpp
#include "common/systems/actions/factoryconstructaction.h"

                                    namespace cqsp::common::systems::loading {
    == == == ==
#include "common/actions/factoryconstructaction.h"
#include "common/util/nameutil.h"

        namespace cqsp::common::loading {
        namespace {
        struct ConnectedCities {
            // Holder class for the names of all the cities connected to this particular city
            std::vector<std::string> entities;
        };
        }  // namespace
        >>>>>>>> pr - 292 : src / common / loading /
                            loadcities.cpp bool CityLoader::LoadValue(const Hjson::Value& values, entt::entity entity) {
            // Load the city
            std::string planet = values["planet"].to_string();
            double longi = values["coordinates"]["longitude"].to_double();
            double lat = values["coordinates"]["latitude"].to_double();
            auto& sc = universe.emplace<components::types::SurfaceCoordinate>(entity, lat, longi);
            sc.planet = universe.planets[planet];

            universe.get_or_emplace<components::Habitation>(universe.planets[planet]).settlements.push_back(entity);

            if (!values["timezone"].empty()) {
                entt::entity tz = universe.time_zones[values["timezone"].to_string()];
                universe.emplace<components::CityTimeZone>(entity, tz);
            }

            auto& settlement = universe.emplace<components::Settlement>(entity);
            // Load population
            if (!values["population"].empty()) {
                Hjson::Value population = values["population"];
                for (int i = 0; i < population.size(); i++) {
                    Hjson::Value population_seg = population[i];
                    entt::entity pop_ent = universe.create();

                    auto size = population_seg["size"].to_int64();
                    universe.emplace<components::PopulationSegment>(pop_ent).population = size;
                    universe.emplace<components::Employee>(pop_ent);
                    settlement.population.push_back(pop_ent);
                }
            } else {
                SPDLOG_WARN("City {} does not have any population",
                            universe.get<components::Identifier>(entity).identifier);
            }

            universe.emplace<components::ResourceLedger>(entity);

            // Industry and economy
            auto& industry = universe.emplace<components::IndustrialZone>(entity);

            // Commercial area
            entt::entity commercial = universe.create();

            universe.emplace<components::Employer>(commercial);
            universe.emplace<components::Commercial>(commercial, entity, 0);

            industry.industries.push_back(commercial);
>>>>>>> pr-292

            if (!values["industry"].empty()) {
                Hjson::Value industry_hjson = values["industry"];

                for (int i = 0; i < industry_hjson.size(); i++) {
                    Hjson::Value ind_val = industry_hjson[i];
                    auto recipe = ind_val["recipe"].to_string();
                    auto productivity = ind_val["productivity"].to_double();
                    if (universe.recipes.find(recipe) == universe.recipes.end()) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/loadcities.cpp
                        == == == =
>>>>>>> pr-303
                                     SPDLOG_INFO("Recipe {} not found in city {}", recipe, identifier);
                        continue;
                    }
                    double wage = 10;
                    if (!ind_val["wage"].empty()) {
                        wage = ind_val["wage"].to_double();
                    }
                    Node rec_ent(universe, universe.recipes[recipe]);

                    actions::CreateFactory(node, rec_ent, productivity);
<<<<<<< HEAD
                    == == == = SPDLOG_INFO("Recipe {} not found in city {}", recipe,
                                           universe.get<components::Identifier>(cityentity).identifier);
                    continue;
                }
                entity rec_ent = universe.recipes[recipe];

                actions::CreateFactory(universe, cityentity, rec_ent, productivity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
            }
        }
        //SPDLOG_INFO("Load SpacePort");
        if (!values["space-port"].empty()) {
            // Add space port
<<<<<<< HEAD:src/common/loading/loadcities.cpp
            auto& space_port = node.emplace<components::infrastructure::SpacePort>();
            space_port.reference_body = sc.planet;
            == == == = universe.emplace<components::infrastructure::SpacePort>(cityentity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
        }
        //SPDLOG_INFO("Load Country");
        if (!values["country"].empty()) {
            if (universe.countries.find(values["country"]) != universe.countries.end()) {
<<<<<<< HEAD:src/common/loading/loadcities.cpp
                Node country_node(universe, universe.countries[values["country"]]);
                node.emplace<components::Governed>(country_node);
                // Add self to country?
                country_node.get_or_emplace<components::CountryCityList>().city_list.push_back(node);

            } else {
                SPDLOG_INFO("City {} has country {}, but it's undefined", identifier, values["country"].to_string());
            }
        } else {
            SPDLOG_WARN("City {} has no country", identifier);
            == == == = entity country = universe.countries[values["country"]];
            universe.emplace<components::Governed>(cityentity, country);
            // Add self to country?
            universe.get_or_emplace<components::CountryCityList>(country).city_list.push_back(cityentity);
        }
        else {
            SPDLOG_INFO("City {} has country {}, but it's undefined",
                        universe.get<components::Identifier>(cityentity).identifier, values["country"]);
        }
    }
    else {
        SPDLOG_WARN("City {} has no country", universe.get<components::Identifier>(cityentity).identifier);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
    }
    //SPDLOG_INFO("Load Provinces");
    if (!values["province"].empty()) {
        if (universe.provinces[values["province"]] != universe.provinces.end()) {
<<<<<<< HEAD:src/common/loading/loadcities.cpp
            Node province_node(universe, universe.provinces[values["province"]]);
            // Now add self to province
            province_node.get<components::Province>().cities.push_back(node);
        } else {
            SPDLOG_WARN("City {} has province {}, but it's undefined", identifier, values["province"].to_string());
            == == == =
        }
    }
    //SPDLOG_INFO("Load SpacePort");
    if (!values["space-port"].empty()) {
        // Add space port
        auto& space_port = node.emplace<components::infrastructure::SpacePort>();
        space_port.reference_body = sc.planet;
    }
    //SPDLOG_INFO("Load Country");
    if (!values["country"].empty()) {
        if (universe.countries.find(values["country"]) != universe.countries.end()) {
            Node country_node(universe, universe.countries[values["country"]]);
            node.emplace<components::Governed>(country_node);
            // Add self to country?
            country_node.get_or_emplace<components::CountryCityList>().city_list.push_back(node);

        } else {
            SPDLOG_INFO("City {} has country {}, but it's undefined", identifier, values["country"].to_string());
        }
    } else {
        SPDLOG_WARN("City {} has no country", identifier);
    }
    //SPDLOG_INFO("Load Provinces");
    if (!values["province"].empty()) {
        if (universe.provinces[values["province"]] != universe.provinces.end()) {
            Node province_node(universe, universe.provinces[values["province"]]);
            // Now add self to province
            province_node.get<components::Province>().cities.push_back(node);
        } else {
            SPDLOG_WARN("City {} has province {}, but it's undefined", identifier, values["province"].to_string());
        }
    }

    //SPDLOG_INFO("Add infrastructure to city");
    auto& infrastructure = node.emplace<components::infrastructure::CityInfrastructure>();
    if (!values["transport"].empty()) {
        infrastructure.default_purchase_cost = values["transport"].to_double();
    } else {
        infrastructure.default_purchase_cost = 100;
    }
    if (!values["infrastructure"].empty()) {
        SPDLOG_INFO("Has Infrastructure");
        // Load infrastructure
        if (!values["infrastructure"]["highway"].empty()) {
            SPDLOG_INFO("Has highway");
            // Set the stuff
            auto& highway = node.emplace<components::infrastructure::Highway>();
            highway.extent = values["infrastructure"]["highway"].to_double();
        }
>>>>>>> pr-303
    }
}

<<<<<<< HEAD
//SPDLOG_INFO("Add infrastructure to city");
auto& infrastructure = node.emplace<components::infrastructure::CityInfrastructure>();
== == == = entity province = universe.provinces[values["province"]];
// Now add self to province
universe.get<components::Province>(province).cities.push_back(cityentity);
}
else {
    SPDLOG_WARN("City {} has province {}, but it's undefined",
                universe.get<components::Identifier>(cityentity).identifier, values["province"]);
}
}

// Add infrastructure to city
auto& infrastructure = universe.emplace<components::infrastructure::CityInfrastructure>(cityentity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
if (!values["transport"].empty()) {
    infrastructure.default_purchase_cost = values["transport"].to_double();
} else {
    infrastructure.default_purchase_cost = 100;
}
if (!values["infrastructure"].empty()) {
    SPDLOG_INFO("Has Infrastructure");
    // Load infrastructure
    if (!values["infrastructure"]["highway"].empty()) {
        SPDLOG_INFO("Has highway");
        // Set the stuff
<<<<<<< HEAD:src/common/loading/loadcities.cpp
        auto& highway = node.emplace<components::infrastructure::Highway>();
        == == == = auto& highway = universe.emplace<components::infrastructure::Highway>(cityentity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
        highway.extent = values["infrastructure"]["highway"].to_double();
    }
}

//SPDLOG_INFO("Load Tags");
if (!values["tags"].empty()) {
    for (int i = 0; i < values["tags"].size(); i++) {
        if (values["tags"][i].to_string() == "capital") {
            // Then it's a capital city of whatever country it's in
<<<<<<< HEAD:src/common/loading/loadcities.cpp
            node.emplace<components::CapitalCity>();
            // Add to parent country
            if (node.any_of<components::Governed>()) {
                Node governor_node(universe, node.get<components::Governed>().governor);
                auto& country_comp = universe.get<components::Country>(governor_node);
                if (country_comp.capital_city != entt::null) {
                    // Get name
                    SPDLOG_INFO("Country {} already has a capital; {} will be replaced with {}",
                                util::GetName(universe, governor_node),
                                util::GetName(universe, country_comp.capital_city), util::GetName(universe, node));
                    == == == = universe.emplace<components::CapitalCity>(cityentity);
                    // Add to parent country
                    if (universe.any_of<components::Governed>(cityentity)) {
                        entity governor = universe.get<components::Governed>(cityentity).governor;
                        auto& country_comp = universe.get<components::Country>(governor);
                        if (country_comp.capital_city != entt::null) {
                            // Get name
                            SPDLOG_INFO("Country {} already has a capital; {} will be replaced with {}",
                                        util::GetName(universe, governor),
                                        util::GetName(universe, country_comp.capital_city),
                                        util::GetName(universe, cityentity));
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
                            // Remove capital tag on the other capital city
                            Node(universe, country_comp.capital_city).remove<components::CapitalCity>();
                        }
<<<<<<< HEAD:src/common/loading/loadcities.cpp
                        country_comp.capital_city = node;
                        == == == = country_comp.capital_city = cityentity;
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
                    }
                    == == == =
                                 //SPDLOG_INFO("Load Tags");
                        if (!values["tags"].empty()) {
                        for (int i = 0; i < values["tags"].size(); i++) {
                            if (values["tags"][i].to_string() == "capital") {
                                // Then it's a capital city of whatever country it's in
                                node.emplace<components::CapitalCity>();
                                // Add to parent country
                                if (node.any_of<components::Governed>()) {
                                    Node governor_node(universe, node.get<components::Governed>().governor);
                                    auto& country_comp = universe.get<components::Country>(governor_node);
                                    if (country_comp.capital_city != entt::null) {
                                        // Get name
                                        SPDLOG_INFO("Country {} already has a capital; {} will be replaced with {}",
                                                    util::GetName(universe, governor_node),
                                                    util::GetName(universe, country_comp.capital_city),
                                                    util::GetName(universe, node));
                                        // Remove capital tag on the other capital city
                                        Node(universe, country_comp.capital_city).remove<components::CapitalCity>();
                                    }
                                    country_comp.capital_city = node;
>>>>>>> pr-303
                                }
                            }
                        }
<<<<<<< HEAD:src/common/loading/loadcities.cpp
                        //SPDLOG_INFO("Save City");
                        universe.cities[identifier] = node;
                        return true;
                    }
<<<<<<< HEAD
                    == == == =
                                 //SPDLOG_INFO("Save City");
                        universe.cities[identifier] = node;
                    return true;
                }
>>>>>>> pr-303

                /**
 * Loads the city and sets the parent.
 */
<<<<<<< HEAD
                void CityLoader::PostLoad(const Node& node) {
                    if (node.all_of<ConnectedCities>()) {
                        auto& connected = node.get<ConnectedCities>();
                        auto& market = node.get<components::Market>();
                        == == == = universe.cities[universe.get<components::Identifier>(cityentity).identifier] =
                                     cityentity;
                        return true;
                    }

                    void CityLoader::PostLoad(const entity& entity) {
                        if (universe.all_of<ConnectedCities>(entity)) {
                            auto& connected = universe.get<ConnectedCities>(entity);
                            auto& market = universe.get<components::Market>(entity);
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
                            for (auto& entity : connected.entities) {
                                market.connected_markets.emplace(universe.cities[entity]);
                            }
                            node.remove<ConnectedCities>();
                        }
                    }
<<<<<<< HEAD:src/common/loading/loadcities.cpp
                }  // namespace cqsp::common::loading
                == == == =
>>>>>>> pr_254:src/common/systems/loading/loadcities.cpp
                             == == == = void CityLoader::PostLoad(const Node& node) {
                    if (node.all_of<ConnectedCities>()) {
                        auto& connected = node.get<ConnectedCities>();
                        auto& market = node.get<components::Market>();
                        for (auto& entity : connected.entities) {
                            market.connected_markets.emplace(universe.cities[entity]);
                        }
                        node.remove<ConnectedCities>();
                    }
                }
            }  // namespace cqsp::common::loading
>>>>>>> pr-303
            == == == = SPDLOG_INFO("Recipe {} not found in city {}", recipe,
                                   universe.get<components::Identifier>(entity).identifier);
            continue;
        }
        entt::entity rec_ent = universe.recipes[recipe];

        actions::CreateFactory(universe, entity, rec_ent, productivity);
    }
}

if (!values["space-port"].empty()) {
    // Add space port
    universe.emplace<components::infrastructure::SpacePort>(entity);
}

if (!values["country"].empty()) {
    if (universe.countries.find(values["country"]) != universe.countries.end()) {
        entt::entity country = universe.countries[values["country"]];
        universe.emplace<components::Governed>(entity, country);
        // Add self to country?
        universe.get_or_emplace<components::CountryCityList>(country).city_list.push_back(entity);
    } else {
        SPDLOG_INFO("City {} has country {}, but it's undefined",
                    universe.get<components::Identifier>(entity).identifier, values["country"]);
    }
} else {
    SPDLOG_WARN("City {} has no country", universe.get<components::Identifier>(entity).identifier);
}

if (!values["province"].empty()) {
    if (universe.provinces[values["province"]] != universe.provinces.end()) {
        entt::entity province = universe.provinces[values["province"]];
        // Now add self to province
        universe.get<components::Province>(province).cities.push_back(entity);
    } else {
        SPDLOG_WARN("City {} has province {}, but it's undefined",
                    universe.get<components::Identifier>(entity).identifier, values["province"]);
    }
}

// Add infrastructure to city
auto& infrastructure = universe.emplace<components::infrastructure::CityInfrastructure>(entity);
if (!values["transport"].empty()) {
    infrastructure.default_purchase_cost = values["transport"].to_double();
} else {
    infrastructure.default_purchase_cost = 100;
}
if (!values["infrastructure"].empty()) {
    SPDLOG_INFO("Has Infrastructure");
    // Load infrastructure
    if (!values["infrastructure"]["highway"].empty()) {
        SPDLOG_INFO("Has highway");
        // Set the stuff
        auto& highway = universe.emplace<components::infrastructure::Highway>(entity);
        highway.extent = values["infrastructure"]["highway"].to_double();
    }
}
return true;
}

< < < < < < < <
    HEAD : src / common / systems / loading / loadcities.cpp void CityLoader::PostLoad(const entt::entity& entity) {}
}  // namespace cqsp::common::systems::loading
== == == == void CityLoader::PostLoad(const entt::entity& entity) {
    if (universe.all_of<ConnectedCities>(entity)) {
        auto& connected = universe.get<ConnectedCities>(entity);
        auto& market = universe.get<components::Market>(entity);
        for (auto& entity : connected.entities) {
            market.connected_markets.emplace(universe.cities[entity]);
        }
        universe.remove<ConnectedCities>(entity);
    }
}
}  // namespace cqsp::common::loading
>>>>>>>> pr - 292 : src / common / loading / loadcities.cpp
>>>>>>> pr-292
