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
#pragma once

#include <string>
#include <vector>

#include "client/scenes/scene.h"
#include "creditswindow.h"
#include "engine/graphics/primitives/pane.h"
#include "engine/graphics/renderable.h"
#include "engine/graphics/text.h"
#include "engine/renderer/renderer.h"
#include "engine/renderer/renderer2d.h"
#include "loadgamewindow.h"
#include "settingswindow.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD namespace cqsp::client::scene {
    class MainMenuScene : public ClientScene {
    == == == = namespace cqsp::scene {
        class MainMenuScene : public cqsp::client::Scene {
>>>>>>> pr_254
         public:
            explicit MainMenuScene(engine::Application& app);
            ~MainMenuScene();
            == == == = namespace cqsp::client::scene {
                class MainMenuScene : public ClientScene {
                 public:
                    explicit MainMenuScene(engine::Application& app);
                    ~MainMenuScene();
>>>>>>> pr-286
                    == == == = namespace cqsp::scene {
                        class MainMenuScene : public cqsp::client::Scene {
                         public:
                            explicit MainMenuScene(cqsp::engine::Application& app);
                            ~MainMenuScene();
>>>>>>> pr-283

                            void Init();
                            void Update(float deltaTime);
                            void Ui(float deltaTime);
                            void Render(float deltaTime);

                         private:
                            void ModWindow();

                            Rml::ElementDocument* main_menu;

<<<<<<< HEAD
                            SettingsWindow settings_window;
                            CreditsWindow credits_window;
                            LoadGameWindow load_game_window;

                            class EventListener : public Rml::EventListener {
                             public:
                                EventListener() = default;
                                void ProcessEvent(Rml::Event& event);
                                engine::Application* app;
                                MainMenuScene* m_scene;
                            } listener;
                            == == == = SettingsWindow settings_window;
                            CreditsWindow credits_window;
                            LoadGameWindow load_game_window;

                            class EventListener : public Rml::EventListener {
                             public:
                                EventListener() = default;
                                void ProcessEvent(Rml::Event& event);
                                engine::Application* app;
                                MainMenuScene* m_scene;
                            } listener;
>>>>>>> pr-286

                            bool is_options_visible = false;
                            bool last_options_visible = false;

                            std::vector<std::string> file_list;
                            int index;

<<<<<<< HEAD
                            void ShuffleFileList();
                            void SetMainMenuImage(const std::string& file);
                            void NextImage();

<<<<<<< HEAD
                            double last_switch = 0;
                            // Change every minute (time is in seconds)
                            const float switch_time = 60;
                        };
<<<<<<< HEAD
                    }  // namespace cqsp::client::scene
                    == == == =
                }  // namespace cqsp::scene
>>>>>>> pr_254
                    == == ==
                    = double last_switch = 0;
                // Change every minute
                const float switch_time = 60;
            };
        }  // namespace cqsp::client::scene
>>>>>>> pr-286
            == == ==
            = double last_switch = 0;
        // Change every minute
        const float switch_time = 60;
    };
}  // namespace cqsp::scene
>>>>>>> pr-283
