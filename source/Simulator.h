#pragma once
#include <functional>
#include <thread>
#include <condition_variable>

namespace StockSimulator {

class Simulator
{
public:
   typedef std::function<void()> DataChanged;
   Simulator(const float initialVal,
             const size_t percentageVariation,
             const size_t updateInterval,
             DataChanged dataChanged);

   void Start();
   void Stop();
   float GetCurrentValue() const;

private:
   bool _IsNotRunning() const { return !_IsRunning; }
   void _UpdateValue();
   void _ThreadRoutine();
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
