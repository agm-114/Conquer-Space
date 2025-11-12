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
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "common/actions/factoryconstructaction.h"
#include "common/components/area.h"
#include "common/components/market.h"
#include "common/components/resource.h"
<<<<<<< HEAD:test/common/components/factoryconstruct_test.cpp == == == =
#include "common/actions/factoryconstructaction.h"
               >>>>>>> pr-292:test/common/components/factoryconstructtest.cpp
#include "common/universe.h"

    TEST(FactoryConstuctTest, ConstructTest) {
    // Create universe and recipe to generate
    cqsp::common::Universe universe;
    cqsp::common::Node city(universe);
    cqsp::common::Node recipe(universe);
    city.emplace<cqsp::common::components::IndustrialZone>();
    auto& recipe_comp = recipe.emplace<cqsp::common::components::Recipe>();
    recipe_comp.workers = 10;
    recipe_comp.type = cqsp::common::components::factory;
<<<<<<< HEAD:test/common/components/factoryconstruct_test.cpp
    cqsp::common::Node factory = cqsp::common::actions::CreateFactory(city, recipe, 10);
    == == == = entt::entity factory = cqsp::common::actions::CreateFactory(universe, city, recipe, 10);
>>>>>>> pr-292:test/common/components/factoryconstructtest.cpp
    // Ensure that it has everything
    ASSERT_TRUE(factory.any_of<cqsp::common::components::Employer>());
    ASSERT_EQ(factory.get<cqsp::common::components::Employer>().population_needed, 10 * 10);
}

TEST(FactoryConstuctTest, ConstructExpectNoCrash) {
    cqsp::common::Universe universe;
<<<<<<< HEAD:test/common/components/factoryconstruct_test.cpp
    cqsp::common::Node city(universe);
    cqsp::common::Node recipe(universe);
    cqsp::common::Node null_node(universe, entt::null);
    EXPECT_TRUE(cqsp::common::actions::CreateFactory(null_node, null_node, 0) == entt::null);
    EXPECT_TRUE(cqsp::common::actions::CreateFactory(city, null_node, 0) == entt::null);
    EXPECT_TRUE(cqsp::common::actions::CreateFactory(null_node, recipe, 0) == entt::null);
    == == == = cqsp::common::actions::CreateFactory(universe, entt::null, entt::null, 0);
    cqsp::common::actions::CreateFactory(universe, universe.create(), entt::null, 0);
    cqsp::common::actions::CreateFactory(universe, entt::null, universe.create(), 0);
>>>>>>> pr-292:test/common/components/factoryconstructtest.cpp
}
