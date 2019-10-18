#ifndef TASK_HPP
#define TASK_HPP
#include "../common/list.hpp"
#include "../platform/processor.hpp"
#include "bloc.hpp"


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
    int q;
    int wcet;
    bloc *ppp; 
  public:
    Task(int id, int C, int D, int T, int q, int wcet,bloc *ppp);
    ~Task(); 
   
    int _id();
    void _id(int id);

    int _C(); 
    void _C(int ET); 

    
    int _D();
    void _D(int D);


    int _T(); 
    void _T(int period);

    
    int _q(); 
    void _q(int quantum);

    int _wcet(); 
    void _wcet(int wcet);

    bloc * _ppp(); 
    void _ppp(bloc * ppp); // un tableau de blocs non preemptifs


     // analysis functions
    // int dbf_exact(int t, common::List<Task *> * ts);
    //double utilization();
    int compute_NPR(common::List<task::Task *>  *tasks,int *deadlines,int nb);
    float dbf(common::List<task::Task *>  *tasks, int D);
    int * compute_DK (common::List<task::Task *>  *tasks, int nb);
    bool existe_Elem(int g,int *deadlines);
    common::List<common::List<task:: Task *> *> * compute_MIN_Runtime_Overhead_BB(common::List<task::Task *>  *tasks);
    int compute_WCET();
    void  list_of_combinaison(common::List<task::Task *>  *tasks,  common::List<processor::Processor *>  *processors);
    // common::List<common::List<task::Task *> *> *  list_of_combinaison(common::List<task::Task *>  *tasks,  common::List<processor::Processor *>  *processors);
    void display();
  };
}

#endif

