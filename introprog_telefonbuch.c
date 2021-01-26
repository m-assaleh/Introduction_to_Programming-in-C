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
    if(check)
    {
        printf("Fehler: Telefonnummer entspricht nicht den Vorgaben oder Telefonnummer bereits vorhanden\n");
        return;
    }

    int len = strlen(name) + 1;
    char *newname = (char*)malloc(len * sizeof(char));
    snprintf(newname, len, "%s", name);
    bst_node *new_elem = (bst_node*)malloc(sizeof(bst_node));

    new_elem -> phone = phone;
    new_elem -> name = newname;
    new_elem -> left = NULL;
    new_elem -> right = NULL;

    if(bst -> root == NULL)
    {
        new_elem -> parent = NULL;
        bst -> root = new_elem;
    }
    else {
        bst_node *next = bst -> root;
        bst_node *prev = NULL;
        while(next)
        {
            if(next -> phone < phone)
            {
                prev = next;
                next = next -> right;
            }
            else {
                prev = next;
                next = next -> left;
            }
        }
        if(prev -> phone < phone)
        {
            new_elem -> parent = prev;
            prev -> right = new_elem;
        }
        else {
            new_elem -> parent = prev;
            prev -> left = new_elem;
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

        bst_free_subtree(node -> left);

        bst_free_subtree(node -> right);

        free(node -> name);

        free(node);

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
