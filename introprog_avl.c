#include <stdlib.h>
#include <stdio.h>	// Ein- / Ausgabe
#include <math.h>	// Für die Berechnungen der Ausgabe
#include "avl.h"


/* Gibt den gesamten AVL Baum in "in-order" Reihenfolge aus. */


AVLNode * finder(AVLTree* avlt, int value) {

    AVLNode * helper = avlt -> root;

    while (helper != NULL) {

        if (value == helper -> value) {

            return helper;

        }

        else if (value < helper -> value) {

            helper = helper -> left;

        } else {

            helper = helper -> right;

        }

    }

    return NULL;
}

int height(AVLNode *node) {

    if (node == NULL) {

        return -1;

    } else {

        return node -> height;
    }
}


void AVL_in_order_walk_node(AVLNode* node) {

    if(node -> left != NULL) {

        AVL_in_order_walk_node(node -> left);

    }

    printf("%d ", node -> value);

    if(node -> right != NULL) {

        AVL_in_order_walk_node(node -> right);

    }

}


void AVL_in_order_walk(AVLTree* avlt) {

    if (avlt != NULL && avlt -> root != NULL) {

        AVL_in_order_walk_node(avlt -> root);

    }

}


/* Diese Funktion führt eine Linksrotation auf dem angegebenen
 * Knoten aus.
 *
 * Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokal)
 * angepasst werden.  Falls dies nicht eingehalten wird
 * funktionieren die Unit-Tests ggf. nicht.
 */


void AVL_rotate_left(AVLTree* avlt, AVLNode* x) {

    AVLNode * y = x -> right;

    x -> right = y -> left;

    if (y -> left != NULL) {

        y -> left -> parent = x;
    }

    y -> parent = x -> parent;

    if ( x -> parent == NULL) {

        avlt -> root = y;

    } else if (x == x -> parent -> left) {

        x -> parent -> left = y;

    } else {

        x -> parent -> right = y;
    }

    y -> left = x;
    x -> parent = y;

    int leftside, rightside;

    if (x -> left != NULL) {

        leftside = x -> left -> height;

    } else {

        leftside = -1;
    }

    if (x -> right != NULL) {

        rightside = x->right->height;

    } else {

        rightside = -1;
    }

    if (leftside > rightside) {
        x -> height = leftside + 1;

    } else {

        x -> height = rightside + 1;
    }

    if (y -> left != NULL) {

        leftside = y -> left -> height;

    } else {

        leftside = -1;
    }

    if (y -> right != NULL) {

        rightside = y -> right -> height;

    } else {

        rightside = -1;

    }

    if (leftside > rightside) {

        y -> height = leftside + 1;

    } else {

        y -> height = rightside + 1;
    }

}


/* Diese Funktion führt eine Rechtsrotation auf dem angegebenen
 * Knoten aus.
 *
 * Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokal)
 * angepasst werden.  Falls dies nicht eingehalten wird
 * funktionieren die Unit-Tests ggf. nicht.
 */


void AVL_rotate_right(AVLTree* avlt, AVLNode* y)
{

    AVLNode * x = y -> left;

    y -> left = x -> right;

    if (x -> right != NULL) {

        x -> right -> parent = y;

    }

    x -> parent = y -> parent;

    if (y -> parent == NULL) {

        avlt -> root = x;

    } else if (y == y -> parent -> right) {

        y -> parent -> right = x;

    } else {

        y -> parent -> left = x;
    }

    x -> right = y;
    y -> parent = x;

    int leftside, rightside;

    if(y -> left != NULL) {

        leftside = y -> left -> height;

    } else {

        leftside = -1;
    }

    if(y -> right != NULL) {

        rightside = y -> right -> height;

    } else {

        rightside = -1;
    }

    if(leftside > rightside) {

        y -> height = leftside + 1;

    } else {

        y -> height = rightside + 1;
    }

    if(x -> left != NULL) {

        leftside = x -> left->height;

    } else {

        leftside = -1;
    }

    if(x -> right != NULL) {

        rightside = x -> right -> height;

    } else {

        rightside = -1;
    }

    if (leftside>rightside) {

        x -> height = leftside + 1;
    } else {

        x -> height = rightside + 1;

    }
}


/* Balanciere den Teilbaum unterhalb von node.
 *
 * Beachtet: Die Höhen der entsprechenden Teilbäume müssen _nicht_
 * angepasst werden, da dieses schon in den Rotationen geschieht.
 * Falls dies nicht eingehalten wird funktionieren die Unit-Tests
 * ggf. nicht.
 */


void AVL_balance(AVLTree* avlt, AVLNode* node) {

    if (node == NULL) {

        return;
    }


    int L = height(node -> left), R = height(node -> right);

    if (L > R + 1) {

        int LL, LR;

        if (node->left != NULL){

            LL = height(node -> left -> left);
            LR = height(node -> left -> right);

        } else {
            LL = -1;
            LR = -1;
        }
        if (LL < LR) {

            AVL_rotate_left(avlt, node -> left);

        }

        AVL_rotate_right(avlt, node);

    } else if (R > L + 1) {

        int RR, RL;

        if (node->right != 0) {

            RR = height(node -> right -> right);// nicht gelich null
            RL = height(node -> right -> left);

        } else {

            RR = -1;
            RL = -1;

        }

        if (RR < RL) {

            AVL_rotate_right(avlt, node -> right);

        }

        AVL_rotate_left(avlt, node);

    }
}


/* Fügt der Wert value in den Baum ein.
 *
 * Die Implementierung muss sicherstellen, dass der Baum nach dem
 * Einfügen immer noch balanciert ist!
 */


void AVL_insert_value(AVLTree* avlt, int value) {

    AVLNode * check = finder(avlt, value);

    AVLNode * newnode = (AVLNode*)malloc(sizeof(AVLNode));

    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> parent = NULL;
    newnode -> value = value;
    newnode -> height = 0;

    if (avlt -> root == NULL) {

        avlt -> root = newnode;
        avlt -> numberOfNodes = avlt -> numberOfNodes + 1;

    } else {

        AVLNode * current = avlt -> root;
        AVLNode * prev;

        while (current != NULL) {

            prev = current;
            if(current -> value < value) {

                current = current -> right;

            } else {

                current = current -> left;

            }
        }

        if (prev -> value < value) {
            prev -> right = newnode;
            newnode -> parent = prev;
            avlt -> numberOfNodes = avlt -> numberOfNodes + 1;

        } else {
            prev -> left = newnode;
            newnode -> parent = prev;
            avlt -> numberOfNodes = avlt -> numberOfNodes + 1;

        }
    }


    AVLNode * temp = newnode;

    while(temp != NULL) {

        AVL_balance(avlt, temp);

        if (temp -> parent != NULL) {

            if(temp -> parent -> left == NULL && temp -> parent -> right == NULL) {
                temp -> parent -> height = 0;

            } else {
                int L, R;

                L = height(temp -> parent -> left);
                R = height(temp -> parent -> right);

                if(L > R) {

                    temp -> parent -> height = L + 1;

                } else {

                    temp -> parent -> height = R + 1;

                }
            }
        }

        temp = temp -> parent;

    }
}


/* Löscht den gesamten AVL-Baum und gibt den Speicher aller Knoten
 * frei.
 */


void AVL_remove_all_nodes(AVLNode * node) {

    if (node -> left != NULL) {

        AVL_remove_all_nodes(node -> left);

    }

    if(node -> right != NULL) {

        AVL_remove_all_nodes(node -> right);

    }

    free(node);

}

void AVL_remove_all_elements(AVLTree* avlt) {

    if(avlt != NULL) {

        AVL_remove_all_nodes(avlt -> root);

    } else {

        free(avlt);

    }
}
