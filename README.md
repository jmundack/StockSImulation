StockSImulation
===============

Write a program using C++ to do the following

Continuously compute P/E

Symbols and their initial values

Symbol Price   Earnings

ABC    8.54    .240000

BCA    13.21   .320000

CAB    23.51   1.810000

CBA    23.66   1.340000

BAC    24.05   2.060000

Write several routines that do the following
One will publish price ticks for each of the above symbols randomly with random shifts in the prices up and down +/- 80% from the last price once per second.
One will publish earnings for each of the above symbols shifting earnings up/down +/- 20% once a minute
The last will read in both feeds and each time a security’s price or earnings change, update the following fields
-- Price
-- Earnings
-- P/E

The original prices and earnings should be an input file so that we can make changes for testing without rebuilding the binary.
Please use C++, no third party software to reduce dependencies.

Build
-------
Run ./build/bootstrap.sh to build

Example
--------
./build/debug/bin/StockSimulator input_file
