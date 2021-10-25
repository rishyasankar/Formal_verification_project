#include "vehicle.h"
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int *globalPosition[24][30];

int* getCurrentPositionandCheckNext(int car)
{
  for(int i=0;i<24;i++)
  {
    for(int j=0; j<30;j++)
    {
      if( *globalPosition[i][j] == car)
       {
         if(*globalPosition[i][j+1] != 0)
         {
           *globalPosition[i][j+1] = car;
           *globalPosition[i][j] = 0;
         }
       }
    }
  }
}





void moveToPosition()
{
  if(checkSignal())
  {
    checkFuturePosition();
    globalPosition[][] = 
  }
}

void selectRouteSegments()
{
 //randomly pick a route
 return numSegments;
}

bool checkSignal(bool signalStatus)
{
  return signalStatus;
}