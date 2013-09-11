#include "StockData.h"

using namespace std;
using namespace StockSimulator;

StockData::StockData():
   _Price(0),
   _Earnings(0),
   _PriceVariationPercentage(0),
   _PriceVariationInterval(0),
   _EarningsVariationPercentage(0),
   _EarningsVariationInterval(0)
{
}

StockData::StockData(const string &name,
                     const float price,
                     const float earnings,
                     const float priceVariationPercentage,
                     const size_t priceVariationInterval,
                     const float earningsVariationPercentage,
                     const size_t earningsVariationInterval):
   _Name(name),
   _Price(price),
   _Earnings(earnings),
   _PriceVariationPercentage(priceVariationPercentage),
   _PriceVariationInterval(priceVariationInterval),
   _EarningsVariationPercentage(earningsVariationPercentage),
   _EarningsVariationInterval(earningsVariationInterval)
{
}

ostream &operator<<(ostream &os, const StockData &data)
{
   os << "Stock Name : " << data.GetName() << endl;
   os << "\tPrice : " << data.GetPrice() << endl;
   os << "\tEarnings: " << data.GetEarnings() << endl;
   os << "\tPercentage Variation in price : " << data.GetPriceVariationPercentage() << endl;
   os << "\tInterval for price variation : " << data.GetPricaVariationInterval() << endl;
   os << "\tPercentage variation in earnings : " << data.GetEarningsVariationPercentage() << endl;
   os << "\tInterval for earnings variation : " << data.GetEarningsVariationInterval() << endl;
   return os;
}
