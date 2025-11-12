#include "common/systems/actions/shiplaunchaction.h"

#include "common/components/bodies.h"
#include "common/components/movement.h"
#include "common/components/ships.h"

<<<<<<< HEAD entt::entity cqsp::common::systems::actions::CreateShip(cqsp::common::Universe& universe, entt::entity civ,
                                                          entt::entity orbit, entt::entity starsystem) {
    namespace cqspt = cqsp::common::components::types;
    namespace cqsps = cqsp::common::components::ships;
    namespace cqspb = cqsp::common::components::bodies;
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
