
#include <hjson.h>

#include <string>

#include "common/loading/hjsonloader.h"
#include "common/universe.h"

namespace cqsp::common::actions {
<<<<<<< HEAD
void ResearchTech(Node& civilization, Node& tech);
void ProcessAction(Node& civilization, const std::string& action);
}  // namespace cqsp::common::actions
== == == = void ResearchTech(Universe & universe, entt::entity civilization, entt::entity tech);
void ProcessAction(Universe& universe, entt::entity civilization, const std::string& action);

}  // namespace cqsp::common::actions
>>>>>>> pr-292
