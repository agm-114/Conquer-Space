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

#include "common/systems/isimulationsystem.h"

namespace cqsp::common::systems {
<<<<<<< HEAD:src/common/systems/economy/sysproduction.h
class SysProduction : public ISimulationSystem {
    == == == = class SysNavyControl : public ISimulationSystem {
>>>>>>> pr_254:src/common/systems/navy/sysnavy.h
     public:
        explicit SysProduction(Game& game) : ISimulationSystem(game) {}
        void DoSystem() override;
        int Interval() override { return components::StarDate::DAY; }
    };
}  // namespace cqsp::common::systems
