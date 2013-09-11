#include <iostream>
#include <memory>
#include <unistd.h>
#include <stdio.h>
#include "Stock.h"
#include "DataReader.h"

using namespace std;

void _UpdateDiaplay(const vector<shared_ptr<Stock> > &stocks)
{
   for (size_t i = 0; i < stocks.size(); i++)
      cout << *stocks.at(i);
   cout << flush;
}

int main ( int argc, char *argv[] )
{
   cout << "Stock Simulation" << endl;
   if (argc != 2)
   {
      cerr << "Usage : " << argv[0] << " <input file>" << endl;
      return 1;
   }
   cout << "Press entr to start.... enter 'q' or 'Q' to stop" << endl;
   cin.ignore();
   DataReader inputFileReader(argv[1]);
   const vector<StockData> &stockData(inputFileReader.GetStockData());
   for (size_t i = 0; i < stockData.size(); i++)
   {
      cout << stockData.at(i);
   }

   vector<shared_ptr<Stock> > simulators;
   Stock::DataChanged dataChanged = bind(&_UpdateDiaplay, ref(simulators));
   for (size_t i = 0; i < stockData.size(); i++)
   {
      shared_ptr<Stock> newStock(new Stock(stockData.at(i), dataChanged));
      simulators.push_back(newStock);
   }
   for (size_t i = 0; i < simulators.size(); i++)
      simulators.at(i)->StartSimulation();
   do
   {
      char c;
      cin >> c;
      if (c == 'q' || c == 'Q') 
      {
         cout << "Stopping Simulation" << endl;
         break;
      }
   }while(true);
   for (size_t i = 0; i < simulators.size(); i++)
      simulators.at(i)->StopSimulation();
   return 0;
}
