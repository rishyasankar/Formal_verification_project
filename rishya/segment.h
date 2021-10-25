//Global variables
 //Time variable
int t;
//Contains empty slots as 0 and filled slots with Carid
int segment[24][30]; 
//Possible routes variable
int *route[2];
//Cars generation variable
int *car[100];
//Car generation decision variable
bool n;
//total number of cars
int total_cars;

//Create segments needed
//24 segments - 12(total) sides * 2 ways
void create_segments(){
  for(int j=0;j<24;j++){
    for(int i=0;i<30;i++){
      segment[j][i] = 0;
    }
  }
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
  route[0][0]=8;route[0][1]=1;route[0][2]=3;route[0][3]=5;route[0][4]=7;route[0][5]=9;route[0][6]=11;route[0][7]=13;route[0][8]=15;
  
  route[1] = new int[12];
  route[1][0]=12;route[1][1]=16;route[1][2]=14;route[1][3]=12;route[1][4]=24;route[1][5]=22;route[1][6]=3;route[1][7]=5;route[1][8]=7;route[1][9]=9;route[1][10]=11;route[1][11]=13;route[1][12]=15;

}

void generate_car(int id){
  // An array containing [array_len,id,segment,pos in segment,list of segments as routes]
  srand ( time(NULL) ); //initialize the random seed
  int RandIndex = rand() % 2;
  car[total_cars] = new int[4+route[RandIndex][0]];
  car[total_cars][0] = 3+route[RandIndex][0]; std::cout<<car[total_cars][0]<<',';//Length of each car array
  car[total_cars][1] = total_cars;    std::cout<<car[total_cars][1]<<','; // This stores the car_id
  car[total_cars][2] = -1;car[total_cars][3] = -1;  std::cout<<car[total_cars][2]<<','<<car[total_cars][3]; // The index [2] stores which segment and [3] stores position in the segment
  car[total_cars][4] = -1; // Stores current segment information
  for(int i=0;i<route[RandIndex][0];i++){
    car[total_cars][i+5] = route[RandIndex][i+1];
    std::cout<<','<<car[total_cars][i+5]; //Rest of the array stores sequence of segment numbers which is the route.
  }
  std::cout<<"\n";
}


void update_car(int id){
  
  int car_array_len = car[id][0];
  int car_route_len = car[id][0]-5;

  if(car[id][2] == -1 && car[id][3] == -1 && car[id][4] == -1){
    car[id][4] = 5; car[id][2] = car[id][car[id][4]]; car[id][3] = 0;
  }
  else {
    if(car[id][3] < 29){
      car[id][3] = car[id][3]+1;
    } 
    else 
      if (car[id][3] == 29) {
        if(car[id][4] == car_array_len){
          car[id][2] = 30;
          car[id][3] = 30;
        }  
        else if (car[id][4] < car_array_len){
          car[id][4] = car[id][4] + 1;
          car[id][2] = car[id][car[id][4]];
          car[id][3] = 0;
        }
      }
    }
}


void update_all_car_pos(){
  for(int l=0;l<total_cars;l++){
    update_car(l);
  }
}


void clear(){
  delete route[0];
  delete route[1];

  for(int i=0; i< total_cars ; i++){
    delete car[i];
  }

}