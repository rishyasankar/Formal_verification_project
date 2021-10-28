#include <iostream>
#include <time.h>
#include <map>
#include <string>
#include "segment.h"

using namespace std;

int main() {
    t=0;
    total_cars = 0;
    total_completed_cars = 0;
    create_segments();
    create_possible_routes();
    car_pos_signal_map();
    
    
    
    


    while(t<3600){
      
      //filled_slot_info(t);
      
      //if(rand()%2){
      if( t % 4 == 0 ){
        generate_car(total_cars);
        total_cars = total_cars + 1;
      }
      
      update_all_car_pos();





      t=t+1;




      t=t+1;
    }
    std::cout<<"Total car before func"<<total_cars<<'\n';
    final_pos_car();
    std::cout<<"Total completed cars = "<<total_completed_cars;
    clear();
    
}