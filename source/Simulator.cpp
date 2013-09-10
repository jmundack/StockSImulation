#include "Simulator.h"
#include <unistd.h>
#include <functional>
#include <iostream>

using namespace std;

Simulator::Simulator(const float initialVal,
                     const size_t percentageVariation,
                     const size_t updateInterval):
   _InitialValue(initialVal),
   _MaxVariationInPercentage(percentageVariation),
   _UpdateInterval(updateInterval),
   _CurrentValue(initialVal),
   _IsRunning(false)
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
   if (_Thread.get() != NULL)
   {
      _Thread->join();
      _Thread.reset();
   }
}

void Simulator::_ThreadRoutine()
{
   while(_IsRunning)
   {
      float change = rand() % (2 * _MaxVariationInPercentage * 100);
      change -= (_MaxVariationInPercentage * 100);
      const float valueChange = _CurrentValue * (change/10000);
      _CurrentValue += valueChange;
      cout << "Current Value : " << _CurrentValue << " value changed = " << valueChange << "(" << change/10000 << "%)" << endl;
      sleep(_UpdateInterval);
   }
}
