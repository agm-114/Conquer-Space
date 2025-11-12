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
#include "common/loading/loadcountries.h"

<<<<<<< HEAD
#include "common/components/market.h"
#include "common/components/name.h"
#include "common/components/organizations.h"

    <<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/loadcountries.cpp namespace cqsp::common::loading {
    bool
    CountryLoader::LoadValue(const Hjson::Value& values, Node& node) {
    == == == = using cqsp::common::systems::loading::CountryLoader;
    using entt::entity;
    == == == = namespace cqsp::common::loading {
        bool CountryLoader::LoadValue(const Hjson::Value& values, Node& node) {
            // Just make the country
            node.emplace<components::Country>();
            universe.countries[node.get<components::Identifier>().identifier] = node;
>>>>>>> pr-303

            bool CountryLoader::LoadValue(const Hjson::Value& values, entity entity) {
>>>>>>> pr_254:src/common/systems/loading/loadcountries.cpp
                // Just make the country
                node.emplace<components::Country>();
                universe.countries[node.get<components::Identifier>().identifier] = node;

<<<<<<< HEAD
                // Add the list of liabilities the country has?

                if (!values["wallet"].empty()) {
                    auto& wallet = node.emplace<components::Wallet>();
                    wallet = values["wallet"];
                }
                return true;
            }
<<<<<<< HEAD:src/common/loading/loadcountries.cpp
        }  // namespace cqsp::common::loading
        == == == =
>>>>>>> pr_254:src/common/systems/loading/loadcountries.cpp
                     == == == = if (!values["wallet"].empty()) {
            auto& wallet = node.emplace<components::Wallet>();
            wallet = values["wallet"];
        }
        return true;
    }
}  // namespace cqsp::common::loading
>>>>>>> pr-303
== == == =
#include "common/components/economy.h"
#include "common/components/name.h"
#include "common/components/organizations.h"

             namespace cqsp::common::loading {
    bool CountryLoader::LoadValue(const Hjson::Value& values, entt::entity entity) {
        // Just make the country
        universe.emplace<components::Country>(entity);
        universe.countries[universe.get<components::Identifier>(entity).identifier] = entity;

        // Add the list of liabilities the country has?

        if (!values["wallet"].empty()) {
            auto& wallet = universe.emplace<components::Wallet>(entity);
            wallet = values["wallet"];
        }
        return true;
    }
}  // namespace cqsp::common::loading
>>>>>>> pr-292
