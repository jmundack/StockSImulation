#include "DataReader.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace StockSimulator;

namespace 
{
   const float _PriceVariationPercentage(80);
   const size_t _PriceVariationInterval(1);
   const float _EarningsVariationPercentage(20);
   const size_t _EarningsVariationInterval(60);
};

DataReader::DataReader(const string &filename)
{
   ifstream inFile(filename.c_str());
   if (inFile.good())
   {
      do
      {
         string name;
         float price(0),earnings(0);
         inFile >> name >> price >> earnings;
         if (inFile.good())
         {
            _Data.push_back(StockData(name,price, earnings, _PriceVariationPercentage, _PriceVariationInterval, _EarningsVariationPercentage, _EarningsVariationInterval));
         }
         else if(!name.empty())
         {
            cerr << "Expected input file of format <name> <price> <earnings>" << endl;
            cerr << "Invalid data for : " << name << endl;
            _Data.clear();
            break;
         }
      }while(inFile.good() && !inFile.eof());
   }
   else
   {
      cerr << "Failed to open file : " << filename << endl;
   }
   if (_Data.empty())
      cout << "No stocks are being simulated" << endl;
}

