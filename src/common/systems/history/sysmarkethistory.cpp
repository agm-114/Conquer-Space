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
#include "common/systems/history/sysmarkethistory.h"

<<<<<<< HEAD
#include "common/components/history.h"
    <<<<<<< HEAD
#include "common/components/market.h"
    namespace cqsp::common::systems::history {

<<<<<<< HEAD
<<<<<<< HEAD
    using components::Market;
    using components::MarketHistory;
    == == == = using cqsp::common::systems::history::SysMarketHistory;
>>>>>>> pr_254

    void SysMarketHistory::DoSystem() {
        /*
=======
namespace cqsp::common::systems::history {
void SysMarketHistory::DoSystem() {
    /*
>>>>>>> main
    for (Node market_node : GetUniverse().nodes<Market>()) {
        Market& market_data = market_node.get<Market>();
        market_data.history.push_back(market_data);
    }
    auto view = GetUniverse().nodes<Market, MarketHistory>();
    for (Node market_node : view) {
        auto& history = market_node.get<MarketHistory>();
        Market& market_data = market_node.get<Market>();
<<<<<<< HEAD
=======
void cqsp::common::systems::history::SysMarketHistory::DoSystem() {
    for (entt::entity marketentity : GetUniverse().view<components::Market>()) {
        components::Market& market_data =
            GetUniverse().get<components::Market>(marketentity);
=======
namespace cqsp::common::systems::history {

using components::MarketHistory;
using components::Market;

void SysMarketHistory::DoSystem() {
    /*
    auto view = GetUniverse().view<Market, MarketHistory>();

    for (entt::entity marketentity : GetUniverse().view<Market>()) {
        Market& market_data = GetUniverse().get<Market>(marketentity);
>>>>>>> pr-290
        market_data.history.push_back(market_data);
    }
    auto view = GetUniverse().view<Market, MarketHistory>();
    for (entt::entity entity : view) {
<<<<<<< HEAD
        auto& history = GetUniverse().get<components::MarketHistory>(entity);
        components::Market& market_data =
            GetUniverse().get<components::Market>(entity);
>>>>>>> pr_191
=======
>>>>>>> pr-303
=======
        auto& history = GetUniverse().get<MarketHistory>(entity);
        Market& market_data = GetUniverse().get<Market>(entity);
>>>>>>> pr-290
        // Loop through the prices
        for (auto resource : market_data.market_information) {
            history.price_history[resource.first].push_back(resource.second.price);
            history.volume[resource.first].push_back(market_data.last_market_information[resource.first].demand);
        }
        double val = 0;
        for (Node participant_node : market_node.Convert(market_data.participants)) {
            if (participant_node.any_of<components::Wallet>()) {
                auto& wallet = participant_node.get<components::Wallet>();
                val += wallet.GetGDPChange();
            }
        }
        history.gdp.push_back(val);
    */
    }
}  // namespace cqsp::common::systems::history
