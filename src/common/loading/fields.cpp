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
#include "common/loading/fields.h"

#include <spdlog/spdlog.h>

#include <map>
#include <string>
#include <vector>

#include "common/components/name.h"
#include "common/components/science.h"
#include "common/loading/loadutil.h"

namespace components = cqsp::common::components;
namespace science = components::science;
using components::Description;
using components::Identifier;
using components::Name;
using entt::entity;
using science::Field;

namespace cqsp::common::systems::science {
struct FieldTemplate {
    std::vector<std::string> parent;
    std::vector<std::string> adjacent;
};

<<<<<<< HEAD:src/common/loading/fields.cpp
namespace cqsp::common::loading {
namespace science = components::science;

== == == =
>>>>>>> pr_254:src/common/systems/science/fields.cpp
             void LoadFields(Universe & universe, Hjson::Value& hjson) {
    for (int i = 0; i < hjson.size(); i++) {
        Hjson::Value val = hjson[i];
        if (val["name"].type() != Hjson::Type::String) {
            continue;
        }
        // Get the name
<<<<<<< HEAD
<<<<<<< HEAD:src/common/loading/fields.cpp
        == == == =
>>>>>>> pr-303
                     Node field_node(universe);
        auto& field_comp = field_node.emplace<science::Field>();
        LoadName(field_node, val);
        if (!LoadIdentifier(field_node, val)) {
            universe.destroy(field_node);
<<<<<<< HEAD
            == == == = entity field = universe.create();
            Field& field_comp = universe.emplace<Field>(field);
            loading::LoadName(universe, field, val);
            if (!loading::LoadIdentifier(universe, field, val)) {
                universe.destroy(field);
>>>>>>> pr_254:src/common/systems/science/fields.cpp
                SPDLOG_INFO("No field with {}", Hjson::Marshal(val));
                == == == = SPDLOG_INFO("No field with {}", Hjson::Marshal(val));
                continue;
            }

            std::string identifier = field_node.get<components::Identifier>();
            auto& field_template = field_node.emplace<FieldTemplate>();

            if (val["parent"].type() == Hjson::Type::Vector) {
                for (int j = 0; j < val["parent"].size(); j++) {
                    std::string parent_name = val["parent"][j];
                    if (parent_name == identifier) {
                        SPDLOG_WARN("Parent for {} cannot be itself!", identifier);
                        continue;
                    }
                    field_template.parent.push_back(parent_name);
                }
            }
            if (val["adjacent"].type() == Hjson::Type::Vector) {
                for (int j = 0; j < val["adjacent"].size(); j++) {
                    std::string parent_name = val["adjacent"][j];
                    // Adjacent cannot be itself
                    if (parent_name == identifier) {
                        SPDLOG_WARN("Adjacent for {} cannot be itself!", identifier);
                        continue;
                    }
                    field_template.adjacent.push_back(parent_name);
                }
            }
            if (universe.fields.find(identifier) != universe.fields.end()) {
                SPDLOG_WARN("Field {} already exists, overwriting", identifier);
            }

            // Description
            if (val["description"].type() == Hjson::Type::String) {
                universe.emplace<components::Description>(field_node, val["description"].to_string());
            }
            universe.fields[identifier] = field_node;
        }

        for (Node field_node : universe.nodes<FieldTemplate>()) {
            auto& field_template = field_node.get<FieldTemplate>();
            auto& field = field_node.get<science::Field>();
            for (const auto& parent_name : field_template.parent) {
                // If it does not contain, warn
                if (universe.fields.find(parent_name) == universe.fields.end()) {
                    SPDLOG_WARN("No field {} exists", parent_name);
>>>>>>> pr-303
                    continue;
                }

<<<<<<< HEAD
                std::string identifier = field_node.get<components::Identifier>();
                auto& field_template = field_node.emplace<FieldTemplate>();

                if (val["parent"].type() == Hjson::Type::Vector) {
                    for (int j = 0; j < val["parent"].size(); j++) {
                        std::string parent_name = val["parent"][j];
                        if (parent_name == identifier) {
                            SPDLOG_WARN("Parent for {} cannot be itself!", identifier);
                            continue;
                        }
                        field_template.parent.push_back(parent_name);
                    }
                }
                if (val["adjacent"].type() == Hjson::Type::Vector) {
                    for (int j = 0; j < val["adjacent"].size(); j++) {
                        std::string parent_name = val["adjacent"][j];
                        // Adjacent cannot be itself
                        if (parent_name == identifier) {
                            SPDLOG_WARN("Adjacent for {} cannot be itself!", identifier);
                            continue;
                        }
                        field_template.adjacent.push_back(parent_name);
                    }
                }
                if (universe.fields.find(identifier) != universe.fields.end()) {
                    SPDLOG_WARN("Field {} already exists, overwriting", identifier);
                }

                // Description
                if (val["description"].type() == Hjson::Type::String) {
                    universe.emplace<components::Description>(field_node, val["description"].to_string());
                }
                universe.fields[identifier] = field_node;
            }

<<<<<<< HEAD:src/common/loading/fields.cpp
            for (Node field_node : universe.nodes<FieldTemplate>()) {
                auto& field_template = field_node.get<FieldTemplate>();
                auto& field = field_node.get<science::Field>();
                == == == = for (entity entity : universe.view<FieldTemplate>()) {
                    auto& field_template = universe.get<FieldTemplate>(entity);
                    Field& field = universe.get<Field>(entity);
>>>>>>> pr_254:src/common/systems/science/fields.cpp
                    for (const auto& parent_name : field_template.parent) {
                        // If it does not contain, warn
                        if (universe.fields.find(parent_name) == universe.fields.end()) {
                            SPDLOG_WARN("No field {} exists", parent_name);
                            continue;
                        }
                        field.parents.push_back(universe.fields[parent_name]);
                    }
                    for (const auto& parent_name : field_template.adjacent) {
                        if (universe.fields.find(parent_name) == universe.fields.end()) {
                            SPDLOG_WARN("No field {} exists", parent_name);
                            continue;
                        }
                        field.adjacent.push_back(universe.fields[parent_name]);
                    }
                    == == == = Hjson::Value WriteFields(Universe & universe) {
                        Hjson::Value all_fields;
                        for (Node field_node : universe.nodes<components::science::Field>()) {
                            Hjson::Value field_hjson;
                            field_hjson["name"] = field_node.get<components::Name>().name;
                            field_hjson["identifier"] = field_node.get<components::Identifier>().identifier;
                            if (field_node.any_of<components::Description>()) {
                                field_hjson["description"] = field_node.get<components::Description>().description;
                            }

                            auto& field = field_node.get<components::science::Field>();
                            if (!field.adjacent.empty()) {
                                // Add all the entities
                                Hjson::Value adj_list;
                                for (entt::entity adj : field.adjacent) {
                                    auto& identifier = universe.get<components::Identifier>(adj);
                                    adj_list.push_back(identifier.identifier);
>>>>>>> pr-303
                                }
                                universe.clear<FieldTemplate>();
                            }
<<<<<<< HEAD

                            Hjson::Value WriteFields(Universe & universe) {
                                Hjson::Value all_fields;
<<<<<<< HEAD:src/common/loading/fields.cpp
                                for (Node field_node : universe.nodes<components::science::Field>()) {
                                    Hjson::Value field_hjson;
                                    field_hjson["name"] = field_node.get<components::Name>().name;
                                    field_hjson["identifier"] = field_node.get<components::Identifier>().identifier;
                                    if (field_node.any_of<components::Description>()) {
                                        field_hjson["description"] =
                                            field_node.get<components::Description>().description;
                                    }

                                    auto& field = field_node.get<components::science::Field>();
                                    == == == = for (entity entity : universe.view<Field>()) {
                                        Hjson::Value field_hjson;
                                        field_hjson["name"] = universe.get<Name>(entity).name;
                                        field_hjson["identifier"] = universe.get<Identifier>(entity).identifier;
                                        if (universe.any_of<Description>(entity)) {
                                            field_hjson["description"] = universe.get<Description>(entity).description;
                                        }

                                        Field& field = universe.get<Field>(entity);
>>>>>>> pr_254:src/common/systems/science/fields.cpp
                                        if (!field.adjacent.empty()) {
                                            // Add all the entities
                                            Hjson::Value adj_list;
                                            for (entt::entity adj : field.adjacent) {
                                                auto& identifier = universe.get<Identifier>(adj);
                                                adj_list.push_back(identifier.identifier);
                                            }
                                            field_hjson["adjacent"] = adj_list;
                                        }
                                        if (!field.parents.empty()) {
                                            // Add all the entities
                                            Hjson::Value adj_list;
<<<<<<< HEAD:src/common/loading/fields.cpp
                                            for (Node adj : field_node.Convert(field.parents)) {
                                                auto& identifier = adj.get<components::Identifier>();
                                                == == == = for (entt::entity adj : field.parents) {
                                                    auto& identifier = universe.get<Identifier>(adj);
>>>>>>> pr_254:src/common/systems/science/fields.cpp
                                                    adj_list.push_back(identifier.identifier);
                                                }
                                                field_hjson["parent"] = adj_list;
                                            }
                                            all_fields.push_back(field_hjson);
                                        }
                                        return all_fields;
                                    }
                                }  // namespace cqsp::common::loading
                                == == == = if (!field.parents.empty()) {
                                    // Add all the entities
                                    Hjson::Value adj_list;
                                    for (Node adj : field_node.Convert(field.parents)) {
                                        auto& identifier = adj.get<components::Identifier>();
                                        adj_list.push_back(identifier.identifier);
                                    }
                                    field_hjson["parent"] = adj_list;
                                }
                                all_fields.push_back(field_hjson);
                            }
                            return all_fields;
                        }
                    }  // namespace cqsp::common::loading
>>>>>>> pr-303
