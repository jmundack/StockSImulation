#include "Stock.h"
#include <iomanip>

using namespace std;
using namespace StockSimulator;

Stock::Stock(const StockData &data, DataChanged &dataChanged):
   _Name(data.GetName()),
   _PriceSimulator(data.GetPrice(), 
                   data.GetPriceVariationPercentage(), 
                   data.GetPricaVariationInterval(), 
                   dataChanged),
   _EarningsSimulator(data.GetEarnings(),
                      data.GetEarningsVariationPercentage(),
                      data.GetEarningsVariationInterval(),
                      dataChanged)
{
}


float Stock::GetPrice() const
{
   return _PriceSimulator.GetCurrentValue();
}

float Stock::GetEarnings() const
{
   return _EarningsSimulator.GetCurrentValue();
}

void Stock::StartSimulation()
{
   _PriceSimulator.Start();
   _EarningsSimulator.Start();
}

void Stock::StopSimulation()
{
   _PriceSimulator.Stop();
   _EarningsSimulator.Stop();
}

ostream &operator<<(ostream &os, const Stock &data)
{
   os << data.GetName() << setprecision(4) << fixed << setw(10)
      << data.GetPrice() << setw(10) 
      << data.GetEarnings() << setw(10)
      << data.GetPrice() / data.GetEarnings() << endl;
   return os;
}
