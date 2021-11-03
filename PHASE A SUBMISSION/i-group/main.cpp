#include <iostream>
using namespace std;

#include "signal.h"
#include "trafficinfo.h"

int il[NUM_JUNCTIONS][NUM_SIGNALS];
int p_light[NUM_JUNCTIONS][NUM_SIGNALS];
int segment[24][30];
int next_segment_info_uturn[24][30];

int main () {
  initialise_queue ();
  int time = 0;
  
  assume_traffic5();
  initial_signal_priority(); 
  priority_signal();
  while (time < 3600) {
    controller (time);
    check_green_light_violations ();
    //check_uturn_violations ();
    //check_red_light_violations ();
    //check_collision ();
    time = time + 2;
    /*if (time == 2) {
      assume_traffic6 ();
    } else {
      assume_traffic7 ();
    }*/
  }
  return 0;
}

