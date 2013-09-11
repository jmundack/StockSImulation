#include "Stock.h"
#include <iomanip>

using namespace std;

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
   os << setw(10);
   os << data.GetName() << "\t" << data.GetPrice() << "\t";
   os << data.GetEarnings() << "\t" << data.GetPrice() / data.GetEarnings() << endl;
   os.clear();
   return os;
}
