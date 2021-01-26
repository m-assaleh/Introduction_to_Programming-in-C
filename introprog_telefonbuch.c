#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "introprog_telefonbuch.h"


void bst_insert_node(bstree* bst, unsigned long phone, char *name) {




    bst_node *ne = malloc(sizeof(bst_node));

    ne -> phone = phone;

    ne -> name = malloc(sizeof(char)*(strlen(name)+1));

    strncpy(ne-> name, name, strlen(name));

    ne -> name = name;
    ne -> left = NULL;
    ne -> right = NULL;
    ne -> parent = NULL;


    if(bst -> root == NULL){

        bst -> root = ne;
        printf("error \n");


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



    bst_node *check = find_node(bst, phone);

    if(check){

        printf("error \n");
        return;
    }

}



bst_node* find_node(bstree* bst, unsigned long phone) {



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
