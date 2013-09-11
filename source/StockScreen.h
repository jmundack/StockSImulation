#pragma once
#include <vector>
#include <mutex>
#include "Stock.h"

namespace StockSimulator {

/**
 * \breif Class represents the display of multiple stocks
 */
class StockScreen
{
public:
   /**
    * \brief Adds a new stock to the display
    */
   void AddStock(std::shared_ptr<Stock> stock);

   /**
    * \breif Refreshes the data deing displayed
    */
   void UpdateDisplay() const;
private:
   mutable std::mutex _DisplayLock;
   std::vector<std::shared_ptr<Stock> > _Stocks;
};
};
