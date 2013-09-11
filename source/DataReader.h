#pragma once

#include "StockData.h"
#include <vector>

namespace StockSimulator {

/**
 * \brief Class represents a file reader that will read stock
 *        data from an input file
 */
class DataReader
{
public:
   /**
    * \brief Create a data reader which will read stock data
    *        from the specified file.
    * 
    * @param[in] filename File containing stock data.
    */
   DataReader(const std::string &filename);

   /**
    * \brief Returns stock data that was read in from input file
    */
   const std::vector<StockData> &GetStockData() const { return _Data;}
private:
   std::vector<StockData> _Data;
};
};
