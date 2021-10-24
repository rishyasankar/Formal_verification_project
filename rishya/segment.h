//Global variables
 //Time variable
int t;
//Contains empty slots as 0 and filled slots with Carid
int segment[24][30]; 
//Possible routes variable
int *route[2];

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
      std::cout<<segment[j][i]<<"\n";
    }
  }

}

//List of possible legal routes to pick from
void create_possible_routes(){
  route[0] = new int[9];
  route[0][0]=8;route[0][1]=1;route[0][2]=3;route[0][3]=5;route[0][4]=7;route[0][5]=9;route[0][6]=11;route[0][7]=13;route[0][8]=15;
  
  route[1] = new int[12];
  route[1][1]=16;route[1][2]=14;route[1][3]=12;route[1][4]=24;route[1][5]=22;route[1][6]=3;route[1][7]=5;route[1][8]=7;route[1][9]=9;route[1][10]=11;route[1][11]=13;route[1][12]=15;

}

