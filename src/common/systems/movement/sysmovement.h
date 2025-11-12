/*
* Copyright 2021 Conquer Space
*/
#pragma once

#include "common/systems/isimulationsystem.h"

<<<<<<< HEAD
<<<<<<< HEAD namespace conquerspace { namespace common {namespace systems { == == == = namespace cqsp::common::systems {
>>>>>>> pr_254
    class SysOrbit : public ISimulationSystem {
 public:
    void DoSystem(components::Universe& universe);
    int Interval();
};

class SysPath : public ISimulationSystem {
    == == == = namespace cqsp::common::systems {
        class SysOrbit : public ISimulationSystem {
>>>>>>> pr-283
         public:
            void DoSystem(components::Universe& universe);
            int Interval();
        };

<<<<<<< HEAD
<<<<<<< HEAD
        class SysMove : public ISimulationSystem {
         public:
            void DoSystem(components::Universe& universe);
        };
<<<<<<< HEAD
    }  // namespace systems
}  // namespace common
}  // namespace conquerspace
== == == = class SysSurface : public ISimulationSystem {
 public:
    void DoSystem(Universe& universe);
    int Interval();
};
}
}
}
>>>>>>> pr_28
== == == = == == == =
                        /// <summary>
    /// Sets the SOI of the entity to the parent
    /// </summary>
    /// <param name="universe"></param>
    /// <param name="body">Needs to have a Body and Orbit parameter</param>
    /// <param name="ppos">Parent position</param>
    void LeaveSOI(const entt::entity& body, entt::entity& parent, components::types::Orbit& orb,
                  components::types::Kinematics& pos, components::types::Kinematics& p_pos);

/// <summary>
/// Change the current body's SOI into a child SOI
/// </summary>
/// <param name="universe"></param>
/// <param name="parent"></param>
/// <param name="body">Body that we want to check if it's entering a SOI</param>
bool EnterSOI(const entt::entity& parent, const entt::entity& body);

/// <summary>
/// Check if the entity has crashed into its parent object
/// </summary>
/// <param name="universe"></param>
/// <param name="orb"></param>
/// <param name="body"></param>
/// <param name="parent"></param>
void CrashObject(components::types::Orbit& orb, entt::entity body, entt::entity parent);

void UpdateCommandQueue(components::types::Orbit& orb, entt::entity body, entt::entity parent);

void CalculateImpulse(components::types::Orbit& orb, entt::entity body, entt::entity parent);
}
;

class SysPath : public ISimulationSystem {
 public:
    explicit SysPath(Game& game) : ISimulationSystem(game) {}
    void DoSystem();
    int Interval() { return 1; }
};

class SysSurface : public ISimulationSystem {
 public:
    explicit SysSurface(Game& game) : ISimulationSystem(game) {}
    void DoSystem();
    int Interval() { return 1; }
};
<<<<<<< HEAD
>>>>>>> pr-290
}  // namespace cqsp::common::systems
>>>>>>> pr_254
== == == =
}  // namespace cqsp::common::systems
>>>>>>> pr-283
