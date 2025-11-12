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

#include <string>

#include "common/universe.h"

<<<<<<< HEAD:src/common/loading/loadprovinces.h namespace cqsp::common::loading {
<<<<<<< HEAD
    void LoadProvinces(Node & planet, const std::string& text);
    == == == = void LoadProvinces(Universe & universe, entt::entity planet, const std::string& text);
>>>>>>> pr-292
    void LoadAdjProvinces(Universe & universe, Hjson::Value & adjacency_map);
    void LoadAllProvinces(Universe & universe);
}  // namespace cqsp::common::loading
== == == = namespace cqsp::common::systems::loading {
    void LoadTechnologies(Universe & universe, Hjson::Value & value);
    void ResearchTech(Universe & universe, entt::entity civilization, entt::entity tech);
    void ProcessAction(Universe & universe, entt::entity civilization, const std::string& action);

}  // namespace cqsp::common::systems::science
>>>>>>> pr-290:src/common/systems/science/technology.h
