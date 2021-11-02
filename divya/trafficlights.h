#include <queue>

il[9][4] = {0};
vector<queue<int>> q(9);

void initialise_queue () {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 4; j++) {
      q[i].push (j);
    }
  }
}

void switch_light () {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 4; j++) {
      if (il[i][j] == 2) {
        il[i][j] = 1;
      }
    }
    int new_light = q[i].front ();
    q[i].pop ();
    il[i][new_light] = 2;
    q[i].push (new_light);
  }
}

int main () {
  int time = 0;
  initialise_queue ();
  while (time < 3600) {
    switch_light ();
    time = time + 2;
  }
}
