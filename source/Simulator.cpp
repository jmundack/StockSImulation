#include "Simulator.h"
#include <unistd.h>
#include <functional>
#include <iostream>

using namespace std;
using namespace StockSimulator;

Simulator::Simulator(const float initialVal,
                     const size_t percentageVariation,
                     const size_t updateInterval,
                     DataChanged dataChanged):
   _InitialValue(initialVal),
   _MaxVariationInPercentage(percentageVariation),
   _UpdateInterval(updateInterval),
   _CurrentValue(initialVal),
   _IsRunning(false),
   _DataChanged(dataChanged)
{
}

void Simulator::Start()
{
   _IsRunning = true;
   _Thread.reset(new thread(bind(&Simulator::_ThreadRoutine, this)));
}

void Simulator::Stop()
{
   _IsRunning = false;
   _ConditionVariable.notify_all();
   if (_Thread.get() != NULL)
   {
      _Thread->join();
      _Thread.reset();
   }
}

float Simulator::GetCurrentValue() const
{
   lock_guard<mutex> lk(_Lock);
   return _CurrentValue;
}

void Simulator::_UpdateValue()
{
   lock_guard<mutex> lk(_Lock);
   float change = rand() % (2 * _MaxVariationInPercentage * 100);
   change -= (_MaxVariationInPercentage * 100);
   const float valueChange = _CurrentValue * (change/10000);
   _CurrentValue += valueChange;
}


void Simulator::_ThreadRoutine()
{
   while(_IsRunning)
   {
      _UpdateValue();
      if (_DataChanged)
         _DataChanged();
      unique_lock<mutex> lk(_Lock);
      _ConditionVariable.wait_for(lk, chrono::seconds(_UpdateInterval),  bind(&Simulator::_IsNotRunning, this));
   }
}
