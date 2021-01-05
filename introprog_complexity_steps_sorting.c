#include <stdio.h>
#include <stdlib.h>
#include "introprog_complexity_steps_input.h"

const int MAX_VALUE = 5000000;

void count_sort_calculate_counts(int input_array[], int len, int count_array[], unsigned int* befehle) {

// allocation of i = 1
    (*befehle)++; 
    for (int i = 0; i < MAX_VALUE; ++i) {
// for the looping n times when True "Comparing i with < MAX_VALUE" and adding 1 to i n times ++i
        (*befehle)++;
        (*befehle)++;

// updating the value of count_array[i = 0 
        (*befehle)++;
        count_array[i] = 0;
        
    }
// exiting the "for" loop when comparing i with < MAX_VALUE returns false
    (*befehle)++; 

// allocation of j = 1
    (*befehle)++; 
    for (int j = 0; j < len; ++j) {
// for the looping n times when True "Comparing j with < len" and adding 1 to j n times ++j
        (*befehle)++;
        (*befehle)++;


// updating the value of count_array[input_array[j]] by adding 1
        (*befehle)++;
        count_array[input_array[j]] = count_array[input_array[j]] + 1;
        
    }
// exiting the "for" loop when comparing j with < len returns false
    (*befehle)++;

}


void count_sort_write_output_array(int output_array[], int len, int count_array[], unsigned int* befehle) {

// allocation of k = 0
    (*befehle)++; 
    int k = 0;

// allocation of i = 0
    (*befehle)++; 
    for (int i = 0; i <= MAX_VALUE; ++i) {
// for the looping n times when True "Comparing i with <= MAX_VALUE" and adding 1 to i n times ++i
        (*befehle)++;
        (*befehle)++;


// allocation of j = 0
        (*befehle)++; 
        for (int j = 0; j < count_array[i]; ++j) {
// for the looping n times when True "Comparing j with < count_array[j]" and adding 1 to j n times ++j
            (*befehle)++;
            (*befehle)++;

            
// updating the value of output_array[k] = i
            (*befehle)++; // 
            output_array[k] = i;


//updatting the value of k by adding 1,  k = k + 1
            (*befehle)++; 
            k = k + 1;
            
        }
// exiting the "for" loop when comparing j with j < count_array[i] returns false
        (*befehle)++;


    }
// exiting the "for" loop when comparing i with i <= MAX_VALUE returns false
    (*befehle)++;
}


void count_sort(int array[], int len, unsigned int* befehle) {

// malloc the array
    (*befehle)++; 
    int* count_array = malloc(MAX_VALUE* sizeof(int));

// calling the function count_sort_calculate_counts
    (*befehle)++; 
    count_sort_calculate_counts(array, len, count_array, befehle);

    // calling the function count_sort_write_output_array
    (*befehle)++; 
    count_sort_write_output_array(array, len, count_array, befehle);


// freeing malloc the array
    (*befehle)++;
    free(count_array);

}

void insertion_sort(int array[], int len, unsigned int* befehle) {

// allocation of i = 0
    (*befehle)++; 
    for (int i = 1; i < len; i++) {
      
// for the looping n times when True "Comparing i with < len" and adding 1 to i n times ++i
        (*befehle)++; 
        (*befehle)++; 

        
// allocation of key and updating its value to array[i]
        (*befehle)++; 
        int key = array[i];


//  allocation of j and updating its value to j = i - 1
        (*befehle)++; 
        int j = i - 1;

        
        while (j > -1 && array[j] > key) {
//  for the looping when Comparing j with > -1 and Comparing array[j] > key
            (*befehle)++;
            (*befehle)++;

// updating the value of array[j+1] to array[j];
            (*befehle)++;
            array[j+1] = array[j];


// updating the value of j by subtracting 1,  j = j - 1
            (*befehle)++;
            j = j - 1;
        }


// exiting the "while" loop when comparing j with > -1 and array[j] > key returns false
        (*befehle)++;
        (*befehle)++;


// updating the value of array[j+1] to = key;
        (*befehle)++;
        array[j+1] = key;
        
    }
    
// exiting the "for" loop when comparing i with i < len returns false
    (*befehle)++;

}


int main(int argc, char *argv[]) {
    const int WERTE[] = {10000,20000,30000,40000,50000};
    const int LEN_WERTE = 5;
    const int LEN_ALGORITHMEN = 2;

    int rc = 0;
    unsigned int befehle_array[LEN_ALGORITHMEN][LEN_WERTE];
    double laufzeit_array[LEN_ALGORITHMEN][LEN_WERTE];

    for(int j = 0; j < LEN_WERTE; ++j) {
        int n = WERTE[j];

        // Reserviere Speicher für  Arrays der Länge n
        int* array_countsort = malloc(sizeof(int) * n);
        int* array_insertionsort = malloc(sizeof(int) * n);

        // Fülle array_countsort mit Zufallswerten ..
        fill_array_randomly(array_countsort, n, MAX_VALUE);
        // ... und kopiere die erzeugten Werte in das Array
        // array_insertionsort
        copy_array_elements(array_insertionsort, array_countsort, n);

        // Teste ob beide Arrays auch wirklich die gleichen Werte
        // enthalten
        if(!check_equality_of_arrays(array_countsort, array_insertionsort, n)) {
            printf("Die Eingaben für beide Algorithmen müssen für die Vergleichbarkeit gleich sein!\n");
            return -1;
        }

        for(int i = 0; i < LEN_ALGORITHMEN; ++i) {
            unsigned int anzahl_befehle = 0;

            start_timer();

            // Aufruf der entsprechenden Sortieralgorithmen
            if(i==0) {
                    count_sort(array_countsort, n, &anzahl_befehle);
            } else if(i==1) {
                    insertion_sort(array_insertionsort, n, &anzahl_befehle);
            }

            // Speichere die Laufzeit sowie die Anzahl benötigter
            // Befehle
            laufzeit_array[i][j] = end_timer();
            befehle_array[i][j] = anzahl_befehle;
        }

        // Teste, ob die Ausgabe beider Algorithmen gleich sind
        if(!check_equality_of_arrays(array_countsort, array_insertionsort, n)) {
            printf("Die Arrays sind nicht gleich. Eines muss (falsch) sortiert worden sein!\n");
            rc = -1;
        }

        // Gib den Speicherplatz wieder frei
        free(array_countsort);
        free(array_insertionsort);
    }

    // Ausgabe der Anzahl ausgeführter Befehle sowie der gemessenen
    // Laufzeiten (in Millisekunden)
    printf("Parameter MAX_VALUE hat den Wert %d\n", MAX_VALUE);
    printf("\t %32s           %32s \n", "Countsort","Insertionsort");
    printf("%8s \t %16s %16s \t %16s %16s \n", "n","Befehle", "Laufzeit","Befehle","Laufzeit");

    for(int j = 0; j < LEN_WERTE; ++j) {
        printf("%8d \t ",WERTE[j]);
        for(int i = 0; i < LEN_ALGORITHMEN; ++i) {
            printf("%16u %16.4f \t ",  befehle_array[i][j], laufzeit_array[i][j]);
        }
        printf("\n");
    }

    return rc;
}

