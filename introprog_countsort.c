#include <stdio.h>
#include <stdlib.h>
#include "arrayio.h"

int MAX_LAENGE = 1000;
int MAX_VALUE = 100;

void count_sort_calculate_counts(int input_array[], int len, int count_array[]) {
    for (int j = 0; j < MAX_LAENGE; ++j) {
        count_array[j] = 0;

        for (int i = 0; i < len; ++i) {
            count_array[input_array[i]] = 1 + count_array[input_array[i]];
        }
    }
}

void count_sort_write_output_array(int output_array[], int len, int count_array[]) {
    for (int i , x = 0; i < MAX_LAENGE; ++i) {
        for (int j = 0; j < count_array[j]; ++j) {
            output_array[++x] = i;
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2){
        printf("Aufruf: %s <Dateiname>\n", argv[0]);
        printf("Beispiel: %s zahlen.txt\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    int input_array[MAX_LAENGE];
    int len = read_array_from_file(input_array, MAX_LAENGE, filename);

    printf("Unsortiertes Array:");
    print_array(input_array, len);

    int count_array[MAX_LAENGE];
    int output_array[len];
    count_sort_calculate_counts(input_array , len , count_array);
    count_sort_write_output_array(output_array , len ,count_array);

    printf("Sortiertes Array:");

    print_array(output_array, len);

    return 0;
}
