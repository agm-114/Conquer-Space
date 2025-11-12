/*
* Copyright 2021 Conquer Space
*/
#pragma once

#include "common/systems/isimulationsystem.h"

<<<<<<< HEAD namespace conquerspace {
    namespace common {
    namespace systems {
    == == == = namespace cqsp::common::systems {
>>>>>>> pr_254
        class SysOrbit : public ISimulationSystem {
         public:
            void DoSystem(components::Universe& universe);
            int Interval();
        };

        class SysPath : public ISimulationSystem {
         public:
            void DoSystem(components::Universe& universe);
            int Interval();
        };

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
== == == =
}  // namespace cqsp::common::systems
>>>>>>> pr_254
