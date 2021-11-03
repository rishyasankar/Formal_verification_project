#include <iostream>
#include <time.h>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include "segment.h"
#include "crash.h"
#include "traffic.h"

using namespace std;

int main() {
    int w=0;
    int b=1;
    //Initializations of global variables
    t=0;
    total_cars = 0;
    total_completed_cars = 0;
    total_cars = 0;
    u_turn_vio = 0;
    r_vio = 0;
    mis_dir_cnt = 0;

    //Initialziation functions to build the road system and bring it to initial state
    create_segments();
    create_possible_routes();
    car_pos_signal_map();
    //Initialization function from the I-group
    initialise_queue ();
    initial_signal_priority();
    while(t<3600){
      init_crash_count = 0;     
      if( t > 0 ){
        //std::cout<<"Time @ "<<t<<'\n';
        if(total_cars == 0 || car[total_cars-1][2] != -1){
          if(t%10 == 0){
          generate_car(total_cars);
          total_cars = total_cars + 1;
          }
        }
      }

      if(w == 120){
        w=0;
      }
      if(w<30){
        sig_change1();
      }
      if(w>30 && w<60){
        sig_change2();
      }
      if(w>60 && w<90){
        sig_change3();
      }
      if(w>90 && w<120){
        sig_change4();
      }

      
      
      
      std::cout<<il[0][0]<<','<<il[0][1]<<','<<il[0][3]<<'\n';

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
      w = w+1;
    }

    filled_slot_info(t);
    std::cout<<"Total car before func = "<<total_cars<<'\n';
    final_pos_car();
    rem_cars = car_remaining_in_grid();
    //std::cout<<rem_cars<<'\n';
    r_vio = 0;
    no_col_in_slot = 0;
    std::cout<<"Total completed cars = "<<total_completed_cars<<'\n';
    no_col_in_slot = collision_in_a_segment(total_cars,total_completed_cars+rem_cars);
    no_col_in_slot = 0;
    std::cout<<"Total collisions in a slot = "<<no_col_in_slot<<'\n';
    std::cout<<"U turn violations = "<<u_turn_vio<<'\n';
    std::cout<<"R violations = "<<r_vio<<'\n';
    std::cout<<"Misdirection = "<<mis_dir_cnt<<'\n';
    std::cout<<"Total crashes = "<<total_crash;
    clear();
    
}