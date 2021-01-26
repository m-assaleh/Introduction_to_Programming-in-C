#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "introprog_telefonbuch.h"


void bst_insert_node(bstree* bst, unsigned long phone, char *name) {

    bst_node *ne = (bst_node*)malloc(sizeof(bst_node));
   ne -> name = (char *)malloc((strlen(name) + 1) *sizeof(char));
    strncpy(ne->name, name, strlen(name));


    ne -> left = NULL;
    ne -> right = NULL;
    ne -> phone = phone;
    ne -> name = name;


    if(bst -> root == NULL){

        ne -> parent = NULL;
        bst -> root = ne;

    } else {

        bst_node *next = bst -> root;
        bst_node *prev = NULL;

        while(next){

            if(next -> phone < phone){

                prev = next;
                next = next -> right;

            } else {

                prev = next;
                next = next -> left;

            }
        }

        if(prev -> phone < phone){

            ne -> parent = prev;
            prev -> right = ne;

        } else {

            ne -> parent = prev;
            prev -> left = ne;

        }
    }
}



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





void bst_in_order_walk_node(bst_node* node) {

    if (node){
        bst_in_order_walk_node(node -> left);

        print_node(node);

        bst_in_order_walk_node(node -> right);

    }
}


void bst_in_order_walk(bstree* bst) {
    if (bst != NULL) {
        bst_in_order_walk_node(bst->root);
    }
}


void bst_free_subtree(bst_node* node) {

    if (node){

        bst_free_subtree(node -> left);

        bst_free_subtree(node -> right);

        free(node -> name);
        free(node);

    }
}


void bst_free_tree(bstree* bst) {
    if(bst != NULL && bst->root != NULL) {
        bst_free_subtree(bst->root);
        bst->root = NULL;
    }
}
