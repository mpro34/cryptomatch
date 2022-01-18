#pragma once

#include <string>

/*
	This class contains information for a single order and how to serialize to and from JSON.
*/

class Order
{
	uint64_t m_amount{ 0 };
	uint64_t m_price{ 0 };
	std::string m_id;
	int8_t side{ 0 };

public:
	Order() = default;
	virtual ~Order() = default;

	Order* FromJSON(std::string msg);
	std::string ToJSON(Order* order);
};
