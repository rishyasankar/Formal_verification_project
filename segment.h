int t;
int segment[24][30]; 


int *route[19];
int *car[900];
bool n; 
int total_completed_cars;
int rem_cars;
int init;
int signal[24][2];



int il[9][4] = {{2,2,0,2}, {2,2,0,2}, {2,2,0,0}, {2,0,2,2}, {2,2,2,2}, {2,2,2,0}, {0,0,2,2}, {0,2,2,2}, {0,2,2,0}};



int arr[19] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
int freq[19] = {10,7,10,7,7,7,5,5,5,7,7,7,5,9,5,5,7,7,7};
int ii, nn = sizeof(arr) / sizeof(arr[0]);

void create_segments(){
  for(int j=0;j<24;j++){
    for(int i=0;i<30;i++){
      segment[j][i] = 0;
    }
  }
}

void car_pos_signal_map(){
  signal[0][0] = 1 ; signal[0][1] = 1;
  signal[1][0] = 0 ; signal[1][1] = 3;
  signal[2][0] = 2 ; signal[2][1] = 1;
  signal[3][0] = 1 ; signal[3][1] = 3;
  signal[4][0] = 5 ; signal[4][1] = 2;
  signal[5][0] = 2 ; signal[5][1] = 0;
  signal[6][0] = 8 ; signal[6][1] = 2;
  signal[7][0] = 5 ; signal[7][1] = 0;
  signal[8][0] = 7 ; signal[8][1] = 3;
  signal[9][0] = 8 ; signal[9][1] = 1;
  signal[10][0] = 6 ; signal[10][1] = 3;
  signal[11][0] = 7 ; signal[11][1] = 1;
  signal[12][0] = 3 ; signal[12][1] = 0;
  signal[13][0] = 6 ; signal[13][1] = 2;
  signal[14][0] = 0 ; signal[14][1] = 0;
  signal[15][0] = 3 ; signal[15][1] = 2;
  signal[16][0] = 4 ; signal[16][1] = 1;
  signal[17][0] = 3 ; signal[17][1] = 3;
  signal[18][0] = 5 ; signal[18][1] = 1;
  signal[19][0] = 4 ; signal[19][1] = 3;
  signal[20][0] = 4 ; signal[20][1] = 2;
  signal[21][0] = 1 ; signal[21][1] = 0;
  signal[22][0] = 7 ; signal[22][1] = 2;
  signal[23][0] = 4 ; signal[23][1] = 0;

}

void create_possible_routes(){
  route[0] = new int[9];
  route[0][0]=8;route[0][1]=0;route[0][2]=2;route[0][3]=4;route[0][4]=6;route[0][5]=8;route[0][6]=10;route[0][7]=12;route[0][8]=14;

}


void generate_car(int id){
  car[0] = new int[5+route[0][0]];
  car[0][0] = 5+route[0][0]; //Length of each car array
  car[0][1] = 1;     // This stores the car_id
  car[0][2] = -1;car[0][3] = -1;   // The index [2] stores which segment and [3] stores position in the segment
  car[0][4] = -1; // Stores current segment information
  init = car[0][1];
  for(int i=0;i<route[0][0];i++){
    car[0][i+5] = route[0][i+1];
  }
}


void update_car(int id){
  
  int car_array_len = car[id][0];
  int car_route_len = car[id][0]-5;
  int y_pre,y_pos;

  y_pre = car[id][3];
  if(car[id][2] == -1 && car[id][3] == -1 && car[id][4] == -1){
    if (segment[car[id][5]][0] == 0 && (il[0][1] == 2)){
      car[id][4] = 5; car[id][2] = car[id][car[id][4]]; car[id][3] = 0;segment[car[id][2]][car[id][3]]=car[id][1];
    }
  }
  else {
    if( (segment[car[id][2]][car[id][3]+1] == 0) && car[id][3] < 29){
      segment[car[id][2]][car[id][3]]=0;
      car[id][3] = car[id][3]+1;
      segment[car[id][2]][car[id][3]]=car[id][1];
    } 
    else 
      if (car[id][3] == 29) {
        
        if(car[id][4] == car_array_len-1){
          if((il[0][0] == 2 && car[id][car[id][4]] == 14 )  || (il[0][3] == 2 && car[id][car[id][4]] == 1)) {
          
            segment[car[id][2]][car[id][3]]=0;
            car[id][2] = 30;
            car[id][3] = 30;
          }
        }   
        else if (car[id][4] < car_array_len-1){
          if((segment[car[id][car[id][4]+1]][0] == 0) &&  (il[signal[car[id][car[id][4]]][0]][signal[car[id][car[id][4]]][1]] == 2)) {
          segment[car[id][2]][car[id][3]]=0;
          car[id][4] = car[id][4] + 1;
          car[id][2] = car[id][car[id][4]];
          car[id][3] = 0;
          segment[car[id][2]][car[id][3]]=car[id][1];
          }
        }
      }
      else if(car[id][3] == 30 && car[id][2] == 30){
        total_completed_cars = total_completed_cars+1;
        car[id][2] = 29;
      }
    }

    y_pos = car[id][3];
}


void update_all_car_pos(){
  for(int l=0;l<1;l++){
    
    update_car(l);
  }
}


void clear(){
  
  for(int j=0;j<19;j++){
    delete route[j];
  }

  for(int i=0; i< 1 ; i++){
      delete car[i];
  }

}

void final_pos_car(){
  for(int l=0;l<1;l++){
      int length_car = car[l][0];
  }
}
