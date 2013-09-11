#pragma once

#include "Simulator.h"
#include "StockData.h"

namespace StockSimulator {

/**
 * \brief Class represent a single stock
 */
class Stock
{
public:
   /**
    * \copydoc Simulator::DataChanged
    */
   typedef Simulator::DataChanged DataChanged;

   /**
    * \brief Create a stock object using stock data
    *
    * @param[in] data        Raw stock data read in from input file
    * @param[in] dataChanged Callback to be invoked when stock data changes
    */
   Stock(const StockData &data, DataChanged &dataChanged);

   /**
    * \brief Returns stock's name
    */
   const std::string &GetName() const { return _Name; }

   /**
    * \brief Returns Stock's price
    */
   float GetPrice() const;

   /**
    * \brief Returns Stock's earnigs
    */
   float GetEarnings() const;

   /**
    * \brief Starts the simulations of stock's price and earnings
    */
   void StartSimulation();

   /**
    * \brief Stops the simulations of stock's price and earnings
    */
   void StopSimulation();

private:
   std::string _Name;             /**< Stock's Name */
   Simulator _PriceSimulator;    /**< Simultor for Stock's price */
   Simulator _EarningsSimulator; /**< Simulator for Stock's earnigns */
};
};

/**
 * \brif Helper fn to print Sotck data
 */
std::ostream &operator<<(std::ostream &os, const StockSimulator::Stock &data);
