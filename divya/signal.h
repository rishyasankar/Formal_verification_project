#include "controller.h"

//0-off,1-red,2-green
void initial_signal_priority()
{
  for(int i=0;i<=8;i++)
  {
    for(int j=0;j<=3;j++)
    {
      if((i==0&&j==2)||(i==1&&j==2)||(i==2&&j==2)||(i==2&&j==3)||(i==3&&j==1)||(i==5&&j==3)||(i==6&&j==0)||(i==6&&j==1)||(i==7&&j==0)||(i==8&&j==0)||(i==8&&j==3))
      {
        il[i][j]=0;
      }
      else if ((i==0&&j==1)||(i==1&&j==1)||(i==2&&j==1)||(i==5&&j==2)||(i==7&&j==3)||(i==6&&j==3)||(i==3&&j==0))
      {
        il[i][j]=2;
      }
      else
        il[i][j]=1;
      std::cout<<"intersection_light"<<i<<j<<"="<<il[i][j]<<"\n";
    }
    
  }
  for(int i=0;i<=8;i++)
    for(int j=0;j<=3;j++)
    {
      p_light[i][j]=0;
    }
}

void priority_signal()
{
  p_light[0][0]=segment[14][29];
  //p_light[0][1] faces node A => so no priority required
  p_light[0][3]=segment[1][29];
  p_light[1][0]=segment[21][29];
  p_light[1][1]=segment[0][29];
  p_light[1][3]=segment[3][29];
  p_light[2][0]=segment[5][29];
  p_light[2][1]=segment[2][29];
  p_light[3][0]=segment[12][29];
  p_light[3][2]=segment[15][29];
  p_light[3][3]=segment[17][29];
  p_light[4][0]=segment[22][29];
  p_light[4][1]=segment[16][29];
  p_light[4][2]=segment[20][29];
  p_light[4][3]=segment[19][29];
  p_light[5][0]=segment[7][29];
  p_light[5][1]=segment[18][29];
  p_light[5][2]=segment[4][29];
  p_light[6][2]=segment[13][29];
  p_light[6][3]=segment[10][29];
  p_light[7][1]=segment[11][29];
  p_light[7][2]=segment[23][29];
  p_light[7][3]=segment[8][29];
  p_light[8][1]=segment[9][29];
  p_light[8][2]=segment[6][29];

  for(int i=0;i<=8;i++)
  {
    for(int j=0;j<=3;j++)
    {
      std::cout<<"priority_signal"<<i<<j<<"="<<p_light[i][j]<<"\n";
    }
  }
  
}
