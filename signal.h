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
    }
    
  }
}
