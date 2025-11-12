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
#include "common/components/coordinates.h"
#include "common/components/event.h"
#include "common/components/name.h"
#include "common/components/organizations.h"
#include "common/components/player.h"
<<<<<<< HEAD
#include "common/components/resource.h"
#include "common/components/ships.h"
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
        >>>>>>> pr_4

    namespace cqsp::common::systems::simulation {
    Simulation::Simulation(Game & game) : m_game(game), m_universe(game.GetUniverse()) {}

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
        int len = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        const int expected_len = 250;
        if (len > expected_len) {
            SPDLOG_WARN("Tick has taken more than {} ms at {} ms", expected_len, len);
        }
<<<<<<< HEAD
        == == == = END_TIMED_BLOCK(Production);

        BEGIN_TIMED_BLOCK(Resource_Consume);
        // Consume resources
        auto consume = m_universe.view<cqspc::ResourceConverter, cqspc::ResourceStockpile>();
        for (entt::entity entity : consume) {
            // Do the same thing
            // Make resources
            cqspc::ResourceConverter &generator = m_universe.get<cqspc::ResourceConverter>(entity);
            cqspc::ResourceStockpile &resource_stockpile = m_universe.get<cqspc::ResourceStockpile>(entity);
            cqspc::Recipe &recipe = m_universe.get<cqspc::Recipe>(generator.recipe);
            // Create resources
            for (auto iterator = recipe.input.begin(); iterator != recipe.input.end(); iterator++) {
                double resource_count = 0;
                if (resource_stockpile.find(iterator->first) != resource_stockpile.end()) {
                    resource_count = resource_stockpile[iterator->first];
                }
                float productivity = 1;
                if (m_universe.all_of<cqspc::FactoryProductivity>(entity)) {
                    productivity = m_universe.get<cqspc::FactoryProductivity>(entity).productivity;
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
