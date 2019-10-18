#pragma once
#include "../task/taskset.hpp"

namespace processor {

  class Processor {
  private:
    int id;
    int TAG;
    
  public: 
   Processor(int id, int TAG);
   ~Processor();
   void _id(int id);
   int _id();
   void _TAG(int id);
   int _TAG();

    //  bool test_edf(Task *tau, int PREEMPTION);
    // bool test_FP(Task *tau, int PREEMPTION);
    // bool test_schedulability(int POLICY, Task *tau, int PREEMPTION);
  };


}
