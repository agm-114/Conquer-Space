/*
 * Copyright 2021 Conquer Space
 */
#include "client/systems/syscommand.h"

#include <GLFW/glfw3.h>

#include <string>

#include "client/scenes/universescene.h"
#include "client/systems/gui/systooltips.h"
#include "client/systems/sysstarsystemrenderer.h"
#include "common/components/bodies.h"
#include "common/components/movement.h"
#include "common/components/name.h"
#include "common/components/ships.h"

<<<<<<< HEAD void conquerspace::client::systems::SysCommand::Init() {}

void conquerspace::client::systems::SysCommand::DoUI(int delta_time) {
    == == == = namespace components = cqsp::common::components;
    namespace bodies = components::bodies;
    namespace ships = components::ships;
    namespace types = components::types;
    namespace systems = cqsp::client::systems;

    using components::Name;

    namespace cqsp::client::systems {
    void SysCommand::Init() {}

    void SysCommand::DoUI(int delta_time) {
        ShipList();
>>>>>>> pr_254
        if (!to_see) {
            return;
        }

<<<<<<< HEAD
        namespace cqspb = conquerspace::common::components::bodies;
        namespace cqsps = conquerspace::common::components::ships;
        namespace cqspt = conquerspace::common::components::types;
        namespace cqspcs = conquerspace::client::systems;
        // Get star system
        entt::entity ent = GetApp().GetUniverse().view<cqspcs::RenderingStarSystem>().front();
        if (ent == entt::null) {
            return;
        }
        auto& star_system = GetApp().GetUniverse().get<cqspb::StarSystem>(ent);
        == == == =
>>>>>>> pr_254
                     ImGui::SetNextWindowPos(
                         ImVec2(ImGui::GetIO().DisplaySize.x * 0.79f, ImGui::GetIO().DisplaySize.y * 0.55f),
                         ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        ImGui::SetNextWindowSize(ImVec2(200, 400), ImGuiCond_Always);
        ImGui::Begin("Order Target", &to_see, ImGuiWindowFlags_NoResize | window_flags);
        int index = 0;
        // Get selected planet
<<<<<<< HEAD
        entt::entity current_planet = conquerspace::scene::GetCurrentViewingPlanet(GetApp());
        for (auto entity : star_system.bodies) {
            == == == = entt::entity current_planet = scene::GetCurrentViewingPlanet(GetUniverse());
            for (auto entity : GetUniverse().view<common::components::types::Orbit>()) {
>>>>>>> pr_254
                bool is_selected = (entity == current_planet);
                std::string planet_name = fmt::format("{}", entity);
                if (GetApp().GetUniverse().all_of<conquerspace::common::components::Name>(entity)) {
                    planet_name = fmt::format(
                        "{}", GetApp().GetUniverse().get<conquerspace::common::components::Name>(entity).name);
                }

                if (ImGui::Selectable(planet_name.c_str(), is_selected, ImGuiSelectableFlags_AllowDoubleClick)) {
                    // Selected object
                    selected_index = index;
                    if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                        // Go to the planet
<<<<<<< HEAD
                        GetApp().GetUniverse().emplace_or_replace<cqspt::MoveTarget>(current_planet, entity);
                        == == == = GetUniverse().emplace_or_replace<types::MoveTarget>(selected_ship, entity);
>>>>>>> pr_254
                        SPDLOG_INFO("Move Ordered");
                    }
                }
                gui::EntityTooltip(entity, GetApp().GetUniverse());
                index++;
            }
            ImGui::End();
        }

<<<<<<< HEAD
        void conquerspace::client::systems::SysCommand::DoUpdate(int delta_time) {
            namespace cqspb = conquerspace::common::components::bodies;
            namespace cqspt = conquerspace::common::components::types;
            selected_planet = conquerspace::scene::GetCurrentViewingPlanet(GetApp());
            entt::entity mouse_over = GetApp()
                                          .GetUniverse()
                                          .view<conquerspace::client::systems::MouseOverEntity, cqspt::Kinematics>()
                                          .front();
            if (!ImGui::GetIO().WantCaptureMouse && GetApp().MouseButtonIsReleased(GLFW_MOUSE_BUTTON_LEFT) &&
                mouse_over == selected_planet && !conquerspace::scene::IsGameHalted() && !GetApp().MouseDragged()) {
                to_see = true;
            }
            if (GetApp().GetUniverse().all_of<cqspt::Orbit>(selected_planet)) {
                to_see = false;
            }
            == == == = void SysCommand::DoUpdate(int delta_time) {
                selected_planet = cqsp::scene::GetCurrentViewingPlanet(GetUniverse());
                /*entt::entity mouse_over = GetUniverse()
            .view<cqsp::client::systems::MouseOverEntity, cqspt::Kinematics>().front();
    if (!ImGui::GetIO().WantCaptureMouse &&
        GetApp().MouseButtonIsReleased(GLFW_MOUSE_BUTTON_LEFT) &&
        mouse_over == selected_planet && !GetApp().MouseDragged()) {
        to_see = true;
    }*/
            }

            void SysCommand::ShipList() {
                /*
    static entt::entity selectedFleetEnt = GetUniverse()
                           .get<cqspc::Civilization>(GetUniverse()
                           .view<cqspc::Player>()
                           .front()).top_level_fleet;

    auto& selectedFleet = GetUniverse().get<cqsps::Fleet>(selectedFleetEnt);
    auto& selectedFleetName = GetUniverse().get<cqspc::Name>(selectedFleetEnt);

    std::stringstream finalSelectedFleetName;
    for (size_t i = 0; i < selectedFleet.echelon; i++) {
        finalSelectedFleetName << GetUniverse()
                                      .get<cqsp::common::components::Name>(
                                          selectedFleet.parent_fleet)
                                      .name
                               << "/";
    }
    finalSelectedFleetName << selectedFleetName.name.c_str();

    ImGui::SetNextWindowSize(ImVec2(200, 400), ImGuiCond_Always);
    ImGui::Begin(finalSelectedFleetName.str().c_str());

    // Show ship list
    int index = 0;
    static int selected = 0;

    for (entt::entity enti : selectedFleet.ships) {
        index++;
        const bool is_selected = (selected == index);
        std::string entity_name = cqsp::client::systems::gui::GetName(GetUniverse(), enti);
        if (CQSPGui::DefaultSelectable(entity_name.c_str(), is_selected)) {
            selected = index;
            to_see = true;
            selected_ship = enti;
        }
    }

    std::vector<entt::entity> subfleetsAndLast = selectedFleet.subfleets;
    bool has_parent = false;
    if (selectedFleet.parent_fleet != entt::null) {
        subfleetsAndLast.push_back(selectedFleet.parent_fleet);
        has_parent = true;
    }

    for (size_t i = 0; i < subfleetsAndLast.size(); i++) {
        index++;

        const bool is_selected = (selected == index);
        std::stringstream entity_name;
        entity_name << (i == (subfleetsAndLast.size() - 1) && has_parent
            ? "<-"
            : "->")
                    << cqsp::client::systems::gui::GetName(GetUniverse(),
                                                           subfleetsAndLast[i]);
        if (CQSPGui::DefaultSelectable(entity_name.str().c_str(),
                                       is_selected)) {
            selected = index;
            selectedFleetEnt = subfleetsAndLast[i];
        }
    }

    ImGui::End();*/
>>>>>>> pr_254
            }
        }  // namespace cqsp::client::systems
