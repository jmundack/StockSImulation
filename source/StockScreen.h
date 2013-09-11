#pragma once
#include <vector>
#include <mutex>
#include "Stock.h"

namespace StockSimulator {

class StockScreen
{
public:
   void AddStock(std::shared_ptr<Stock> stock);
   void UpdateDisplay() const;
private:
   mutable std::mutex _DisplayLock;
   std::vector<std::shared_ptr<Stock> > _Stocks;
};
};
