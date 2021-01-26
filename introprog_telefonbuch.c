#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "introprog_telefonbuch.h"

/*
 * Fügt einen Knoten mit der Telefonnummer phone und dem Namen name
 * in den Binären Suchbaum bst ein.  Für den Suchbaum soll die
 * Eigenschaft gelten, dass alle linken Kinder einen Wert kleiner
 * gleich (<=) und alle rechten Kinder einen Wert größer (>) haben.
 */

void bst_insert_node(bstree *bst, unsigned long phone, char *name)
{


    bst_node *check = find_node(bst, phone);

    if(check){

        printf(" error \n");

        return;
    }


    char *an = malloc((strlen(name) + 1) * sizeof(char));

    snprintf(an, (strlen(name) + 1), "%s", name);


    bst_node *bn = malloc(sizeof(bst_node));

    bn -> left = NULL;
    bn -> right = NULL;
    bn -> phone = phone;
    bn -> name = an;


    if(bst -> root == NULL){

        bn -> parent = NULL;
        bst -> root = bn;

    }else {

        bst_node *first = bst -> root;
        bst_node *second = NULL;

        while(first){

            if(first -> phone < phone){

                second = first;

                first = first -> right;

            } else {
                second = first;

                first = first -> left;

            }
        }

        if(second -> phone < phone){

            bn -> parent = second;
            second -> right = bn;

        } else {

            bn -> parent = second;
            second -> left = bn;

        }
    }
    

}


/*
 * Diese Funktion liefert einen Zeiger auf einen Knoten im Baum mit
 * dem Wert phone zurück, falls dieser existiert.  Ansonsten wird
 * NULL zurückgegeben.
 */


bst_node* find_node(bstree* bst, unsigned long phone) {


    if (bst == NULL) {

        return NULL;

    }

    bst_node *r = bst -> root;
    while(r){

        if(r -> phone == phone){

            return r;
        }

        else if(phone < r -> phone){

            r = r -> left;
        }

        else if (phone > r -> phone){

            r = r -> right;

        }
    }

    return NULL;
}



/* Gibt den Unterbaum von node in "in-order" Reihenfolge aus */


void bst_in_order_walk_node(bst_node* node) {

    if (node){

        bst_in_order_walk_node(node -> left);

        print_node(node);

        bst_in_order_walk_node(node -> right);

    }
}

/*
 * Gibt den gesamten Baum bst in "in-order" Reihenfolge aus.  Die
 * Ausgabe dieser Funktion muss aufsteigend soriert sein.
 */


void bst_in_order_walk(bstree* bst) {
    if (bst != NULL) {
        bst_in_order_walk_node(bst->root);
    }
    
}

/*
 * Löscht den Teilbaum unterhalb des Knotens node rekursiv durch
 * "post-order" Traversierung, d.h. zurerst wird der linke und dann
 * der rechte Teilbaum gelöscht.  Anschließend wird der übergebene
 * Knoten gelöscht.
 */


void bst_free_subtree(bst_node* node) {

    if (node){

        bst_node * thenode = node;

        bst_free_subtree(thenode -> left);
        bst_free_subtree(thenode -> right);
        free(thenode -> name);
        
        free(thenode);

    }
    
}


/*
 * Löscht den gesamten Baum bst und gibt den entsprechenden
 * Speicher frei.
 */


void bst_free_tree(bstree* bst) {
    if(bst != NULL && bst->root != NULL) {
        bst_free_subtree(bst->root);
        bst->root = NULL;
    }
    
}

