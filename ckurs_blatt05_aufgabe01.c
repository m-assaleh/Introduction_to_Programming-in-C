#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int len) {
    printf("Array: %d", array[0]);
    for (int i = 1; i < len; ++i) {
        printf(", %d", array[i]);
    }
    printf("\n");
}


int sum(int array[], int len, int *p) {
    int sum;
    for (int i = 0; i < len-1 ; ++i) {
        sum = sum + array[i];
        *p = sum;
    }
}

int min(int array[], int len) {

int min = array[0];
for (int i = 1; i < len; ++i) {
if (array[i] < min) {
min = array[i];
}
}

return min;

}

int max(int array[], int len) {

    int max = array[0];
    for (int i = 1; i < len; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;

}



int main() {
    int array[] = {9, 4, 7, 8, 10, 5, 1, 6, 3, 2};
    int len = 10;
    print_array(array, len);
   

    int min = min(array, len);
    printf("Minimum: %d\n", min);

    int max = max(array, len);
    printf("Maximum: %d\n",max);
    int p;
    sum(array, len, &p);
    printf("Summe: %d", p);
}

















