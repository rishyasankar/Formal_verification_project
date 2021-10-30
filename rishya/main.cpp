#include <iostream>
#include <time.h>
#include <map>
#include <string>
#include "segment.h"
#include "crash.h"
using namespace std;

int main() {
    t=0;
    total_cars = 0;
    total_completed_cars = 0;
    total_cars = 0;
    create_segments();
    create_possible_routes();
    car_pos_signal_map();


    while(t<3600){
      filled_slot_info(t);
      //if(rand()%2){
      if( t % 4 == 0 ){
        generate_car(total_cars);
        total_cars = total_cars + 1;
      }
      junction_pre_check_for_crash();
      update_all_car_pos();
      junction_pos_check_for_crash();
      total_crash = total_crash + check_crash();
      t=t+1;
      t=t+1;
    }
    //std::cout<<"Total car before func"<<total_cars<<'\n';
    final_pos_car();
    //std::cout<<"Total completed cars = "<<total_completed_cars<<'\n';
    //std::cout<<"Total crashes = "<<total_crash;
    clear();
    
}