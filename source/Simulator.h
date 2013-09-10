#pragma once
#include <functional>
#include <thread>

class Simulator
{
public:
   Simulator(const float initialVal,
             const size_t percentageVariation,
             const size_t updateInterval);

   void Start();
   void Stop();
   float GetCurrentValue() const { return _CurrentValue; }

private:
   void _ThreadRoutine();
   const float _InitialValue;
   const size_t _MaxVariationInPercentage;
   const size_t _UpdateInterval;
   float _CurrentValue;
   std::auto_ptr<std::thread> _Thread;
   bool _IsRunning;
};
