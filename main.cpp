#include <iostream>
#include <time.h>
#include "segment.h"
using namespace std;




int main() {
    t=0;
    total_cars = 0;
    create_segments();
    create_possible_routes();
    
    
    
    while(t<5){

      std::cout<<"Do you want to generate a car @ "<<t<<" [1] Yes [0] No : ";
      std::cin>>n;
      if(n == 1){
        generate_car(total_cars);
        total_cars = total_cars + 1;
      }

      //filled_slot_info(t);
      update_all_car_pos();





      t=t+1;




      t=t+1;
    }

    clear();
    
}