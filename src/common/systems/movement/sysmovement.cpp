#include "sysmovement.h"

#include <math.h>

#include "common/components/movement.h"
#include "common/components/ships.h"
#include "common/components/units.h"
<<<<<<< HEAD == == == =
#include "common/actions/maneuver/commands.h"
#include "common/util/nameutil.h"
    >>>>>>> pr - 292

<<<<<<< HEAD
<<<<<<< HEAD void conquerspace::common::systems::SysOrbit::DoSystem(components::Universe& universe) {
                namespace cqspc = conquerspace::common::components;
namespace cqsps = conquerspace::common::components::ships;
namespace cqspt = conquerspace::common::components::types;

<<<<<<< HEAD
auto bodies = universe.view<cqspt::Orbit>();
== == == = using types::Kinematics;
using bodies::Body;
using bodies::OrbitalSystem;
using types::Orbit;
== == == = namespace cqsp::common::systems {
    namespace ships = components::ships;
    namespace types = components::types;
    namespace bodies = components::bodies;

    using bodies::Body;
    using bodies::OrbitalSystem;
    using types::Kinematics;
    using types::Orbit;
>>>>>>> pr-290

    void SysOrbit::DoSystem() {
        ZoneScoped;
        Universe& universe = GetGame().GetUniverse();
        ParseOrbitTree(entt::null, GetUniverse().sun);
    }

<<<<<<< HEAD
    void SysOrbit::LeaveSOI(const entt::entity& body, entt::entity& parent, Orbit& orb, Kinematics& pos,
                            Kinematics& p_pos) {
        == == == = void SysOrbit::LeaveSOI(const entt::entity& body, entt::entity& parent, Orbit& orb, Kinematics& pos,
                                           Kinematics& p_pos) {
>>>>>>> pr-290
            // Then change parent, then set the orbit
            auto& p_orb = GetUniverse().get<Orbit>(parent);
            if (p_orb.reference_body == entt::null) {
                return;
            }
            // Then add to orbital system
            GetUniverse().get<OrbitalSystem>(p_orb.reference_body).push_back(body);

            auto& parent_parent_orb = GetUniverse().get<Body>(p_orb.reference_body);

            auto& pp_pos = GetUniverse().get<Kinematics>(p_orb.reference_body);
            // Remove from parent
            auto& pt = GetUniverse().get<OrbitalSystem>(parent);
            std::erase(pt.children, body);
            // Get velocity and change posiiton
            // Convert orbit
            orb = types::Vec3ToOrbit(pos.position + p_pos.position, pos.velocity + p_pos.velocity, parent_parent_orb.GM,
                                     GetUniverse().date.ToSecond());
            orb.reference_body = p_orb.reference_body;

            // Set new position
            pos.position = pos.position + p_pos.position;
            pos.velocity = pos.velocity + p_pos.velocity;
            // Update dirty orbit
            GetUniverse().emplace_or_replace<bodies::DirtyOrbit>(body);

            commands::ProcessCommandQueue(GetUniverse(), body, components::Trigger::OnExitSOI);
        }

        void SysOrbit::CrashObject(Orbit & orb, entt::entity body, entt::entity parent) {
            if (GetUniverse().any_of<Body>(body)) {
                return;
            }
            auto& p_bod = GetUniverse().get<Body>(parent);
            auto& pos = GetUniverse().get<Kinematics>(body);
            if (GetUniverse().any_of<ships::Crash>(body)) {
                pos.position = glm::vec3(0);
                return;
            }

            // Next time we need to account for the atmosphere
            if (glm::length(pos.position) > p_bod.radius) {
                return;
            }
            // Check if there is a command
            if (commands::ProcessCommandQueue(GetUniverse(), body, components::Trigger::OnCrash)) {
                SPDLOG_INFO("Executed maneuver on crash");
            } else {
                // Crash
                SPDLOG_INFO("Object {} collided with the ground", (uint64_t)body);
                // Then remove from the tree or something like that
                GetUniverse().get_or_emplace<ships::Crash>(body);
                GetUniverse().get_or_emplace<bodies::DirtyOrbit>(body);
                pos.position = glm::vec3(0);
                orb.semi_major_axis = 0;
            }
        }

        void SysOrbit::CalculateImpulse(types::Orbit & orb, entt::entity body, entt::entity parent) {
            if (GetUniverse().any_of<types::Impulse>(body)) {
                // Then add to the orbit the speed.
                // Then also convert the velocity
                auto& impulse = GetUniverse().get<types::Impulse>(body);
                auto reference = orb.reference_body;
                auto& pos = GetUniverse().get_or_emplace<Kinematics>(body);

                orb = types::Vec3ToOrbit(pos.position, pos.velocity + impulse.impulse, orb.GM,
                                         GetUniverse().date.ToSecond());
                orb.reference_body = reference;
                pos.position = types::toVec3(orb);
                pos.velocity = types::OrbitVelocityToVec3(orb, orb.v);
                GetUniverse().emplace_or_replace<bodies::DirtyOrbit>(body);
                // Remove impulse
                GetUniverse().remove<types::Impulse>(body);
            }
        }

        void SysOrbit::UpdateCommandQueue(Orbit & orb, entt::entity body, entt::entity parent) {
            // Process thrust before updating orbit
            if (!GetUniverse().any_of<components::CommandQueue>(body)) {
                return;
            }
            // Check if the current date is beyond the universe date
            auto& queue = GetUniverse().get<components::CommandQueue>(body);
            if (queue.maneuvers.empty()) {
                return;
            }
            auto& command = queue.maneuvers.front();
            if (command.time > GetUniverse().date.ToSecond()) {
                return;
            }
            if (GetUniverse().date.ToSecond() - command.time > Interval()) {
                SPDLOG_INFO("Negative time? {}", GetUniverse().date.ToSecond() - command.time);
            }
            // Then execute the command
            orb = types::ApplyImpulse(orb, command.delta_v, command.time);
            GetUniverse().emplace_or_replace<components::bodies::DirtyOrbit>(body);
            // Check if the next command is something, and then execute it
            queue.maneuvers.pop_front();
            // Now then executethe next command or something like that
            // Then check the command queue for more commands
            commands::ProcessCommandQueue(GetUniverse(), body, components::Trigger::OnManeuver);
        }

        void SysOrbit::ParseOrbitTree(entt::entity parent, entt::entity body) {
<<<<<<< HEAD
            == == == =

>>>>>>> pr-290
                         if (!GetUniverse().valid(body)) {
                return;
            }

            auto& orb = GetUniverse().get<types::Orbit>(body);

            UpdateCommandQueue(orb, body, parent);

            types::UpdateOrbit(orb, GetUniverse().date.ToSecond());
            auto& pos = GetUniverse().get_or_emplace<types::Kinematics>(body);
            if (GetUniverse().any_of<types::SetTrueAnomaly>(body)) {
                orb.v = GetUniverse().get<types::SetTrueAnomaly>(body).true_anomaly;
                // Set new mean anomaly at epoch
                GetUniverse().remove<types::SetTrueAnomaly>(body);
            }
            pos.position = types::toVec3(orb);
            pos.velocity = types::OrbitVelocityToVec3(orb, orb.v);

            if (parent != entt::null) {
                auto& p_pos = GetUniverse().get_or_emplace<types::Kinematics>(parent);
                // If distance is above SOI, then be annoyed
                auto& p_bod = GetUniverse().get<components::bodies::Body>(parent);
                if (glm::length(pos.position) > p_bod.SOI) {
                    LeaveSOI(body, parent, orb, pos, p_pos);
                }

                CrashObject(orb, body, parent);

                CalculateImpulse(orb, body, parent);
                pos.center = p_pos.center + p_pos.position;
                if (EnterSOI(parent, body)) {
                    SPDLOG_INFO("Entered SOI");
                }
            }

            auto& future_pos = GetUniverse().get_or_emplace<types::FuturePosition>(body);
            future_pos.position =
                types::OrbitTimeToVec3(orb, GetUniverse().date.ToSecond() + components::StarDate::TIME_INCREMENT);
            future_pos.center = pos.center;

            if (!GetUniverse().any_of<components::bodies::OrbitalSystem>(body)) {
                return;
            }
            for (entt::entity entity : GetUniverse().get<components::bodies::OrbitalSystem>(body).children) {
                // Calculate position
                ParseOrbitTree(body, entity);
            }
        }

        void SysSurface::DoSystem() {
            Universe& universe = GetGame().GetUniverse();

            auto objects = GetUniverse().view<types::SurfaceCoordinate>();
            // First put them in a tree
            // Find all the entities
            for (entt::entity object : objects) {
                types::SurfaceCoordinate& surface = GetUniverse().get<types::SurfaceCoordinate>(object);
                //types::Kinematics& surfacekin = universe.get_or_emplace<types::Kinematics>(object);
                //types::Kinematics& center = universe.get<types::Kinematics>(surface.planet);
                glm::vec3 anglevec = types::toVec3(surface);
                // Get planet radius
                //surfacekin.position = (anglevec * surface.radius + center.position);
            }
        }

        void SysPath::DoSystem() {
            ZoneScoped;

            Universe& universe = GetUniverse();

            auto bodies = universe.view<types::MoveTarget, Kinematics>(entt::exclude<Orbit>);
<<<<<<< HEAD
>>>>>>> pr-292
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
        void conquerspace::common::systems::SysPath::DoSystem(components::Universe & universe) {
            namespace cqspc = conquerspace::common::components;
            namespace cqsps = conquerspace::common::components::ships;
            namespace cqspt = conquerspace::common::components::types;
            == == == = for (entt::entity body : bodies) {
                Kinematics& bodykin = universe.get<Kinematics>(body);
                Kinematics& targetkin = universe.get<Kinematics>(GetUniverse().get<types::MoveTarget>(body).target);
                glm::vec3 path = targetkin.position - bodykin.position;
            }
        }

        bool SysOrbit::EnterSOI(const entt::entity& parent, const entt::entity& body) {
            // We should ignore bodies
            if (GetUniverse().any_of<Body>(body)) {
                return false;
            }
            SPDLOG_TRACE("Calculating SOI entrance for {} in {}", util::GetName(universe, body),
                         util::GetName(universe, parent));

            if (!GetUniverse().all_of<Kinematics, Orbit>(body)) {
                return false;
            }
            auto& pos = GetUniverse().get<Kinematics>(body);
            auto& orb = GetUniverse().get<Orbit>(body);
            // Check parents for SOI if we're intersecting with anything
            auto& o_system = GetUniverse().get<OrbitalSystem>(parent);
>>>>>>> pr-290

<<<<<<< HEAD
            auto bodies = universe.view<cqspt::MoveTarget>(entt::exclude<cqspt::Orbit>);
            for (entt::entity body : bodies) {
                cqspt::Kinematics& bodykin = universe.get<cqspt::Kinematics>(body);
                cqspt::Kinematics& targetkin =
                    universe.get<cqspt::Kinematics>(universe.get<cqspt::MoveTarget>(body).targetent);

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

                        orb = types::Vec3ToOrbit(pos.position, pos.velocity + impulse.impulse, orb.GM,
                                                 universe.date.ToSecond());
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
                                orb = types::Vec3ToOrbit(pos.position - kinematics.position,
                                                         pos.velocity - kinematics.velocity, body_comp.GM,
                                                         universe.date.ToSecond());
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
                        future_pos.position = types::OrbitTimeToVec3(
                            orb, universe.date.ToSecond() + components::StarDate::TIME_INCREMENT);
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
                            Kinematics& targetkin =
                                universe.get<Kinematics>(universe.get<types::MoveTarget>(body).target);
                            glm::vec3 path = targetkin.position - bodykin.position;
                        }
                    }
>>>>>>> pr_254
                    == == == = for (entt::entity entity : o_system.children) {
                        // Get the stuff
                        if (entity == body) {
                            continue;
                        }
                        // Check the distance
                        if (!GetUniverse().all_of<Body, Kinematics>(entity)) {
                            continue;
                        }
                        const auto& body_comp = GetUniverse().get<Body>(entity);
                        const auto& target_position = GetUniverse().get<Kinematics>(entity);
                        if (glm::distance(target_position.position, pos.position) <= body_comp.SOI) {
                            // Calculate position
                            orb = types::Vec3ToOrbit(pos.position - target_position.position,
                                                     pos.velocity - target_position.velocity, body_comp.GM,
                                                     GetUniverse().date.ToSecond());
                            orb.reference_body = entity;
                            // Calculate position, and change the thing
                            pos.position = types::toVec3(orb);
                            pos.velocity = types::OrbitVelocityToVec3(orb, orb.v);
                            // Then change SOI
                            GetUniverse().get_or_emplace<OrbitalSystem>(entity).push_back(body);
                            auto& vec = GetUniverse().get<OrbitalSystem>(parent).children;
                            vec.erase(std::remove(vec.begin(), vec.end(), body), vec.end());
                            GetUniverse().emplace_or_replace<bodies::DirtyOrbit>(body);
                            // I have a bad feeling about this
                            commands::ProcessCommandQueue(GetUniverse(), body, components::Trigger::OnEnterSOI);
                            return true;
                        }
                        // Now check if it's intersecting with any things outside of stuff
                        if (parent == GetUniverse().sun) {
                            continue;
                        }
                    }
                    return false;
                }
<<<<<<< HEAD
            }  // namespace cqsp::common::systems
>>>>>>> pr-292
            == == == =
                         // Check the distance
                if (!GetUniverse().all_of<Body, Kinematics>(entity)) {
                continue;
            }
            const auto& body_comp = GetUniverse().get<Body>(entity);
            const auto& target_position = GetUniverse().get<Kinematics>(entity);
            if (glm::distance(target_position.position, pos.position) <= body_comp.SOI) {
                // Calculate position
                orb =
                    types::Vec3ToOrbit(pos.position - target_position.position, pos.velocity - target_position.velocity,
                                       body_comp.GM, GetUniverse().date.ToSecond());
                orb.reference_body = entity;
                // Calculate position, and change the thing
                pos.position = types::toVec3(orb);
                pos.velocity = types::OrbitVelocityToVec3(orb, orb.v);
                // Then change SOI
                GetUniverse().get_or_emplace<OrbitalSystem>(entity).push_back(body);
                auto& vec = GetUniverse().get<OrbitalSystem>(parent).children;
                vec.erase(std::remove(vec.begin(), vec.end(), body), vec.end());
                GetUniverse().emplace_or_replace<bodies::DirtyOrbit>(body);
                // I have a bad feeling about this
                commands::ProcessCommandQueue(GetUniverse(), body, commands::Trigger::OnEnterSOI);
                return true;
            }
            // Now check if it's intersecting with any things outside of stuff
            if (parent == GetUniverse().sun) {
                continue;
            }
        }
        return false;
    }
}  // namespace cqsp::common::systems
>>>>>>> pr-290
