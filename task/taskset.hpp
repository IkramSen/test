#ifndef TASK_HPP
#define TASK_HPP
#include "../common/list.hpp"


#include <fstream>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define EXACT_DBF  0
#define BARUAH_APPROX 1
#define NON_PREEMP 2

#define FAIR 0
#define PROP 1

namespace task {

  class Task {

  private:
    int id;
    int C;
    int D;
    int T;
   
 
  public:
    Task(int id, int C, int D, int T);
    ~Task(); 
   
    int _id();
    void _id(int id);

    int _C(); 
    void _C(int ET); 

    
    int _D();
    void _D(int D);


    int _T(); 
    void _T(int period);


     //Functions
    
    //common::List<common::List<task:: Task *> *> *  compute_MIN_Runtime_Overhead();
                                            
  };
}

#endif
