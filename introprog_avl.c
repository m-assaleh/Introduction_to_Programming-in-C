#include <stdlib.h>		
#include <stdio.h>	// Ein- / Ausgabe
#include <math.h>	// Für die Berechnungen der Ausgabe
#include "avl.h"


AVLNode* getnode(AVLTree* avlt, int value)
{
AVLNode *temp = avlt -> root;
while(temp != NULL)
{
if(value == temp -> value)
{
return temp;
}
else if(value < temp -> value)
{
temp = temp -> left;
}
else {
temp = temp -> right;
}
}
return NULL;
}

int hohe(AVLNode *node) {
if(node == NULL) {
return -1;
}
else {
return node -> height;
}
}

void AVL_in_order_walk(AVLTree* avlt)
{	
	if(avlt->root==NULL) return;
	AVLNode *temp1=avlt->root;
	avlt->root=avlt->root->left;
	
	AVL_in_order_walk(avlt);
	avlt->root=temp1;

	printf(" %d",avlt->root->value);

	avlt->root=avlt->root->right;

	AVL_in_order_walk(avlt);

	avlt->root=temp1;
	if(avlt->root->parent ==NULL) printf("\n");    
}

void AVL_rotate_left(AVLTree* avlt, AVLNode* x)
{
	AVLNode *y=x->right;
	x->right=y->left;

	if(y->left!=NULL){
		y->left->parent=x;
	}

	y->parent=x->parent;

	if(x->parent==NULL) avlt->root=y;
	else{
		if(x==x->parent->left) x->parent->left=y;
		else x->parent->right=y;
	}
	y->left=x;
	x->parent=y;

	if(x->left==NULL && x->right==NULL){
		x->height=0;
	       	return;
	}

	if(x->left==NULL && x->right!=NULL){
		x->height=1+(x->right->height);
		return;
	}

	if(x->left!=NULL && x->right==NULL){
		x->height=1+(x->left->height);
		return;
	}

	if(x->left!=NULL && x->right!=NULL){
		int sol=x->left->height;
		int rww=x->right->height;
		if(sol<rww)x->height=1+rww;
		if(sol>rww) x->height=1+sol;
		if(sol==0 && rww==0)x->height=1;
		if(sol==rww) x->height=1+sol;
		return;
	}
	
	if(y->left==NULL && y->right==NULL){
		y->height=0;
	       	return;
	}

	if(y->left==NULL && y->right!=NULL){
		y->height=1+(y->right->height);
		return;
	}

	if(y->left!=NULL && y->right==NULL){
		y->height=1+(y->left->height);
		return;
	}

	if(y->left!=NULL && y->right!=NULL){
		int sol=y->left->height;
		int rww=y->right->height;
		if(sol<rww)y->height=1+rww;
		if(sol>rww) y->height=1+sol;
		if(sol==0 && rww==0)y->height=1;
		if(sol==rww) y->height=1+sol;
		return;
}
}

void AVL_rotate_right(AVLTree* avlt, AVLNode* y)
{

AVLNode* x = y->left;
y->left = x->right;
if (x->right != NULL) {
x->right->parent = y;
}
x->parent = y->parent;
if (y->parent == NULL) {
avlt->root = x;
} else if (y == y->parent->right) {
y->parent->right = x;
} else {
y->parent->left = x;
}
x->right = y;
y->parent = x;

	
	if(y->left==NULL && y->right==NULL){
		y->height=0;
	       	return;
	}

	if(y->left==NULL && y->right!=NULL){
		y->height=1+(y->right->height);
		return;
	}

	if(y->left!=NULL && y->right==NULL){
		y->height=1+(y->left->height);
		return;
	}

	if(y->left!=NULL && y->right!=NULL){
		int sol=y->left->height;
		int rww=y->right->height;
		if(sol<rww)y->height=1+rww;
		if(sol>rww) y->height=1+sol;
		if(sol==0 && rww==0)y->height=1;
		if(sol==rww) y->height=1+sol;
		return;
	}



	if(x->left==NULL && x->right==NULL){
		x->height=0;
	       	return;
	}

	if(x->left==NULL && x->right!=NULL){
		x->height=1+(x->right->height);
		return;
	}

	if(x->left!=NULL && x->right==NULL){
		x->height=1+(x->left->height);
		return;
	}

	if(x->left!=NULL && x->right!=NULL){
		int sol=x->left->height;
		int rww=x->right->height;
		if(sol<rww)x->height=1+rww;
		if(sol>rww) x->height=1+sol;
		if(sol==0 && rww==0)x->height=1;
		if(sol==rww) x->height=1+sol;
		return;
	}
}

void AVL_balance(AVLTree* avlt, AVLNode* node)
{
	AVLNode *rt=node->right;
	AVLNode *lt=node->left;

	int black, white, bubu, red, green, blue;
	black=white=-1;
	bubu=red=green=blue=-2;

	if(rt==NULL) black=-1;
	else{
		black=rt->height;
		if(rt->right!=NULL) green=rt->right->height;
		if(rt->left!=NULL) blue=rt->left->height;
	}

	if(lt==NULL) white=-1;
	else{
		white=lt->height;
		if(lt->right!=NULL) red=lt->right->height;
		if(lt->left!=NULL) bubu=lt->left->height;
	}
	

	if(white > 1+black)
	{
	  if(bubu < red)
	  {
	    AVL_rotate_left(avlt,lt);
	  }
	  AVL_rotate_right(avlt,node);
	}

	else
	{
	 if(black > 1+white)
	 {
	   if(green < blue)
	   {
	     AVL_rotate_right(avlt,rt);
	   }
	   AVL_rotate_left(avlt,node);
	 }
	}
	
}


void AVL_insert_value(AVLTree* avlt, int value)
{
AVLNode *check = getnode(avlt, value);
if(check != NULL) {
printf("Der Wert ist bereits vorhanden!\n");
return;
}

AVLNode *newnode = (AVLNode*)malloc(sizeof(AVLNode));
newnode -> left = NULL;
newnode -> right = NULL;
newnode -> parent = NULL;
newnode -> value = value;
newnode -> height = 0;

if(avlt -> root == NULL) {
avlt -> root = newnode;
avlt -> numberOfNodes = avlt -> numberOfNodes + 1;
}
else {
AVLNode *current = avlt -> root;
AVLNode *prev;
while(current != NULL) {
prev = current;
if(current -> value < value) {
current = current -> right;
}
else {
current = current -> left;
}
}
if(prev -> value < value) {
prev -> right = newnode;
newnode -> parent = prev;
avlt -> numberOfNodes = avlt -> numberOfNodes + 1;
}
else {
prev -> left = newnode;
newnode -> parent = prev;
avlt -> numberOfNodes = avlt -> numberOfNodes + 1;
}
}

AVLNode *temp = newnode;
while(temp != NULL) {
AVL_balance(avlt, temp);
if(temp -> parent != NULL) {
if(temp -> parent -> left == NULL && temp -> parent -> right == NULL) {
temp -> parent -> height = 0;
}
else {
int L, R;
L = hohe(temp -> parent -> left);
R = hohe(temp -> parent -> right);
if(L > R) {
temp -> parent -> height = L + 1;
}
else {
temp -> parent -> height = R + 1;
}
}
}
temp = temp -> parent;
}
}

void AVL_remove_all_nodes(AVLNode *node) {
if(node -> left != NULL) {
AVL_remove_all_nodes(node -> left);
}
if(node -> right != NULL) {
AVL_remove_all_nodes(node -> right);
}
free(node);
}

void AVL_remove_all_elements(AVLTree* avlt)
{
if(avlt != NULL) {
AVL_remove_all_nodes(avlt -> root);
}
else {
free(avlt);
}
}
