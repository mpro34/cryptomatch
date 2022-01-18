# cryptomatch
A cryptocurrecy trade engine focused on matching orders in an order book.

## Purpose
The purpose of this project is for me to understand a trade engine that uses matching. In previous projects I have built an auto-trader in Python using the Oanda Forex API which made trades based on simple technical indicators like the SMA12/24 cross. However, I would like to see how those trades get matched and fullfilled once they leave the client.

## Components
The fundamental structures for a matching trade engine are:
1. Order
2. OrderBook - Support Limit, Market and Stop Orders
3. Trade

To support scalability of the project, I will be using Apache Kafka for event streaming from clients to my trade engine.Instead of storing state in a database, we will use event streaming to topics to get messages to/from client and engine.


