// CryptoMatch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "engine/order_book.hpp"

int main()
{
    std::cout << "CryptoMatch Engine Online!\n";

    // TODO: Create a consumer and listen for new orders - Kafka
    // https://docs.confluent.io/clients-librdkafka/current/overview.html

    // TODO: Create a producer for trade messages

    // Create the order book
    OrderBook* order_book = new OrderBook;

    // TODO: Start processing orders until done or canceled
}