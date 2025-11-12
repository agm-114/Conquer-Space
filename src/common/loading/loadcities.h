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

#include "common/loading/hjsonloader.h"

<<<<<<< HEAD:src/common/loading/loadcities.h namespace cqsp::common::loading {
    == == == = namespace cqsp::common::systems {
        namespace resource {
>>>>>>> pr-283:src/common/systems/actions/sysresourcetransfer.h
        /// <summary>
        /// This loader has to be loaded after \ref PlanetLoader because it adds the cities to the
        /// respectve planets
        /// </summary>
<<<<<<< HEAD:src/common/loading/loadcities.h
        class CityLoader : public HjsonLoader {
         public:
            explicit CityLoader(Universe& universe) : HjsonLoader(universe) {}

            const Hjson::Value& GetDefaultValues() override { return default_val; }
            bool LoadValue(const Hjson::Value& values, Node& node) override;
            void PostLoad(const Node& node) override;

         private:
            Hjson::Value default_val;
        };
        }  // namespace cqsp::common::loading
        == == == =
                     /// <param name="registry">Registry to transfer</param>
            /// <param name="from">Needs to be a resource stockpile</param>
            /// <param name="to">Needs to be a resource stockpile</param>
            /// <param name="good">good to transfer</param>
            /// <param name="amount">amount of resources to transfer</param>
            /// <returns>If transfering resources failed.</returns>
            bool TransferResources(entt::registry & registry, entt::entity from, entt::entity to, entt::entity good,
                                   double amount);
    }  // namespace resource
}  // namespace cqsp::common::systems
>>>>>>> pr-283:src/common/systems/actions/sysresourcetransfer.h
