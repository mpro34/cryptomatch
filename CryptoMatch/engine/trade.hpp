#pragma once

#include <string>

struct Trade
{
	std::string m_taker_order_id;
	std::string m_maker_order_id;
	uint64_t m_amount{ 0 };
	uint64_t m_price{ 0 };

	Trade() = default;
	virtual ~Trade() = default;

	Trade* FromJSON(std::string msg);
	std::string ToJSON(Trade* trade);
};


