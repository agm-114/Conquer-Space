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
#include "client/scenes/universeloadingscene.h"

#include <spdlog/spdlog.h>

#include <string>

<<<<<<< HEAD
#include "client/components/clientctx.h"
#include "client/scenes/universe/universescene.h"
#include "client/systems/assetloading.h"
        <<<<<<<HEAD == == == =
#include "common/util/save/savegame.h"
                   >>>>>>>
            pr - 294
#include "client/systems/universeloader.h"
    == == ==
    =
#include <sol/sol.hpp>

#include "client/scenes/universescene.h"
#include "common/components/bodies.h"
#include "common/components/movement.h"
#include "common/components/name.h"
#include "common/components/resource.h"
#include "common/universe.h"
        >>>>>>> pr_8
#include "common/systems/sysuniversegenerator.h"
#include "common/util/save/savegame.h"

        <<<<<<< HEAD < < < < < < <
        HEAD namespace cqsp::client::scene {

    UniverseLoadingScene::UniverseLoadingScene(engine::Application & app) : ClientScene(app) {}

    UniverseLoadingScene::~UniverseLoadingScene() {
        GetApp().CloseDocument("../data/core/gui/screens/universe_loading_screen.rml");
        == == == = using cqsp::scene::UniverseLoadingScene;
        == == == = namespace cqsp::client::scene {
            UniverseLoadingScene::UniverseLoadingScene(engine::Application & app) : ClientScene(app) {}

            UniverseLoadingScene::~UniverseLoadingScene() {
                GetApp().CloseDocument("../data/core/gui/screens/universe_loading_screen.rml");
            }

            void UniverseLoadingScene::Init() {
                auto loading = [&]() { LoadCurrentUniverse(); };
>>>>>>> pr-286

                UniverseLoadingScene::UniverseLoadingScene(cqsp::engine::Application & app)
                    : cqsp::client::Scene(app) {}

<<<<<<< HEAD
                UniverseLoadingScene::~UniverseLoadingScene() {
                    GetApp().CloseDocument("../data/core/gui/screens/universe_loading_screen.rml");
                }

<<<<<<< HEAD
                void UniverseLoadingScene::Init() {
                    auto loading = [&]() { LoadUniverse(); };
                    == == == = void UniverseLoadingScene::Update(float deltaTime) {
                        if (m_completed_loading && thread->joinable()) {
                            // Switch scene
                            thread->join();
                            GetApp().SetScene<UniverseScene>();
                        }
                    }
>>>>>>> pr-294

                    m_completed_loading = false;
                    thread = std::make_unique<std::thread>(loading);
                    document = GetApp().LoadDocument("../data/core/gui/screens/universe_loading_screen.rml");
                    if (document != nullptr) {
                        document->Show();
                    }
                }

                void UniverseLoadingScene::Update(float deltaTime) {
                    if (m_completed_loading && thread->joinable()) {
                        // Switch scene
                        thread->join();
                        GetApp().SetScene<cqsp::scene::UniverseScene>();
                    }
                }

<<<<<<< HEAD
<<<<<<< HEAD
                void UniverseLoadingScene::Ui(float deltaTime) {} == == ==
                    = void UniverseLoadingScene::LoadCurrentUniverse() {
                    LoadUniverse(GetAssetManager(), *dynamic_cast<ConquerSpace*>(GetApp().GetGame()));
                    // Load saves
                    if (GetUniverse().ctx().contains<ctx::GameLoad>()) {
                        const std::string& load_dir = GetUniverse().ctx().at<ctx::GameLoad>().load_dir;
                        SPDLOG_INFO("Loading save {}", load_dir);
                        common::save::load_game(GetUniverse(), load_dir);
                    }
>>>>>>> pr-294
                    == == == = void UniverseLoadingScene::LoadCurrentUniverse() {
                        LoadUniverse(GetAssetManager(), *dynamic_cast<ConquerSpace*>(GetApp().GetGame()));
                        // Load saves
                        if (GetUniverse().ctx().contains<ctx::GameLoad>()) {
                            const std::string& load_dir = GetUniverse().ctx().at<ctx::GameLoad>().load_dir;
                            SPDLOG_INFO("Loading save {}", load_dir);
                            save::load_game(GetUniverse(), load_dir);
                        }
>>>>>>> pr-288

                        void UniverseLoadingScene::Render(float deltaTime) {}

                        void UniverseLoadingScene::LoadUniverse() {
                            client::systems::LoadAllResources(
                                GetApp(), *dynamic_cast<cqsp::client::ConquerSpace*>(GetApp().GetGame()));
                            SPDLOG_INFO("Made all game resources into game objects");
                            using asset::TextAsset;
                            // Process scripts for core
                            TextAsset* script_list = GetAssetManager().GetAsset<TextAsset>("core:base");
                            GetScriptInterface().RunScript(script_list->data);
                            SPDLOG_INFO("Done loading scripts");
                            using common::systems::universegenerator::ScriptUniverseGenerator;
                            // Load universe
                            ScriptUniverseGenerator script_generator(GetScriptInterface());

                            script_generator.Generate(GetUniverse());
                            if (GetUniverse().ctx().contains<client::ctx::GameLoad>()) {
                                const std::string& load_dir = GetUniverse().ctx().at<client::ctx::GameLoad>().load_dir;
                                SPDLOG_INFO("Loading save {}", load_dir);
                                client::save::load_game(GetUniverse(), load_dir);
>>>>>>> pr_254
                            }

                            void UniverseLoadingScene::Init() {
                                auto loading = [&]() { LoadCurrentUniverse(); };

                                m_completed_loading = false;
                                thread = std::make_unique<std::thread>(loading);
                                document =
                                    GetApp().LoadDocument("../data/core/gui/screens/universe_loading_screen.rml");
                                if (document != nullptr) {
                                    document->Show();
                                }
                            }

                            void UniverseLoadingScene::Update(float deltaTime) {
                                if (m_completed_loading && thread->joinable()) {
                                    // Switch scene
                                    thread->join();
                                    GetApp().SetScene<UniverseScene>();
                                }
                            }

                            void UniverseLoadingScene::Ui(float deltaTime) {}

                            void UniverseLoadingScene::Render(float deltaTime) {}

                            void UniverseLoadingScene::LoadCurrentUniverse() {
                                LoadUniverse(GetAssetManager(), *dynamic_cast<ConquerSpace*>(GetApp().GetGame()));
                                // Load saves
                                if (GetUniverse().ctx().contains<ctx::GameLoad>()) {
                                    const std::string& load_dir = GetUniverse().ctx().at<ctx::GameLoad>().load_dir;
                                    SPDLOG_INFO("Loading save {}", load_dir);
                                    common::save::load_game(GetUniverse(), load_dir);
                                }

                                SPDLOG_INFO("Done loading the universe, entering game");
                                m_completed_loading = true;
                            }
                        }  // namespace cqsp::client::scene
                        == == == = void UniverseLoadingScene::Update(float deltaTime) {
                            if (m_completed_loading && thread->joinable()) {
                                // Switch scene
                                thread->join();
                                GetApp().SetScene<cqsp::client::scene::UniverseScene>();
                            }
                        }

                        void UniverseLoadingScene::Ui(float deltaTime) {}

                        void UniverseLoadingScene::Render(float deltaTime) {}

                        void UniverseLoadingScene::LoadCurrentUniverse() {
                            LoadUniverse(GetAssetManager(), *dynamic_cast<ConquerSpace*>(GetApp().GetGame()));
                            // Load saves
                            if (GetUniverse().ctx().contains<client::ctx::GameLoad>()) {
                                const std::string& load_dir = GetUniverse().ctx().at<ctx::GameLoad>().load_dir;
                                SPDLOG_INFO("Loading save {}", load_dir);
                                save::load_game(GetUniverse(), load_dir);
                            }

                            SPDLOG_INFO("Done loading the universe, entering game");
                            m_completed_loading = true;
                        }
                    }  // namespace cqsp::client::scene
>>>>>>> pr-286
