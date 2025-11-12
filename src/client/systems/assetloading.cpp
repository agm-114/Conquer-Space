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
#include "client/systems/assetloading.h"

#include <chrono>
#include <memory>
#include <string>

#include "client/scripting/clientscripting.h"
#include "client/scripting/clientuielements.h"
#include "client/scripting/imguifunctions.h"
#include "common/components/surface.h"
#include "common/loading/fields.h"
#include "common/loading/hjsonloader.h"
#include "common/loading/loadcities.h"
#include "common/loading/loadcountries.h"
#include "common/loading/loadgoods.h"
#include "common/loading/loadnames.h"
#include "common/loading/loadprovinces.h"
#include "common/loading/loadsatellites.h"
#include "common/loading/loadterrain.h"
#include "common/loading/planetloader.h"
#include "common/loading/recipeloader.h"
#include "common/loading/technology.h"
#include "common/loading/timezoneloader.h"
#include "common/scripting/luafunctions.h"
<<<<<<< HEAD
#include "common/systems/sysuniversegenerator.h"
#include "engine/asset/assetmanager.h"

    <<<<<<< HEAD namespace cqsp::client::systems { namespace loading = common::loading; == ==
    ==
    =
#include "common/loading/fields.h"
#include "common/loading/hjsonloader.h"
#include "common/loading/loadcities.h"
#include "common/loading/loadcountries.h"
#include "common/loading/loadgoods.h"
#include "common/loading/loadnames.h"
#include "common/loading/loadplanets.h"
#include "common/loading/loadprovinces.h"
#include "common/loading/loadsatellites.h"
#include "common/loading/technology.h"
#include "common/loading/timezoneloader.h"
#include "common/systems/sysuniversegenerator.h"
#include "engine/asset/assetmanager.h"

        namespace cqsp::client::systems {

    namespace loading = common::loading;
>>>>>>> pr-292
    namespace components = common::components;
    using asset::AssetManager;
    using asset::HjsonAsset;
    using common::Universe;
    using loading::HjsonLoader;

    void LoadResource(AssetManager & asset_manager, Universe & universe, const std::string& asset_name,
                      void (*func)(Universe& universe, Hjson::Value& recipes)) {
        for (const auto& it : asset_manager) {
            == == == =

                         namespace components = cqsp::common::components;
            namespace loading = cqsp::common::systems::loading;  // NOLINT
            using cqsp::asset::HjsonAsset;
            using cqsp::common::Universe;
            using cqsp::common::systems::loading::HjsonLoader;
            using cqsp::engine::Application;
            using loading::LoadProvinces;

<<<<<<< HEAD
            namespace cqsp::client::systems {
            void LoadResource(Application& app, Universe& universe, const std::string& asset_name,
                              void (*func)(common::Universe& universe, Hjson::Value& recipes)) {
                for (const auto& it : app.GetAssetManager()) {
>>>>>>> pr_254
                    if (!it.second->HasAsset(asset_name)) {
                        continue;
                    }
                    HjsonAsset* good_assets = it.second->GetAsset<HjsonAsset>(asset_name);
                    try {
                        func(universe, good_assets->data);
                    } catch (std::runtime_error& error) {
                        SPDLOG_INFO("Failed to load hjson asset {}: {}", asset_name, error.what());
                    } catch (Hjson::index_out_of_bounds& error) {
                        SPDLOG_INFO("Failed to load hjson asset {}: Index out of bounds: {}", asset_name, error.what());
                    }
                }
            }
            == == ==
                = template <class T>
                void LoadResource(AssetManager & asset_manager, Universe& universe, const std::string& asset_name) {
                auto start = std::chrono::system_clock::now();
                static_assert(std::is_base_of_v<HjsonLoader, T>, "Class is not child of");
                std::unique_ptr<HjsonLoader> ptr = std::make_unique<T>(universe);
                //SPDLOG_INFO("Starting load {}", asset_name);

                for (const auto& it : asset_manager) {
                    if (!it.second->HasAsset(asset_name)) {
                        continue;
                    }
                    HjsonAsset* good_assets = it.second->GetAsset<HjsonAsset>(asset_name);
                    try {
                        ptr->LoadHjson(good_assets->data);
                    } catch (std::runtime_error& error) {
                        SPDLOG_INFO("Failed to load hjson asset {}: {}", asset_name, error.what());
                    } catch (Hjson::index_out_of_bounds& error) {
                        SPDLOG_INFO("Failed to load hjson asset {}: Index out of bounds: {}", asset_name, error.what());
                    }
                }
                auto end = std::chrono::system_clock::now();
                SPDLOG_INFO("{} load took {} ms", asset_name,
                            std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
            }

            void LoadPlanetProvinces(AssetManager& asset_manager, ConquerSpace& conquer_space) {
                auto& universe = conquer_space.GetUniverse();
                auto view = universe.nodes<components::ProvincedPlanet>();
                SPDLOG_INFO("Loading Provinces");
                for (common::Node node : view) {
                    // Check if it's empty or not
                    //SPDLOG_INFO("Loading Provinces for planet");

<<<<<<< HEAD
                    auto& province_map = node.get<components::ProvincedPlanet>();
                    if (!province_map.province_definitions.empty()) {
                        asset::TextAsset* asset =
                            asset_manager.GetAsset<asset::TextAsset>(province_map.province_definitions);
                        if (asset != nullptr) {
                            loading::LoadProvinces(node, asset->data);
                        }
                    }
                    //SPDLOG_INFO("Done Loading Provinces for planet");
                }
                SPDLOG_INFO("Proviences Loaded");
            }
>>>>>>> pr-303

            template <class T>
<<<<<<< HEAD
            void LoadResource(AssetManager& asset_manager, Universe& universe, const std::string& asset_name) {
                auto start = std::chrono::system_clock::now();
                static_assert(std::is_base_of_v<HjsonLoader, T>, "Class is not child of");
                == == == = void LoadResource(Application & app, Universe & universe, const std::string& asset_name) {
                    static_assert(std::is_base_of<HjsonLoader, T>::value, "Class is not child of");
>>>>>>> pr_254
                    std::unique_ptr<HjsonLoader> ptr = std::make_unique<T>(universe);
                    //SPDLOG_INFO("Starting load {}", asset_name);
                    == == == = LoadResource(asset_manager, conquer_space.m_universe, "names", loading::LoadNameLists);
                    LoadResource(asset_manager, conquer_space.m_universe, "tech_fields", loading::LoadFields);
                    LoadResource(asset_manager, conquer_space.m_universe, "tech_list", loading::LoadTechnologies);

                    // Initialize planet terrains
                    HjsonAsset* asset = asset_manager.GetAsset<HjsonAsset>("core:terrain_colors");
                    loading::LoadTerrainData(conquer_space.GetUniverse(), asset->data);
>>>>>>> pr-292

<<<<<<< HEAD
                    for (const auto& it : asset_manager) {
                        == == == = for (const auto& it : app.GetAssetManager()) {
>>>>>>> pr_254
                            if (!it.second->HasAsset(asset_name)) {
                                continue;
                            }
                            HjsonAsset* good_assets = it.second->GetAsset<HjsonAsset>(asset_name);
                            try {
                                ptr->LoadHjson(good_assets->data);
                            } catch (std::runtime_error& error) {
                                SPDLOG_INFO("Failed to load hjson asset {}: {}", asset_name, error.what());
                            } catch (Hjson::index_out_of_bounds& error) {
                                SPDLOG_INFO("Failed to load hjson asset {}: Index out of bounds: {}", asset_name,
                                            error.what());
                            }
                        }
                        auto end = std::chrono::system_clock::now();
                        SPDLOG_INFO("{} load took {} ms", asset_name,
                                    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
                    }

<<<<<<< HEAD
                    void LoadPlanetProvinces(AssetManager & asset_manager, ConquerSpace & conquer_space) {
                        auto& universe = conquer_space.GetUniverse();
                        auto view = universe.nodes<components::ProvincedPlanet>();
                        SPDLOG_INFO("Loading Provinces");
                        for (common::Node node : view) {
                            // Check if it's empty or not
                            //SPDLOG_INFO("Loading Provinces for planet");

                            auto& province_map = node.get<components::ProvincedPlanet>();
                            if (!province_map.province_definitions.empty()) {
                                asset::TextAsset* asset =
                                    asset_manager.GetAsset<asset::TextAsset>(province_map.province_definitions);
                                if (asset != nullptr) {
                                    loading::LoadProvinces(node, asset->data);
                                }
                            }
                            //SPDLOG_INFO("Done Loading Provinces for planet");
                        }
                        SPDLOG_INFO("Proviences Loaded");
                    }

                    void LoadAllResources(AssetManager & asset_manager, ConquerSpace & conquer_space) {
                        LoadResource<loading::GoodLoader>(asset_manager, conquer_space.GetUniverse(), "goods");
                        LoadResource<loading::RecipeLoader>(asset_manager, conquer_space.GetUniverse(), "recipes");
                        LoadResource<loading::PlanetLoader>(asset_manager, conquer_space.GetUniverse(), "planets");
                        LoadResource<loading::TimezoneLoader>(asset_manager, conquer_space.GetUniverse(), "timezones");
                        LoadResource<loading::CountryLoader>(asset_manager, conquer_space.GetUniverse(), "countries");

                        LoadPlanetProvinces(asset_manager, conquer_space);
                        LoadResource<loading::CityLoader>(asset_manager, conquer_space.GetUniverse(), "cities");
                        LoadResource<loading::SatelliteLoader>(asset_manager, conquer_space.GetUniverse(),
                                                               "satellites");

                        LoadResource(asset_manager, conquer_space.m_universe, "names", loading::LoadNameLists);
                        LoadResource(asset_manager, conquer_space.m_universe, "tech_fields", loading::LoadFields);
                        LoadResource(asset_manager, conquer_space.m_universe, "tech_list", loading::LoadTechnologies);

                        // Initialize planet terrains
                        HjsonAsset* asset = asset_manager.GetAsset<HjsonAsset>("core:terrain_colors");
                        loading::LoadTerrainData(conquer_space.GetUniverse(), asset->data);
                        == == == = void LoadAllResources(Application & app, ConquerSpace & conquer_space) {
                            LoadResource<loading::GoodLoader>(app, conquer_space.GetUniverse(), "goods");
                            LoadResource<loading::RecipeLoader>(app, conquer_space.GetUniverse(), "recipes");
                            LoadResource<loading::PlanetLoader>(app, conquer_space.GetUniverse(), "planets");
                            LoadResource<loading::TimezoneLoader>(app, conquer_space.GetUniverse(), "timezones");
                            LoadResource<loading::CountryLoader>(app, conquer_space.GetUniverse(), "countries");
                            LoadProvinces(conquer_space.GetUniverse(),
                                          app.GetAssetManager().GetAsset<asset::TextAsset>("province_defs")->data);
                            LoadResource<loading::CityLoader>(app, conquer_space.GetUniverse(), "cities");
                            LoadResource(app, conquer_space.m_universe, "names", loading::LoadNameLists);
                            LoadResource(app, conquer_space.m_universe, "tech_fields",
                                         common::systems::science::LoadFields);
                            LoadResource(app, conquer_space.m_universe, "tech_list",
                                         common::systems::science::LoadTechnologies);
                            common::systems::loading::LoadSatellites(
                                conquer_space.GetUniverse(),
                                app.GetAssetManager().GetAsset<asset::TextAsset>("satellites")->data);

                            // Initialize planet terrains
                            HjsonAsset* asset = app.GetAssetManager().GetAsset<HjsonAsset>("core:terrain_colors");
                            common::systems::loading::LoadTerrainData(conquer_space.GetUniverse(), asset->data);
>>>>>>> pr_254

                            // Load scripts
                            // Load lua functions
                            common::scripting::LoadFunctions(conquer_space.GetUniverse(),
                                                             conquer_space.GetScriptInterface());
<<<<<<< HEAD
                            scripting::LoadImGuiFunctions(conquer_space.GetUniverse(),
                                                          conquer_space.GetScriptInterface());
                            scripting::ClientFunctions(asset_manager, conquer_space.GetUniverse(),
                                                       conquer_space.GetScriptInterface());
                            scripting::InitClientElements(conquer_space.GetUniverse(),
                                                          conquer_space.GetScriptInterface());
                            == == == = scripting::ClientFunctions(app, conquer_space.GetUniverse(),
                                                                  conquer_space.GetScriptInterface());
>>>>>>> pr_254

                            // Load universe
                            // Register data groups
                            auto& script_interface = conquer_space.GetScriptInterface();
                            script_interface.RegisterDataGroup("generators");
                            script_interface.RegisterDataGroup("events");
                            script_interface.RegisterDataGroup("interfaces");
                        }
                    }  // namespace cqsp::client::systems
