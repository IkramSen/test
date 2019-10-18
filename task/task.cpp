#include "task.hpp"
#include "../common/list.hpp"

#include <cmath>
#include <map>

#include <algorithm>  

#define EXACT_PREEMP  0
#define APROX_PREEMP  1
#define EXACT_NPEEMP  2


using namespace std;

namespace task {

 

  Task::Task(int id, int C, int D, int T, int q, int wcet, bloc* ppp){

    this->id = id;
    this->C = C;
    this->D = D;
    this->T = T;
    this->q = q;
    this->wcet= wcet;
    this->ppp = (bloc *)malloc(10 * sizeof(bloc));
  }


  Task::~Task(){
    // do not forget to destroy the malloc of the grap table !!
    // do not forget to destroy all the conc and sep.
  }


  // getters and setters
  int Task::_C(){
    return C;
  }
  
  void  Task::_C(int ET){
    this->C = ET;
  }

  int Task::_D(){
    return D;
  }
  
  void  Task::_D(int deadline){
    this->D = deadline;
  }
  
  int Task::_T(){
    return T;
  }
  
  void  Task::_T(int period){
    this->T = period;
  }
  
 
  int Task::_q(){
    return q;
  }
  
  void  Task::_q(int q){
    this->q = q;
  }

 
  int Task::_id(){
    return id;
  }
  
  void  Task::_id(int id){
    this->id = id;
  }

 
  int Task::_wcet(){
    return wcet;
  }
  
  void  Task::_wcet(int wcet){
    this->wcet = wcet;
  }

//print tasks
  void Task::display(){
    std::cout<<"[Task ID:"<<id<<std::endl;
   
    std::cout<<std::endl;
  }
 

  //--//
  int Task::compute_NPR(common::List<task::Task *>  *tasks,int *deadlines, int nb){
    int size= nb*nb;
    int *SLACKS =  (int*) malloc(size * sizeof(int));
    int q=0;
    SLACKS[1]= deadlines[1]- dbf(tasks,deadlines[1]);
   
    for(int k=2; k<=84; k++){
      std::cout<< "K= " << k << "/ D[k]  = " << deadlines[k] <<std::endl;
      std::cout<< " SLACKS[k-1]  " << SLACKS[k-1]  <<std::endl;
      std::cout<< " LA FONCTION DBF =  " << dbf(tasks,deadlines[k])  <<std::endl;
      std::cout<< " SLACKS[k]- DBF= " <<  deadlines[k]-(int) dbf(tasks,deadlines[k])  <<std::endl;
      SLACKS[k]= std::min(SLACKS[k-1], deadlines[k]-(int) dbf(tasks,deadlines[k]));
      std::cout<< "LE MIN SLACKS[k] ET SLACKS[k-1]  =  " << SLACKS[k]  <<std::endl;
      std::cout<< "----------------------------------------------------------------------------------------Qi = " << q  <<std::endl;

      if (SLACKS[k] < 0)  std::cout<< " ERROR" <<std::endl;
      if (this->_id() != 1) {
      if (this->_D() == deadlines[k])  {
	std::cout<< " test sl == deadline" <<std::endl; 
  
	q= std::min(SLACKS[k],this->_C()); }
        
      }else 
	   q=this->_C();
    }
    return q;
  }

  float Task::dbf(common::List<task::Task *>  *tasks, int D) {
  int i=0;
  int dbfF = 0;
  common::Node <task::Task *> *current = tasks->head;
  for (i = 0 ; i<tasks->size; i++){
    dbfF= dbfF+((current->el->_C()) * (floor((D+current->el->_T()-current->el->_D())/current->el->_T())));
    current=current->next;
  }
  return dbfF;		
}

  // bool Task::existe_Elem(int g,int *deadlines){
  // size_t n = sizeof(deadlines) / sizeof(deadlines[1]);
  // std::cout<< "nnnnnnnnnnnnnnnnnnn = " <<  n <<std::endl;
  //   for (int i = 0 ; i<n; i++){
       
  //   }
  // }


  int * Task::compute_DK (common::List<task::Task *>  *tasks, int nbTsk){
    int size= nbTsk*nbTsk; 
    int *deadlines =  (int*) malloc(size * sizeof(int));
    std::cout<< " nbTsk = " <<  nbTsk  <<std::endl;

      int l=-1;
      int k=0; // indice pour Dk deadlines
      int g=0;
      for (int i = 0 ; i<nbTsk; i++){ //loop on l  changer la condition d'arret 
	common::Node <task::Task *> *curr = tasks->head;
	l=l+1;
	// std::cout<< " l = " << l  <<std::endl;
	for (int j = 0 ; j<nbTsk; j++){ //loop on tasks
	  g=(l *curr->el->_T())+ curr->el->_D();
	  // std::cout<< " g = " << g  <<std::endl;
          
	  // bool notExiste= existe_Elem(g, deadlines);
          bool notExiste=1 ;
	  if (g<=725 && notExiste){
	    deadlines[k++]= (l *curr->el->_T())+ curr->el->_D();
	  }
	  curr=curr->next;
        } 
      }      

     return deadlines;
  }



  common::List<common::List<task:: Task *> *> * Task::compute_MIN_Runtime_Overhead_BB(common::List<task::Task *>  *tasks){
    common::List<common::List<task::Task *> *> * l_p = new common::List<common::List<task::Task *> *> ();
    // solution initial
    common::Node <task::Task *> *curr = tasks->head;
  

    return l_p;    
  }

int Task::compute_WCET() {
  int i=0;
  int wcet = 0;
  int q= this->_q();
  //std::cout<< " q_ "<< this->_id()<<"=" << q  <<std::endl;
  

  return wcet;		
}


// common::List<common::List<task:: Task *> *> * Task::compute_MIN_Runtime_Overhead_BB(common::List<task::Task *>  *tasks){
//     common::List<common::List<task::Task *> *> * l_p = new common::List<common::List<task::Task *> *> ();
//     // solution initial
//     common::Node <task::Task *> *curr = tasks->head;
  

//     return l_p;    
//   }


  void  Task::list_of_combinaison(common::List<task::Task *>  *tasks,  common::List<processor::Processor *>  *processors){
      
    // solution initial
    common::List<common::List< task::Task*> *>  *all_comb;
    common::Node <processor::Processor *> *proc_curr = processors->head;
    for (int i = 0 ; i<processors->size; i++){
      common::List<Task * > * ts =tasks->copy();
      common::Node <task::Task *> *curr = ts->head;
      all_comb= new common::List<common::List< task::Task*> *> ();
      common::List<task::Task *>  *task_for_proc= new common::List<task::Task *> ();
      common::List<task::Task *>  *list_tmp= new common::List<task::Task *> ();
      
      for (int j = 0 ; j<tasks->size; j++){ 
        
           task_for_proc->add_at_head(new common::Node<task::Task *>(curr->el));
	   all_comb->add_at_head(new common::Node<common::List<Task *> * >(task_for_proc)); // sauvgareder la liste ex: {t1}, {t1,t2}
           //std::cout<< " combinaison added " <<std::endl;
	   ts->remove(curr->el);
	   // std::cout<< " element supp " <<std::endl;
	   // std::cout<< " liste size " << ts->size <<std::endl;
	   //list_tmp =ts;
	   //if( ts-> size == 0) {std::cout<< " liste vide " <<std::endl;}
          
	   list_of_combinaison(ts,processors); 
         

	curr=curr->next;
      }
      std::cout<< " Processeur num= " << proc_curr->el->_id()  <<std::endl;
      all_comb->display();
     proc_curr=proc_curr->next;
    }
   
    
  }


 }
