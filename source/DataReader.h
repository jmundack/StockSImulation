#pragma once

#include "StockData.h"
#include <vector>

class DataReader
{
public:
   DataReader(const std::string &filename);
   const std::vector<StockData> &GetStockData() const { return _Data;}
private:
   std::vector<StockData> _Data;
};
