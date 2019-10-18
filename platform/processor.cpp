#include "processor.hpp"
#include <cmath>
#include <map>

#include <algorithm>  

#define EXACT_PREEMP  0
#define APROX_PREEMP  1
#define EXACT_NPEEMP  2


using namespace std;

namespace processor {

 Processor::Processor(int id, int TAG){

    this->id = id;
    this->TAG = TAG;
    
  }

  Processor::~Processor(){
    // do not forget to destroy the malloc of the grap table !!
    // do not forget to destroy all the conc and sep.
  }
 int Processor::_id(){
    return id;
  }
  
  void Processor::_id(int id){
    this->id = id;
  }

 
  int Processor::_TAG(){
    return TAG;
  }
  
  void  Processor::_TAG(int TAG){
    this->TAG = TAG;
  }

}

