#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "introprog_input_merge_sort.h"

/*
 * Diese Funktion fügt zwei bereits sortierte Arrays zu einem
 * sortierten Array zusammen
 *
 * array : Pointer auf das Array
 * first : Index des ersten Elements (Beginn) des (Teil-)Array
 * middle: Index des mittleren Elements des (Teil-)Array
 * last  : Index des letzten Elements(Ende) des (Teil-)Array
 */
void merge(int* array, int first, int middle, int last)
{

  // int *b = (int*)malloc((last - first + 1) *sizeof (int ));


    int b[last - first + 1];
    int k = first;
    int m = middle + 1;
    int i = 1;


    while( (k <= middle) && (m <= last) ) {

        if(array[k] <= array[m]) {

            b[i] = array[k];

            k++;

        } else {

            b[i] = array[m];

            m++;

        }
        i++;
    }

    while(k <= middle) {

        b[i] = array[k];

        k++;

        i++;

    }

    while(m <= last) {

        b[i] = array[m];

        m++;

        i++;

    }

    int j = 1;

    while( j < i) {

        array[first + j - 1] = b[j];

        j++;

    }

 // free(b);

}

/*
 * Diese Funktion implementiert den rekursiven Mergesort
 * Algorithmus auf einem Array. Sie soll analog zum Pseudocode in
 * Listing 1 implementiert werden.
 *
 * array: Pointer auf das Array
 * first: Index des ersten Elements des (Teil-)Array
 * last:  Index des letzten Elements des (Teil-)Array
 */
void merge_sort(int* array, int first, int last)
{

    if (first < last) {

        int middle = ((first + last) / 2);

        merge_sort(array, first, middle);

        merge_sort(array, (middle + 1), last);

        merge(array, first, middle, last);

    }
}

/*
 * Hauptprogramm.
 *
 * Liest Integerwerte aus einer Datei und gibt diese sortiert im
 * selben Format über die Standardausgabe wieder aus.
 *
 * Aufruf: ./introprog_merge_sort_rekursiv <maximale anzahl> \
 *         <dateipfad>
 */
int main (int argc, char *argv[])
{
    if (argc!=3){
        printf ("usage: %s <maximale anzahl>  <dateipfad>\n", argv[0]);
        exit(2);
    }

    char *filename = argv[2];

  //  int maximale_anzahl = atoi(argv[1]);

 //   int *array = (int*)malloc(maximale_anzahl * sizeof(int));

 //  int array[atoi(argv[1])];

   int *array = malloc(sizeof(int)*atoi(argv[1]));



    int len = read_array_from_file(array, atoi(argv[1]), filename);

    printf("Eingabe:\n");
    print_array(array, len);

    merge_sort(array, 0 , (len - 1 ));

    printf("Sortiert:\n");
    print_array(array, len);


    free(array);

    return 0;
}
