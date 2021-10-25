#include <iostream>
using namespace std;

#include <queue>

#define NUM_JUNCTIONS 9
#define NUM_SIGNALS 4

int il[NUM_JUNCTIONS][NUM_SIGNALS] = {{0,1,1,1}, {0,1,1,1}, {0,0,1,1}, {0,1,1,1}, {1,1,1,1}, {0,1,1,1}, {0,0,1,1}, {0,1,1,1}, {0,0,1,1}};
int p[NUM_JUNCTIONS][NUM_SIGNALS] = {{0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {0,1,1,0}, {1,1,0,1}, {0,1,0,0}, {0,0,0,0}, {0,0,0,1}, {0,0,0,0}};

void scheduler (queue <int> q, int jun[], int priority, int pri[]) {
  int new_light = q.front ();
  q.pop ();
  if (priority == 0) {
    //simple round robin
    if (jun[new_light] != 0) {
      jun[new_light] = 2; //set to green
      std::cout << new_light <<"\n";
      q.push (new_light);
      return;
    } else {
      q.push (new_light);
      scheduler (q, jun, priority, pri);
    }
  } else {
    //set to green for the signal with priority = 1
    if (jun[new_light] != 0 && pri[new_light] == 1) {
      jun[new_light] = 2;
      std:: cout << "new light from priority " << new_light << "\n";
      pri[new_light] = 0;
      q.push (new_light);
      return;
    } else {
      q.push (new_light);
      scheduler (q, jun, priority, pri);
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
      if (p[i][j] == 1) {
        priority = 1;
      }
      q.push (j);
    }
    scheduler (q, il[i], priority, p[i]);
  }
}

int main () {
  controller ();
  return 0;
}

