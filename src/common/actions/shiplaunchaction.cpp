<<<<<<< HEAD
=======
<<<<<<<< HEAD:src/common/systems/actions/shiplaunchaction.cpp
#include "common/systems/actions/shiplaunchaction.h"
========
>>>>>>> pr-292
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
#include "common/actions/shiplaunchaction.h"
<<<<<<< HEAD

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <string>

#include "common/components/bodies.h"
#include "common/components/coordinates.h"
#include "common/components/name.h"
#include "common/components/orbit.h"
#include "common/components/organizations.h"
#include "common/components/ships.h"

=======
>>>>>>>> pr-292:src/common/actions/shiplaunchaction.cpp

#include "common/components/bodies.h"
#include "common/components/movement.h"
#include "common/components/ships.h"

<<<<<<<< HEAD:src/common/systems/actions/shiplaunchaction.cpp
<<<<<<< HEAD entt::entity cqsp::common::systems::actions::CreateShip(cqsp::common::Universe& universe, entt::entity civ,
                                                          entt::entity orbit, entt::entity starsystem) {
    namespace cqspt = cqsp::common::components::types;
    namespace cqsps = cqsp::common::components::ships;
    namespace cqspb = cqsp::common::components::bodies;
========
>>>>>>> pr-292
namespace cqsp::common::actions {

namespace types = components::types;
namespace ships = components::ships;
namespace bodies = components::bodies;

using ships::Ship;

<<<<<<< HEAD
Node CreateShip(Node& starsystem, Node& fleet, const glm::vec3& orbit, const std::string& shipName) {
    Node ship(fleet.universe());
    ship.emplace<Ship>();

    auto& position = ship.emplace<types::Kinematics>();
    // Get planet position
    position.position = orbit;
    //universe.get<cqspb::StarSystem>(starsystemEnt).bodies.push_back(ship);
    // Set name
    if (shipName.empty()) {
        ship.emplace<components::Name>(fmt::format("Ship {}", ship));

    } else {
        ship.emplace<components::Name>(shipName);
    }
    // Set in fleet
    if (fleet.all_of<components::ships::Fleet>()) fleet.get<components::ships::Fleet>().ships.push_back(ship);

    return ship;
}

Node CreateShip(Node& starsystem, Node& fleet, Node& orbit, const std::string& shipName) {
    return CreateShip(starsystem, fleet, orbit.get<types::Orbit>(), shipName);
}

Node CreateShip(Node& starsystem, Node& fleet, const components::types::Orbit& orbit, const std::string& shipName) {
    return CreateShip(starsystem, fleet, types::toVec3AU(orbit), shipName);
}

entt::entity LaunchShip(Universe& universe, const components::types::Orbit& orbit) {
=======
entt::entity CreateShip(Universe& universe, entt::entity civEnt, const glm::vec3& orbit, entt::entity starsystem) {

>>>>>>>> pr-292:src/common/actions/shiplaunchaction.cpp
    entt::entity ship = universe.create();
    universe.emplace<cqsps::Ship>(ship);

    auto& position = universe.emplace<cqspt::Kinematics>(ship);

    // Get planet position
    position.postion = cqspt::tovec3(universe.get<cqspt::Orbit>(orbit));
    universe.get<cqspb::StarSystem>(starsystem).bodies.push_back(ship);
    == == == = namespace components = cqsp::common::components;

    namespace types = components::types;
    namespace ships = components::ships;
    namespace bodies = components::bodies;
    using bodies::Body;
    using ships::Ship;
    using types::Kinematics;
    using types::Orbit;
    using types::toVec3AU;

    using entt::entity;

    namespace cqsp::common::systems::actions {
    entity CreateShip(Universe& universe, entity civEnt, const glm::vec3& orbit, entity starsystem) {
        entity ship = universe.create();
        universe.emplace<Ship>(ship);

        auto& position = universe.emplace<Kinematics>(ship);

        // Get planet position
        position.position = orbit;
        //universe.get<cqspb::StarSystem>(starsystem).bodies.push_back(ship);
        // Set name
        universe.emplace<components::Name>(ship, fmt::format("Ship {}", ship));
        return ship;
    }

    entity CreateShip(Universe& universe, entity civ, entity orbit, entity starsystem) {
        return CreateShip(universe, civ, types::toVec3AU(universe.get<Orbit>(orbit)), starsystem);
    }

    entity CreateShip(Universe& universe, entity fleetEnt, entity starsystemEnt, const glm::vec3& orbit,
                      const std::string& shipName) {
        entity ship = universe.create();
        universe.emplace<Ship>(ship);

<<<<<<<< HEAD:src/common/systems/actions/shiplaunchaction.cpp
        auto& position = universe.emplace<Kinematics>(ship);
        // Get planet position
        position.position = orbit;
        //universe.get<cqspb::StarSystem>(starsystemEnt).bodies.push_back(ship);
        // Set name
        universe.emplace<components::Name>(ship, shipName);
        // Set in fleet
        universe.get<ships::Fleet>(fleetEnt).ships.push_back(ship);

        return ship;
    }

    entity CreateShip(Universe& universe, entity fleetEnt, entity starsystemEnt, entity orbitEnt,
                      const std::string& shipName) {
        return CreateShip(universe, fleetEnt, starsystemEnt, toVec3AU(universe.get<Orbit>(orbitEnt)), shipName);
    }

    entity LaunchShip(Universe& universe, Orbit& orbit) {
        // Set the orbit
        entity ship = universe.create();
        universe.emplace<Ship>(ship);
        // Now do things
        auto& o = universe.emplace<Orbit>(ship, orbit);
        universe.emplace<Kinematics>(ship);
        auto& body = universe.get<Body>(orbit.reference_body);
        o.GM = body.GM;
        universe.get<bodies::OrbitalSystem>(orbit.reference_body).push_back(ship);
>>>>>>> pr_254
        return ship;
        return entt::entity();
    }
    }  // namespace cqsp::common::systems::actions
========
>>>>>>> pr-292
    entt::entity ship = universe.create();
    universe.emplace<Ship>(ship);
    // Now do things
    auto& o = universe.emplace<types::Orbit>(ship, orbit);
    universe.emplace<types::Kinematics>(ship);
    auto& body = universe.get<bodies::Body>(orbit.reference_body);
    o.GM = body.GM;
    universe.get<bodies::OrbitalSystem>(orbit.reference_body).push_back(ship);
    return ship;
}
}  // namespace cqsp::common::actions
<<<<<<< HEAD
=======
>>>>>>>> pr-292:src/common/actions/shiplaunchaction.cpp
>>>>>>> pr-292
