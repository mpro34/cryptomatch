
#include "trade.hpp"

Trade::Trade(std::string taker_order_id, std::string maker_order_id, 
	uint64_t amount, uint64_t price) :
	m_taker_order_id{ taker_order_id },
	m_maker_order_id{ maker_order_id },
	m_amount{ amount },
	m_price{ price } {}

Trade* Trade::FromJSON(std::string msg)
{
	return new Trade;
}

std::string Trade::ToJSON(Trade* trade)
{
	//TODO:
	std::string output{ "todo" };
	return output;
}