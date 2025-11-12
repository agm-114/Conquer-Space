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
#include <string>
#include <vector>

#include "client/scenes/scene.h"
#include "engine/renderer/framebuffer.h"
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD namespace cqsp::client::scene {
    == == ==
    = namespace cqsp::scene {
>>>>>>> pr_254
    /// <summary>
    /// Just a playground for various graphics stuff
    /// </summary>
    /// <param name="app"></param>
<<<<<<< HEAD
    class TextTestScene : public ClientScene {
     public:
        explicit TextTestScene(engine::Application& app)
            : client::ClientScene(app) {} == == ==
            = class TextTestScene : public client::Scene {
         public:
            explicit TextTestScene(engine::Application& app) : client::Scene(app) {}
>>>>>>> pr_254
            ~TextTestScene();
            == == == = namespace cqsp::client::scene {
                /// <summary>
                /// Just a playground for various graphics stuff
                /// </summary>
                /// <param name="app"></param>
                class TextTestScene : public ClientScene {
                 public:
                    explicit TextTestScene(engine::Application& app) : client::ClientScene(app) {}
                    ~TextTestScene();
>>>>>>> pr-286
                    == == == = namespace cqsp::scene {
                        /// <summary>
                        /// Just a playground for various graphics stuff
                        /// </summary>
                        /// <param name="app"></param>
                        class TextTestScene : public cqsp::client::Scene {
                         public:
                            explicit TextTestScene(cqsp::engine::Application& app) : cqsp::client::Scene(app) {}
                            ~TextTestScene();
>>>>>>> pr-283

                            void Init();
                            void Update(float deltaTime);
                            void Ui(float deltaTime);
                            void Render(float deltaTime);

<<<<<<< HEAD
<<<<<<< HEAD

                         private:
                            engine::LayerRenderer renderer;
                            float font_size = 40.f;
                            std::string text = "The quick brown fox jumps over the lazy dog";
                            int layer;
                            int src = 0;
                            int post = 0;
                            std::map<std::string, int> indices;
                            std::vector<const char*> names;
                            float delta_t = 0;
                        };
<<<<<<< HEAD
                    }  // namespace cqsp::client::scene
                    == == == =
             }  // namespace cqsp::scene
>>>>>>> pr_254
                 == == ==
                 = private : engine::LayerRenderer renderer;
                float font_size = 40.f;
                std::string text = "The quick brown fox jumps over the lazy dog";
                int layer;
                int src = 0;
                int post = 0;
                std::map<std::string, int> indices;
                std::vector<const char*> names;
                float delta_t = 0;
            };
     }  // namespace cqsp::client::scene
>>>>>>> pr-286
         == == ==
         = private : cqsp::engine::LayerRenderer renderer;
        float font_size = 40.f;
        std::string text = "The quick brown fox jumps over the lazy dog";
        int layer;
        int src = 0;
        int post = 0;
        std::map<std::string, int> indices;
        std::vector<const char*> names;
        float delta_t = 0;
    };
    == == == =
<<<<<<< HEAD namespace cqsp::client::scene {
                 == == == = namespace cqsp::scene {
>>>>>>> pr-283
        /// <summary>
        /// Just a playground for various graphics stuff
        /// </summary>
        /// <param name="app"></param>
        class TextTestScene : public ClientScene {
         public:
            explicit TextTestScene(engine::Application& app) : client::ClientScene(app) {}
            ~TextTestScene();

            void Init();
            void Update(float deltaTime);
            void Ui(float deltaTime);
            void Render(float deltaTime);

         private:
            engine::LayerRenderer renderer;
            float font_size = 40.f;
            std::string text = "The quick brown fox jumps over the lazy dog";
            int layer;
            int src = 0;
            int post = 0;
            std::map<std::string, int> indices;
            std::vector<const char*> names;
            float delta_t = 0;
        };
<<<<<<< HEAD
    }  // namespace cqsp::client::scene
    == == == =
>>>>>>> pr-286
}  // namespace cqsp::scene
>>>>>>> pr-283
