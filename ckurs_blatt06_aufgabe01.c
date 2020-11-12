#include <stdio.h>
#include <stdlib.h>
#include "input2.h"

int main() {
    int n = lese_int();
    int laenge = n-1;
    int* array = malloc(n * sizeof(int));

    for(int i=0; i < laenge; i++) {
        array[i] = 1;
    }

    for(int i=0; i<laenge; i++){

        if(array[i] == 1) {

            int x = i+2;
            for(int j=i+1; j<laenge; j++) {
                if((j+2) % x == 0) {
                    array[j]=0;
                }
            }
        }
    }

    print_prim(array, laenge);
    free(array);
    return 0;
}