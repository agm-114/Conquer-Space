/* Conquer Space
<<<<<<< HEAD
 * Copyright (C) 2021-2025 Conquer Space
=======
 * Copyright (C) 2021-2023 Conquer Space
>>>>>>> pr-292
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
#include "common/actions/economy/markethelpers.h"

<<<<<<< HEAD
#include "common/components/history.h"
#include "common/components/market.h"

    namespace cqsp::common::actions {

    void AddParticipant(Node & market_node, Node & participant) {
        auto& market = market_node.get<components::Market>();
        market.participants.insert(participant);
        participant.emplace<components::MarketAgent>(market_node);
        static_cast<void>(participant.get_or_emplace<components::Wallet>());
    }

    double GetCost(Node & market, const components::ResourceLedger& ledger) {
        if (!market.any_of<components::Market>()) {
            return 0.0;
        }
        return market.get<components::Market>().GetPrice(ledger);
    }

    Node CreateMarket(Universe & universe) {
        Node market(universe);
        static_cast<void>(market.get_or_emplace<components::Market>());
        static_cast<void>(market.get_or_emplace<components::MarketHistory>());
        return market;
    }

    bool PurchaseGood(Node & agent, const components::ResourceLedger& purchase) {
        // Calculating on how to buy from the market shouldn't be too hard, right?
        // Get the market connected to, and build the demand
        Node market(agent.universe(), agent.get<components::MarketAgent>().market);
        auto& market_comp = market.get<components::Market>();
        == == == =
#include "common/components/economy.h"
#include "common/components/history.h"

                     < < < < < < < < HEAD : src / common / systems / economy / markethelpers.cpp namespace components =
                         cqsp::common::components;
        using components::Market;
        using components::MarketAgent;
        using components::MarketHistory;
        using components::ResourceLedger;
        using components::ResourceStockpile;
        using components::Wallet;
        using entt::entity;
        namespace cqsp::common::systems::economy {
        void AddParticipant(Universe& universe, entity market_entity, entity entity) {
            auto& market = universe.get<Market>(market_entity);
            == == == == namespace cqsp::common::actions {
                void AddParticipant(Universe & universe, entt::entity market_entity, entt::entity entity) {
                    auto& market = universe.get<components::Market>(market_entity);
                    >>>>>>>> pr - 292 : src / common / actions / economy /
                                        markethelpers.cpp market.participants.insert(entity);
                    universe.emplace<MarketAgent>(entity, market_entity);
                    static_cast<void>(universe.get_or_emplace<Wallet>(entity));
                }

                < < < < < < < < HEAD : src / common / systems / economy /
                                       markethelpers.cpp double GetCost(Universe & universe, entity market,
                                                                        const ResourceLedger& ledger) {
                    if (!universe.any_of<Market>(market)) {
                        == == == ==
                            double GetCost(Universe & universe, entt::entity market,
                                           const components::ResourceLedger& ledger) {
                            if (!universe.any_of<components::Market>(market)) {
                                >>>>>>>> pr - 292 : src / common / actions / economy / markethelpers.cpp return 0.0;
                            }
                            return universe.get<Market>(market).GetPrice(ledger);
                        }

                        < < < < < < < < HEAD : src / common / systems / economy /
                                               markethelpers.cpp entity CreateMarket(Universe & universe) {
                            entity market = universe.create();
                            == == == == entt::entity CreateMarket(Universe & universe) {
                                entt::entity market = universe.create();
                                >>>>>>>> pr - 292 : src / common / actions / economy /
                                                    markethelpers.cpp CreateMarket(universe, market);
                                return market;
                            }

                            < < < < < < < <
                                HEAD : src / common / systems / economy /
                                       markethelpers.cpp void CreateMarket(Universe & universe, entity market) {
                                static_cast<void>(universe.get_or_emplace<Market>(market));
                                static_cast<void>(universe.get_or_emplace<MarketHistory>(market));
                            }

                            bool PurchaseGood(Universe & universe, entity agent, const ResourceLedger& purchase) {
                                == == == ==
                                void CreateMarket(Universe & universe, entt::entity market) {
                                    static_cast<void>(universe.get_or_emplace<components::Market>(market));
                            static_cast<void>(universe.get_or_emplace<components::MarketHistory>(market));
                        }

                        bool PurchaseGood(Universe & universe, entt::entity agent,
                                          const components::ResourceLedger& purchase) {
                            >>>>>>>> pr - 292
                                : src /
                                  common / actions / economy /
                                  markethelpers.cpp
                                      // Calculating on how to buy from the market shouldn't be too hard, right?
                                      // Get the market connected to, and build the demand
                                      entity market = universe.get<MarketAgent>(agent).market;
                            auto& market_comp = universe.get<Market>(market);
>>>>>>> pr-292
                            // Prices
                            double cost = market_comp.GetPrice(purchase);

                            // Then subtract the cash from the person, or something
                            // Check if they have enough money and purchase, I guess
<<<<<<< HEAD
                            auto& wallet = agent.get<components::Wallet>();
                            == == == = auto& wallet = universe.get<Wallet>(agent);
>>>>>>> pr-292

                            // TODO(EhWhoAmI):
                            // Check if there are enough resources on the market, or else there will have a shortage
                            // Then get the maximum resources that they allow
                            // Just allow agents to take as many resources as they want because I'm too lazy to implement
                            // limitations.
                            if (wallet.GetBalance() < cost) {
                                return false;
                            }

                            // Then agent has enough money to buy
                            market_comp.AddDemand(purchase);
<<<<<<< HEAD
                            if (agent.all_of<components::ResourceStockpile>()) {
                                agent.get<components::ResourceStockpile>() += purchase;
                                == == == = if (universe.all_of<ResourceStockpile>(agent)) {
                                    universe.get<ResourceStockpile>(agent) += purchase;
>>>>>>> pr-292
                                }
                                wallet -= cost;
                                return true;
                            }

<<<<<<< HEAD
                            bool SellGood(Node & agent, const components::ResourceLedger& selling) {
                                // Calculating on how to buy from the market shouldn't be too hard, right?
                                // Get the market connected to, and build the demand
                                Node market(agent.universe(), agent.get<components::MarketAgent>().market);
                                auto& market_comp = market.get<components::Market>();
                                auto& agent_stockpile = agent.get<components::ResourceStockpile>();
                                == == == = < < < < < < < < HEAD
                                    : src /
                                      common / systems / economy /
                                      markethelpers.cpp bool SellGood(Universe & universe, entity agent,
                                                                      const ResourceLedger& selling) {
                                          == == == ==
                                          bool SellGood(Universe & universe, entt::entity agent,
                                                        const components::ResourceLedger& selling) {
                                              >>>>>>>>
                                                  pr -
                                                      292 : src / common / actions / economy /
                                                          markethelpers.cpp
                                                              // Calculating on how to buy from the market shouldn't be too hard, right?
                                                              // Get the market connected to, and build the demand
                                                              entity market = universe.get<MarketAgent>(agent).market;
                                auto& market_comp = universe.get<Market>(market);
                                auto& agent_stockpile = universe.get<ResourceStockpile>(agent);
>>>>>>> pr-292
                                market_comp.AddSupply(selling);

                                double cost = market_comp.GetPrice(selling);

                                // Remove from stockpile
                                agent_stockpile -= selling;

                                // Then subtract the cash from the person, or something
                                // Check if they have enough money and purchase, I guess
<<<<<<< HEAD
                                components::Wallet& wallet = agent.get<components::Wallet>();
                                wallet += cost;
                                return true;
                            }

                        }  // namespace cqsp::common::actions
                        == == == = Wallet& wallet = universe.get<Wallet>(agent);
                        wallet += cost;
                        return true;
                    }
                    < < < < < < < < HEAD : src / common / systems / economy / markethelpers.cpp
                }  // namespace cqsp::common::systems::economy
                == == == ==

            }  // namespace cqsp::common::actions
            >>>>>>>> pr - 292 : src / common / actions / economy / markethelpers.cpp
>>>>>>> pr-292
