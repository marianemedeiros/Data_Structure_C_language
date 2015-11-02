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
	 *
 */
void enQueue(Queue* queue, ItemType element){
	Node* aux;
	aux = (Node*) calloc(1, sizeof(Node));
	aux->data = element;
	if((queue->first == NULL) && (queue->last == NULL)){
		queue->last = aux;
		queue->first = aux;
		queue->size++;
		aux->next = NULL; 
	}
	else{
		queue->last->next = aux;
		aux->next = NULL;
		queue->last = aux;
		queue->size++;
	}
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
	Node* aux;
	if(queue->first == NULL){
		return -1;
	}
	else{
		*element = queue->first->data;
		aux = queue->first;
		queue->first = aux->next;
		free(aux);
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
	Node* aux = queue->first;
	while(aux != NULL){
		if(aux->data == element){
			return 0;
		}
		else{
			aux = aux->next;
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
	Node* aux = queue->first;
	while(aux != NULL){
		printf("%d\n", aux->data);
		aux= aux->next;
	}
}