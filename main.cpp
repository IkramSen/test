  #include "common/list.hpp"
 #include "task/task.hpp"

#include "platform/processor.hpp"
#include <algorithm>  

#define GPU 1
#define CPU 2


using namespace std;


int main(int argc, char ** argv){

   
  int nb=10;
  bloc ppp1[1]= {{2,0}};
  task::Task *tau1 = new task::Task(1,2,8,8,0, 0, ppp1);  // id, C, D, T, q, wcet, int* ppp
  bloc ppp2[2]= {{3,3}, {1,0}};
  task::Task *tau2 = new task::Task(2,4,10,20,0,0, ppp2);

   bloc ppp3[1]= {{2,0}};
  task::Task *tau3 = new task::Task(3,2,15,25,0,0,ppp3);

  bloc ppp4[2]= {{2,1}, {2,0}};
  task::Task *tau4 = new task::Task(4,4,30,35,0,0,  ppp4);

  bloc ppp5[2]= {{2,4}, {1,0}};
  task::Task *tau5 = new task::Task(5,3,50, 50,0,0,  ppp5);

  bloc ppp6[1]= {{4,0}};
  task::Task *tau6 = new task::Task(6,4,50,90,0,0,  ppp6);

  bloc ppp7[3]= {{2,1}, {4,2}, {2,0}};
  task::Task *tau7 = new task::Task(7,8,60,110,0,0,  ppp7);

  bloc ppp8[3]= {{3,2}, {2,0}};
  task::Task *tau8 = new task::Task(8,5,60,105,0,0,  ppp8);

  bloc ppp9[1]= {{3,0}};
  task::Task *tau9 = new task::Task(9,3,60, 100,0,0,  ppp9);

  bloc ppp10[2]= {{2,3}, {2,0}};
  task::Task *tau10 = new task::Task(10,4,100,110,0,0, ppp10);

  
  common::List<task::Task *>  *tasks= new common::List<task::Task *> ();
  tasks->add_at_head(new common::Node<task::Task *>(tau1));
  tasks->add_at_head(new common::Node<task::Task *>(tau2));
  tasks->add_at_head(new common::Node<task::Task *>(tau3));
  tasks->add_at_head(new common::Node<task::Task *>(tau4));
  tasks->add_at_head(new common::Node<task::Task *>(tau5));
  tasks->add_at_head(new common::Node<task::Task *>(tau6));
  tasks->add_at_head(new common::Node<task::Task *>(tau7));
  tasks->add_at_head(new common::Node<task::Task *>(tau8));
  tasks->add_at_head(new common::Node<task::Task *>(tau9));
  tasks->add_at_head(new common::Node<task::Task *>(tau10));

  processor::Processor *p1 = new processor::Processor(1,1); 
  processor::Processor *p2 = new processor::Processor(2,1); 
    
  common::List<processor::Processor *>  *processors= new common::List<processor::Processor *> ();
  processors->add_at_head(new common::Node<processor::Processor *>(p1)); 
  processors->add_at_head(new common::Node<processor::Processor *>(p2));

  //common::List<common::List<Task *> *> * comb = sort_clusters(clusters);
  // common::List<res *> * result= tau1->list_of_combinaison(tasks,processors);

  tau1->list_of_combinaison(tasks,processors);
  
  
}


