#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "introprog_input_merge_sort.h"

/*
 * Diese Funktion fügt zwei bereits sortierte Arrays zu einem
 * sortierten Array zusammen
 *
 * array : Pointer auf das Array
 * first : Index des ersten Elemements (Beginn) des (Teil-)Array
 * middle: Index des mittleren Elements des (Teil-)Array
 * last  : Index des Letzten Elements (Ende) des (Teil-)Array
 */
void merge(int* array, int first, int middle, int last)
{

    int bx[last - first + 1];
    int k = first;
    int m = middle + 1;
    int i = 1;

    while( (k <= middle) && (m <= last) ) {

        if(array[k] <= array[m]) {

            bx[i] = array[k];

            k++;

        } else {

            bx[i] = array[m];

            m++;

        }

        i++;
    }

    while(k <= middle) {

        bx[i] = array[k];

        k++;

        i++;

    }

    while(m <= last) {

        bx[i] = array[m];

        m++;

        i++;

    }

    int j = 1;

    while( j < i) {

        array[first + j - 1] = bx[j];

        j++;

    }

}

/*
 * Diese Funktion implementiert den iterativen Mergesort
 * Algorithmus auf einem Array. Sie soll analog zum Pseudocode in
 * Listing 4 implementiert werden.
 *
 * array:  Pointer auf das Array
 * first:  Index des ersten Elements
 * last :  Index des letzten Elements
 */
void merge_sort(int* array, int first, int last)
{

    int step = 1;
    int right = 0;
    int middle = 0;
    int left;

    while (step <= last){
        left = 1;
        while (left <= last - step){
            middle = left + step - 1;
            middle = ((middle < last) ? middle : last);
            right = left + 2*step - 1;
            right = ((right < last ) ? right : last);
            merge(array , left , middle , right);
            left = left + 2*step;
        }
        step = step*2;
    }




    /*

    int step = 1;
    int right = 0;
    int middle = 0;
    int left = 0;


    do {

        left = 1;

        do {

            middle = left + step - 1;

            middle = (((middle) < (last))?(middle):(last));

            right = left + 2*step - 1;

            right = (((right) < (last))?(right):(last));

            merge(first , left , middle , right);

            left = left + 2*step;

        }

        while (left <= (last - step) );

        step = 2 * step;


    }

    while (step <= last);
*/

}

/*
 * Hauptprogramm.
 *
 * Liest Integerwerte aus einer Datei und gibt diese sortiert im
 * selben Format über die Standardausgabe wieder aus.
 *
 * Aufruf: ./introprog_merge_sort_rekursiv <maximale anzahl> \
 * 	   <dateipfad>
 */
int main (int argc, char *argv[])
{
    if (argc!=3){
        printf ("usage: %s <maximale anzahl>  <dateipfad>\n", argv[0]);
        exit(2);
    }

    char *filename = argv[2];

    int *array = (int*)malloc(atoi(argv[1])*sizeof(int));

    int len = read_array_from_file(array, atoi(argv[1]), filename);

    printf("Eingabe:\n");
    print_array(array, len);

    merge_sort(array, 0 , (len - 1 ));

    printf("Sortiert:\n");
    print_array(array, len);

    free(array);

    return 0;
}
