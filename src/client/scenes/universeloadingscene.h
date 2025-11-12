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

#include <atomic>
#include <memory>
#include <thread>

#include "client/scenes/scene.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD namespace cqsp::client::scene {
    class UniverseLoadingScene : public ClientScene {
    == == == = namespace cqsp::scene {
        class UniverseLoadingScene : public client::Scene {
>>>>>>> pr_254
         public:
            explicit UniverseLoadingScene(engine::Application& app);
            ~UniverseLoadingScene();
            == == == = namespace cqsp::client::scene {
                class UniverseLoadingScene : public ClientScene {
                 public:
                    explicit UniverseLoadingScene(engine::Application& app);
                    ~UniverseLoadingScene();
>>>>>>> pr-286
                    == == == = namespace cqsp::scene {
                        class UniverseLoadingScene : public cqsp::client::Scene {
                         public:
                            explicit UniverseLoadingScene(cqsp::engine::Application& app);
                            ~UniverseLoadingScene();
>>>>>>> pr-283

                            void Init();
                            void Update(float deltaTime);
                            void Ui(float deltaTime);
                            void Render(float deltaTime);

                         private:
                            std::atomic<bool> m_done_loading;
                            std::unique_ptr<std::thread> thread;

<<<<<<< HEAD
                            void LoadCurrentUniverse();
                            == == == = void LoadCurrentUniverse();
>>>>>>> pr-286

                            bool m_completed_loading;

<<<<<<< HEAD
<<<<<<< HEAD
                            Rml::ElementDocument* document;
                        };
<<<<<<< HEAD
                    }  // namespace cqsp::client::scene
                    == == == =
                }  // namespace cqsp::scene
>>>>>>> pr_254
                    == == ==
                    = Rml::ElementDocument * document;
            };
        }  // namespace cqsp::client::scene
>>>>>>> pr-286
            == == ==
            = Rml::ElementDocument * document;
    };
}  // namespace cqsp::scene
    == == ==
    =
<<<<<<< HEAD namespace cqsp::client::scene {
        class UniverseLoadingScene : public ClientScene {
    == == == = namespace cqsp::scene {
        class UniverseLoadingScene : public cqsp::client::Scene {
>>>>>>> pr-283
         public:
            explicit UniverseLoadingScene(engine::Application& app);
            ~UniverseLoadingScene();

            void Init();
            void Update(float deltaTime);
            void Ui(float deltaTime);
            void Render(float deltaTime);

         private:
            std::atomic<bool> m_done_loading;
            std::unique_ptr<std::thread> thread;

            void LoadCurrentUniverse();

            bool m_completed_loading;

            Rml::ElementDocument* document;
        };
<<<<<<< HEAD
    }  // namespace cqsp::client::scene
    == == == =
}  // namespace cqsp::scene
>>>>>>> pr-286
>>>>>>> pr-283
