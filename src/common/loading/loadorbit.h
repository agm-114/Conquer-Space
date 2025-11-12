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

#include <hjson.h>

#include <optional>

<<<<<<< HEAD:src/common/loading/loadorbit.h
#include "common/components/orbit.h"

    namespace cqsp::common::loading {
    std::optional<components::types::Orbit> LoadOrbit(const Hjson::Value& values);
}  // namespace cqsp::common::loading
== == == =
#include "common/components/coordinates.h"
#include "common/components/ships.h"
#include "common/components/units.h"
#include "common/systems/movement/sysmovement.h"
             namespace cqsp::common::systems {
    void SysNavyControl::DoSystem() { Universe& universe = GetUniverse(); }
}  // namespace cqsp::common::systems
>>>>>>> pr-290:src/common/systems/navy/sysnavy.cpp
