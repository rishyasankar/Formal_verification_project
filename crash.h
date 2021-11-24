
int r_pre_ch[24];
int r_pos_ch[24];
int r_vio;

void red_vio_pre_check(){
  for(int i=0;i<24;i++){
    if(il[signal[i][0]][signal[i][1]] == 1){
      r_pre_ch[i] = segment[i][29];
    }
    else 
      r_pre_ch[i] = 0;

  }
}

void red_vio_pos_check(){
  for(int i=0;i<24;i++){
    if(il[signal[i][0]][signal[i][1]] == 1){
      r_pos_ch[i] = segment[i][29];
    }
    else 
      r_pos_ch[i] = 0;

  }
}



int check_r_vio(){
  int cccc = 0;
  for(int i=0;i<23;i++){
    if(r_pre_ch[i] != r_pos_ch[i] && r_pre_ch[i] != 0 ){
      cccc = cccc+1;
    }
  }
  __CPROVER_assert (cccc!=0, "Red light violations"); 
  return cccc;
}

