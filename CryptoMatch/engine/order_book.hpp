#pragma once

#include <vector>
#include "order.hpp"
#include "trade.hpp"

class OrderBook
{
	// Sorted by price: Lowest -> Highest
	std::vector<Order*> m_buy_orders;
	// Sorted by price: Highest -> Lowest
	std::vector<Order*> m_sell_orders;

public:
	OrderBook() = default;
	OrderBook(std::vector<Order*>& buy_orders, std::vector<Order*>& sell_orders);
	virtual ~OrderBook() = default;

	/* Add a buy order to the current order book */
	void AddBuyOrder(Order* order);

	/* Add a sell order to the current order book */
	void AddSellOrder(Order* order);

	/* Remove a buy order from the order book at a given index */
	void RemoveBuyOrder(int index);

	/* Remove a sell order form the order book at a given index */
	void RemoveSellOrder(int index);
	
	// -- Trade Matching Methods -- //

	/* Process a limit buy order*/
	std::vector<Trade*> ProcessLimitBuy(Order* order);

	/* Process a limit sell order */
	std::vector<Trade*> ProcessLimitSell(Order* order);

	/* Process an order and return the trades generated before adding
		the remaining amount to the market */
	std::vector<Trade*> ProcessOrder(Order* order);

	/* Print the current holdings for the user */
	void PrintPortfolio();
};
