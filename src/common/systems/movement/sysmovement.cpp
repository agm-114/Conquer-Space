#include "sysmovement.h"

#include <math.h>

#include "common/components/movement.h"
#include "common/components/ships.h"
#include "common/components/units.h"

<<<<<<< HEAD void conquerspace::common::systems::SysOrbit::DoSystem(components::Universe& universe) {
    namespace cqspc = conquerspace::common::components;
    namespace cqsps = conquerspace::common::components::ships;
    namespace cqspt = conquerspace::common::components::types;

    auto bodies = universe.view<cqspt::Orbit>();
    for (entt::entity body : bodies) {
<<<<<<< HEAD
        auto& orb = cqspt::updateOrbit(universe.get<cqspt::Orbit>(body));
        == == == =
                     // Disable orbits for now
            auto& orb = cqspt::updateOrbit(universe.get<cqspt::Orbit>(body));
>>>>>>> pr_28
        cqspt::updatePos(universe.get<cqspt::Kinematics>(body), orb);
    }
}

int conquerspace::common::systems::SysOrbit::Interval() { return 1; }

<<<<<<< HEAD
void conquerspace::common::systems::SysPath::DoSystem(components::Universe& universe) {
    namespace cqspc = conquerspace::common::components;
    namespace cqsps = conquerspace::common::components::ships;
    namespace cqspt = conquerspace::common::components::types;

    auto bodies = universe.view<cqspt::MoveTarget>(entt::exclude<cqspt::Orbit>);
    for (entt::entity body : bodies) {
        cqspt::Kinematics& bodykin = universe.get<cqspt::Kinematics>(body);
        cqspt::Kinematics& targetkin = universe.get<cqspt::Kinematics>(universe.get<cqspt::MoveTarget>(body).targetent);

        glm::vec3 path = targetkin.postion - bodykin.postion;
        if (glm::distance(targetkin.postion, bodykin.postion) < bodykin.topspeed) {
            bodykin.postion = targetkin.postion;
            bodykin.velocity = glm::vec3(0, 0, 0);
        } else {
            bodykin.velocity = bodykin.topspeed * glm::normalize(path);
            == == == = void cqsp::common::systems::SysSurface::DoSystem(Universe & universe) {
                namespace cqspc = cqsp::common::components;
                namespace cqsps = cqsp::common::components::ships;
                namespace cqspt = cqsp::common::components::types;

                auto objects = universe.view<cqspt::SurfaceCoordinate>();
                for (entt::entity object : objects) {
                    cqspt::SurfaceCoordinate& surface = universe.get<cqspt::SurfaceCoordinate>(object);
                    cqspt::Kinematics& surfacekin = universe.get<cqspt::Kinematics>(object);
                    cqspt::Kinematics& center = universe.get<cqspt::Kinematics>(surface.planet);
                    glm::vec3 anglevec =
                        glm::vec3(cos(surface.latitude) * cos(surface.longitude),
                                  cos(surface.latitude) * sin(surface.longitude), sin(surface.latitude));
                    surfacekin.postion = (anglevec * surface.radius + center.postion);
                }
            }

            int cqsp::common::systems::SysSurface::Interval() { return SysOrbit().Interval(); }

            void cqsp::common::systems::SysPath::DoSystem(Universe & universe) {
                namespace cqspc = cqsp::common::components;
                namespace cqsps = cqsp::common::components::ships;
                namespace cqspt = cqsp::common::components::types;

                auto bodies = universe.view<cqspt::MoveTarget, cqspt::Kinematics>(entt::exclude<cqspt::Orbit>);
                for (entt::entity body : bodies) {
                    cqspt::Kinematics& bodykin = universe.get<cqspt::Kinematics>(body);
                    cqspt::Kinematics targetkin =
                        universe.get<cqspt::Kinematics>(universe.get<cqspt::MoveTarget>(body).target);
                    glm::vec3 path = targetkin.postion - bodykin.postion;
                    if (glm::length(path) < bodykin.topspeed) {
                        bodykin.postion = targetkin.postion;
                    } else {
                        bodykin.postion += (targetkin.topspeed * glm::normalize(path));
>>>>>>> pr_28
                    }
                    cqspt::updatePos(universe.get<cqspt::Kinematics>(body));
                }
            }

<<<<<<< HEAD
            int conquerspace::common::systems::SysPath::Interval() { return 1; }

            void conquerspace::common::systems::SysMove::DoSystem(components::Universe & universe) {
                namespace cqspc = conquerspace::common::components;
                namespace cqsps = conquerspace::common::components::ships;
                namespace cqspt = conquerspace::common::components::types;
            }
            == == == = int cqsp::common::systems::SysPath::Interval() { return 1; }


>>>>>>> pr_28
            == == == = namespace components = cqsp::common::components;
            namespace ships = components::ships;
            namespace types = components::types;
            namespace bodies = components::bodies;
            namespace systems = cqsp::common::systems;
            using bodies::Body;
            using bodies::DirtyOrbit;
            using bodies::OrbitalSystem;
            using components::CommandQueue;
            using entt::entity;
            using systems::SysOrbit;
            using systems::SysPath;
            using systems::SysSurface;
            using types::Impulse;
            using types::Kinematics;
            using types::Orbit;
            using types::SurfaceCoordinate;

            void SysOrbit::DoSystem() {
                ZoneScoped;
                Universe& universe = GetGame().GetUniverse();
                ParseOrbitTree(entt::null, universe.sun);
            }

            namespace cqsp::common::systems {

            void LeaveSOI(Universe& universe, const entity& body, entity& parent, Orbit& orb, Kinematics& pos,
                          Kinematics& p_pos) {
                // Then change parent, then set the orbit
                auto& p_orb = universe.get<Orbit>(parent);
                if (p_orb.reference_body == entt::null) {
                    return;
                }
                // Then add to orbital system
                universe.get<OrbitalSystem>(p_orb.reference_body).push_back(body);

                auto& parent_parent_orb = universe.get<Body>(p_orb.reference_body);

                auto& pp_pos = universe.get<Kinematics>(p_orb.reference_body);
                // Remove from parent
                auto& pt = universe.get<OrbitalSystem>(parent);
                std::erase(pt.children, body);
                // Get velocity and change posiiton
                // Convert orbit
                orb = types::Vec3ToOrbit(pos.position + p_pos.position, pos.velocity + p_pos.velocity,
                                         parent_parent_orb.GM, universe.date.ToSecond());
                orb.reference_body = p_orb.reference_body;

                // Update dirty orbit
                universe.emplace_or_replace<DirtyOrbit>(body);
            }

            /// <summary>
            /// Check if the entity has crashed into its parent object
            /// </summary>
            /// <param name="universe"></param>
            /// <param name="orb"></param>
            /// <param name="body"></param>
            /// <param name="parent"></param>
            void CrashObject(Universe& universe, Orbit& orb, entity body, entity parent) {
                if (universe.any_of<Body>(parent)) {
                    return;
                }
                auto& p_bod = universe.get<Body>(parent);
                auto& pos = universe.get<Kinematics>(body);
                if (universe.any_of<ships::Crash>(body)) {
                    pos.position = glm::vec3(0);
                }

                // Next time we need to account for the atmosphere
                if (glm::length(pos.position) <= p_bod.radius) {
                    // Crash
                    SPDLOG_INFO("Object {} collided with the ground", body);
                    // Then remove from the tree or something like that
                    universe.get_or_emplace<components::ships::Crash>(body);
                    pos.position = glm::vec3(0);
                    orb.semi_major_axis = 0;
                }
            }

            void CalculateImpulse(Universe& universe, Orbit& orb, entity body, entity parent) {
                if (!universe.any_of<Impulse>(body)) {
                    return;
                }
                // Then add to the orbit the speed.
                // Then also convert the velocity
                Impulse& impulse = universe.get<Impulse>(body);
                auto reference = orb.reference_body;
                auto& pos = universe.get_or_emplace<Kinematics>(body);

                orb =
                    types::Vec3ToOrbit(pos.position, pos.velocity + impulse.impulse, orb.GM, universe.date.ToSecond());
                orb.reference_body = reference;
                pos.position = types::toVec3(orb);
                pos.velocity = OrbitVelocityToVec3(orb, orb.v);
                universe.emplace_or_replace<DirtyOrbit>(body);
                // Remove impulse
                universe.remove<Impulse>(body);
            }

            void UpdateCommandQueue(Universe& universe, Orbit& orb, entity body, entity parent) {
                // Process thrust before updating orbit
                if (!universe.any_of<CommandQueue>(body)) {
                    return;
                }
                // Check if the current date is beyond the universe date
                auto& queue = universe.get<CommandQueue>(body);
                if (queue.commands.empty()) {
                    return;
                }
                auto& command = queue.commands.front();
                if (command.time > universe.date.ToSecond()) {
                    return;
                }
                // Then execute the command
                orb = types::ApplyImpulse(orb, command.delta_v, command.time);
                universe.emplace_or_replace<DirtyOrbit>(body);
                queue.commands.pop_front();
            }

            bool EnterSOI(Universe& universe, const entity& parent, const entity& body) {
                // We should ignore bodies
                if (universe.any_of<Body>(body)) {
                    return false;
                }
                SPDLOG_TRACE("Calculating SOI entrance for {} in {}", util::GetName(universe, body),
                             util::GetName(universe, parent));

                auto& pos = universe.get<Kinematics>(body);
                auto& orb = universe.get<Orbit>(body);
                // Check parents for SOI if we're inters ecting with anything
                auto& o_system = universe.get<OrbitalSystem>(parent);

                for (entt::entity child : o_system.children) {
                    // Get the stuff
                    if (child == body) {
                        continue;
                    }
                    // Check the distance
                    if (!universe.all_of<Body, Kinematics>(child)) {
                        continue;
                    }
                    const Body& body_comp = universe.get<Body>(child);
                    const auto& kinematics = universe.get<Kinematics>(child);
                    if (glm::distance(kinematics.position, pos.position) <= body_comp.SOI) {
                        // Calculate position
                        orb = types::Vec3ToOrbit(pos.position - kinematics.position, pos.velocity - kinematics.velocity,
                                                 body_comp.GM, universe.date.ToSecond());
                        orb.reference_body = child;
                        // Calculate position, and change the thing
                        pos.position = types::toVec3(orb);
                        pos.velocity = types::OrbitVelocityToVec3(orb, orb.v);
                        // Then change SOI
                        universe.get_or_emplace<OrbitalSystem>(child).push_back(body);
                        auto& vec = universe.get<OrbitalSystem>(parent).children;
                        vec.erase(std::remove(vec.begin(), vec.end(), body), vec.end());
                        universe.emplace_or_replace<DirtyOrbit>(body);
                        return true;
                    }
                    // Now check if it's intersecting with any things outside of stuff
                    if (parent == universe.sun) {
                        continue;
                    }
                }
                return false;
            }
            }  // namespace cqsp::common::systems

            void SysOrbit::ParseOrbitTree(entity parent, entity body) {
                Universe& universe = GetGame().GetUniverse();
                if (!universe.valid(body)) {
                    return;
                }

                auto& orb = universe.get<Orbit>(body);

                UpdateCommandQueue(universe, orb, body, parent);

                types::UpdateOrbit(orb, universe.date.ToSecond());
                auto& pos = universe.get_or_emplace<Kinematics>(body);
                pos.position = toVec3(orb);
                pos.velocity = OrbitVelocityToVec3(orb, orb.v);

                if (parent != entt::null) {
                    auto& p_pos = universe.get_or_emplace<Kinematics>(parent);
                    // If distance is above SOI, then be annoyed
                    auto& p_bod = universe.get<Body>(parent);
                    if (glm::length(pos.position) > p_bod.SOI) {
                        LeaveSOI(universe, body, parent, orb, pos, p_pos);
                    }

                    CrashObject(universe, orb, body, parent);

                    CalculateImpulse(universe, orb, body, parent);
                    pos.center = p_pos.center + p_pos.position;
                    if (EnterSOI(universe, parent, body)) {
                        SPDLOG_INFO("Entered SOI");
                    }
                }

                auto& future_pos = universe.get_or_emplace<types::FuturePosition>(body);
                future_pos.position =
                    types::OrbitTimeToVec3(orb, universe.date.ToSecond() + components::StarDate::TIME_INCREMENT);
                future_pos.center = pos.center;

                if (!universe.any_of<OrbitalSystem>(body)) {
                    return;
                }
                for (entity entity : universe.get<OrbitalSystem>(body).children) {
                    // Calculate position
                    ParseOrbitTree(body, entity);
                }
            }

            void SysSurface::DoSystem() {
                Universe& universe = GetGame().GetUniverse();

                auto objects = universe.view<SurfaceCoordinate>();
                // First put them in a tree
                // Find all the entities
                for (entity object : objects) {
                    SurfaceCoordinate& surface = universe.get<SurfaceCoordinate>(object);
                    //cqspt::Kinematics& surfacekin = universe.get_or_emplace<cqspt::Kinematics>(object);
                    //cqspt::Kinematics& center = universe.get<cqspt::Kinematics>(surface.planet);
                    glm::vec3 anglevec = types::toVec3(surface);
                    // Get planet radius
                    //surfacekin.position = (anglevec * surface.radius + center.position);
                }
            }

            void SysPath::DoSystem() {
                ZoneScoped;
                Universe& universe = GetUniverse();

                auto bodies = universe.view<types::MoveTarget, Kinematics>(entt::exclude<Orbit>);
                for (entity body : bodies) {
                    Kinematics& bodykin = universe.get<Kinematics>(body);
                    Kinematics& targetkin = universe.get<Kinematics>(universe.get<types::MoveTarget>(body).target);
                    glm::vec3 path = targetkin.position - bodykin.position;
                }
            }
>>>>>>> pr_254
