
int intArray[9][4];
int itemcount[9] = {0};
int Front[9] = {0};
int Rear[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};


int peek(int i) {
   return intArray[i][Front[i]];
}

bool isEmpty(int i) {
   return itemcount[i] == 0;
}

void insert(int data, int i) {
  
  if(Rear[i] == 3) {
    Rear[i] = -1;            
  }
  intArray[i][++Rear[i]] = data;
  itemcount[i]++;
}

int removeData(int i) {
   int data = intArray[i][Front[i]++];
   if(Front[i] == 4) {
      Front[i] = 0;
   }
   itemcount[i]--;
   return data;  
}


