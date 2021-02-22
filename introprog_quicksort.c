#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "quicksort.h"



void init_list(list* mylist){

    mylist -> first = NULL;

    mylist -> last = NULL;

}

void insert_list(list_element* le, list* mylist){

    le -> next = NULL;
    
    if (mylist -> first == NULL){

        mylist -> first = le;
        mylist -> last = le;

    } else {

        mylist -> last -> next = le;
        mylist -> last = le;

    }

}

void free_list(list* mylist) {

    list_element * saver = mylist -> first;

    while (saver != NULL){

        list_element * saverx = saver -> next;

        free(saver -> password);
        free(saver);

        saver = saverx;

    }

}

void read_data(char* filename, list* mylist){

    FILE * file_in = fopen(filename, "r");

    char in [255], out [255];

    int num = 0;

    list_element * sav;

    while (fgets(in, 255, file_in) != NULL){

        sscanf(in, "%s %d", out, &num);

        char * password = malloc(sizeof(char) * (strlen(out) + 1) );

        sav = malloc(sizeof(list_element) );

        strcpy(password, out);

        sav -> password = password;

        sav -> count = num;

        insert_list(sav, mylist);

    }

    fclose(file_in);

}

list_element* partition(list* input, list* left, list* right){

    list_element* pivot = input -> first;

    list_element* p = input -> first -> next;

    while (p != NULL){

        list_element* x = p -> next;

        if(p -> count < pivot -> count) {
            insert_list(p, left);
        }
        else {
            insert_list(p, right);
        }
        
        p = x;
    }
    
    return pivot;
    
}

void qsort_list(list* mylist){

    if (mylist -> first == mylist -> last){

        return;

    } else {

        list right, left;

        init_list(&left);
        
        init_list(&right);

        list_element* pivot = partition(mylist, &left, &right);

        qsort_list(&left);
        
        qsort_list(&right);

        if (left.first == NULL){

            mylist -> first = pivot;

        } else {

            mylist -> first = left.first;

            left.last -> next = pivot;

        }

        if (right.first == NULL){

            pivot -> next = NULL;

            mylist -> last = pivot;

        } else {

            pivot -> next = right.first;

            mylist -> last = right.last;

        }

        return;
    }

}

void print_list(list* mylist){

    list_element * sav = mylist -> first;

    while (sav != NULL){

        printf("%s %d\n", sav -> password, sav -> count);
        sav = sav -> next;

    }

}


