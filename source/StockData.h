#pragma once

#include <string>
#include <iostream>

namespace StockSimulator {

/**
 * \brief Class represents raw stock data with getters and settrs
 */
class StockData
{
public:
   StockData();
   StockData(const std::string &name,
             const float price,
             const float earnings,
             const float priceVariationPercentage,
             const size_t priceVariationInterval,
             const float earningsVariationPercentage,
             const size_t earningsVariationInterval);

   const std::string &GetName() const { return _Name;}
   float GetPrice() const { return _Price; }
   float GetEarnings() const { return _Earnings; }
   float GetPriceVariationPercentage() const { return _PriceVariationPercentage; }
   size_t GetPricaVariationInterval() const { return _PriceVariationInterval; }
   float GetEarningsVariationPercentage() const { return _EarningsVariationPercentage; }
   float GetEarningsVariationInterval() const { return _EarningsVariationInterval; }
private:
   const std::string _Name;
   const float _Price;
   const float _Earnings;
   const float _PriceVariationPercentage;
   const size_t _PriceVariationInterval;
   const float _EarningsVariationPercentage;
   const size_t _EarningsVariationInterval;
};
};

/**
 * \brief Helper function to print raw stock data
 */
std::ostream &operator<<(std::ostream &os, const StockSimulator::StockData &data);
