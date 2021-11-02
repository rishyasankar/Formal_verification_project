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
extern int segment[24][30];
vector<queue<int>> q(NUM_JUNCTIONS);

int segment_info[NUM_JUNCTIONS][NUM_SIGNALS] = {{14, 100, 100, 1}, {21, 0, 100, 3}, {5, 2, 100, 100}, {12, 100, 15, 17}, {22, 16, 20, 19}, {7, 18, 4, 100}, {100, 100, 13, 10}, {100, 11, 23, 8}, {100, 9, 6, 100}};

int uturn_segment_info[NUM_JUNCTIONS][NUM_SIGNALS] = {{15, 100, 100, 0}, {20, 1, 100, 2}, {4, 3, 100, 100}, {13, 100, 14, 16}, {23, 17, 21, 18}, {6, 19, 5, 100}, {100, 100, 12, 11}, {100, 10, 22, 9}, {100, 8, 7, 100}};

extern int next_segment_info_uturn[24][30];

void check_uturn_violations () {
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    for (int j = 0; j < NUM_SIGNALS; j++) {
      int segno = segment_info[i][j];
      int uturn_segno = uturn_segment_info[i][j];
      if (segno == INVALID_SEGMENT || uturn_segno == INVALID_SEGMENT) {
        std::cout << "No U-Turn violation at junction " << i << " and light " << j << "\n";
      } else if ((segment[segno][29] == next_segment_info_uturn[uturn_segno][0]) && segment[segno][29] != 0) {
        std::cout << "U-Turn violation at junction " << i << " and light " << j << "\n";
      } else {
        std::cout << "No U-Turn violation at junction " << i << " and light " << j << "\n";
      }
    }
  }
}
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

void scheduler (int jun[], int priority, int pri[], int first, int num_cars[]) {

  if (q[first].empty ()) {
    initialise_queue ();
    scheduler (jun, priority, pri, first, num_cars);
    return;
  }

  int new_light = q[first].front ();
  q[first].pop ();

  if (priority == 0) {
    
    //at first junction, always allow cars from node A if no other car is returning back to A
    if (first == 0) {
      jun[1] = 2; //change to the signal which faces A
      return;
    }

    //simple round robin
    if (jun[new_light] != 0) {
      jun[new_light] = 2; //set to green
      q[first].push (new_light);
      return;
    } else {
      q[first].push (new_light);
      scheduler (jun, priority, pri, first, num_cars);
      return;
    }

  } else {
    int high_pri = check_priority (num_cars);

    //if priority = 1 and light is off, change the priority to 0
    if (jun[new_light] == 0) {
      q[first].push (new_light);
      scheduler (jun, priority, pri, first, num_cars);
      return;
    } else if (jun[new_light] != 0 && new_light == high_pri) {
      //set to green for the signal with priority = max_cars
      jun[new_light] = 2;
      q[first].push (new_light);
      return;
    } else {
      q[first].push (new_light);
      scheduler (jun, priority, pri, first, num_cars);
      return;
    }
  }
}

void controller (int time) {
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
    }
    scheduler (il[i], priority, p_light[i], i, num_cars);
  }
  // print il[i][j] => to verify only one green light is there at each junction
  
  std::cout << "lights at time t = " << time << "\n";
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    std::cout << "intersection = " << i << "\n";
    for (int j = 0; j < NUM_SIGNALS; j++) {
      std::cout << il[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void check_green_light_violations () {
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    int green_signal_count = 0;
    for (int j = 0; j < NUM_SIGNALS; j++) {
      if (il[i][j] == 2) {
        green_signal_count++;
      }
    }
    if (green_signal_count > 1) {
      std::cout << "Green Signal Violations found at junction " << i << "\n";
    } else {
      std::cout << "No Green Signal Violations at the junction " << i << "\n";
    }
  }
}
/*
int next_segment_info[NUM_JUNCTIONS][NUM_SIGNALS][3] = {0};
int car_next_pos[3] = {0};

void get_car_next_position (int i, int j) {
  int car_next_pos[3] = {0};
  for (int k = 0; k < 3; k++) {
    int segno = next_segment_info[i][j][k];
    if (segno == INVALID_SEGMENT) {
      car_next_pos[k] = 0;
    } else {
      car_next_pos[k] = segment[segno][0];
    }
  }
}

int get_car_position (int i, int j) {
  int segno = segment_info[i][j];
  if (segno == INVALID_SEGMENT) {
    return 0;
  }
  return segment[segno][29];
}

bool check_collision (int car_current_pos) {
  for (int k = 0; k < 3; k++) {
    if (car_current_pos == car_next_pos[k]) {
      return true;
    }
  }
  return false;
}

void check_uturn_violations () {
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    for (int j = 0; j < NUM_SIGNALS; j++) {
      int segno = segment_info[i][j];
      int uturnsegno = next_segment_info[i][j];

    }
  }
}

void check_vehicle_collisions () {
  for (int i = 0; i < NUM_JUNCTIONS; i++) {
    int collision_count = 0;
    for (int j = 0; j < NUM_SIGNALS; j++) {
      int segno = segment_info[i][j];
      int car_current_pos = get_car_position (i, j);
      get_car_next_position (i, j);
      if (check_collision (car_current_pos)) {
        collision_count++;
      }
    }
    if (collision_count > 0) {
      std::cout << "Collision occured at junction " << i << "\n";
    } else {
      std::cout << "No Collision at junction " << i << "\n";
    }
  }
}*/
