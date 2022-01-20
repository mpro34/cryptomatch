
#include "order_book.hpp"

/*
	Add input order to m_buy_orders while keeping ascending order consistent.
*/
void OrderBook::AddBuyOrder(Order* order)
{
	if (order == nullptr) return;

	bool added{ false };
	for (auto it = m_buy_orders.begin(); it != m_buy_orders.end(); ++it)
	{
		if (it->m_price >= order->m_price)
		{
			m_buy_orders.insert(it, order);
			added = true;
			break;
		}
	}

	if (!added)
	{
		m_buy_orders.push_back(order);
	}
}

/*
	Add input order to m_sell_orders while keeping descending order consistent.
*/
void OrderBook::AddSellOrder(Order* order)
{
	if (order == nullptr) return;

	bool added{ false };
	for (auto it = m_sell_orders.begin(); it != m_sell_orders.end(); ++it)
	{
		if (it->m_price < order->m_price)
		{
			m_sell_orders.insert(it, order);
			added = true;
			break;
		}
	}

	if (!added)
	{
		m_sell_orders.push_back(order);
	}
}

void OrderBook::RemoveBuyOrder(int index)
{
	if (index >= m_buy_orders.size()) return; // index out of range

	m_buy_orders.erase(m_buy_orders.begin() + index);
}

void OrderBook::RemoveSellOrder(int index)
{
	if (index >= m_sell_orders.size()) return; // index out of range

	m_sell_orders.erase(m_sell_orders.begin() + index);
}

std::vector<Trade*> OrderBook::ProcessLimitBuy(Order* order)
{
	std::vector<Trade*> trades;
	int n = m_sell_orders.size();

	// Check for at least one matching order in the sell_orders list.
	if ((n != 0) || (m_sell_orders[n - 1]->m_price <= order->m_price))
	{
		// traverse all orders that match
		for (int i = n - 1; i >= 0; i--)
		{
			Order* sell_order = m_sell_orders[i];
			if (sell_order->m_price > order->m_price) break;

			// Fill the entire order
			if (sell_order->m_amount >= order->m_amount)
			{
				// Add new trade
				trades.push_back(new Trade{
					order->m_id, sell_order->m_id, order->m_amount, sell_order->m_price
				});
				// Decrement current order amount and continue
				sell_order->m_amount -= order->m_amount;
				if (sell_order->m_amount == 0)
				{
					RemoveSellOrder(i);
				}
				return trades;
			}

			// Fill a partial order and continue
			if (sell_order->m_amount < order->m_amount)
			{
				trades.push_back(new Trade{
					order->m_id, sell_order->m_id, sell_order->m_amount, sell_order->m_price
				});
				// Decrement the input order for a partial
				order->m_amount -= sell_order->m_amount;
				RemoveSellOrder(i);
				continue;
			}
		}
	}
	// finally add any remaining orders to the order book
	AddBuyOrder(order);
	return trades;
}

std::vector<Trade*> OrderBook::ProcessLimitSell(Order* order)
{

}

std::vector<Trade*> OrderBook::ProcessOrder(Order* order)
{
	if (order->side == 1)
	{
		return ProcessLimitBuy(order);
	}
	else
	{
		return ProcessLimitSell(order);
	}
}