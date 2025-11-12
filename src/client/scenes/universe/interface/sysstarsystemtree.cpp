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
#include "sysstarsystemtree.h"

#include <string>

#include "client/scenes/universe/universescene.h"
#include "client/scenes/universe/views/starsystemview.h"
#include "common/components/bodies.h"
#include "common/components/coordinates.h"
#include "common/components/name.h"
#include "common/components/orbit.h"
#include "common/util/nameutil.h"
#include "engine/cqspgui.h"
#include "systooltips.h"

<<<<<<< HEAD
<<<<<<< HEAD namespace cqsp::client::systems { namespace components = common::components;
    == == ==
    = namespace cqsp::client::systems {
    namespace components = common::components;
>>>>>>> pr-286
    namespace bodies = components::bodies;
    namespace types = components::types;
    using bodies::OrbitalSystem;
    using common::util::GetName;
<<<<<<< HEAD
    == == == = namespace bodies = cqsp::common::components::bodies;
    namespace systems = cqsp::client::systems;
    namespace components = cqsp::common::components;
    namespace types = cqsp::common::components::types;
    using bodies::OrbitalSystem;
    using entt::entity;
    using systems::SysStarSystemTree;
    using types::Orbit;
>>>>>>> pr_254
    == == == =
>>>>>>> pr-286

                 void SysStarSystemTree::Init() {
        // Sort all the planets in order

        auto& orbital_system = GetUniverse().get<OrbitalSystem>(GetUniverse().sun);
        planets.emplace(GetUniverse().sun);
        planets.insert(orbital_system.children.begin(), orbital_system.children.end());
<<<<<<< HEAD
    planets.sort([&](const entt::entity lhs, const entt::entity rhs) {
            return (GetUniverse().get<types::Orbit>(lhs).semi_major_axis <
                    GetUniverse().get<types::Orbit>(rhs).semi_major_axis);
<<<<<<< HEAD
            == == == = planets.sort([&](const entity lhs, const entity rhs) {
                return (GetUniverse().get<Orbit>(lhs).semi_major_axis < GetUniverse().get<Orbit>(rhs).semi_major_axis);
>>>>>>> pr_254
            });
}

void SysStarSystemTree::DoUI(int delta_time) {
<<<<<<< HEAD
            // Get star system
            selected_planet = scene::GetCurrentViewingPlanet(GetUniverse());
            ImGui::SetNextWindowPos(ImVec2(30, ImGui::GetIO().DisplaySize.y - 30), ImGuiCond_Always, ImVec2(0.f, 1.f));
            ImGui::SetNextWindowSize(ImVec2(200, 400), ImGuiCond_Always);
            ImGui::Begin("Star System", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | window_flags);
            int index = 0;
            // Get selected planet
            // Sort by sma
<<<<<<< HEAD
            entt::entity current_planet = scene::GetCurrentViewingPlanet(GetUniverse());
            == == == =
                         //entity current_planet = scene::GetCurrentViewingPlanet(GetUniverse());
>>>>>>> pr_254
                for (auto entity : planets) {
                if (!GetUniverse().any_of<OrbitalSystem>(entity) || entity == GetUniverse().sun) {
                    SeePlanetSelectable(entity);
                } else {
                    std::string planet_name = GetName(GetUniverse(), entity);
                    if (ImGui::TreeNodeEx(planet_name.c_str(), ImGuiTreeNodeFlags_OpenOnArrow)) {
                        // If it's double clicked
                        if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                            // Go to the planet
                            scene::SeePlanet(GetUniverse(), entity);
                        }
                        // Get children
                        gui::EntityTooltip(GetUniverse(), entity);
                        DoChildTree(entity);
                        ImGui::TreePop();
                    } else {
                        if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                            scene::SeePlanet(GetUniverse(), entity);
                        }
                        gui::EntityTooltip(GetUniverse(), entity);
                        == == == =
                    });
                }

                void SysStarSystemTree::DoUI(int delta_time) {
                    // Get star system
                    selected_planet = scene::GetCurrentViewingPlanet(GetUniverse());
                    ImGui::SetNextWindowPos(ImVec2(30, ImGui::GetIO().DisplaySize.y - 30), ImGuiCond_Always,
                                            ImVec2(0.f, 1.f));
                    ImGui::SetNextWindowSize(ImVec2(200, 400), ImGuiCond_Always);
                    ImGui::Begin("Star System", NULL,
                                 ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | window_flags);
                    int index = 0;
                    // Get selected planet
                    // Sort by sma
                    entt::entity current_planet = scene::GetCurrentViewingPlanet(GetUniverse());
                    for (auto entity : planets) {
                        if (!GetUniverse().any_of<OrbitalSystem>(entity) || entity == GetUniverse().sun) {
                            SeePlanetSelectable(entity);
                        } else {
                            std::string planet_name = GetName(GetUniverse(), entity);
                            if (ImGui::TreeNodeEx(planet_name.c_str(), ImGuiTreeNodeFlags_OpenOnArrow)) {
                                // If it's double clicked
                                if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                    // Go to the planet
                                    scene::SeePlanet(GetUniverse(), entity);
                                }
                                // Get children
                                gui::EntityTooltip(GetUniverse(), entity);
                                DoChildTree(entity);
                                ImGui::TreePop();
                            } else {
                                if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                    scene::SeePlanet(GetUniverse(), entity);
>>>>>>> pr-286
                                }
                                == == == =
                                             // Get star system
                                    selected_planet = scene::GetCurrentViewingPlanet(GetUniverse());
                                ImGui::SetNextWindowPos(ImVec2(30, ImGui::GetIO().DisplaySize.y - 30), ImGuiCond_Always,
                                                        ImVec2(0.f, 1.f));
                                ImGui::SetNextWindowSize(ImVec2(200, 400), ImGuiCond_Always);
                                ImGui::Begin("Star System", NULL,
                                             ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | window_flags);
                                int index = 0;
                                // Get selected planet
                                // Sort by sma
                                entt::entity current_planet = scene::GetCurrentViewingPlanet(GetUniverse());
                                for (auto entity : planets) {
                                    if (!GetUniverse().any_of<OrbitalSystem>(entity) || entity == GetUniverse().sun) {
                                        SeePlanetSelectable(entity);
                                    } else {
                                        std::string planet_name = GetName(GetUniverse(), entity);
                                        if (ImGui::TreeNodeEx(planet_name.c_str(), ImGuiTreeNodeFlags_OpenOnArrow)) {
                                            // If it's double clicked
                                            if (ImGui::IsItemHovered() &&
                                                ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                // Go to the planet
                                                scene::SeePlanet(GetUniverse(), entity);
>>>>>>> pr-288
                                            }
                                        }
                                        ImGui::End();
                                    }

                                    void SysStarSystemTree::DoUpdate(int delta_time) {}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                                    void SysStarSystemTree::SeePlanetSelectable(entt::entity entity) {
                                        std::string planet_name = GetName(GetUniverse(), entity);
                                        == == == = void SysStarSystemTree::SeePlanetSelectable(entity entity) {
                                            std::string planet_name = common::util::GetName(GetUniverse(), entity);
>>>>>>> pr_254
                                            bool is_selected = (entity == selected_planet);
                                            ImGui::Dummy(ImVec2(20, 16));
                                            ImGui::SameLine();
                                            if (CQSPGui::DefaultSelectable(planet_name.c_str(), is_selected,
                                                                           ImGuiSelectableFlags_AllowDoubleClick)) {
                                                // Selected object
                                                if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                    // Go to the planet
                                                    scene::SeePlanet(GetUniverse(), entity);
                                                }
                                            }
                                            gui::EntityTooltip(GetUniverse(), entity);
                                        }

<<<<<<< HEAD
                                        void SysStarSystemTree::DoChildTree(entt::entity entity) {
                                            for (auto child : GetUniverse().get<OrbitalSystem>(entity).children) {
                                                std::string child_name = GetName(GetUniverse(), child);
                                                == == == = void SysStarSystemTree::DoChildTree(entity entity) {
                                                    for (auto child :
                                                         GetUniverse().get<OrbitalSystem>(entity).children) {
                                                        std::string child_name =
                                                            common::util::GetName(GetUniverse(), child);
>>>>>>> pr_254
                                                        bool is_selected = (child == selected_planet);
                                                        if (CQSPGui::DefaultSelectable(
                                                                child_name.c_str(), is_selected,
                                                                ImGuiSelectableFlags_AllowDoubleClick)) {
                                                            if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                                // Go to the planet
                                                                scene::SeePlanet(GetUniverse(), child);
                                                            }
                                                        }
                                                        gui::EntityTooltip(GetUniverse(), child);
                                                    }
                                                }
                                                == == ==
                                                    = void SysStarSystemTree::SeePlanetSelectable(entt::entity entity) {
                                                    std::string planet_name = GetName(GetUniverse(), entity);
                                                    bool is_selected = (entity == selected_planet);
                                                    ImGui::Dummy(ImVec2(20, 16));
                                                    ImGui::SameLine();
                                                    if (CQSPGui::DefaultSelectable(
                                                            planet_name.c_str(), is_selected,
                                                            ImGuiSelectableFlags_AllowDoubleClick)) {
                                                        // Selected object
                                                        if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                            // Go to the planet
                                                            scene::SeePlanet(GetUniverse(), entity);
                                                        }
                                                    }
                                                    gui::EntityTooltip(GetUniverse(), entity);
                                                }

                                                void SysStarSystemTree::DoChildTree(entt::entity entity) {
                                                    for (auto child :
                                                         GetUniverse().get<OrbitalSystem>(entity).children) {
                                                        std::string child_name = GetName(GetUniverse(), child);
                                                        bool is_selected = (child == selected_planet);
                                                        if (CQSPGui::DefaultSelectable(
                                                                child_name.c_str(), is_selected,
                                                                ImGuiSelectableFlags_AllowDoubleClick)) {
                                                            if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                                // Go to the planet
                                                                scene::SeePlanet(GetUniverse(), child);
                                                            }
                                                        }
                                                        gui::EntityTooltip(GetUniverse(), child);
                                                    }
                                                }
                                            }  // namespace cqsp::client::systems
>>>>>>> pr-286
                                            == == == = void SysStarSystemTree::DoChildTree(entt::entity entity) {
                                                for (auto child : GetUniverse().get<OrbitalSystem>(entity).children) {
                                                    std::string child_name = GetName(GetUniverse(), child);
                                                    bool is_selected = (child == selected_planet);
                                                    if (!GetUniverse().any_of<OrbitalSystem>(child)) {
                                                        // Then just selectable
                                                        if (CQSPGui::DefaultSelectable(
                                                                child_name.c_str(), is_selected,
                                                                ImGuiSelectableFlags_AllowDoubleClick)) {
                                                            if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                                // Go to the planet
                                                                scene::SeePlanet(GetUniverse(), child);
                                                            }
                                                        }
                                                        gui::EntityTooltip(GetUniverse(), child);
                                                    } else {
                                                        if (ImGui::TreeNodeEx(child_name.c_str(),
                                                                              ImGuiTreeNodeFlags_OpenOnArrow)) {
                                                            // If it's double clicked
                                                            if (ImGui::IsItemHovered() &&
                                                                ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                                // Go to the planet
                                                                scene::SeePlanet(GetUniverse(), child);
                                                            }
                                                            // Get children
                                                            gui::EntityTooltip(GetUniverse(), child);
                                                            DoChildTree(child);
                                                            ImGui::TreePop();
                                                        } else {
                                                            if (ImGui::IsItemHovered() &&
                                                                ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                                                                scene::SeePlanet(GetUniverse(), child);
                                                            }
                                                            gui::EntityTooltip(GetUniverse(), child);
                                                        }
                                                    }
                                                    // If it has children we should
                                                }
                                            }
                                        }  // namespace cqsp::client::systems
>>>>>>> main
