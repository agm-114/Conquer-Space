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
#include "client/scenes/universe/interface/spaceshipwindow.h"

#include "client/scenes/universe/views/starsystemview.h"
#include "common/actions/maneuver/commands.h"
#include "common/actions/maneuver/hohmann.h"
#include "common/actions/maneuver/maneuver.h"
#include "common/actions/maneuver/rendezvous.h"
#include "common/components/coordinates.h"
#include "common/components/movement.h"
#include "common/components/orbit.h"
#include "common/components/ships.h"
#include "common/components/surface.h"
#include "common/util/nameutil.h"

<<<<<<< HEAD namespace cqsp::client::systems {
    namespace components = cqsp::common::components;
    namespace types = components::types;
    namespace ships = components::ships;
    namespace bodies = components::bodies;
    using common::systems::commands::PushManeuvers;
    using common::util::GetName;
    using types::GetCircularOrbitingVelocity;
    using types::Kinematics;
    using types::Orbit;
    using types::OrbitVelocity;
    using types::toDegree;
    == == == = namespace components = cqsp::common::components;
    namespace types = cqsp::common::components::types;
    namespace ships = cqsp::common::components::ships;
    namespace systems = cqsp::common::systems;
    using components::CommandQueue;
    using components::Maneuver;
    using types::Kinematics;
    using types::Orbit;

    using types::OrbitVelocity;

    using components::bodies::Body;
    using cqsp::client::systems::SpaceshipWindow;
    using cqsp::common::util::GetName;
    using entt::entity;
>>>>>>> pr_254

    void SpaceshipWindow::Init() {}

    void SpaceshipWindow::DoUI(int delta_time) {
<<<<<<< HEAD
        == == == = using types::toDegree;
>>>>>>> pr_254
        // Get selected spaceship, and then do the window
        // Check if the selected body is a spaceship
        // Then display information on it
        entity body = GetUniverse().view<FocusedPlanet>().front();
        if (!GetUniverse().valid(body)) {
            return;
        }
<<<<<<< HEAD
        if (!GetUniverse().all_of<ships::Ship, Orbit>(body)) {
            return;
        }
        // Display the details of the spaceship
        == == == = if (!GetUniverse().all_of<ships::Ship>(body)) {
            // Display the details of the spaceship
            return;
        }
>>>>>>> pr_254
        ImGui::Begin(fmt::format("{}", GetName(GetUniverse(), body)).c_str());
        // Display orbital elements
        auto& orbit = GetUniverse().get<Orbit>(body);
        if (ImGui::CollapsingHeader("Orbital Elements", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::TextFmt("Semi-major axis: {} km", orbit.semi_major_axis);
            ImGui::TextFmt("Eccentricity: {}", orbit.eccentricity);
            // Degree symbol is broken :(
            ImGui::TextFmt("Inclination: {}\u00b0", toDegree(orbit.inclination));
            ImGui::TextFmt("Longitude of the ascending node: {}\u00b0", toDegree(orbit.LAN));
            ImGui::TextFmt("Argument of periapsis: {}\u00b0", toDegree(orbit.w));
            ImGui::TextFmt("Mean anomaly at Epoch: {}\u00b0", toDegree(orbit.M0));
            ImGui::TextFmt("True anomaly: {}", orbit.v);
            ImGui::TextFmt("Epoch: {}s", orbit.epoch);
            ImGui::TextFmt("GM: {} km^3 * s^-2", orbit.GM);
            ImGui::TextFmt("Orbital period: {} s", orbit.T());
            ImGui::TextFmt("Orbiting: {}", GetName(GetUniverse(), orbit.reference_body).c_str());
<<<<<<< HEAD
            if (GetUniverse().valid(orbit.reference_body) && GetUniverse().any_of<bodies::Body>(orbit.reference_body)) {
                double r = orbit.GetOrbitingRadius();
                double p = GetUniverse().get<bodies::Body>(orbit.reference_body).radius;
                == == == = if (GetUniverse().any_of<Body>(orbit.reference_body)) {
                    double r = orbit.GetOrbitingRadius();
                    double p = GetUniverse().get<Body>(orbit.reference_body).radius;
>>>>>>> pr_254
                    p = 0;
                    ImGui::TextFmt("Altitude: {:.1f} km", (r - p));
                    ImGui::TextFmt("Periapsis: {:<10} km ({:.1f} s)", orbit.GetPeriapsis() - p,
                                   orbit.TimeToTrueAnomaly(0));
                    if (ImGui::IsItemHovered()) {
                        ImGui::BeginTooltip();
                        ImGui::TextFmt("{:.2f} hours", orbit.TimeToTrueAnomaly(0) / (60 * 60));
                        ImGui::EndTooltip();
                    }
                    ImGui::TextFmt("Apoapsis: {:<10} km ({:.1f} s)", orbit.GetApoapsis() - p,
<<<<<<< HEAD
                                   orbit.TimeToTrueAnomaly(common::components::types::PI));
                    if (ImGui::IsItemHovered()) {
                        ImGui::BeginTooltip();
                        ImGui::TextFmt("{:.2f} hours",
                                       orbit.TimeToTrueAnomaly(common::components::types::PI) / (60 * 60));
                        ImGui::EndTooltip();
                    }
                }
            }
            if (GetUniverse().all_of<Kinematics>(body) && ImGui::CollapsingHeader("Orbital Vectors")) {
=======
                           orbit.TimeToMeanAnomaly(components::types::PI));
            }
        }
        if (ImGui::CollapsingHeader("Orbital Vectors")) {
>>>>>>> pr_254
            auto& coords = GetUniverse().get<Kinematics>(body);
            ImGui::TextFmt("Position {} {} {}", coords.position.x, coords.position.y, coords.position.z);
            ImGui::TextFmt("Velocity {} {} {}", coords.velocity.x, coords.velocity.y, coords.velocity.z);
        }

        if (ImGui::CollapsingHeader("Maneuver Queue")) {
<<<<<<< HEAD
            if (GetUniverse().any_of<components::CommandQueue>(body)) {
                auto& queue = GetUniverse().get<components::CommandQueue>(body);
                for (auto& maneuver : queue) {
                    ImGui::TextFmt("Maneuver in {}", maneuver.time - GetUniverse().date.ToSecond());
                    == == == = if (GetUniverse().any_of<CommandQueue>(body)) {
                        auto& queue = GetUniverse().get<CommandQueue>(body);
                        for (auto& manuver : queue) {
                            ImGui::TextFmt("Maneuver in {}", manuver.time - GetUniverse().date.ToSecond());
>>>>>>> pr_254
                        }
                    }
                }

                if (ImGui::CollapsingHeader("Basic Orbital Maneuvers")) {
                    static float true_anomaly = 0;
                    ImGui::SliderAngle("trueanomaly", &true_anomaly, (0));

                    double apoapsis_velocity = OrbitVelocity(common::components::types::PI, orbit.eccentricity,
                                                             orbit.semi_major_axis, orbit.GM);
                    double periapsis_velocity = OrbitVelocity(0, orbit.eccentricity, orbit.semi_major_axis, orbit.GM);
                    double max_altitude = 10000000;
                    double min_altitude = 0;

                    if (ImGui::Button("Fix True anomaly")) {
                        // Emplace
                        GetUniverse().emplace_or_replace<types::SetTrueAnomaly>(body, true_anomaly);
                    }
                    if (GetUniverse().any_of<types::SetTrueAnomaly>(body)) {
                        // Now set the true anomaly consistently or something
                    }
                    if (ImGui::Button("Circularize at apoapsis")) {
                        // Add random delta v
<<<<<<< HEAD
                        common::systems::commands::PushManeuvers(GetUniverse(), body,
                                                                 {common::systems::CircularizeAtApoapsis(orbit)});
                    }
                    if (ImGui::IsItemHovered()) {
                        double circular_velocity = GetCircularOrbitingVelocity(orbit.GM, orbit.GetApoapsis());
                        // So for apoapsis, we need this amount of delta v at prograde
                        // Get the vector of the direction and then compute?
                        // Then transform by the orbital math
                        ImGui::SetTooltip("Delta-v: %f km/s", circular_velocity - apoapsis_velocity);
                    }

                    if (ImGui::Button("Circularize at perapsis")) {
                        PushManeuvers(GetUniverse(), body, {common::systems::CircularizeAtPeriapsis(orbit)});
                    }

                    if (ImGui::IsItemHovered()) {
                        double circular_velocity = GetCircularOrbitingVelocity(orbit.GM, orbit.GetPeriapsis());
                        // So for apoapsis, we need this amount of delta v at prograde
                        // Get the vector of the direction and then compute?
                        // Then transform by the orbital math
                        ImGui::SetTooltip("Delta-v: %f km/s", circular_velocity - periapsis_velocity);
                        == == == = Maneuver maneuver(common::systems::CircularizeAtApoapsis(orbit));
                        maneuver.time += GetUniverse().date.ToSecond();
                        GetUniverse().get_or_emplace<CommandQueue>(body).commands.push_back(maneuver);
                    }
                    if (ImGui::IsItemHovered()) {
                        double circular_velocity = types::GetCircularOrbitingVelocity(orbit.GM, orbit.GetApoapsis());
                        // So for apoapsis, we need this amount of delta v at prograde
                        // Get the vector of the direction and then compute?
                        // Then transform by the orbital math
                        double orbit_velocity =
                            OrbitVelocity(types::PI, orbit.eccentricity, orbit.semi_major_axis, orbit.GM);
                        ImGui::SetTooltip("Delta-v: %f km/s", circular_velocity - orbit_velocity);
                    }

                    if (ImGui::Button("Circularize at perapsis")) {
                        Maneuver maneuver(common::systems::CircularizeAtPeriapsis(orbit));
                        maneuver.time += GetUniverse().date.ToSecond();
                        GetUniverse().get_or_emplace<CommandQueue>(body).commands.push_back(maneuver);
                    }

                    if (ImGui::IsItemHovered()) {
                        double circular_velocity = types::GetCircularOrbitingVelocity(orbit.GM, orbit.GetPeriapsis());
                        // So for apoapsis, we need this amount of delta v at prograde
                        // Get the vector of the direction and then compute?
                        // Then transform by the orbital math
                        double orbit_velocity = OrbitVelocity(0, orbit.eccentricity, orbit.semi_major_axis, orbit.GM);
                        ImGui::SetTooltip("Delta-v: %f km/s", circular_velocity - orbit_velocity);
>>>>>>> pr_254
                    }

                    // Change apogee
                    ImGui::InputDouble("Set Apoapsis Altitude", &new_perigee, min_altitude, max_altitude);
                    if (ImGui::Button("Set Apoapsis")) {
                        // Get velocity at the new apogee
                        // Get the velocity
<<<<<<< HEAD
                        auto maneuver = common::systems::SetApoapsis(orbit, new_perigee);
                        PushManeuvers(GetUniverse(), body, {maneuver});
                        == == == = Maneuver maneuver;
                        auto m = common::systems::SetApoapsis(orbit, new_perigee);
                        maneuver.delta_v = m.first;
                        maneuver.time = GetUniverse().date.ToSecond() + m.second;
                        GetUniverse().get_or_emplace<CommandQueue>(body).commands.push_back(maneuver);
>>>>>>> pr_254
                    }

                    if (ImGui::IsItemHovered()) {
                        double new_sma = (orbit.GetApoapsis() + new_perigee) / 2;
                        // Get velocity at the new apogee
<<<<<<< HEAD
                        double new_v =
                            common::components::types::OrbitVelocityAtR(orbit.GM, new_sma, orbit.GetApoapsis());
                        ImGui::SetTooltip("Delta-v: %f km/s", new_v - periapsis_velocity);
                        == == == = double new_v = types::OrbitVelocityAtR(orbit.GM, new_sma, orbit.GetApoapsis());
                        double orbit_velocity =
                            types::OrbitVelocity(0, orbit.eccentricity, orbit.semi_major_axis, orbit.GM);
                        ImGui::SetTooltip("Delta-v: %f km/s", new_v - orbit_velocity);
>>>>>>> pr_254
                    }

                    // Change apogee
                    ImGui::InputDouble("Set Periapsis Altitude", &new_apogee, min_altitude, max_altitude);
                    if (ImGui::Button("Set Periapsis")) {
                        // Get velocity at the new apogee
                        // Get the velocity
<<<<<<< HEAD
                        auto maneuver = common::systems::SetPeriapsis(orbit, new_apogee);
                        PushManeuvers(GetUniverse(), body, {maneuver});
                        == == == = Maneuver maneuver;
                        auto m = common::systems::SetPeriapsis(orbit, new_apogee);
                        maneuver.delta_v = m.first;
                        maneuver.time = GetUniverse().date.ToSecond() + m.second;
                        GetUniverse().get_or_emplace<CommandQueue>(body).commands.push_back(maneuver);
>>>>>>> pr_254
                    }

                    if (ImGui::IsItemHovered()) {
                        double new_sma = (orbit.GetPeriapsis() + new_apogee) / 2;
                        // Get velocity at the new apogee
<<<<<<< HEAD
                        double new_v =
                            common::components::types::OrbitVelocityAtR(orbit.GM, new_sma, orbit.GetPeriapsis());
                        ImGui::SetTooltip("Delta-v: %f km/s", new_v - periapsis_velocity);
                        == == == = double new_v = types::OrbitVelocityAtR(orbit.GM, new_sma, orbit.GetPeriapsis());
                        double orbit_velocity =
                            types::OrbitVelocity(0, orbit.eccentricity, orbit.semi_major_axis, orbit.GM);
                        ImGui::SetTooltip("Delta-v: %f km/s", new_v - orbit_velocity);
>>>>>>> pr_254
                    }

                    ImGui::InputDouble("Set Orbit Altitude", &new_hohmann, min_altitude, max_altitude);
                    if (ImGui::Button("Set New Orbit")) {
                        // Get velocity at the new apogee
                        // Get the velocity
                        auto hohmann = common::systems::HohmannTransfer(orbit, new_hohmann);
                        if (hohmann.has_value()) {
<<<<<<< HEAD
                            PushManeuvers(GetUniverse(), body, *hohmann);
                            == == == = auto& queue = GetUniverse().get_or_emplace<CommandQueue>(body);
                            Maneuver man_1(hohmann->first);
                            Maneuver man_2(hohmann->second);
                            man_1.time += (GetUniverse().date.ToSecond() + 1000);
                            man_2.time += (GetUniverse().date.ToSecond() + 1000);
                            queue.commands.push_back(man_1);
                            queue.commands.push_back(man_2);
>>>>>>> pr_254
                        } else {
                            SPDLOG_INFO("Orbit is not circular!");
                        }
                    }
                }

                // Display spaceship delta v in the future
                // Display controls of the spaceship
                if (ImGui::CollapsingHeader("Rendezvous")) {
<<<<<<< HEAD
                    auto& o_system = GetUniverse().get<bodies::OrbitalSystem>(orbit.reference_body);
                    static entt::entity selected = o_system.children.empty() ? entt::null : o_system.children.front();
                    auto& target = GetUniverse().get<Orbit>(selected);

                    // Get distance from target
                    glm::dvec3 target_distance =
                        GetUniverse().get<Kinematics>(selected).position - GetUniverse().get<Kinematics>(body).position;
                    == == == = auto& o_system =
                                 GetUniverse().get<components::bodies::OrbitalSystem>(orbit.reference_body);
                    static entity selected = o_system.children.empty() ? entt::null : o_system.children.front();
                    auto& target = GetUniverse().get<Orbit>(selected);

                    // Get distance from target
                    glm::vec3 target_distance =
                        GetUniverse().get<Kinematics>(selected).position - GetUniverse().get<Kinematics>(body).position;
>>>>>>> pr_254
                    ImGui::TextFmt("Distance to target: {}", glm::length(target_distance));
                    if (ImGui::Button("Rendez-vous!")) {
                        // Rdv with target
                        auto pair =
                            cqsp::common::systems::CoplanarIntercept(orbit, target, GetUniverse().date.ToSecond());
<<<<<<< HEAD
                        common::systems::commands::PushManeuvers(GetUniverse(), body, pair);
                    }
                    if (ImGui::Button("Maneuver to point")) {
                        auto pair =
                            cqsp::common::systems::CoplanarIntercept(orbit, target, GetUniverse().date.ToSecond());
                        common::systems::commands::PushManeuvers(GetUniverse(), body, {pair.first});
                    }
                    if (ImGui::Button("Match Planes")) {
                        == == == = auto& queue = GetUniverse().get_or_emplace<CommandQueue>(body);
                        Maneuver man_1(pair.first);
                        Maneuver man_2(pair.second);
                        man_1.time += GetUniverse().date.ToSecond();
                        man_2.time += GetUniverse().date.ToSecond();
                        queue.commands.push_back(man_1);
                        queue.commands.push_back(man_2);
                    }
                    if (ImGui::Button("Maneuver to point")) {
                        auto pair =
                            cqsp::common::systems::CoplanarIntercept(orbit, target, GetUniverse().date.ToSecond());
                        auto& queue = GetUniverse().get_or_emplace<CommandQueue>(body);
                        common::components::Maneuver man_1(pair.first);
                        man_1.time += GetUniverse().date.ToSecond();
                        queue.commands.push_back(man_1);
                    }
                    if (ImGui::Button("Match Planes")) {
                        auto& queue = GetUniverse().get_or_emplace<CommandQueue>(body);
>>>>>>> pr_254
                        auto maneuver = cqsp::common::systems::MatchPlanes(orbit, target);
                        common::systems::commands::PushManeuver(GetUniverse(), body, maneuver);
                    }
<<<<<<< HEAD
                    ImGui::TextFmt("Phase angle: {}", cqsp::common::components::types::CalculatePhaseAngle(
                                                          orbit, target, GetUniverse().date.ToSecond()));
                    ImGui::TextFmt("Transfer angle: {}",
                                   cqsp::common::components::types::CalculateTransferAngle(orbit, target));
                    double ttma =
                        orbit.TimeToTrueAnomaly(common::components::types::AscendingTrueAnomaly(orbit, target));
                    if (ImGui::Button("Lambert transfer")) {
                        // Compute lambert problem
                        // Get future position of the entity

                        // Get the position of the satellite at the time
                        // Assume elliptic lol
                        auto& target_orbit = GetUniverse().get<Orbit>(selected);
                        //OrbitTimeToVec3(target_orbit, )
                        // Now get the x and y position
                    }
                    ImGui::SliderFloat("Lambert Time of Flight (seconds)", &lambert_tof, 0, 1e6);
                    == == == = ImGui::TextFmt("Phase angle: {}",
                                              types::CalculatePhaseAngle(orbit, target, GetUniverse().date.ToSecond()));
                    ImGui::TextFmt("Transfer angle: {}", types::CalculateTransferAngle(orbit, target));
                    double ttma = orbit.TimeToMeanAnomaly(types::AscendingTrueAnomaly(orbit, target));
>>>>>>> pr_254
                    ImGui::TextFmt("Time to ascending node: {}", ttma);
                    if (ImGui::BeginChild("Rendezvous Target")) {
                        for (auto& entity : o_system.children) {
                            if (ImGui::Selectable(GetName(GetUniverse(), entity).c_str(), selected == entity)) {
                                selected = entity;
                            }
                        }
                    }
                    ImGui::EndChild();
                }
                if (ImGui::CollapsingHeader("Moon Transfers")) {
                    auto& o_system = GetUniverse().get<bodies::OrbitalSystem>(orbit.reference_body);
                    double angle = common::components::types::AngleWith(
                        orbit, GetUniverse().get<types::Orbit>(orbit.reference_body));
                    ImGui::TextFmt("Angle: {}", angle * 180 / types::PI);
                    static entt::entity selected = entt::null;
                    if (selected == entt::null) {
                        ImGui::BeginDisabled(true);
                    }
                    if (ImGui::Button("Transfer to Moon")) {
                        common::systems::commands::TransferToMoon(GetUniverse(), body, selected);
                    }

                    // Land on body?
                    if (ImGui::Button("Land On City")) {
                        // Check if the targeted body has a settlement to land on
                        // Just grab the first one
                        auto& cities = GetUniverse().get<components::Habitation>(selected);
                        if (!cities.settlements.empty()) {
                            common::systems::commands::LandOnMoon(GetUniverse(), body, selected,
                                                                  cities.settlements.front());
                        }
                    }
                    if (selected == entt::null) {
                        ImGui::EndDisabled();
                    }

                    if (ImGui::BeginChild("Landing Target")) {
                        for (auto& entity : o_system.children) {
                            if (!GetUniverse().all_of<bodies::Planet, Orbit>(entity)) {
                                continue;
                            }
                            if (ImGui::Selectable(GetName(GetUniverse(), entity).c_str(), selected == entity)) {
                                selected = entity;
                            }
                        }
                    }
                    ImGui::EndChild();
                }
                ImGui::End();
            }

            void SpaceshipWindow::DoUpdate(int delta_time) {}
<<<<<<< HEAD

        }  // namespace cqsp::client::systems
        == == == =
>>>>>>> pr_254
