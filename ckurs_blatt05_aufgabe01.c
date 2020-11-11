#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int len) {
    printf("Array: %d", array[0]);
    for (int i = 1; i < len; ++i) {
        printf(", %d", array[i]);
    }
    printf("\n");
}

void print_sum(int array[], int len){
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum = sum + array[i];
    }
    printf("Sum: %d\n",sum);
}

void print_min(int array[], int len){
    int min = array[0];
    for(int i = 1; i < len; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    printf("Minimum: %d\n", min);
}

void print_max(int array[], int len){
    int max = array[0];
    for(int i = 1; i < len; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    printf("Maximum: %d\n", max);
}

int main() {
    int array[] = {9, 4, 7, 8, 10, 5, 1, 6, 3, 2};
    int len = 10;

    print_array(array, len);
    print_min(array, len);
    print_max(array, len);
    print_sum(array, len);

    return 0;
}
