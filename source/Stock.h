#pragma once

#include "Simulator.h"
#include "StockData.h"

class Stock
{
public:
   typedef Simulator::DataChanged DataChanged;

   Stock(const StockData &data, DataChanged &dataChanged);
   const std::string &GetName() const { return _Name; }
   float GetPrice() const;
   float GetEarnings() const;
   void StartSimulation();
   void StopSimulation();
private:
   std::string _Name;
   Simulator _PriceSimulator;
   Simulator _EarningsSimulator;
};

std::ostream &operator<<(std::ostream &os, const Stock &data);
