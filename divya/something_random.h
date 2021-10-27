#include <queue>
#include <algorithm>
using namespace std;

#define NUM_JUNCTIONS 9
#define NUM_SIGNALS 4


// Global variables
extern int il[NUM_JUNCTIONS][NUM_SIGNALS];
extern int p_light[NUM_JUNCTIONS][NUM_SIGNALS];
extern int segment[25][30];
int count1[NUM_JUNCTIONS][NUM_SIGNALS];
int segment_info[NUM_JUNCTIONS][NUM_SIGNALS] = {{14, 100, 100, 1}, {21, 0, 100, 3}, {5, 2, 100, 100}, {12, 100, 15, 17}, {22, 16, 20, 19}, {7, 18, 4, 100}, {100, 100, 13, 10}, {100, 11, 23, 8}, {100, 9, 6, 100}};
/*
void initialise_queue (queue <int> q[]) {
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    for (int j = 0; j < NUM_SIGNALS; j++) {
      q[i].push (j);
    }
  }
}
*/

int get_car_count_from_segment (int seg[]) {
  std::cout << "here 5\n";
  int cnt = 0;
  for (int i = 29; i > 18; i--) {
    std::cout << "here 4" << "\n";
    if (seg[i] > 0) {
      std::cout << "here" << seg[i] << "\n";
      cnt++;
    } else {
      std::cout << "here 7\n";
    }
  }
  return cnt;
}

void check_priority (int seg[]) {
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    for (int j = 0; j < NUM_SIGNALS; j++) {
      if (p_light[i][j] > 0) {
        std::cout  << "here 2\n";
        count1[i][j] = get_car_count_from_segment (seg);
        std::cout << "here 3" << count1[i][j] << "\n";
      } else {
        count1[i][j] = 0;
      }
      std::cout << "count of cars for i, j " <<i<<j<< " " << count1[i][j] << "\n";
    }
  }
}

int compare_priority (int car_count[]) {
  int signal_info=0;
  for (int c = 1; c < NUM_SIGNALS; c++) {
    if (car_count[c-1] > car_count[c]) {
      signal_info = c-1;
    }
  }
  return signal_info;
}

// TO DO:
// 1) Add queue as global and each junction should have its own queue
// 2) Remove duplicate code and add more functions
// 3) Have a main function which calls initialise_signal at only t=0 and update_priority and controller at every t=2sec 
// 4) For the python plot, find way for a) plotting 4 different values at single point and differentiate between them b) plotting all values in a simple way 
void scheduler (queue <int> q, int jun[], int priority, int pri[], int first) {
  int new_light = q.front ();
  q.pop ();
  if (priority == 0) {
    //at first junction, always allow cars from node A if no other car is returning back to A
    if (first == 0) {
      jun[1] = 2; //change to the signal which faces A
      std::cout << "0\n";
      return;
    }
    //simple round robin
    if (jun[new_light] != 0) {
      jun[new_light] = 2; //set to green
      std::cout << new_light <<"\n";
      q.push (new_light);
      return;
    } else {
      q.push (new_light);
      scheduler (q, jun, priority, pri, first);
    }
  } else {
    //if multiple signals hasve priority as 1, take the signal with highest numer of cars from segments 19 to 29 
    int k = segment_info[first][new_light];
    std::cout<<"here 6"<<k<<"\n";
    check_priority (segment[k]);
    int x = compare_priority (count1[first]);
    //if priority = 1 and light is off, change the priority to 0
    if (jun[new_light] == 0 && pri[new_light] > 0) {
      priority = 0;
      q.push (new_light);
      scheduler (q, jun, priority, pri, first);
    }
    //set to green for the signal with priority = 1
    else if (jun[new_light] != 0 && pri[new_light] > 0) {
      // else if ( "" && new_light == x) {
      jun[new_light] = 2;
      std:: cout << "new light from priority " << new_light << "\n";
      pri[new_light] = 0;
      q.push (new_light);
      return;
    } else {
      q.push (new_light);
      scheduler (q, jun, priority, pri, first);
    }
  }
}

void controller () {
  std::cout << "hi\n";
  //add signal information as inputs may be (should be global)
  //each signal should have information about whether its red or green and which junction it belongs to
  //use simple round robin alogorithm to turn one of them green in each junction
  //always turn green lights red and then turn red lights into green
  //this should be done for each junction parallely (ideally)
  //simple round robin can be changed based on vehicle information
  //signal is in form of il[i][j]
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    queue <int> q;
    int priority = 0;
    for (int j = 0; j < NUM_SIGNALS; j++) {
      if (il[i][j] == 2) {
        il[i][j] = 1; //change the green signals to red
      }
      if (p_light[i][j] > 0) {
        priority = 1;
      }
      q.push (j);
    }
    scheduler (q, il[i], priority, p_light[i], i);
  }
  // print il[i][j] => to verify only one green light is there at each junction
  std::cout << "lights\n";
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    for (int j = 0; j < NUM_SIGNALS; j++) {
      std::cout << il[i][j] << " ";
    }
    std::cout << "\n";
  }
}
