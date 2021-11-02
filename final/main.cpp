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

/*
  for(int i = 0; i <= 23; i++) {
    for(int j = 0; j <= 29; j++) {
      segment[i][j] = 0;
    }
  }
  //segment21
  segment[21][29]=1;
  segment[21][27]=4;
  segment[21][18]=7;
  segment[21][20]=5;

  //segment22
  segment[22][29]= 3 ;
  segment[22][23]= 4;
  segment[22][25]= 5;
  segment[22][19]= 6;
  segment[22][22]= 7;
  segment[22][12]= 8;
  segment[22][24]= 0;

  //segment17
  segment[17][29]= 6 ;
  segment[17][23]= 9 ;
  segment[17][28]=12 ;

  //segement18
  segment[18][29]= 23;

  //segment19
  segment[19][29]= 27;

  //segment20
  segment[20][29]= 12;
  segment[20][28]= 13 ;
  segment[20][27]= 14;
  segment[20][26]= 15;
  segment[20][25]= 16;
  segment[20][24]= 17;
  segment[20][23]= 18;
  segment[20][22]= 19;

  //segment23
  segment[23][29]= 20;

  //segment16
  segment[16][29]= 34;
  segment[16][18]= 35;
*/
  
  priority_signal();
  while (time < 3600) {
    controller (time);
    //check_green_light_violations ();
    //check_uturn_violations ();
    //check_red_light_violations ();
    check_collision ();
    time = time + 2;
    if (time == 2) {
      assume_traffic6 ();
    } else {
      assume_traffic7 ();
    }
  }
  
  return 0;
}





