
#include "trade.hpp"

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