/*
* Copyright 2021 Conquer Space
*/
#include "client/systems/sysplanetviewer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <noise/noise.h>
#include <noiseutils.h>

#include <map>
#include <string>

#include "client/scenes/universescene.h"
#include "client/systems/gui/systooltips.h"
#include "client/systems/sysstarsystemrenderer.h"
#include "client/systems/ui/sysstockpileui.h"
#include "common/components/area.h"
#include "common/components/bodies.h"
#include "common/components/economy.h"
#include "common/components/movement.h"
#include "common/components/name.h"
#include "common/components/organizations.h"
#include "common/components/player.h"
#include "common/components/population.h"
#include "common/components/resource.h"
#include "common/components/surface.h"
#include "common/util/utilnumberdisplay.h"
#include "engine/gui.h"

void conquerspace::client::systems::SysPlanetInformation::DisplayPlanet() {
    namespace cqspc = conquerspace::common::components;
    if (!to_see) {
        return;
    }

    ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x * 0.4f, ImGui::GetIO().DisplaySize.y * 0.8f),
                             ImGuiCond_Appearing);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.79f, ImGui::GetIO().DisplaySize.y * 0.55f),
                            ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    std::string planet_name = "Planet";
    if (selected_planet == entt::null) {
        return;
    }
    if (GetApp().GetUniverse().all_of<cqspc::Name>(selected_planet)) {
        planet_name = GetApp().GetUniverse().get<cqspc::Name>(selected_planet).name;
    }
    ImGui::Begin(planet_name.c_str(), &to_see, window_flags);
    switch (view_mode) {
        case ViewMode::PLANET_VIEW:
            PlanetInformationPanel();
            break;
        case ViewMode::CITY_VIEW:
            CityInformationPanel();
            break;
    }
    ImGui::End();
}

void conquerspace::client::systems::SysPlanetInformation::Init() {}

void conquerspace::client::systems::SysPlanetInformation::DoUI(int delta_time) { DisplayPlanet(); }

void conquerspace::client::systems::SysPlanetInformation::DoUpdate(int delta_time) {
    // If clicked on a planet, go to the planet
    // Get the thing
    namespace cqspb = conquerspace::common::components::bodies;
    selected_planet = conquerspace::scene::GetCurrentViewingPlanet(GetApp());
    entt::entity mouse_over = GetApp().GetUniverse().view<conquerspace::client::systems::MouseOverEntity>().front();
    if (!ImGui::GetIO().WantCaptureMouse && GetApp().MouseButtonIsReleased(GLFW_MOUSE_BUTTON_LEFT) &&
        mouse_over == selected_planet && !conquerspace::scene::IsGameHalted() && !GetApp().MouseDragged()) {
        to_see = true;
        SPDLOG_INFO("Switched entity");
    }
    if (!GetApp().GetUniverse().all_of<cqspb::Body>(selected_planet)) {
        to_see = false;
    }
}

void conquerspace::client::systems::SysPlanetInformation::CityInformationPanel() {
    namespace cqspc = conquerspace::common::components;
    if (ImGui::ArrowButton("cityinformationpanel", ImGuiDir_Left)) {
        view_mode = ViewMode::PLANET_VIEW;
    }
    ImGui::SameLine();
    static bool thing = true;
    ImGui::Checkbox("Macroeconomic/Ownership mode", &thing);

    ImGui::TextFmt("{}", GetApp().GetUniverse().get<cqspc::Name>(selected_city_entity).name);

    if (GetApp().GetUniverse().all_of<cqspc::Settlement>(selected_city_entity)) {
        int size = GetApp().GetUniverse().get<cqspc::Settlement>(selected_city_entity).population.size();
        for (auto b : GetApp().GetUniverse().get<cqspc::Settlement>(selected_city_entity).population) {
            auto& bad_var_name = GetApp().GetUniverse().get<cqspc::PopulationSegment>(b);
            ImGui::TextFmt("Population: {}", conquerspace::util::LongToHumanString(bad_var_name.population));
        }
    } else {
        ImGui::TextFmt("No population");
    }

<<<<<<< HEAD
    if (GetApp().GetUniverse().all_of<cqspc::Industry>(selected_city_entity)) {
        == == == = if (GetUniverse().all_of<cqspc::CityTimeZone>(selected_city_entity)) {
            // Set time zone
            auto& tz = GetUniverse().get<cqspc::CityTimeZone>(selected_city_entity);
            auto& tz_def = GetUniverse().get<cqspc::TimeZone>(tz.time_zone);
            int time = (int)(GetUniverse().date.GetDate() + tz_def.time_diff) % 24;
            if (time < 0) {
                time = time + 24;
            }
            const std::string& tz_name = GetUniverse().get<cqspc::Identifier>(tz.time_zone).identifier;
            ImGui::TextFmt("{} {}:00 ({})", GetUniverse().date.ToString(tz_def.time_diff), time, tz_name);
        }

        if (GetUniverse().all_of<cqspc::IndustrialZone>(selected_city_entity)) {
>>>>>>> pr_191
            if (ImGui::BeginTabBar("CityTabs", ImGuiTabBarFlags_None)) {
                if (ImGui::BeginTabItem("Industries")) {
                    IndustryTab();
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Resources")) {
                    ResourcesTab();
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
        }
    }

    void conquerspace::client::systems::SysPlanetInformation::PlanetInformationPanel() {
        namespace cqspc = conquerspace::common::components;
        if (!GetApp().GetUniverse().all_of<cqspc::Habitation>(selected_planet)) {
            return;
        }
        auto& habit = GetApp().GetUniverse().get<cqspc::Habitation>(selected_planet);
        ImGui::Text(fmt::format("Cities: {}", habit.settlements.size()).c_str());

        ImGui::BeginChild("citylist", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar | window_flags);
        // Market
        if (GetApp().GetUniverse().all_of<cqspc::MarketCenter>(selected_planet)) {
            auto& center = GetApp().GetUniverse().get<cqspc::MarketCenter>(selected_planet);
            auto& market = GetApp().GetUniverse().get<cqspc::Market>(center.market);
            ImGui::Text("Is market center");
            if (ImGui::IsItemHovered()) {
                ImGui::BeginTooltip();
                ImGui::Text(fmt::format("Has {} markets attached to it", market.participants.size()).c_str());
                // Get resource stockpile
                auto& stockpile = GetApp().GetUniverse().get<cqspc::ResourceStockpile>(center.market);
                DrawLedgerTable(GetApp().GetUniverse(), stockpile);
                ImGui::EndTooltip();
            }
            ImGui::Separator();
        }

        // List cities
        for (int i = 0; i < habit.settlements.size(); i++) {
            const bool is_selected = (selected_city_index == i);

            entt::entity e = habit.settlements[i];
            std::string name = GetApp().GetUniverse().get<cqspc::Name>(e).name;
            if (ImGui::Selectable(fmt::format("{}", name).c_str(), is_selected)) {
                // Load city
                selected_city_index = i;
                selected_city_entity = habit.settlements[i];
                view_mode = ViewMode::CITY_VIEW;

                if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
                    // See city
                    spdlog::info("Mouse clicked");
                }
            }
            gui::EntityTooltip(e, GetApp().GetUniverse());
        }
        ImGui::EndChild();
    }

    void conquerspace::client::systems::SysPlanetInformation::ResourcesTab() {
        namespace cqspc = conquerspace::common::components;
        // Consolidate resources
<<<<<<< HEAD
        auto& city_industry = GetApp().GetUniverse().get<cqspc::Industry>(selected_city_entity);
        cqspc::ResourceLedger resources;
        == == == = auto& city_industry = GetUniverse().get<cqspc::IndustrialZone>(selected_city_entity);
        cqspc::ResourceLedger resources = GetUniverse().get<cqspc::ResourceStockpile>(selected_city_entity);
        DrawLedgerTable("cityresources", GetUniverse(), resources);
>>>>>>> pr_191
        for (auto area : city_industry.industries) {
            if (GetApp().GetUniverse().all_of<cqspc::ResourceStockpile>(area)) {
                // Add resources
                auto& stockpile = GetApp().GetUniverse().get<cqspc::ResourceStockpile>(area);
                resources += stockpile;
            }
        }

        DrawLedgerTable(GetApp().GetUniverse(), resources);
    }

<<<<<<< HEAD
    void conquerspace::client::systems::SysPlanetInformation::IndustryTab() {
        namespace cqspc = conquerspace::common::components;
        auto& city_industry = GetApp().GetUniverse().get<cqspc::Industry>(selected_city_entity);
        == == == = void SysPlanetInformation::IndustryTab() {
            auto& city_industry = GetUniverse().get<cqspc::IndustrialZone>(selected_city_entity);
>>>>>>> pr_191

            ImGui::Text(fmt::format("Factories: {}", city_industry.industries.size()).c_str());
            ImGui::BeginChild(
                "salepanel", ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f - ImGui::GetStyle().ItemSpacing.y, 260),
                true, ImGuiWindowFlags_HorizontalScrollbar | window_flags);
<<<<<<< HEAD
            ImGui::Text("Services Sector");
            == == == = auto& city_industry = GetUniverse().get<cqspc::IndustrialZone>(selected_city_entity);
            ImGui::TextFmt(tabname);
>>>>>>> pr_191
            // List all the stuff it produces
            ImGui::Text("GDP:");
            ImGui::EndChild();

            ImGui::SameLine();

            ImGui::BeginChild(
                "ManufacturingPanel",
                ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f - ImGui::GetStyle().ItemSpacing.y, 260), true,
                ImGuiWindowFlags_HorizontalScrollbar | window_flags);
            ImGui::Text("Manufactuing Sector");
            // List all the stuff it produces
            ImGui::Text("GDP:");

            cqspc::ResourceLedger input_resources;
            cqspc::ResourceLedger output_resources;
<<<<<<< HEAD
            for (auto thingies : city_industry.industries) {
                if (GetApp().GetUniverse().all_of<cqspc::ResourceConverter, cqspc::Factory>(thingies)) {
                    auto& generator = GetApp().GetUniverse().get<cqspc::ResourceConverter>(thingies);
                    auto& recipe = GetApp().GetUniverse().get<cqspc::Recipe>(generator.recipe);
                    input_resources += recipe.input;
                    output_resources += recipe.output;
                    == == == = double GDP_calculation = 0;
                    int count = 0;
                    for (auto industry : city_industry.industries) {
                        if (GetUniverse().all_of<cqspc::Production, inddustrytype>(industry)) {
                            count++;
                            const cqspc::Production& generator = GetUniverse().get<cqspc::Production>(industry);
                            const cqspc::Recipe& recipe = GetUniverse().get<cqspc::Recipe>(generator.recipe);
                            const cqspc::IndustrySize& ratio = GetUniverse().get<cqspc::IndustrySize>(industry);

                            input_resources += (recipe.input * ratio.size);
                            output_resources[recipe.output.entity] += recipe.output.amount;

                            if (GetUniverse().all_of<cqspc::Wallet>(industry)) {
                                GDP_calculation += GetUniverse().get<cqspc::Wallet>(industry).GetGDPChange();
                            }
                        }
                    }
                    ImGui::TextFmt("GDP: {}", cqsp::util::LongToHumanString(GDP_calculation));
                    ImGui::TextFmt("{} Count: {}", industryname, count);

                    ImGui::SameLine();
                    if (CQSPGui::SmallDefaultButton("List")) {
                        factory_list_panel = true;
                        industrylist.resize(0);
                        auto& city_industry = GetUniverse().get<cqspc::IndustrialZone>(selected_city_entity).industries;
                        for (entt::entity production : city_industry) {
                            if (GetUniverse().all_of<inddustrytype>(production)) industrylist.push_back(production);
>>>>>>> pr_191
                        }
                    }

                    ImGui::Text("Output");
                    // Output table
                    DrawLedgerTable(GetApp().GetUniverse(), output_resources);

                    ImGui::Text("Input");
                    DrawLedgerTable(GetApp().GetUniverse(), input_resources);
                    ImGui::EndChild();

                    ImGui::BeginChild(
                        "MinePanel",
                        ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f - ImGui::GetStyle().ItemSpacing.y, 260),
                        true, ImGuiWindowFlags_HorizontalScrollbar | window_flags);
                    ImGui::Text("Mining Sector");
                    ImGui::Text("GDP:");
                    // Get what resources they are making
                    cqspc::ResourceLedger resources;
                    for (auto thingies : city_industry.industries) {
                        if (GetApp().GetUniverse().all_of<cqspc::ResourceGenerator, cqspc::Mine>(thingies)) {
                            auto& generator = GetApp().GetUniverse().get<cqspc::ResourceGenerator>(thingies);
                            resources += generator;
                        }
                    }

                    // Draw on table
                    DrawLedgerTable(GetApp().GetUniverse(), resources);

                    ImGui::EndChild();
                    ImGui::SameLine();

                    ImGui::BeginChild(
                        "AgriPanel",
                        ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f - ImGui::GetStyle().ItemSpacing.y, 260),
                        true, ImGuiWindowFlags_HorizontalScrollbar | window_flags);
                    ImGui::Text("Agriculture Sector");
                    ImGui::Text("GDP:");

                    ImGui::EndChild();
<<<<<<< HEAD
                }
                == == == =

                             static int prod = 1;
                ImGui::PushItemWidth(-1);
                ImGui::Text("Production");
                ImGui::SameLine();
                CQSPGui::DragInt("label", &prod, 1, 1, INT_MAX);
                ImGui::PopItemWidth();
                if (tech_progress.researched_mining.size() > 0) {
                    if (CQSPGui::DefaultButton("Construct!")) {
                        // Construct things
                        SPDLOG_INFO("Constructing mine with good {}", selected_good);
                        // Add demand to the market for the amount of resources
                        // When construction takes time in the future, then do the costs.
                        // So first charge it to the market
                        entt::entity city_market = GetUniverse().get<cqspc::MarketCenter>(selected_planet).market;
                        /*auto cost = cqsp::common::systems::actions::GetFactoryCost(
                GetUniverse(), selected_city_entity, selected_good, prod);
            GetUniverse().get<cqspc::Market>(city_market).demand += cost;
            GetUniverse().get<cqspc::ResourceStockpile>(city_market) -= cost;
            */
                        // Buy things on the market
                        //entt::entity factory = cqsp::common::systems::actions::CreateMine(
                        //    GetUniverse(), selected_city_entity, selected_good, 1, prod);
                        //cqsp::common::systems::economy::AddParticipant(GetUniverse(), city_market, factory);
                    }

                    if (ImGui::IsItemHovered()) {
                        ImGui::BeginTooltip();
                        DrawLedgerTable("building_cost_tooltip", GetUniverse(),
                                        cqsp::common::systems::actions::GetFactoryCost(
                                            GetUniverse(), selected_city_entity, selected_good, prod));
                        ImGui::EndTooltip();
                    }
                }
            }

            void SysPlanetInformation::SpacePortTab() {
                namespace cqspt = cqsp::common::components::types;
                namespace cqsps = cqsp::common::components::ships;
                namespace cqspb = cqsp::common::components::bodies;

                // Set the things
                static float semi_major_axis = 8000;
                static float inclination = 0;
                static float eccentricity = 0;
                static float arg_of_perapsis = 0;
                static float LAN = 0;
                ImGui::SliderFloat("Semi Major Axis", &semi_major_axis, 6000, 5000000);
                ImGui::SliderFloat("Eccentricity", &eccentricity, 0, 0.9999);
                ImGui::SliderAngle("Inclination", &inclination, 0, 180);
                ImGui::SliderAngle("Argument of perapsis", &arg_of_perapsis, 0, 360);
                ImGui::SliderAngle("Longitude of the ascending node", &LAN, 0, 360);
                if (ImGui::Button("Launch!")) {
                    // Get reference body
                    entt::entity reference_body = selected_planet;
                    // Launch inclination will be the inclination of the thing
                    double axial = GetUniverse().get<cqspc::bodies::Body>(selected_planet).axial;
                    double inc = GetUniverse().get<cqspc::types::SurfaceCoordinate>(selected_city_entity).r_latitude();
                    inc += axial;
                    double sma = 0;
                    // Currently selected city
                    //entt::entity star_system = GetUniverse().get<cqspc::bodies::Body>(selected_planet);
                    // Launch
                    cqspc::types::Orbit orb;
                    orb.reference_body = selected_planet;
                    orb.inclination = inclination;
                    orb.semi_major_axis = semi_major_axis;
                    orb.eccentricity = eccentricity;
                    orb.w = arg_of_perapsis;
                    orb.LAN = LAN;
                    cqsp::common::systems::actions::LaunchShip(GetUniverse(), orb);
                    //cqsp::common::systems::actions::CreateShip(
                    //GetUniverse(), entt::null, selected_planet, star_system);
                }
            }

            void SysPlanetInformation::InfrastructureTab() {
                if (power_plant_output_panel) {
                    ImGui::Begin("Power Plant", &power_plant_output_panel);
                    double& prod_d =
                        GetUniverse().get<cqspc::infrastructure::PowerPlant>(power_plant_changing).production;
                    float prod = static_cast<float>(prod_d);
                    ImGui::PushItemWidth(-1);
                    CQSPGui::DragFloat("power_plant_supply", &prod, 1, 1, INT_MAX);
                    prod_d = prod;
                    ImGui::PopItemWidth();
                    ImGui::End();
                }
                ImGui::Text("Infrastructure");
                // Get the areas that generate power
                ImGui::Separator();
                ImGui::Text("Power");
                auto& city_industry = GetUniverse().get<cqspc::IndustrialZone>(selected_city_entity);
                double power_production = 0;
                double power_demand = 0;
                if (GetUniverse().any_of<cqspc::infrastructure::CityPower>(selected_city_entity)) {
                    auto& power = GetUniverse().get<cqspc::infrastructure::CityPower>(selected_city_entity);
                    power_production = power.total_power_prod;
                    power_demand = power.total_power_consumption;
                }
                std::vector<entt::entity> power_plants;
                for (int i = 0; i < city_industry.industries.size(); i++) {
                    entt::entity industry = city_industry.industries[i];
                    if (GetUniverse().any_of<cqspc::infrastructure::PowerPlant>(industry)) {
                        power_plants.push_back(industry);
                    }
                }
                ImGui::TextFmt("Power Production: {}/{} MW", power_demand, power_production);
                if (GetUniverse().any_of<cqspc::infrastructure::BrownOut>(selected_city_entity)) {
                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(255, 0, 0, 1));
                    // Get seriousness, then do random other things
                    ImGui::TextFmt("Brown Out!");
                    ImGui::PopStyleColor(1);
                }

                for (entt::entity plant : power_plants) {
                    double prod = GetUniverse().get<cqspc::infrastructure::PowerPlant>(plant).production;
                    ImGui::TextFmt("Power Plant: {} MW", prod);
                    ImGui::SameLine();
                    if (ImGui::Button("Change Power plant output")) {
                        power_plant_output_panel = true;
                        power_plant_changing = plant;
                    }
                }
            }

            void SysPlanetInformation::ScienceTab() {
                if (!GetUniverse().valid(selected_planet)) {
                    return;
                }
                auto& city_industry = GetUniverse().get<cqspc::IndustrialZone>(selected_city_entity);
                ImGui::Text("Science");
                // Get the science labs
                cqspc::ResourceLedger led;
                for (int i = 0; i < city_industry.industries.size(); i++) {
                    entt::entity industry = city_industry.industries[i];
                    if (GetUniverse().any_of<cqspc::science::Lab>(industry)) {
                        ImGui::Text("Lab %d", i);
                        auto& lab = GetUniverse().get<cqspc::science::Lab>(industry);
                        led += lab.science_contribution;
                    }
                }
                // Get all the combined science
                ImGui::Text("Science Contribution");
                systems::DrawLedgerTable("science_contrib_table", GetUniverse(), led);
            }

            void SysPlanetInformation::MarketInformationTooltipContent(const entt::entity marketentity) {}

            void SysPlanetInformation::ConstructionConfirmationPanel() {
                if (!enable_construction_confirmation_panel) {
                    return;
                }
                ImGui::SetNextWindowPos(
                    ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), ImGuiCond_Always,
                    ImVec2(0.5f, 0.5f));
                ImGui::Begin("Construction Complete", &enable_construction_confirmation_panel,
                             ImGuiWindowFlags_NoDecoration);
                ImGui::Text("Constructed factory");
                if (ImGui::Button("Ok", ImVec2(-1, 0))) {
                    enable_construction_confirmation_panel = false;
                }
                ImGui::End();
            }

            void SysPlanetInformation::RecipeConstructionCostPanel(entt::entity selected_recipe, double prod,
                                                                   const common::components::ResourceLedger& cost) {
                entt::entity city_market = GetUniverse().get<cqspc::MarketCenter>(selected_planet).market;
                // Cost table
                ImGui::TextFmt("Estimated Cost: {}",
                               common::systems::economy::GetCost(GetUniverse(), city_market, cost));
                CQSPGui::SimpleTextTooltip("Estimated cost at current market prices");

                ImGui::Text("Resources Needed");
                DrawLedgerTable("factory_cost", GetUniverse(), cost);
            }

            void SysPlanetInformation::RecipeConstructionConstructButton(
                entt::entity selected_recipe, double prod, const common::components::ResourceLedger& cost) {
                // Get the cost, and display it
                // Calculate the cost
                if (!CQSPGui::DefaultButton("Construct!")) {
                    return;
                }
                // Construct things
                SPDLOG_INFO("Constructing factory with recipe {}", selected_recipe);
                // Create construction site and do the cost
                entt::entity player = GetUniverse().view<cqspc::Player>().front();

                entt::entity city_market = GetUniverse().get<cqspc::MarketCenter>(selected_planet).market;
                entt::entity factory = common::systems::actions::OrderConstructionFactory(
                    GetUniverse(), selected_city_entity, city_market, selected_recipe, prod, player);
                if (factory == entt::null) {
                    return;
                }
                enable_construction_confirmation_panel = true;
            }
        }  // namespace cqsp::client::systems
>>>>>>> pr_191
