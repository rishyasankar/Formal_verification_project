#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define NUM_JUNCTIONS 9
#define NUM_SIGNALS 4
#define INVALID_SEGMENT 100

// global variables
extern int il[NUM_JUNCTIONS][NUM_SIGNALS];
extern int p_light[NUM_JUNCTIONS][NUM_SIGNALS];
extern int segment[25][30];
int segment_info[NUM_JUNCTIONS][NUM_SIGNALS] = {{14, 100, 100, 1}, {21, 0, 100, 3}, {5, 2, 100, 100}, {12, 100, 15, 17}, {22, 16, 20, 19}, {7, 18, 4, 100}, {100, 100, 13, 10}, {100, 11, 23, 8}, {100, 9, 6, 100}};
vector<queue<int>> q(NUM_JUNCTIONS);

void initialise_queue () {
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    for (int j = 0; j < NUM_SIGNALS; j++) {
      q[i].push (j);
    }
  }
}

int get_car_count_from_segment (int segmentno) {
  int cnt = 0;
  if (segmentno == INVALID_SEGMENT) {
    return 0;
  }
  for (int i = 29; i > 18; i--) {
    if (segment[segmentno][i] > 0) {
      cnt++;
    }
  }
  return cnt;
}

int check_priority (int num_cars[]) {
  int index = 0;
  for (int i = 1; i < NUM_SIGNALS; i++) {
    if (num_cars[index] < num_cars[i]) {
      index = i;
    }
  }
  return index;
}

void scheduler (queue <int> q, int jun[], int priority, int pri[], int first, int num_cars[]) {

  if (q.empty ()) {
    initialise_queue ();
    scheduler (q, jun, priority, pri, first, num_cars);
    return;
  }

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
      scheduler (q, jun, priority, pri, first, num_cars);
      return;
    }

  } else {
    int high_pri = check_priority (num_cars);

    //if priority = 1 and light is off, change the priority to 0
    if (jun[new_light] == 0) {
      q.push (new_light);
      scheduler (q, jun, priority, pri, first, num_cars);
      return;
    } else if (jun[new_light] != 0 && new_light == high_pri) {
      //set to green for the signal with priority = max_cars
      jun[new_light] = 2;
      q.push (new_light);
      return;
    } else {
      q.push (new_light);
      scheduler (q, jun, priority, pri, first, num_cars);
      return;
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
    int priority = 0;
    int num_cars[NUM_SIGNALS] = {0};
    for (int j = 0; j < NUM_SIGNALS; j++) {
      if (il[i][j] == 2) {
        il[i][j] = 1; //change the green signals to red
      }
      if (p_light[i][j] > 1) {
        priority = 1;
        int segmentno = segment_info[i][j];
        num_cars[j] = get_car_count_from_segment (segmentno);
      }
      q[i].push (j);
    }
    scheduler (q[i], il[i], priority, p_light[i], i, num_cars);
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
