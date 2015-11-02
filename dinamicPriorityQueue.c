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
#define ItemType int

typedef struct node{
	ItemType data;
	struct node *next;
}Node;

typedef struct{
	Node *first;
	Node *last;
	int size;
}Queue;

/**
 * create and inicialize structure.
 *
 * @returns a pointer of type Queue, with first and last pointing to null and size zero.
 */
Queue *initializeQueue(){
	Queue* p;
	p = (Queue*) calloc(1, sizeof(Queue));
	p->first = NULL;
	p->last = NULL;
	p->size = 0;
	return p;	
}

/**
 * Inserts Elements.
 *
 * @param Queue* queue, pointer of type Queue.
 * @param ItemType element, the element to be inserted in the Queue.
 * Inserts element ordering in ascending order.
 *
 * @returns 0 if the element has been successfully inserted.
 */
int enQueue(Queue* queue, ItemType element){
	Node* newNode;
	Node* backNode;
	Node* aux;
	newNode = (Node*) calloc(1, sizeof(Node));
	newNode->data = element;

	if((queue->first == NULL) && (queue->last == NULL)){
		queue->last = newNode;
		queue->first = newNode;
		queue->size++;
		newNode->next = NULL; 
		return 0;	
	}

	if(queue->first->data > element){
		newNode->next = queue->first;
		queue->first = newNode;
		queue->size++;
		return 0;
	}

	if(queue->last->data < element){
		queue->last->next = newNode;
		queue->last = newNode;
		newNode->next = NULL;
		queue->size++;
		return 0;
	}

	backNode = queue->first;
	aux = queue->first->next;
	while(aux->data < element){
		backNode = aux;
		aux = aux->next;
	}
	newNode->next = aux;	
	backNode->next = newNode;
	queue->size++;

	return 0;
}

/**
 * Remove Elements.
 *
 * @param Queue* queue, pointer of type Queue.
 * @param ItemType element, the element to be removed in the Queue.
 * And the removed element is returned by parameter.
 *
 * @returns 0 if element is successfully removed, or -1 if element was not removed.
 */
int deQueue(Queue* queue, ItemType* element){
	Node* newNode;
	if(queue->first == NULL){
		return -1;
	}
	else{
		*element = queue->first->data;
		newNode = queue->first;
		queue->first = newNode->next;
		free(newNode);
		queue->size--;
		return 0;
	}
}

/**
 * First queue element;
 *
 * @param Queue* queue, pointer of type Queue.
 * @param ItemType element, the element to be removed in the Queue.
 * And returned first element by parameter.
 *
 * @returns 0 if successfully, or -1 if empty queue.
 */
int peek(Queue* queue, ItemType* element){
	if(queue->first == NULL){
		return -1;
	}
	else{
		*element = queue->first->data;
		return 0;	
	}
}

/**
 * Verifies that an element is in the queue.
 *
 * @param Queue* queue, a pointer of type Queue.
 * @param ItemType element, element sought in the queue.
 *
 * @returns 0 if element was found, or -1 if the element was not found.
 */
int contains(Queue* queue, ItemType element){
	Node* newNode = queue->first;
	while(newNode != NULL){
		if(newNode->data == element){
			return 0;
		}
		else{
			newNode = newNode->next;
		}
	}
	return -1;
}

/**
 * Size Queue.
 *
 * @param Queue* queue, a pointer of type Queue.
 *
 * @returns size Queue,
 */
int sizeQueue(Queue* queue){
	return queue->size;
}

/**
 * Verifies that the queue is empty.
 *
 * @param Queue* queue, a pointer of type Queue.
 *
 * @returns 0 if the queue is empty, or -1 if the queue is not empty
 */
int isEmptyQueue(Queue* queue){
	return(queue->size == 0? 0 : -1);
}

/**
 * Prints the elements of the queue .
 *
 * @param Queue* queue, a pointer of type Queue.
 *
 */
void printQueue(Queue* queue){
	Node* newNode = queue->first;
	while(newNode != NULL){
		printf("%d\n", newNode->data);
		newNode= newNode->next;
	}
}
