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
#include "common/simulation.h"

#include <spdlog/spdlog.h>

#include <memory>
#include <string>
#include <vector>

#include "common/components/area.h"
<<<<<<< HEAD
#include "common/components/coordinates.h"
    == == ==
    =
#include "common/components/name.h"
#include "common/components/resource.h"
#include "common/systems/economy/sysmarketplace.h"
#include "common/systems/movement/sysmovement.h"
#include "common/systems/sysresourcegen.h"
#include "common/util/profiler.h"

        >>>>>>> pr_8
#include "common/components/event.h"
#include "common/components/name.h"
#include "common/components/organizations.h"
#include "common/components/player.h"
        <<<<<<<HEAD
#include "common/components/resource.h"
#include "common/components/ships.h"
                   <<<<<<<HEAD == == == =
#include "common/components/movement.h"
                              >>>>>>>
                       pr_8
#include "common/components/units.h"
#include "common/systems/economy/sysagent.h"
#include "common/systems/economy/sysfinance.h"
#include "common/systems/economy/sysinfrastructure.h"
#include "common/systems/economy/sysinterplanetarytrade.h"
#include "common/systems/economy/sysmarket.h"
#include "common/systems/economy/sysmarketreset.h"
#include "common/systems/economy/sysplanetarytrade.h"
#include "common/systems/economy/syspopulation.h"
#include "common/systems/economy/sysproduction.h"
#include "common/systems/economy/sysspaceport.h"
#include "common/systems/history/sysmarkethistory.h"
#include "common/systems/movement/sysorbit.h"
#include "common/systems/science/syssciencelab.h"
#include "common/systems/science/systechnology.h"
#include "common/systems/scriptrunner.h"
#include "common/util/profiler.h"
                   == == ==
               =
#include "common/components/orbit.h"
#include "common/components/ships.h"
#include "common/components/units.h"
                   >>>>>>>
            pr_4

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        namespace cqsp::common::systems::simulation {
    Simulation::Simulation(Game & game)
        : m_game(game),
          m_universe(game.GetUniverse()) {} == == ==
          = conquerspace::common::systems::simulation::Simulation::Simulation(
              conquerspace::common::components::Universe & _universe, scripting::ScriptInterface & script_interface)
        : m_universe(_universe),
          script_runner(_universe, script_interface) {
        AddSystem<conquerspace::common::systems::SysResourceGen>();
        AddSystem<conquerspace::common::systems::SysFactoryResourceProduction>();
        // Sell the resources they produce
        AddSystem<conquerspace::common::systems::SysMarketSeller>();
        // Buy resources
        // Request demand, and buy things
        AddSystem<conquerspace::common::systems::SysMarketBuyer>();
        AddSystem<conquerspace::common::systems::SysFactoryResourceConsumption>();
        // Move planets around orbits
        // Move ships towards targets
        AddSystem<conquerspace::common::systems::SysOrbit>();
        AddSystem<conquerspace::common::systems::SysPath>();
        == == == = using cqsp::common::systems::simulation::Simulation;
        using cqsp::common::Universe;
        Simulation::Simulation(Universe & _universe, scripting::ScriptInterface & script_interface)
            : m_universe(_universe), script_runner(_universe, script_interface) {
            namespace cqspcs = cqsp::common::systems;
            AddSystem<cqspcs::SysPopulationGrowth>();
            AddSystem<cqspcs::SysPopulationConsumption>();
            AddSystem<cqspcs::SysFactory>();
            AddSystem<cqspcs::SysOrbit>();
            AddSystem<cqspcs::SysPath>();
            AddSystem<cqspcs::SysSurface>();
            == == == = using cqsp::common::systems::simulation::Simulation;
            using cqsp::common::Universe;

            Simulation::Simulation(cqsp::common::Game & game) : m_game(game), m_universe(game.GetUniverse()) {
                namespace cqspcs = cqsp::common::systems;
                AddSystem<cqspcs::SysScript>();
                AddSystem<cqspcs::SysWalletReset>();

                // AddSystem<cqspcs::SysNavyControl>();

                AddSystem<cqspcs::SysScienceLab>();
                AddSystem<cqspcs::SysTechProgress>();

                AddSystem<cqspcs::InfrastructureSim>();
                AddSystem<cqspcs::SysPopulationConsumption>();
                AddSystem<cqspcs::SysProduction>();

                // AddSystem<cqspcs::SysAgent>();
                AddSystem<cqspcs::SysMarket>();
                AddSystem<cqspcs::history::SysMarketHistory>();
                AddSystem<cqspcs::SysOrbit>();
                AddSystem<cqspcs::SysPath>();

                cqspcs::SysMarket::InitializeMarket(game);
            }

<<<<<<< HEAD
            void Simulation::tick() {
                m_universe.DisableTick();
                m_universe.date.IncrementDate();
                // Get previous tick spacing
                namespace cqspc = cqsp::common::components;
                namespace cqsps = cqsp::common::components::ships;
                namespace cqspt = cqsp::common::components::types;
                auto start = std::chrono::high_resolution_clock::now();
                BEGIN_TIMED_BLOCK(Game_Loop);
                == == == = == == == = void Simulation::Init() {
                    CreateSystems();
                    for (auto &sys : system_list) {
                        sys->Init();
                    }
                }
>>>>>>> main

                namespace cqsp::common::systems::simulation {
                Simulation::Simulation(Game &game) : m_game(game), m_universe(game.GetUniverse()) {
                    AddSystem<SysScript>();
                    AddSystem<SysWalletReset>();

                    AddSystem<SysScienceLab>();
                    AddSystem<SysTechProgress>();

                    // Economy progress
                    AddSystem<SysMarketReset>();

                    AddSystem<InfrastructureSim>();
                    AddSystem<SysPopulationConsumption>();
                    AddSystem<SysProduction>();

                    // AddSystem<SysAgent>();
                    AddSystem<SysMarket>();
                    AddSystem<SysPlanetaryTrade>();
                    AddSystem<history::SysMarketHistory>();

                    // Movement
                    AddSystem<SysOrbit>();
                }

                void Simulation::Init() {
                    SysMarket::InitializeMarket(m_game);
>>>>>>> pr-290

                    for (auto &sys : system_list) {
                        if (m_universe.date.GetDate() % sys->Interval() == 0) {
                            sys->DoSystem();
>>>>>>> pr_191
                        }
>>>>>>> pr_28

<<<<<<< HEAD
                        // Register functions
    script_interface.set_function("event_player", [&](sol::table event_table) {
                            auto view = m_universe.view<conquerspace::common::components::Player>();
                            for (auto b : view) {
                                auto &queue = m_universe.get_or_emplace<event::EventQueue>(b);
                                auto event = std::make_shared<event::Event>();
                                event->title = event_table["title"];
                                SPDLOG_INFO("Parsing event \"{}\"", event->title);
                                event->content = event_table["content"];
                                event->image = event_table["image"];
                                sol::optional<std::vector<sol::table>> optional = event_table["actions"];
                                if (optional) {
                                    for (auto &action : *optional) {
                                        if (action == sol::nil) {
                                            continue;
                                        }
                                        auto event_result = std::make_shared<event::EventResult>();
                                        event_result->name = action["name"];
                                        sol::optional<std::string> tooltip = action["tooltip"];
                                        if (tooltip) {
                                            event_result->tooltip = *tooltip;
                                        }
>>>>>>> pr_8

                                        void Simulation::CreateSystems() {
                                            AddSystem<SysScript>();
                                            AddSystem<SysWalletReset>();

                                            AddSystem<SysScienceLab>();
                                            AddSystem<SysTechProgress>();

                                            // Economy progress
                                            AddSystem<SysMarketReset>();
                                            AddSystem<SysSpacePort>();

                                            AddSystem<InfrastructureSim>();
                                            AddSystem<SysPopulationConsumption>();
                                            AddSystem<SysProduction>();

                                            // AddSystem<SysAgent>();
                                            AddSystem<SysMarket>();
                                            AddSystem<SysPlanetaryTrade>();
                                            AddSystem<SysInterplanetaryTrade>();
                                            AddSystem<history::SysMarketHistory>();

                                            // Movement
                                            AddSystem<SysOrbit>();
                                        }

                                        void Simulation::Init() {
                                            for (auto &sys : system_list) {
                                                sys->Init();
                                            }
                                        }

                                        void Simulation::tick() {
                                            m_universe.DisableTick();
                                            m_universe.date.IncrementDate();
                                            // Get previous tick spacing
<<<<<<< HEAD
                                            == == == = namespace cqspc = conquerspace::common::components;
                                            namespace cqsps = conquerspace::common::components::ships;
                                            namespace cqspt = conquerspace::common::components::types;
>>>>>>> pr_4

                                            auto start = std::chrono::high_resolution_clock::now();
                                            BEGIN_TIMED_BLOCK(Game_Loop);

                                            for (auto &sys : system_list) {
                                                if (m_universe.date.GetDate() % sys->Interval() == 0) {
                                                    sys->DoSystem();
                                                }
                                            }
                                            END_TIMED_BLOCK(Game_Loop);
                                            auto end = std::chrono::high_resolution_clock::now();
                                            int len = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                                                          .count();
                                            const int expected_len = 250;
                                            if (len > expected_len) {
                                                SPDLOG_WARN("Tick has taken more than {} ms at {} ms", expected_len,
                                                            len);
                                            }
<<<<<<< HEAD
<<<<<<< HEAD
                                            == == == = END_TIMED_BLOCK(Production);

                                            BEGIN_TIMED_BLOCK(Resource_Consume);
                                            // Consume resources
                                            auto consume =
                                                m_universe.view<cqspc::ResourceConverter, cqspc::ResourceStockpile>();
                                            for (entt::entity entity : consume) {
                                                // Do the same thing
                                                // Make resources
                                                cqspc::ResourceConverter &generator =
                                                    m_universe.get<cqspc::ResourceConverter>(entity);
                                                cqspc::ResourceStockpile &resource_stockpile =
                                                    m_universe.get<cqspc::ResourceStockpile>(entity);
                                                cqspc::Recipe &recipe = m_universe.get<cqspc::Recipe>(generator.recipe);
                                                // Create resources
                                                for (auto iterator = recipe.input.begin();
                                                     iterator != recipe.input.end(); iterator++) {
                                                    double resource_count = 0;
                                                    if (resource_stockpile.find(iterator->first) !=
                                                        resource_stockpile.end()) {
                                                        resource_count = resource_stockpile[iterator->first];
                                                    }
                                                    float productivity = 1;
                                                    if (m_universe.all_of<cqspc::FactoryProductivity>(entity)) {
                                                        productivity =
                                                            m_universe.get<cqspc::FactoryProductivity>(entity)
                                                                .productivity;
                                                    }

                                                    resource_count -= iterator->second * productivity;

                                                    m_universe.emplace_or_replace<cqspc::Production>(entity);

                                                    // Add to resource stockpile
                                                    resource_stockpile[iterator->first] = resource_count;
                                                }
                                            }
                                            END_TIMED_BLOCK(Resource_Consume);

                                            BEGIN_TIMED_BLOCK(Orbit_Sim);
                                            auto bodies = m_universe.view<cqspt::Orbit>();
                                            for (entt::entity body : bodies) {
                                                cqspt::updateOrbit(m_universe.get<cqspt::Orbit>(body));
                                            }
                                            END_TIMED_BLOCK(Orbit_Sim);
>>>>>>> pr_4
                                        }
                                    }  // namespace cqsp::common::systems::simulation
                                    == == == =
                                }
                            }
>>>>>>> pr_8
                            == == == = void Simulation::tick() {
                                m_universe.DisableTick();
                                m_universe.date.IncrementDate();
                                // Get previous tick spacing

                                auto start = std::chrono::high_resolution_clock::now();
                                BEGIN_TIMED_BLOCK(Game_Loop);

                                for (auto &sys : system_list) {
                                    if (m_universe.date.GetDate() % sys->Interval() == 0) {
                                        sys->DoSystem();
                                    }
                                }
                                END_TIMED_BLOCK(Game_Loop);
                                auto end = std::chrono::high_resolution_clock::now();
                                int len = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                                const int expected_len = 250;
                                if (len > expected_len) {
                                    SPDLOG_WARN("Tick has taken more than {} ms at {} ms", expected_len, len);
                                }
                            }
}  // namespace cqsp::common::systems::simulation
>>>>>>> pr-290
