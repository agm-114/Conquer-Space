/*
 * Copyright 2021 Conquer Space
*/
#pragma once

#include "client/systems/sysgui.h"

<<<<<<< HEAD namespace conquerspace { namespace client {namespace systems { == == == = namespace cqsp::client::systems {
>>>>>>> pr_254
    class SysCommand : public
    SysUserInterface {public : explicit SysCommand(conquerspace::engine::Application & app) : SysUserInterface(app) {}

                      void Init();
void DoUI(int delta_time);
void DoUpdate(int delta_time);

bool to_see = false;

<<<<<<< HEAD

private:
int selected_index = 0;
entt::entity selected_planet = entt::null;
}
;
<<<<<<< HEAD
}  // namespace systems
}  // namespace client
}  // namespace conquerspace
== == == =
}  // namespace cqsp::client::systems
>>>>>>> pr_254
== == == = private : int selected_index = 0;
entt::entity selected_planet = entt::null;
entt::entity selected_ship = entt::null;
void ShipList();
}
;
}  // namespace cqsp::client::systems
>>>>>>> pr-288
