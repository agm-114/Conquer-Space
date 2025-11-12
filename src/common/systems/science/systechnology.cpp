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
#include "common/systems/science/systechnology.h"

#include <vector>

#include <tracy/Tracy.hpp>

#include "common/components/science.h"
#include "common/loading/technology.h"

<<<<<<< HEAD namespace cqsp::common::systems {
    namespace science = components::science;

    void SysTechProgress::DoSystem() {
        ZoneScoped;
        auto fields = GetUniverse().nodes<science::ScientificResearch>();

        for (Node field_node : fields) {
            auto& research = field_node.get<science::ScientificResearch>();
            std::vector<Node> completed_techs;
            == == == = using cqsp::common::components::science::Technology;
            using cqsp::common::components::science::ScientificResearch;
            using cqsp::common::systems::SysTechProgress;
            using entt::entity;

            void SysTechProgress::DoSystem() {
                ZoneScoped;
                for (entity presearch : GetUniverse().view<ScientificResearch>()) {
                    auto& research = GetUniverse().get<ScientificResearch>(presearch);
                    std::vector<entity> completed_techs;
>>>>>>> pr_254
                    for (auto& res : research.current_research) {
                        res.second += Interval();
                        Node tech_node(field_node, res.first);
                        // Get the research amount
<<<<<<< HEAD

                        auto& tech = tech_node.get<science::Technology>();
                        == == == = auto& tech = GetUniverse().get<Technology>(res.first);
>>>>>>> pr_254
                        if (res.second > tech.difficulty) {
                            // Add the researched
                            completed_techs.push_back(tech_node);
                        }
                    }
<<<<<<< HEAD
                    for (Node tech : completed_techs) {
                        actions::ResearchTech(field_node, tech);
                        research.current_research.erase(tech);
                        == == == = for (entity r : completed_techs) {
                            science::ResearchTech(GetUniverse(), presearch, r);
                            research.current_research.erase(r);
>>>>>>> pr_254
                        }
                    }
                }
            }  // namespace cqsp::common::systems