/* Conquer Space
<<<<<<< HEAD
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
== == == = *Copyright(C) 2021 Conquer Space * *This program is free software : you can redistribute it and / or
           modify * it under the terms of the GNU General Public License as published by * the Free Software Foundation,
      either version 3 of the License,
      or *(at your option)any later version.** This program is distributed in the hope that it will be useful,
      *but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
>>>>>>> pr-292
#pragma once

#include <utility>

#include <entt/entt.hpp>

#include "common/components/resource.h"
#include "common/universe.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD:src/common/actions/factoryconstructaction.h namespace cqsp::common::actions {
    == == ==
    = namespace cqsp::common::systems::actions {
>>>>>>> pr_254:src/common/systems/actions/factoryconstructaction.h
    /// <summary>
    /// Will charge the entity builder the amount needed to construct the factory/building. You'll have to find a
    /// organization that can construct it though.
    /// </summary>
    /// <param name="universe"></param>
    /// <param name="city"></param>
    /// <param name="recipe"></param>
    /// <param name="productivity"></param>
    /// <param name="builder"></param>
    /// <returns>The factory entity created, entt::null if it's not possible.</returns>
<<<<<<< HEAD:src/common/actions/factoryconstructaction.h
    Node OrderConstructionFactory(Node & city, Node & market, Node & recipe, Node & builder, int productivity = 1);
    == == == = entt::entity OrderConstructionFactory(Universe & universe, entt::entity city, entt::entity market,
                                                     entt::entity recipe, int productivity, entt::entity builder);
>>>>>>> pr_254:src/common/systems/actions/factoryconstructaction.h

    /// <summary>
    /// Creates a factory from thin air
    /// </summary>
    /// <param name="universe"></param>
    /// <param name="city"></param>
    /// <param name="recipe"></param>
    /// <param name="productivity"></param>
    /// <returns>The factory entity created</returns>
<<<<<<< HEAD:src/common/actions/factoryconstructaction.h
    Node CreateFactory(Node & city, Node & recipe, int productivity = 1, double wages = 10);

    components::ResourceLedger GetFactoryCost(Node & city, Node & recipe, int productivity = 1);

    Node CreateCommercialArea(Node & city);
    == == == = namespace cqsp::common::actions {
        /// <summary>
        /// Will charge the entity builder the amount needed to construct the factory/building. You'll have to find a
        /// organization that can construct it though.
        /// </summary>
        /// <param name="universe"></param>
        /// <param name="city"></param>
        /// <param name="recipe"></param>
        /// <param name="productivity"></param>
        /// <param name="builder"></param>
        /// <returns>The factory entity created, entt::null if it's not possible.</returns>
        Node OrderConstructionFactory(Node & city, Node & market, Node & recipe, Node & builder, int productivity = 1);

        /// <summary>
        /// Creates a factory from thin air
        /// </summary>
        /// <param name="universe"></param>
        /// <param name="city"></param>
        /// <param name="recipe"></param>
        /// <param name="productivity"></param>
        /// <returns>The factory entity created</returns>
        Node CreateFactory(Node & city, Node & recipe, int productivity = 1, double wages = 10);

        components::ResourceLedger GetFactoryCost(Node & city, Node & recipe, int productivity = 1);

        Node CreateCommercialArea(Node & city);
>>>>>>> pr-303

    }  // namespace cqsp::common::actions
    == == ==
        = entt::entity CreateFactory(Universe & universe, entt::entity city, entt::entity recipe, int productivity);

    components::ResourceLedger GetFactoryCost(Universe & universe, entt::entity city, entt::entity recipe,
                                              int productivity);

    entt::entity CreateCommercialArea(Universe & universe, entt::entity city);

}  // namespace cqsp::common::systems::actions
>>>>>>> pr_254:src/common/systems/actions/factoryconstructaction.h
== == == = < < < < < < < < HEAD : src / common / systems / actions / factoryconstructaction.h namespace cqsp {
    namespace common {
    namespace systems {
    namespace actions {
    == == == == namespace cqsp::common::actions {
        >>>>>>>> pr - 292
            : src /
              common / actions /
              factoryconstructaction.h
                  /// <summary>
                  /// Will charge the entity builder the amount needed to construct the factory/building. You'll have to find a
                  /// organization that can construct it though.
                  /// </summary>
                  /// <param name="universe"></param>
                  /// <param name="city"></param>
                  /// <param name="recipe"></param>
                  /// <param name="productivity"></param>
                  /// <param name="builder"></param>
                  /// <returns>The factory entity created, entt::null if it's not possible.</returns>
                  entt::entity
                  OrderConstructionFactory(cqsp::common::Universe & universe, entt::entity city, entt::entity market,
                                           entt::entity recipe, int productivity, entt::entity builder);

        /// <summary>
        /// Creates a factory from thin air
        /// </summary>
        /// <param name="universe"></param>
        /// <param name="city"></param>
        /// <param name="recipe"></param>
        /// <param name="productivity"></param>
        /// <returns>The factory entity created</returns>
        entt::entity CreateFactory(cqsp::common::Universe & universe, entt::entity city, entt::entity recipe,
                                   int productivity);

        cqsp::common::components::ResourceLedger GetFactoryCost(cqsp::common::Universe & universe, entt::entity city,
                                                                entt::entity recipe, int productivity);

        entt::entity CreateCommercialArea(cqsp::common::Universe & universe, entt::entity city);

    }  // namespace actions
    }  // namespace systems
    }  // namespace common
    }  // namespace cqsp
>>>>>>> pr-292
