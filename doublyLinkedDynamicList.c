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
	struct node* prev;
	struct node* next;
}Node;

typedef struct{
	Node* first;
	Node* last;
	int size;
}List;

/**
 * create and inicialize structure.
 *
 * @returns a pointer of type List, with first and last pointing to null and size zero.
 */
List* initializeList(){
	List* p;
	p = (List*) calloc(1, sizeof(List));
	p->first = NULL;
	p->last = NULL;
	p->size = 0;
	return p;
}

/**
 * Inserts elements at the end of the list.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, the element to be inserted in the end list.
 *
 */
void addLastList(List* list, ItemType element){
	Node* newNode;
	newNode=(Node*)calloc(1,sizeof(Node));
	newNode->data = element;
	if(list->first == NULL){
		list->first = newNode;
		list->last = newNode;
		list->first->prev == NULL;
		list->last->next == NULL;
		list->size++;
	}
	else{
		list->last->next = newNode;
		newNode->prev = list->last;
		list->last = newNode;
		list->last->next = NULL;
		list->size++;
	}
}


/**
 * Inserts elements by index.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, the element to be inserted in list.
 * @param int index, the index that will be done to insertion.
 *
 */
void addList(List* list, ItemType element, int index){
	int i;
	Node* newNode;
	Node* aux = list->first;
	newNode=(Node*)calloc(1,sizeof(Node));
	newNode->data = element;
	if(index <= 0){
		list->first->prev = newNode;
		newNode->next = list->first;
		newNode->prev = NULL;
		list->first = newNode;
		list->size++;
	}
	else if(index >= list->size){
		list->last->next = newNode;
		newNode->prev = list->last;
		newNode->next = NULL;
		list->last = newNode;
		list->size++;
	}
	else{
		aux = list->first->next;
		for(i = 1; i < list->size; i++){
			if(index == i){
				newNode->next = aux;
				newNode->prev = aux->prev;
				newNode->prev->next = newNode;
				aux->prev = newNode;
				list->size++;
				break;
			}
			aux = aux->next;
		}
	}
}

/**
 * Removes element by index.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, parameter used to send the element found..
 * @param int index, the index removal will be done.
 * And the removed element is returned by parameter.
 *
 * @returns 0 if element is successfully removed, or -1 if element was not removed.
 */
int removeList(List* list, ItemType* element, int index){
	Node* aux = list->first;
	int i;
	if(index == 0){
		*element = list->first->data;
		aux = list->first->next;
		free(list->first);
		list->first = aux;
		list->first->prev = NULL;
		if(list->size == 1){
			list->last = list->first;		
		}
		list->size --;
		return 0;	
	}

	else	if(index > list->size || index < 0){
		return -1;	
	}

	else{
		aux = list->first->next;
		for(i = 1; i < list->size; i++){
			if(i == index){
				*element = aux->data;
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;
				list->size--;
				return 0;
			}
			aux = aux->next;
		}
	}
}

/**
 * Removes per element.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, the element to be removed in the List.
 *
 * @returns 0 if element is successfully removed, or -1 if element was not removed.
 */
int removeElementList(List* list, ItemType element){
	int i;
	Node* aux = list->first;
	for(i = 0; i < list->size; i++){
		if(aux->data == element && i == 0){
			list->first = aux->next;
			list->first->prev = NULL;
			free(aux);
			list->size--;
			return 0;
		}
		if(aux->data == element){
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			list->size--;
			return 0;
		}		
		aux = aux->next;
	}
	return -1;
}

/**
 * Search element by index.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, parameter used to send the element found.
 * @param int index, The index used to search for the element.
 * The element will be sent by parameter
 * 
 * @returns 0 if element is successfully found, or -1 if element was not found.
 */
int getList(List* list, ItemType* element, int index){
	int i;
	Node* aux = list->first;
	if(index < 0 || index > list->size){
		return -1;
	}
	else{
		for(i = 0; i < list->size; i++){
			if(index == i){
				*element = aux->data;
				return 0;
			}
			aux = aux->next;
		}
	}
}


/**
 * Replaces the element by index.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, new element.
 * @param int index, index of the element to be replaced.
 * 
 * @returns 0 if element is successfully replaced, or -1 if element was not replaced.
 */
int setList(List* list, ItemType element, int index){
	int i;
	Node* aux = list->first;
	if(index < 0 || index > list->size){
		return 0;
	}
	else{
		for(i = 0; i < list->size; i++){
			if(index == i){
				aux->data = element;
				return 1;
			}
			aux = aux->next;
		}
	}
}	

/**
 * Returns the index of the element.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, element.
 * 
 * @returns the index of the element, or -1 if element was not found.
 */
int indexOfList(List* list, ItemType element){
	int i;
	Node* aux = list->first;
	for(i = 0; i < list->size; i++){
		if(aux->data == element){
			return i;
		}
		aux = aux->next;
	}
	return -1;
}

/**
 * Search for an element in the list.
 *
 * @param List* list, pointer of type List.
 * @param ItemType element, the element to be searched.
 * 
 * @returns 0 if element is successfully found, or -1 if element was not found.
 */
int containsList(List* list, ItemType element){
	Node* aux = list->first;
	while(aux != NULL){
		if(element == aux->data) return 0;
		aux = aux->next;
	}
	return -1;
}

/**
 * Size List.
 *
 * @param List* list, pointer of type List.
 * 
 * @returns size list.
 */
int sizeList(List* list){
	return list->size;
}

/**
 * Verifies that the list is empty.
 *
 * @param List* list, a pointer of type List.
 *
 * @returns 0 if the list is empty, or -1 if the list is not empty
 */
int isEmptyList(List* list){
	if(list->size == 0) return 1;
	return 0;
}

/**
 * Prints the elements of the list .
 *
 * @param List* list, a pointer of type List.
 *
 */
void printList(List* list){
	Node* aux = list->first;
	while(aux != NULL){
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}
