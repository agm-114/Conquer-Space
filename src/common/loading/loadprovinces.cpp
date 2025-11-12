/* Conquer Space
<<<<<<< HEAD
 * Copyright (C) 2021-2025 Conquer Space
=======
 * Copyright (C) 2021-2023 Conquer Space
>>>>>>> pr-292
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
#include "common/loading/loadprovinces.h"

#include <spdlog/spdlog.h>

#include <sstream>

#include "common/components/name.h"
#include "common/components/organizations.h"
#include "common/components/surface.h"

<<<<<<< HEAD namespace cqsp::common::loading {
    void LoadProvinces(Node & planet, const std::string& text) {
        == == == = < < < < < < < < HEAD : src / common / systems / loading /
                                       loadprovinces.cpp void cqsp::common::systems::loading::LoadProvinces(
                                           Universe & universe, const std::string& text) {
                                           == == == ==
                                           namespace cqsp::common::loading {void LoadProvinces(
                                               Universe & universe, entt::entity planet, const std::string& text) {
                                               >>>>>>>> pr - 292 : src / common / loading /
                                                                 loadprovinces.cpp
>>>>>>> pr-292
                                                                     // The text has to be csv, so treat it is csv
                                                                     std::istringstream f(text);
    std::string line;
    while (std::getline(f, line)) {
        // Split and parse
        std::string token;
        std::istringstream f2(line);
        std::getline(f2, token, ',');
        std::string identifier = token;
        std::getline(f2, token, ',');
        std::string r = token;
        std::getline(f2, token, ',');
        std::string g = token;
        std::getline(f2, token, ',');
        std::string b = token;
        std::getline(f2, token, ',');
        std::string country = token;
        // Create
<<<<<<< HEAD
        //SPDLOG_INFO("Loading Country: {} ID {}", country, identifier);
        Universe& universe = planet.universe();
        Node province_node(universe);
        Node country_node(universe, universe.countries[country]);
        province_node.emplace<components::Province>(country_node);
        province_node.emplace<components::Identifier>(identifier);
        auto& color = province_node.emplace<components::ProvinceColor>(std::stoi(r), std::stoi(g), std::stoi(b));

        if (universe.provinces.find(identifier) == universe.provinces.end()) {
            universe.provinces[identifier] = province_node;
            == == == = entt::entity entity = universe.create();
            universe.emplace<components::Province>(entity, universe.countries[country]);
            universe.emplace<components::Identifier>(entity, identifier);
            auto& color = universe.emplace<components::ProvinceColor>(entity, std::stoi(r), std::stoi(g), std::stoi(b));
            if (universe.provinces.find(identifier) == universe.provinces.end()) {
                universe.provinces[identifier] = entity;
>>>>>>> pr-292
            } else {
                SPDLOG_WARN("Province {} conflicts with an already preexisting province", identifier);
            }
            // Add province to country
<<<<<<< HEAD
            // check if it is assigned to a country
            if (!country.empty() && universe.countries.contains(country)) {
                country_node.get_or_emplace<components::CountryCityList>().province_list.push_back(province_node);
            }
            universe.province_colors[planet][(int)color] = province_node;
            universe.colors_province[planet][province_node] = (int)color;
            //SPDLOG_INFO("Provience Loaded");
        }
    }

    void LoadAdjProvinces(Universe & universe, Hjson::Value & adjacency_map) {
        // Go through value
        for (auto const& [province_name, neighbors] : adjacency_map) {
            if (!universe.provinces.contains(province_name)) {
                SPDLOG_WARN("Cannot find province {}", province_name);
                continue;
            }
            Node province_Node(universe, universe.provinces[province_name]);
            auto& province = province_Node.get<components::Province>();
            province.neighbors.resize(neighbors.size());
            for (int i = 0; i < neighbors.size(); i++) {
                if (!universe.provinces.contains(neighbors[i].to_string())) {
                    SPDLOG_WARN("Cannot find province {}", neighbors[i].to_string());
                    continue;
                }
                province.neighbors[i] = universe.provinces[neighbors[i].to_string()];
            }
        }
    }
}  // namespace cqsp::common::loading
== == ==
    = universe.get_or_emplace<components::CountryCityList>(universe.countries[country]).province_list.push_back(entity);

universe.province_colors[(int)color] = entity;
universe.colors_province[entity] = (int)color;
}
}
< < < < < < < < HEAD : src / common / systems / loading / loadprovinces.cpp == == == ==
}  // namespace cqsp::common::loading
>>>>>>>> pr - 292 : src / common / loading / loadprovinces.cpp
>>>>>>> pr-292
