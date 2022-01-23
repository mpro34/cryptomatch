// CryptoMatch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "engine/order_book.hpp"
#include <librdkafka/rdkafka.h>
#include <signal.h>

int main()
{
    std::cout << "CryptoMatch Engine Online!\n";

    // Create the order book
    OrderBook* order_book = new OrderBook;

    // Add Buy Order 1
    Order* buy_one = new Order;
    buy_one->m_amount = 100;
    buy_one->m_id = std::string("ETH");
    buy_one->m_price = 25.50;
    buy_one->side = 1;

    Order* buy_two = new Order;
    buy_one->m_amount = 50;
    buy_one->m_id = std::string("BTC");
    buy_one->m_price = 10.00;
    buy_one->side = 1;

    order_book->AddBuyOrder(buy_one);
    order_book->AddBuyOrder(buy_two);

    // Print what the current holdings for the user are.
    order_book->PrintPortfolio();
}