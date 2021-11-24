#include "queue.h"
#include "segment.h"
#include "crash.h"
#include "controller.h"
#include "signal.h"



int main() {

    t=0;
    total_completed_cars = 0;
    r_vio = 0;

    create_segments();
    create_possible_routes();
    car_pos_signal_map();

    initialise_queue ();
    initial_signal_priority();
    generate_car(0);
    while(t<6){


      if(t%4 == 0){
      controller(t);
      }





      if(t<500){
        il[0][0]=1;
        il[0][1]=2;
        il[0][2]=0;
        il[0][3]=1;
      }

      if(t>2999){
      if( t%3 == 0){
        il[0][0]=1;
        il[0][1]=1;
        il[0][2]=0;
        il[0][3]=2;
      } else {
        il[0][0]=2;
        il[0][1]=1;
        il[0][2]=0;
        il[0][3]=1;
      }

      }
      
      
      red_vio_pre_check();
      update_all_car_pos();
      
      red_vio_pos_check();

      r_vio = r_vio + check_r_vio();

      
      
      t=t+1;
      t=t+1;
    }


    clear();
return 0;
} 
