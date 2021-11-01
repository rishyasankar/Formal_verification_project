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
    u_turn_vio = 0;
    r_vio = 0;
    mis_dir_cnt = 0;
    create_segments();
    create_possible_routes();
    car_pos_signal_map();


    while(t<750){
      init_crash_count = 0;
      filled_slot_info(t);
      //if(rand()%2){
      if( t % 4 == 0 ){
        generate_car(total_cars);
        total_cars = total_cars + 1;
      }
      red_vio_pre_check();
      u_turn_precheck();
      junction_pre_check_for_crash();
      
      update_all_car_pos();
      
      junction_pos_check_for_crash();
      u_turn_poscheck();
      red_vio_pos_check();
      r_vio = r_vio + check_r_vio();
      u_turn_vio = u_turn_vio + check_utrun_vio();
      total_crash = total_crash + check_crash();
      t=t+1;
      t=t+1;
    }
    //std::cout<<"Total car before func"<<total_cars<<'\n';
    final_pos_car();
    rem_cars = car_remaining_in_grid();
    std::cout<<"Total completed cars = "<<total_completed_cars<<'\n';

    no_col_in_slot = collision_in_a_segment(total_cars,total_completed_cars+rem_cars);
    std::cout<<"Total collisions in a slot = "<<no_col_in_slot<<'\n';
    std::cout<<"U turn violations = "<<u_turn_vio<<'\n';
    std::cout<<"R violations = "<<r_vio<<'\n';
    std::cout<<"Misdirection = "<<mis_dir_cnt<<'\n';
    std::cout<<"Total crashes = "<<total_crash;
    clear();
    
}