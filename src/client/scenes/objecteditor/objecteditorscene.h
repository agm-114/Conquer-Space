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

#include <map>
#include <memory>
#include <string>
#include <utility>

#include "client/scenes/scene.h"
#include "client/systems/sysgui.h"

<<<<<<< HEAD
<<<<<<< HEAD namespace cqsp::client::scene {
    class ObjectEditorScene : public ClientScene {
    == == == = namespace cqsp::scene {
        class ObjectEditorScene : public client::Scene {
>>>>>>> pr_254
         public:
            explicit ObjectEditorScene(engine::Application& app);
            ~ObjectEditorScene();
            == == == = namespace cqsp::client::scene {
                class ObjectEditorScene : public ClientScene {
                 public:
                    explicit ObjectEditorScene(engine::Application& app);
                    ~ObjectEditorScene();
>>>>>>> pr-286

                    void Init();
                    void Update(float deltaTime);
                    void Ui(float deltaTime);
                    void Render(float deltaTime);

                    template <class T>
                    void AddUISystem(const std::string& name) {
                        auto ui = std::make_unique<T>(GetApp());
                        ui->Init();
                        user_interfaces[name] = std::make_pair(false, std::move(ui));
                    }

<<<<<<< HEAD

                 private:
<<<<<<< HEAD
                    std::map<std::string, std::pair<bool, std::unique_ptr<systems::SysUserInterface>>> user_interfaces;
                    == == ==
                        = std::map<std::string, std::pair<bool, std::unique_ptr<client::systems::SysUserInterface>>>
                            user_interfaces;
>>>>>>> pr_254
                };
            }  // namespace cqsp::client::scene
         == == == = private : std::map<std::string, std::pair<bool, std::unique_ptr<systems::SysUserInterface>>>
                                  user_interfaces;
        };
    }  // namespace cqsp::client::scene
>>>>>>> pr-286
