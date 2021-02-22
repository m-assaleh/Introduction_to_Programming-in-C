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

    if (mylist -> first == NULL){

        mylist -> last -> next = NULL;


        mylist -> first = le;
        mylist -> last = le;

    } else {

        mylist -> last -> next = le;
        mylist -> last = le;

    }

}

void free_list(list* mylist){

    list_element * fisrt = mylist -> first;

    list_element * last = NULL;


    while(fisrt){

        last = fisrt;
        fisrt = fisrt -> next;

        free(last -> password);
        free(last);

    }

}

int words(char *string){

    int counter = 0, len = strlen(string);
    char lastC;

    if (len > 0){

        lastC = string[0];

    }

    for (int i = 0; i <= len; i++) {
        if ((string[i] == ' ' || string[i] == '\0') && lastC != ' '){

            counter++;
        }

        lastC = string[i];

    }

    return counter;

}

void read_data(char* filename, list* mylist){

    FILE *fp = fopen(filename, "r");

    if (fp == NULL){

        perror("Error");

        return;
    }


    char buffer[100], pw[100], *strbuffer, pwcountbuffer[100], pwcount, pwwords;

    memset(pw, 0, sizeof(pw));

    while (fgets ( buffer, sizeof (buffer), fp ) != NULL){

        pwwords = words(buffer) - 1;

        strbuffer = strtok(buffer, " ");


        for (int i = 0; i < pwwords; i++){

            strcat(pw, strbuffer);

            if (pwwords > 1 && i != pwwords - 1){

                strcat(pw, " ");

            }

            strbuffer = strtok(NULL, " ");
        }

        strcpy(pwcountbuffer, strbuffer);

        pwcount = atoi(pwcountbuffer);

        list_element* newle = (list_element *) malloc (sizeof (list_element) );

        if (newle == NULL){

            perror("Overflow!");

            return;

        }

        newle -> password = (char *) malloc( sizeof(pw)* sizeof(char) );

        strcpy(newle -> password, pw);

        newle -> count = pwcount;

        insert_list(newle, mylist);

        memset(pw, 0, sizeof(pw) );

    }

    fclose(fp);

}

list_element* partition( list* input, list* left, list* right ){

    list_element *pivot;

    if (input -> first == NULL){

        pivot = NULL;
        input -> last = NULL;

    } else {

        pivot = input -> first;
        input -> first = pivot -> next;
        pivot -> next = NULL;

    }

    if (pivot != NULL){

        list_element *temp = input -> first;

        while (temp != NULL){

            input -> first = temp -> next;

            if (input -> first == NULL){

                input -> last = NULL;

            }

            if (temp -> count >= pivot -> count){

                insert_list(temp, right);

            } else {

                insert_list(temp, left);

            }

            temp = input -> first;

        }

    }

    return pivot;

}

void qsort_list(list* mylist){

    if (mylist -> first == mylist -> last){

        return;

    } else {

        list lstack;
        list rstack;
        list *left = &lstack;
        list *right = &rstack;
        init_list(left);
        init_list(right);
        list_element *pivot = partition(mylist, left, right);
        qsort_list(left);
        qsort_list(right);


        if (left -> first == NULL){

            mylist -> first = pivot;

        } else {

            mylist -> first = left -> first;

            left -> last -> next = pivot;
        }

        if (right -> first == NULL){

            pivot -> next = NULL;

            mylist -> last = pivot;

        } else {

            pivot -> next = right -> first;

            mylist -> last = right -> last;

        }

    }

}

void print_list(list* mylist){

    if (mylist -> first == NULL){

        printf("List is empty!\n\n");

        return;

    }

    list_element *temp = mylist -> first;

    while (temp){

        printf("%s %d\n", temp -> password, temp -> count);

        temp = temp -> next;

    }

}