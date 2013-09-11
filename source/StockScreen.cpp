#include "StockScreen.h"
#include <iostream>
#include <iomanip>
#include <thread>

using namespace std;
using namespace StockSimulator;

void StockScreen::AddStock(shared_ptr<Stock> stock)
{
   if (stock.get() == NULL)
      cerr << "Ignoring invalid stock" << endl;
   else
   {
      lock_guard<mutex> lk(_DisplayLock);
      _Stocks.push_back(stock);
   }
}

void StockScreen::UpdateDisplay() const
{
   lock_guard<mutex> lk(_DisplayLock);
   cout << "-----------------------------------------------" << endl;
   cout << "Name" << setw(10)
      << "Price" << setw(10) 
      << "Earnings" << setw(10) 
      << "P/E" << endl;
   cout << "-----------------------------------------------" << endl;
   for (size_t i = 0; i < _Stocks.size(); i++)
      cout << *_Stocks.at(i);
   cout << "-----------------------------------------------" << endl;
   cout << flush;
}
