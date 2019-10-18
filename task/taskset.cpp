#include "taskset.hpp"

#define SORT_UTI_DESC  0 
#define SORT_UTI_CROI  1
#define SORT_PREMP_AWARE  2

namespace task{
  
  int Taskset::_size(){
    return list->size;
  }

  common::List<Task *> *  Taskset:: _list(){
    return list;
  }

  Taskset::Taskset(int id){
    this->id = id;
  }

  Taskset::Taskset(int id, common::List<Task *> *tasks ){
    this->id = id;
    this->list = tasks;
  }

  Taskset::~Taskset(){

  }



 
  int Taskset::LCM(int a, int b){
    int x =a;
    int y = b;
    int t;
    while (b != 0) {
      t = b;
      b = a % b;
      a = t;
    }
    return (x*y)/a;
  }
  


  int Taskset::hyperperiod(){
    int hyper = 1;
    common::Node<Task *> *  curr = list->head;
    for (int i=0; i< list->size ; i++){
      hyper = LCM(hyper,curr->el->_T());
      curr = curr -> next;
    }
    return hyper;

  }


  void Taskset::read(char *arg){
    
  }


  void Taskset::write(char *arg){
    
  }
  


  void Taskset::sort(int METHOD){
     
     
  }



  double Taskset::utilization(){
    double U = 0;
    common::Node<Task *> *  curr = list->head;
    for (int i=0; i< list->size ; i++){
      U +=  curr->el->utilization();
      curr = curr -> next;
    }
    return U;
  }

  void Taskset::display(){
    common::Node<Task *> *  curr = list->head;
    for (int i=0; i< list->size ; i++){
      curr->display();
      curr = curr -> next;
    }
  }

  // common::List<common::List<task:: Task *> *> * Taskset::compute_MIN_Runtime_Overhead(){
       
  // }
}
