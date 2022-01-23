// CryptoMatch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "engine/order_book.hpp"
#include <librdkafka/rdkafka.h>
#include <signal.h>

int main()
{
    std::cout << "CryptoMatch Engine Online!\n";

    rd_kafka_topic_t* rkt;
    char* topic = NULL;
    rd_kafka_conf_t* conf;
    rd_kafka_topic_conf_t* topic_conf;
    char errstr[512];
    char tmp[16];

    /* Create default Kafka Configuration */
    conf = rd_kafka_conf_new();

    /* Quick termination setup */
    snprintf(tmp, sizeof(tmp), "%i", SIGINT);
    rd_kafka_conf_set(conf, "internal.termination.signal", tmp, NULL, 0);

    /* Topic configuration */
    topic_conf = rd_kafka_topic_conf_new();

    // TODO: Create a consumer and listen for new orders - Kafka

    rd_kafka_conf_set(conf, "enable.partition.eof", "true", NULL, 0);

    /* Create kafka consumer handle*/
    rd_kafka_t* consumer_handle = rd_kafka_new(RD_KAFKA_CONSUMER, conf, errstr, sizeof(errstr));
    if (consumer_handle == nullptr)
    {
        fprintf(stderr, "%% Failed to create a new consumer: %s\n", errstr);
        exit(1);
    }

    /* Create topic */
    rkt = rd_kafka_topic_new(consumer_handle, topic, topic_conf);
    topic_conf = NULL; // Transfer ownership to topic.

    // TODO: Create a producer for trade messages

    // Create the order book
    OrderBook* order_book = new OrderBook;

    // TODO: Start processing orders until done or canceled
}