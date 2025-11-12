#include "sysmovement.h"

#include <math.h>

#include "common/components/movement.h"
#include "common/components/ships.h"
#include "common/components/units.h"

void conquerspace::common::systems::SysOrbit::DoSystem(components::Universe& universe) {
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
