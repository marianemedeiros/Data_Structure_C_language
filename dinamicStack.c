/*
   Copyright (C) 2014, Guilherme Castro Diniz.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation (FSF); in version 2 of the
   license.

   This program is distributed in the hope that it can be useful,
   but WITHOUT ANY IMPLIED WARRANTY OF ADEQUATION TO ANY
   MARKET OR APPLICATION IN PARTICULAR. See the
   GNU General Public License for more details.
   <http://www.gnu.org/licenses/>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ItemType int
typedef struct node{
	ItemType data;
	struct node *next;
}Node;

typedef struct{
	Node *top;
	int size;
}Stack;


/**
 * create and inicialize structure.
 *
 * @returns a pointer of type Stack, with first and last pointing to null and size zero.
 */
Stack* initializeStack(){
	Stack* p;
	p = (Stack*) calloc(1, sizeof(Stack)); 
	p->top = NULL;
	p->size = 0;
	return p;
}

/**
 * Inserts Elements.
 *
 * @param Stack* stack, pointer of type Stack.
 * @param ItemType element, the element to be inserted in the stack.
 *
 */
void push(Stack* stack, ItemType element){   
	Node* newNode;
	newNode = (Node*) calloc(1,sizeof(Node)); 
	newNode->data = element;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->size ++;
}

/**
 * Remove Elements.
 *
 * @param stack* stack, pointer of type stack.
 * @param ItemType element, the element to be removed in the stack.
 * And the removed element is returned by parameter.
 *
 * @returns 0 if element is successfully removed, or -1 if element was not removed.
 */
int pop(Stack* stack, ItemType* element){
	if(stack->size == 0)return -1;
	Node* newNode;
	newNode = stack->top;
	*element = newNode->data;
	stack->top = newNode->next;
	stack->size --;
	free(newNode);
	return 0;
}

/**
 * Verifies that an element is in the stack.
 *
 * @param Stack* stack, a pointer of type stack.
 * @param ItemType element, element sought in the stack.
 *
 * @returns 0 if element was found, or -1 if the element was not found.
 */
int containsStack(Stack* stack, ItemType element){
	int i; 
	Node* newNode;
	newNode = stack->top;
	for(i = 0; i < stack->size; i++){
		if(element == newNode->data){
			return 0;
		}
		newNode = newNode->next;
	}
	return -1;
}

/**
 * Size stack.
 *
 * @param Stack* stack, a pointer of type stack.
 *
 * @returns size stack,
 */
int sizeStack(Stack* stack){
	return stack->size;
}

/**
 * Top element of the stack.
 *
 * @param Stack* stack, a pointer of type stack.
 * @param ItemType element, parameter used to send the element found.
 * The element will be sent by parameter.
 *
 */
void topStack(Stack* stack, ItemType *element){
	*element = stack->top->data;
}

/**
 * Verifies that the stack is empty.
 *
 * @param Stack* stack, a pointer of type stack.
 *
 * @returns 0 if the stack is empty, or -1 if the stack is not empty
 */
int isEmptyStack(Stack* stack){
	return(stack->size == 0? 0 : -1);
} 

/**
 * Prints the elements of the stack .
 *
 * @param Stack* stack, a pointer of type stack.
 *
 */
void printStack(Stack* stack){
	int i;
	Node* newNode;
	newNode = stack->top;
	for(i = 0; i < stack->size; i++){
		printf("%d\n", newNode->data);
		newNode = newNode->next;
	}
}
