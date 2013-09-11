// System Headers
#include <iostream>
#include <memory>
#include <stdio.h>

// Application headers
#include "DataReader.h"
#include "Stock.h"
#include "StockScreen.h"

using namespace std;
using namespace StockSimulator;

int main ( int argc, char *argv[] )
{
   if (argc != 2)
   {
      cerr << "Usage : " << argv[0] << " <input file>" << endl;
      return 1;
   }
   cout << "Stock Simulation" << endl;
   cout << "Press ENTER to start.... enter 'q' or 'Q' to stop" << endl;
   cin.ignore();

   DataReader inputFileReader(argv[1]);
   const vector<StockData> &stockData(inputFileReader.GetStockData());
   for (size_t i = 0; i < stockData.size(); i++)
      cout << stockData.at(i);

   vector<shared_ptr<Stock> > stocks;
   StockScreen screen;

   // screen udpate function to be called when something changes
   Stock::DataChanged dataChanged = bind(&StockScreen::UpdateDisplay, &screen);

   for (size_t i = 0; i < stockData.size(); i++)
   {
      // Create  anew staock from th sock data read in
      shared_ptr<Stock> newStock(new Stock(stockData.at(i), dataChanged));
      stocks.push_back(newStock);
      screen.AddStock(newStock); // add stock to be displayed
   }

   // Start the simulations for all tickers
   for (size_t i = 0; i < stocks.size(); i++)
      stocks.at(i)->StartSimulation();

   // Wait till the user press 'q' or 'Q'
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

   // Stop all the simulations
   for (size_t i = 0; i < stocks.size(); i++)
      stocks.at(i)->StopSimulation();
   return 0;
}
