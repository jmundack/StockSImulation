#pragma once
#include <functional>
#include <thread>
#include <condition_variable>

namespace StockSimulator {

/**
 * \brief Class represaents a simulator - which simulated values
 *        based on arguments
 */
class Simulator
{
public:
   /**
    * \brief prototype of the callback to be invoked when data changes
    */
   typedef std::function<void()> DataChanged;

   /**
    * \brief Initializes a Simulater with starting values
    *        and criteria/frequency for updates
    */
   Simulator(const float initialVal,
             const size_t percentageVariation,
             const size_t updateInterval,
             DataChanged dataChanged);

   /**
    * \brief Destructor - Make sure the simulator is stopped
    */
   ~Simulator() { Stop(); }

   /**
    * \brief Starts the simulator
    */
   void Start();

   /**
    * \brief Stops the simulator
    */
   void Stop();

   /**
    * \brief Retuns the current value/last value simulated
    */
   float GetCurrentValue() const;

private:
   /**
    * \brief Helper function used by condition variable
    */
   bool _IsNotRunning() const { return !_IsRunning; }

   /**
    * \brief Helper function that simulates and updates current value
    */
   void _UpdateValue();

   /**
    * \brief Thread function that simulates async events
    */
   void _ThreadRoutine();

   // private data
   const float _InitialValue;
   const size_t _MaxVariationInPercentage;
   const size_t _UpdateInterval;
   float _CurrentValue;
   std::auto_ptr<std::thread> _Thread;
   bool _IsRunning;
   DataChanged _DataChanged;
   mutable std::mutex _Lock;
   std::condition_variable _ConditionVariable;
};
};
