void initialise_queue () {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 4; j++) {
      insert (j, i);
    }
  }
}

void scheduler (int jun[], int first) {
  int new_light = peek (first);
  removeData (first);

    if (jun[new_light] != 0) {
      jun[new_light] = 2; //set to green
      insert (new_light, first);
      return;
    } else {
      insert (new_light, first);
      scheduler (jun, first);
      return;
    }

}

void controller (int time) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 4; j++) {
      if (il[i][j] == 2) {
        il[i][j] = 1; //change the green signals to red
      }
    }
    scheduler (il[i], i);
  }
}






