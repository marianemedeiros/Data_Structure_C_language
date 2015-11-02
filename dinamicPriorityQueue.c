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

//cria e inicializa uma estrutura
Queue *inicializaQueue(Queue* q){
	Queue* p;
	p = (Queue*) calloc(1, sizeof(Queue));
	p->first = NULL;
	p->last = NULL;
	p->size = 0;
	return p;	
}
//insere elementos
int enQueue(Queue* q, ItemType e){
	Node* new;
	Node* anterior;
	Node* aux;
	new = (Node*) calloc(1, sizeof(Node));
	new->data = e;

	if((q->first == NULL) && (q->last == NULL)){
		q->last = new;
		q->first = new;
		q->size++;
		new->next = NULL; 
		printf("Elemento inserido na 1°opcao.\n");
		return 1;	
	}

	if(q->first->data > e){
		new->next = q->first;
		q->first = new;
		q->size++;
		return 1;
	}

	if(q->last->data < e){
		q->last->next = new;
		q->last = new;
		new->next = NULL;
		q->size++;
		return 1;
	}

	anterior = q->first;
	aux = q->first->next;
	while(aux->data < e){
		anterior = aux;
		aux = aux->next;
	}
	new->next = aux;	
	anterior->next = new;
	q->size++;

	return 1;
}

int deQueue(Queue* q, ItemType*e){
	Node* new;
	if(q->first == NULL){
		return -1;
	}
	else{
		*e = q->first->data;
		new = q->first;
		q->first = new->next;
		free(new);
		q->size--;
		return 0;
	}
}
//retorna elemento do topo
int peek(Queue* q, ItemType* e){
	if(q->first == NULL){
		return -1;
	}
	else{
		*e = q->first->data;
		return 0;	
	}
}
//verifica se um elemento está na fila
int contains(Queue* q, ItemType e){
	Node* new = q->first;
	while(new != NULL){
		if(new->data == e){
			return 0;
		}
		else{
			new = new->next;
		}
	}
	return -1;
}

//retorna o tamanho fa fila;
int sizeQueue(Queue* q){
	return q->size;
}

//verifica se a pilha está vazia
int isEmptyQueue(Queue* q){
	return(q->size == 0? 1 : 0);
}

//imprime Queue
void printQueue(Queue* q){
	Node* new = q->first;
	while(new != NULL){
		printf("%d\n", new->data);
		new= new->next;
	}
}


/* exemplos de como utiliza*/
int main (){
	Queue* newQueue;
	ItemType e = 0, e1 = 40, e2 = 0, e3 = 4, e4 = 250, e5 = 60, elemento;
	int recebe = 0;
	newQueue = inicializaQueue(newQueue);
	enQueue(newQueue, e);
	enQueue(newQueue, e1);
	enQueue(newQueue, e2);
	enQueue(newQueue, e3);
	enQueue(newQueue, e4);
	enQueue(newQueue, e5);

	printQueue(newQueue);

	recebe = deQueue(newQueue, &elemento);
	if(recebe == 0){
		printf("elemento removido: %d\n", elemento);
	}
	else{
		printf("elemento nao removido.\n");
	}

	recebe = peek(newQueue, &elemento);
	if(recebe == 0){
		printf("elemento do inicio eh: %d\n", elemento);
	}
	else{
		printf("fila vazia.\n");
	}

	elemento = 20;
	recebe = contains(newQueue, elemento);
	if(recebe == 0){
		printf("elemento encontrado\n");
	}
	else{
		printf("elemento nao encontrado.\n");
	}
	printf("a quantidade de elementos eh: %d\n", sizeQueue(newQueue));	
	recebe = isEmptyQueue(newQueue);
	if(recebe == 0){
		printf("fila não esta vazia\n");
	}
	else{
		printf("Fila está vazia\n");
	}
	return 0;
}

