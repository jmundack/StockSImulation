#include "DataReader.h"
#include <fstream>
#include <iostream>

using namespace std;
namespace 
{
   const float _PriceVariationPercentage(80);
   const size_t _PriceVariationInterval(1);
   const float _EarningsVariationPercentage(20);
   const size_t _EarningsVariationInterval(10);
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
#if 0
         else
         {
            cerr << "Expected input file of format <name> <price> <price variation in %>";
            cerr << " <price variation interval> <earnings variation in percentage> <earnings variation interval>" << endl;
            break;
         }
#endif
      }while(inFile.good() && !inFile.eof());
   }
   else
   {
      cerr << "Failed to open file : " << filename << endl;
   }
}

