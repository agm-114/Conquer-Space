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
#include "common/systems/economy/sysinfrastructure.h"

#include <tracy/Tracy.hpp>

#include "common/components/area.h"
#include "common/components/infrastructure.h"
namespace cqsp::common::systems {

<<<<<<< HEAD
<<<<<<< HEAD
== == == =
>>>>>>> pr-290
             namespace infrastructure = components::infrastructure;

void InfrastructureSim::DoSystem() {
    ZoneScoped;
<<<<<<< HEAD
    // Get all cities with industry and infrastruture
<<<<<<< HEAD
<<<<<<< HEAD
    for (Node zone_node : GetUniverse().nodes<components::IndustrialZone>()) {
        auto& industry = zone_node.get<components::IndustrialZone>();
        == == == = auto view = universe.view<cqspc::IndustrialZone>();
        for (entt::entity entity : view) {
            auto& industry = universe.get<cqspc::IndustrialZone>(entity);
>>>>>>> pr_191
            double power_production = 0;
            double power_consumption = 0;
            for (Node industrial_node : zone_node.Convert(industry.industries)) {
                if (industrial_node.any_of<infrastructure::PowerPlant>()) {
                    power_production += industrial_node.get<infrastructure::PowerPlant>().production;
                }
                if (industrial_node.any_of<infrastructure::PowerConsumption>()) {
                    power_consumption += industrial_node.get<infrastructure::PowerConsumption>().max;
                }
            }
            // Now assign infrastrutural information
            zone_node.emplace_or_replace<infrastructure::CityPower>(power_production, power_consumption);
            == == == = using cqsp::common::systems::InfrastructureSim;
            namespace components = cqsp::common::components;
            namespace infrastructure = components::infrastructure;
            using components::IndustrialZone;
            using entt::entity;
            using infrastructure::BrownOut;
            using infrastructure::CityInfrastructure;
            using infrastructure::CityPower;
            using infrastructure::Highway;
            using infrastructure::PowerConsumption;
            using infrastructure::PowerPlant;

            void InfrastructureSim::DoSystem() {
                ZoneScoped;
                Universe& universe = GetUniverse();
                // Get all cities with industry and infrastruture
                for (entity zone : universe.view<IndustrialZone>()) {
                    auto& industry = universe.get<IndustrialZone>(zone);
                    double power_production = 0;
                    double power_consumption = 0;
                    for (entity industrial_site : industry.industries) {
                        if (universe.any_of<PowerPlant>(industrial_site)) {
                            power_production += universe.get<PowerPlant>(industrial_site).production;
                        }
                        if (universe.any_of<PowerConsumption>(industrial_site)) {
                            power_consumption += universe.get<PowerConsumption>(industrial_site).max;
                        }
                    }
                    // Now assign infrastrutural information
                    universe.emplace_or_replace<CityPower>(zone, power_production, power_consumption);
>>>>>>> pr_254

                    if (power_production < power_consumption) {
                        // Then city has no power. Next time, we'd allow transmitting power, or allowing emergency use power
                        // but for now, the city will go under brownout.
<<<<<<< HEAD
                        zone_node.get_or_emplace<infrastructure::BrownOut>();
                    } else {
                        zone_node.remove<infrastructure::BrownOut>();
                    }
                    if (zone_node.any_of<infrastructure::CityInfrastructure>()) {
                        auto& infra = zone_node.get<infrastructure::CityInfrastructure>();
                        infra.improvement = 0;
                        // Add highway things I guess
                        if (zone_node.any_of<infrastructure::Highway>()) {
                            infra.improvement += zone_node.get<infrastructure::Highway>().extent;
                        }
                        == == == = universe.get_or_emplace<BrownOut>(zone);
                    } else {
                        universe.remove<BrownOut>(zone);
                    }
                    CityInfrastructure& infra = GetUniverse().get_or_emplace<CityInfrastructure>(zone);
                    infra.improvement = 0;
                    // Add highway things I guess
                    if (GetUniverse().any_of<Highway>(zone)) {
                        infra.improvement += GetUniverse().get<Highway>(zone).extent;
>>>>>>> pr_254
                    }
                }
                == == == = for (Node zone_node : GetUniverse().nodes<components::IndustrialZone>()) {
                    auto& industry = zone_node.get<components::IndustrialZone>();
                    double power_production = 0;
                    double power_consumption = 0;
                    for (Node industrial_node : zone_node.Convert(industry.industries)) {
                        if (industrial_node.any_of<infrastructure::PowerPlant>()) {
                            power_production += industrial_node.get<infrastructure::PowerPlant>().production;
                        }
                        if (industrial_node.any_of<infrastructure::PowerConsumption>()) {
                            power_consumption += industrial_node.get<infrastructure::PowerConsumption>().max;
                        }
                    }
                    // Now assign infrastrutural information
                    zone_node.emplace_or_replace<infrastructure::CityPower>(power_production, power_consumption);

                    if (power_production < power_consumption) {
                        // Then city has no power. Next time, we'd allow transmitting power, or allowing emergency use power
                        // but for now, the city will go under brownout.
                        zone_node.get_or_emplace<infrastructure::BrownOut>();
                    } else {
                        zone_node.remove<infrastructure::BrownOut>();
                    }
                    if (zone_node.any_of<infrastructure::CityInfrastructure>()) {
                        auto& infra = zone_node.get<infrastructure::CityInfrastructure>();
                        infra.improvement = 0;
                        // Add highway things I guess
                        if (zone_node.any_of<infrastructure::Highway>()) {
                            infra.improvement += zone_node.get<infrastructure::Highway>().extent;
>>>>>>> pr-303
                        }
                    }  // namespace cqsp::common::systems
                    == == == = Universe& universe = GetUniverse();
                    // Get all cities with industry and infrastruture
                    auto view = universe.view<components::IndustrialZone>();
                    for (entt::entity entity : view) {
                        auto& industry = universe.get<components::IndustrialZone>(entity);
                        double power_production = 0;
                        double power_consumption = 0;
                        for (entt::entity industrial_site : industry.industries) {
                            if (universe.any_of<infrastructure::PowerPlant>(industrial_site)) {
                                power_production +=
                                    universe.get<infrastructure::PowerPlant>(industrial_site).production;
                            }
                            if (universe.any_of<infrastructure::PowerConsumption>(industrial_site)) {
                                power_consumption +=
                                    universe.get<infrastructure::PowerConsumption>(industrial_site).max;
                            }
                        }
                        // Now assign infrastrutural information
                        universe.emplace_or_replace<infrastructure::CityPower>(entity, power_production,
                                                                               power_consumption);

                        if (power_production < power_consumption) {
                            // Then city has no power. Next time, we'd allow transmitting power, or allowing emergency use power
                            // but for now, the city will go under brownout.
                            universe.get_or_emplace<infrastructure::BrownOut>(entity);
                        } else {
                            universe.remove<infrastructure::BrownOut>(entity);
                        }
                        if (GetUniverse().any_of<infrastructure::CityInfrastructure>(entity)) {
                            auto& infra = GetUniverse().get<infrastructure::CityInfrastructure>(entity);
                            infra.improvement = 0;
                            // Add highway things I guess
                            if (GetUniverse().any_of<infrastructure::Highway>(entity)) {
                                infra.improvement += GetUniverse().get<infrastructure::Highway>(entity).extent;
                            }
                        }
                    }
                }
            }  // namespace cqsp::common::systems
>>>>>>> pr-290
