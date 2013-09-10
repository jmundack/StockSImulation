#include <iostream>
#include <unistd.h>
#include "Simulator.h"

using namespace std;

int main()
{
   cout << "Stock Simulation" << endl;
   Simulator s(8.54,20,1);
   s.Start();
   sleep(10);
   s.Stop();
   return 0;
}
