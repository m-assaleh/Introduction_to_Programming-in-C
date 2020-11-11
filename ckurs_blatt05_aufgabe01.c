#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int len){
  printf("Array: %d", array[0]);
  for(int i = 1; i < len; i++){
    printf(", %d",array[i]);
  }
  printf("\n");
}

int sum(int array[], int len){
  int sum = 0;
  for(int i = 0; i < len; i++){
    sum += array[i];
  }
  return sum;
}

int  max(int array[], int len){
  int max = array[0];
  for(int i = 1; i < len; i++){
    if(array[i] > max){
      max = array[i];
    }
  }
  return max;
}

int  min(int array[], int len){
  int min = array[0];
  for(int i = 1; i < len; i++){
    if(array[i] < min){
      min = array[i];
    }
  }
  return min;
}

int main(){
  int array[]={9,4,7,8,10,5,1,6,3,2};
int len = 10;

  print_array(array, len);

  int min_num = min(array, len);
  printf("Minimum: %d\n", min_num);

  int max_num = max(array, len);
  printf("Maximum: %d\n", max_num);

  int sum_num = sum(array, len);
  printf("Summe: %d\n",sum_num);

  return 0;
}