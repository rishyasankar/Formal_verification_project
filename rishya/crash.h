
//Junction check for crash variables
int junction0_prech[2];
int junction0_posch[2];
int junction1_prech[6];
int junction1_posch[6];
int junction2_prech[2];
int junction2_posch[2];
int junction3_prech[6];
int junction3_posch[6];
int junction4_prech[12];
int junction4_posch[12];
int junction5_prech[6];
int junction5_posch[6];
int junction6_prech[2];
int junction6_posch[2];
int junction7_prech[6];
int junction7_posch[6];
int junction8_prech[2];
int junction8_posch[2];



void junction0_precheck(){
  junction0_prech[0]=segment[1][29];
  junction0_prech[1]=segment[14][29];
}

void junction1_precheck(){
  junction1_prech[0]=segment[0][29];
  junction1_prech[1]=segment[0][29];
  junction1_prech[2]=segment[21][29];
  junction1_prech[3]=segment[21][29];
  junction1_prech[4]=segment[3][29];
  junction1_prech[5]=segment[3][29];
}

void junction2_precheck(){
  junction2_prech[0]=segment[2][29];
  junction2_prech[1]=segment[2][29];
}

void junction3_precheck(){
  junction3_prech[0]=segment[15][29];
  junction3_prech[1]=segment[15][29];
  junction3_prech[2]=segment[17][29];
  junction3_prech[3]=segment[17][29];
  junction3_prech[4]=segment[12][29];
  junction3_prech[5]=segment[12][29];
}

void junction4_precheck(){
  junction4_prech[0]=segment[20][29];
  junction4_prech[1]=segment[20][29];
  junction4_prech[2]=segment[20][29];
  junction4_prech[3]=segment[19][29];
  junction4_prech[4]=segment[19][29];
  junction4_prech[5]=segment[19][29];
  junction4_prech[6]=segment[23][29];
  junction4_prech[7]=segment[23][29];
  junction4_prech[8]=segment[23][29];
  junction4_prech[9]=segment[16][29];
  junction4_prech[10]=segment[16][29];
  junction4_prech[11]=segment[16][29];
}



void junction5_precheck(){
  junction5_prech[0]=segment[4][29];
  junction5_prech[1]=segment[4][29];
  junction5_prech[2]=segment[18][29];
  junction5_prech[3]=segment[18][29];
  junction5_prech[4]=segment[7][29];
  junction5_prech[5]=segment[7][29];
}

void junction6_precheck(){
  junction6_prech[0]=segment[13][29];
  junction6_prech[1]=segment[10][29];
}

void junction7_precheck(){
  junction7_prech[0]=segment[22][29];
  junction7_prech[1]=segment[22][29];
  junction7_prech[2]=segment[11][29];
  junction7_prech[3]=segment[11][29];
  junction7_prech[4]=segment[8][29];
  junction7_prech[5]=segment[8][29];
}

void junction8_precheck(){
  junction8_prech[0]=segment[6][29];
  junction8_prech[1]=segment[9][29];
}



void junction0_poscheck(){
  junction0_posch[0]=segment[15][0];
  junction0_posch[1]=segment[0][0];
}

void junction1_poscheck(){
  junction1_posch[0]=segment[2][0];
  junction1_posch[1]=segment[20][0];
  junction1_posch[2]=segment[1][0];
  junction1_posch[3]=segment[2][0];
  junction1_posch[4]=segment[1][0];
  junction1_posch[5]=segment[20][0];
}

void junction2_poscheck(){
  junction2_posch[0]=segment[4][0];
  junction2_posch[1]=segment[3][0];
}

void junction3_poscheck(){
  junction3_posch[0]=segment[16][0];
  junction3_posch[1]=segment[13][0];
  junction3_posch[2]=segment[14][0];
  junction3_posch[3]=segment[13][0];
  junction3_posch[4]=segment[16][0];
  junction3_posch[5]=segment[14][0];
}

void junction4_poscheck(){
  junction4_posch[0]=segment[17][0];
  junction4_posch[1]=segment[18][0];
  junction4_posch[2]=segment[22][0];
  junction4_posch[3]=segment[21][0];
  junction4_posch[4]=segment[17][0];
  junction4_posch[5]=segment[22][0];
  junction4_posch[6]=segment[18][0];
  junction4_posch[7]=segment[17][0];
  junction4_posch[8]=segment[21][0];
  junction4_posch[9]=segment[22][0];
  junction4_posch[10]=segment[18][0];
  junction4_posch[11]=segment[21][0];
}


void junction5_poscheck(){
  junction5_posch[0]=segment[19][0];
  junction5_posch[1]=segment[6][0];
  junction5_posch[2]=segment[6][0];
  junction5_posch[3]=segment[5][0];
  junction5_posch[4]=segment[19][0];
  junction5_posch[5]=segment[5][0];
}

void junction6_poscheck(){
  junction6_posch[0]=segment[11][0];
  junction6_posch[1]=segment[12][0];
}

void junction7_poscheck(){
  junction7_posch[0]=segment[10][0];
  junction7_posch[1]=segment[9][0];
  junction7_posch[2]=segment[9][0];
  junction7_posch[3]=segment[23][0];
  junction7_posch[4]=segment[23][0];
  junction7_posch[5]=segment[10][0];
}

void junction8_poscheck(){
  junction8_posch[0]=segment[8][0];
  junction8_posch[1]=segment[7][0];
}


bool check_crash_j0(){
  int cc = 0;
  for(int x=0;x<2;x++){
    if(junction0_prech[x] == junction0_posch[x]){
      if(junction0_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}


bool check_crash_j1(){
  int cc = 0;
  for(int x=0;x<6;x++){
    if(junction1_prech[x] == junction1_posch[x]){
      if(junction1_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}

bool check_crash_j2(){
  int cc = 0;
  for(int x=0;x<2;x++){
    if(junction2_prech[x] == junction2_posch[x]){
      if(junction2_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}

bool check_crash_j3(){
  int cc = 0;
  for(int x=0;x<6;x++){
    if(junction3_prech[x] == junction3_posch[x]){
      if(junction3_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}

bool check_crash_j4(){
  int cc = 0;
  for(int x=0;x<12;x++){
    if(junction4_prech[x] == junction4_posch[x]){
      if(junction4_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}

bool check_crash_j5(){
  int cc = 0;
  for(int x=0;x<6;x++){
    if(junction5_prech[x] == junction5_posch[x]){
      if(junction5_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}

bool check_crash_j6(){
  int cc = 0;
  for(int x=0;x<2;x++){
    if(junction6_prech[x] == junction6_posch[x]){
      if(junction6_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}
bool check_crash_j7(){
  int cc = 0;
  for(int x=0;x<6;x++){
    if(junction7_prech[x] == junction7_posch[x]){
      if(junction7_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}

bool check_crash_j8(){
  int cc = 0;
  for(int x=0;x<2;x++){
    if(junction8_prech[x] == junction8_posch[x]){
      if(junction8_prech[x] != 0){
        cc = cc + 1;
      }
    }
  }
  if(cc > 1) {
    return 1;
  }
  else {
    return 0;
  }
}


void junction_pre_check_for_crash(){
  
  junction0_precheck();
  junction1_precheck();
  junction2_precheck();
  junction3_precheck();
  junction4_precheck();
  junction5_precheck();
  junction6_precheck();
  junction7_precheck();
  junction8_precheck();
  
}
void junction_pos_check_for_crash(){
  junction0_poscheck();
  junction1_poscheck();
  
  junction2_poscheck();
  junction3_poscheck();
  junction4_poscheck();
  junction5_poscheck();
  junction6_poscheck();
  junction7_poscheck();
  junction8_poscheck();
}

int check_crash(){
  int tc = 0;
  tc = tc + check_crash_j0();
  tc = tc + check_crash_j1();
  tc = tc + check_crash_j2();
  tc = tc + check_crash_j3();
  tc = tc + check_crash_j4();
  tc = tc + check_crash_j5();
  tc = tc + check_crash_j6();
  tc = tc + check_crash_j7();
  tc = tc + check_crash_j8();
  return tc;
}