//Global variables
 //Time variable
int t;
//Contains empty slots as 0 and filled slots with Carid
int segment[24][30]; 
//Possible routes variable
int *route[15];
//Cars generation variable
int *car[900];
//Car generation decision variable
bool n; 
//total number of cars
unsigned int total_cars;
//total completed cars
int total_completed_cars;
//remaining cars
int rem_cars;
//Total crash count
int total_crash;
//variable to indicate crash at junction 0, when two cars try to complete at A in the same time
int init_crash_count;

//variable to indicate initial box where car is generated and returned // pos is assumed as -1,-1
int init;

//variable to count no of cars running in wri=ong direction
int mis_dir_cnt;

//Import from IV team 
#define NUM_JUNCTIONS 9
#define NUM_SIGNALS 4


//
int il[NUM_JUNCTIONS][NUM_SIGNALS] = {{2,2,2,2}, {2,2,2,2}, {2,2,2,2}, {2,2,2,2}, {2,2,2,2}, {2,2,2,2}, {2,2,2,2}, {2,2,2,2}, {2,2,2,2}};

//Variable to store signal to car pos
int signal[24][2];


//Create segments needed
//24 segments - 12(total) sides * 2 ways
void create_segments(){
  for(int j=0;j<24;j++){
    for(int i=0;i<30;i++){
      segment[j][i] = 0;
    }
  }
}

//Hashmap for road signal and car pos
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

//Print out the filled slot info
void filled_slot_info (int time){
  std::cout<<"@Time : "<<time<<"\n";
  for(int j=0;j<24;j++){
    for(int i=0;i<30;i++){
      std::cout<<segment[j][i]<<",";
    }
    std::cout<<"\n";
  }

}

//List of possible legal routes to pick from
void create_possible_routes(){
  route[0] = new int[9];
  route[0][0]=8;route[0][1]=0;route[0][2]=2;route[0][3]=4;route[0][4]=6;route[0][5]=8;route[0][6]=10;route[0][7]=12;route[0][8]=14;
  
  route[1] = new int[13];
  route[1][0]=12;route[1][1]=15;route[1][2]=13;route[1][3]=11;route[1][4]=23;route[1][5]=21;route[1][6]=2;route[1][7]=4;route[1][8]=6;route[1][9]=8;route[1][10]=10;route[1][11]=12;route[1][12]=14;

  route[2] = new int[9];
  route[2][0]=8;route[2][1]=15;route[2][2]=13;route[2][3]=11;route[2][4]=9;route[2][5]=7;route[2][6]=5;route[2][7]=3;route[2][8]=1;

  route[3] = new int[13];
  route[3][0]=12;route[3][1]=15;route[3][2]=13;route[3][3]=11;route[3][4]=23;route[3][5]=21;route[3][6]=2;route[3][7]=4;route[3][8]=6;route[3][9]=8;route[3][10]=23;route[3][11]=21;route[3][12]=1;

  route[4] = new int[13];
  route[4][0]=12;route[4][1]=15;route[4][2]=13;route[4][3]=11;route[4][4]=23;route[4][5]=21;route[4][6]=2;route[4][7]=4;route[4][8]=6;route[4][9]=8;route[4][10]=23;route[4][11]=17;route[4][12]=14;

  route[5] = new int[13];
  route[5][0]=12;route[5][1]=15;route[5][2]=13;route[5][3]=11;route[5][4]=23;route[5][5]=21;route[5][6]=2;route[5][7]=4;route[5][8]=6;route[5][9]=8;route[5][10]=23;route[5][11]=21;route[5][12]=1;

  route[6] = new int[15];
  route[6][0]=14;route[6][1]=0;route[6][2]=2;route[6][3]=4;route[6][4]=19;route[6][5]=22;route[6][6]=10;route[6][7]=12;route[6][8]=16;route[6][9]=18;route[6][10]=6;route[6][11]=8;route[6][12]=23;route[6][13]=17;route[6][14]=14;

  route[7] = new int[15];
  route[7][0]=14;route[7][1]=0;route[7][2]=2;route[7][3]=4;route[7][4]=19;route[7][5]=22;route[7][6]=10;route[7][7]=12;route[7][8]=16;route[7][9]=18;route[7][10]=6;route[7][11]=8;route[7][12]=23;route[7][13]=21;route[7][14]=1;

  route[8] = new int[15];
  route[8][0]=14;route[8][1]=0;route[8][2]=2;route[8][3]=4;route[8][4]=19;route[8][5]=22;route[8][6]=10;route[8][7]=12;route[8][8]=16;route[8][9]=18;route[8][10]=6;route[8][11]=8;route[8][12]=10;route[8][13]=12;route[8][14]=14;

  route[9] = new int[13];
  route[9][0]=12;route[9][1]=0;route[9][2]=2;route[9][3]=4;route[9][4]=19;route[9][5]=17;route[9][6]=13;route[9][7]=11;route[9][8]=9;route[9][9]=7;route[9][10]=5;route[9][11]=3;route[9][12]=1;

  route[10] = new int[13];
  route[10][0]=12;route[10][1]=0;route[10][2]=2;route[10][3]=4;route[10][4]=19;route[10][5]=17;route[10][6]=13;route[10][7]=11;route[10][8]=9;route[10][9]=7;route[10][10]=19;route[10][11]=21;route[10][12]=1;

  route[11] = new int[13];
  route[11][0]=12;route[11][1]=0;route[11][2]=2;route[11][3]=4;route[11][4]=19;route[11][5]=17;route[11][6]=13;route[11][7]=11;route[11][8]=9;route[11][9]=7;route[11][10]=19;route[11][11]=17;route[11][12]=14;

  route[12] = new int[17];
  route[12][0]=16;route[12][1]=0;route[12][2]=2;route[12][3]=4;route[12][4]=19;route[12][5]=17;route[12][6]=13;route[12][7]=11;route[12][8]=9;route[12][9]=7;route[12][10]=5;route[12][11]=3;route[12][12]=20;route[12][13]=22;route[12][14]=10;route[12][15]=12;route[12][16]=14;

  route[13] = new int[13];
  route[13][0]=12;route[13][1]=15;route[13][2]=16;route[13][3]=21;route[13][4]=2;route[13][5]=4;route[13][6]=6;route[13][7]=8;route[13][8]=10;route[13][9]=12;route[13][10]=16;route[13][11]=21;route[13][12]=1;

  route[14] = new int[11];
  route[14][0]=10;route[14][1]=15;route[14][2]=16;route[14][3]=21;route[14][4]=2;route[14][5]=4;route[14][6]=6;route[14][7]=8;route[14][8]=10;route[14][9]=12;route[14][10]=15;

}


void generate_car(int id){
  // An array containing [array_len,id,segment,pos in segment,list of segments as routes]
  //srand ( time(NULL) ); //initialize the random seed
  int RandIndex = rand() % 15; //std::cout<<"Rand index :"<< RandIndex<<'\n';
  car[total_cars] = new int[5+route[RandIndex][0]];
  car[total_cars][0] = 5+route[RandIndex][0]; //std::cout<<car[total_cars][0]<<',';//Length of each car array
  car[total_cars][1] = total_cars+1;    //std::cout<<car[total_cars][1]<<','; // This stores the car_id
  car[total_cars][2] = -1;car[total_cars][3] = -1;  //std::cout<<car[total_cars][2]<<','<<car[total_cars][3]; // The index [2] stores which segment and [3] stores position in the segment
  car[total_cars][4] = -1; //std::cout<<','<<car[total_cars][4];// Stores current segment information
  init = car[total_cars][1];
  for(int i=0;i<route[RandIndex][0];i++){
    car[total_cars][i+5] = route[RandIndex][i+1];
    //std::cout<<','<<car[total_cars][i+5]; //Rest of the array stores sequence of segment numbers which is the route.
  }
  //std::cout<<"\n";
}


void update_car(int id){
  
  int car_array_len = car[id][0];
  int car_route_len = car[id][0]-5;
  int y_pre,y_pos;

  y_pre = car[id][3];
  if(car[id][2] == -1 && car[id][3] == -1 && car[id][4] == -1){
    if (segment[car[id][5]][0] == 0 && (il[0][1] == 2)){
      //segment[car[id][2]][car[id][3]]=0;
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
          if(il[0][0] == 2 || il[0][3] == 2)
          //std::cout<<car[id][2]<<','<<car[id][3]<<'\n';
            segment[car[id][2]][car[id][3]]=0;
            car[id][2] = 30;
            car[id][3] = 30;
            init_crash_count = init_crash_count+1;
        }   
        else if (car[id][4] < car_array_len-1){
          if((segment[car[id][car[id][4]+1]][0] == 0) &&     (il[signal[car[id][car[id][4]]][0]][signal[car[id][car[id][4]]][1]] == 2)) {
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
        //delete car[id];
      }
    }

    y_pos = car[id][3];
    if(y_pre > y_pos && y_pre != 29){
      mis_dir_cnt = mis_dir_cnt + 1;
    }
}

void print_car_info(int b){
  if(car[b][2] != 29 && car[b][3] != 30){
    for(int z=0;z<car[b][0];z++){
      //std::cout<<car[b][z]<<",";
    }
  //std::cout<<'\n';
  }
}


void update_all_car_pos(){
  for(int l=0;l<total_cars;l++){
    
    update_car(l);
    //print_car_info(l);
  }
}


void clear(){
  
  for(int j=0;j<15;j++){
    delete route[j];
  }

  for(int i=0; i< total_cars ; i++){
    //if(car[i][2] != 29 && car[i][3] == 30){
      delete car[i];
    //}
  }

}

void final_pos_car(){
  //std::cout<<"Total cars = "<<total_cars<<'\n';
  for(int l=0;l<total_cars;l++){
    //if(car[l][2] != 29 && car[l][3] == 30){
      int length_car = car[l][0];
      for(int m=0;m<length_car;m++){
        //std::cout<<car[l][m]<<',';
      }
      //std::cout<<'\n';
   //}
  }
}