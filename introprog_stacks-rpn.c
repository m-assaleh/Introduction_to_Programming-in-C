#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // definiert den speziellen Wert NaN für floats
#include "introprog_input_stacks-rpn.h"

typedef struct _stack stack;
typedef struct _stack_element stack_element;

struct _stack {
    stack_element* top;
};

struct _stack_element {
    stack_element* next;
    float value;
};

void stack_push(stack* astack, float value)
{

    stack_element * xnew = (stack_element*) malloc(sizeof(stack_element));
    xnew -> next = NULL;
    xnew -> value = value;
    xnew -> next = astack -> top;
    astack -> top = xnew;

}


float stack_pop(stack* astack)
{
    stack_element *holder;

    if (astack -> top == NULL) {
        return NAN;

    } else {

        float xe = astack -> top -> value;
        holder = astack -> top;
        astack -> top = holder -> next;
        free(holder);
        return xe;

    }

}

void process(stack* astack, char* token)
{
    float x,y,result;

    if (is_number(token)==1) {

        x = atof(token);
        stack_push(astack, x);
    }

    else if(is_add(token)==1) {

        if(astack -> top != NULL && astack -> top -> next != NULL){

            x = stack_pop(astack);
            y = stack_pop(astack);
            result = x + y;

            stack_push(astack, result);
        }
        else {
            if(astack -> top == NULL) stack_push(astack, NAN);
            else astack -> top -> value = NAN;
        }
    }

    else if (is_sub(token)==1) {

        if(astack -> top != NULL && astack -> top -> next != NULL){

            x = stack_pop(astack);
            y = stack_pop(astack);
            result = y - x;

            stack_push(astack, result);
        }
        else {
            if(astack -> top == NULL) stack_push(astack, NAN);
            else astack -> top -> value = NAN;
        }
    }  else if (is_mult(token)==1){

        if(astack -> top != NULL && astack -> top -> next != NULL){

            x = stack_pop(astack);
            y = stack_pop(astack);
            result = x * y;

            stack_push(astack, result);
        }  else {
            if(astack -> top == NULL) stack_push(astack, NAN);
            else astack -> top -> value = NAN; }
    }  else {

        printf("\n<Logik fehlt!>\n");

    }

    return;

}

void print_stack(stack *astack) {
    int counter = 0;
    printf("\n |xxxxx|xxxxxxxxxxxxxxxxxxx|xxxxxxxxxxxxxxxxxxx|xxxxxxxxx|\n");
    printf(" | Nr. | Adresse           | Next              | Wert    |\n");
    printf(" |-----|-------------------|-------------------|---------|\n");
    for (stack_element* elem=astack->top; elem != NULL; elem = elem->next) {
        printf(" | %3d | %17p | %17p | %7.3f |\n", counter, elem, elem->next, elem->value);
        counter++;
    }
    printf(" |xxxxx|xxxxxxxxxxxxxxxxxxx|xxxxxxxxxxxxxxxxxxx|xxxxxxxxx|\n");
}

/*
 * Erstelle einen Stack mit dynamischem Speicher.
 * Initialisiere die enthaltenen Variablen.
 *
 * Gebe einen Pointer auf den Stack zurück.
 */
stack* stack_erstellen() {

    stack *xnum = malloc(sizeof(stack));
    xnum -> top = NULL;
    return xnum;

}

int main(int argc, char** args)
{
    stack* astack = stack_erstellen();
    char zeile[MAX_STR];
    char* token;

    intro();
    while (taschenrechner_input(zeile) == 0) {
        // Erstes Token einlesen
        token = strtok(zeile, " ");

        while (token != NULL) {
            printf("Token: %s\n", token);
            // Stackoperationen durchführen
            process(astack, token);
            // Nächstes Token einlesen
            token = strtok(NULL, " ");
            print_stack(astack);
        }

        printf("\nExtrahiere Resultat\n");
        float result = stack_pop(astack);
        print_stack(astack);

        if (astack->top != NULL) {
            while (astack->top != NULL) {
                stack_pop(astack);   //Räume Stack auf
            }
            printf("\nDoes not Compute: Stack nicht leer!\n");
        } else if (result != result) {
            printf("\nDoes not Compute: Berechnung fehlgeschlagen!\n");
        } else {
            printf("\nDein Ergebnis:\t%7.3f\n\n", result);
        }
    }
    free(astack);
}
