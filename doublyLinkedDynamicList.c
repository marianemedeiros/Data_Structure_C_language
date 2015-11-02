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

//incicializa struct list
List* incializaList(List* p){
	p = (List*) calloc(1, sizeof(List));
	p->first = NULL;
	p->last = NULL;
	p->size = 0;
	return p;
}

//insere elementos
void addLastList(List* l, ItemType e){
	Node* new;
	new=(Node*)calloc(1,sizeof(Node));
	new->data = e;
	if(l->first == NULL){
		l->first = new;
		l->last = new;
		l->first->prev == NULL;
		l->last->next == NULL;
		l->size++;
	}
	else{
		l->last->next = new;
		new->prev = l->last;
		l->last = new;
		l->last->next = NULL;
		l->size++;
	}
}

//insere por posicao
void addList(List* l, ItemType e, int index){
	int i;
	Node* new;
	Node* aux = l->first;
	new=(Node*)calloc(1,sizeof(Node));
	new->data = e;
	if(index <= 0){
		l->first->prev = new;
		new->next = l->first;
		new->prev = NULL;
		l->first = new;
		l->size++;
	}
	else if(index >= l->size){
		l->last->next = new;
		new->prev = l->last;
		new->next = NULL;
		l->last = new;
		l->size++;
	}
	else{
		aux = l->first->next;
		for(i = 1; i < l->size; i++){
			if(index == i){
				new->next = aux;
				new->prev = aux->prev;
				new->prev->next = new;
				aux->prev = new;
				l->size++;
				break;
			}
			aux = aux->next;
		}
	}
}
//remove items de acordo com a posicao
int removeList(List* l, ItemType* e, int index){
	Node* aux = l->first;
	int i;
	if(index == 0){
		*e = l->first->data;
		aux = l->first->next;
		free(l->first);
		l->first = aux;
		l->first->prev = NULL;
		if(l->size == 1){
			l->last = l->first;		
		}
		l->size --;
		return 1;	
	}

	else	if(index > l->size || index < 0){
		return 0;	
	}

	else{
		aux = l->first->next;
		for(i = 1; i < l->size; i++){
			if(i == index){
				*e = aux->data;
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;
				l->size--;
				return 1;
			}
			aux = aux->next;
		}
	}
}
int removeElementList(List* l, ItemType e){
	int i;
	Node* aux = l->first;
	for(i = 0; i < l->size; i++){
		if(aux->data == e && i == 0){
			l->first = aux->next;
			l->first->prev = NULL;
			free(aux);
			l->size--;
			return 1;
		}
		if(aux->data == e){
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			l->size--;
			return 1;
		}		
		aux = aux->next;
	}
	return 0;
}

//ele devolve o elemento de acordo com o indice
int getList(List* l, int index, ItemType* e){
	int i;
	Node* aux = l->first;
	if(index < 0 || index > l->size){
		return 0;
	}
	else{
		for(i = 0; i < l->size; i++){
			if(index == i){
				*e = aux->data;
				return 1;
			}
			aux = aux->next;
		}
	}
}

//substitui elemento por posicao
int setList(List* l, int index, ItemType e){
	int i;
	Node* aux = l->first;
	if(index < 0 || index > l->size){
		return 0;
	}
	else{
		for(i = 0; i < l->size; i++){
			if(index == i){
				aux->data = e;
				return 1;
			}
			aux = aux->next;
		}
	}
}	

// retorna a posicao de acordo com o elemento
int indexOfList(List* l, ItemType e){
	int i;
	Node* aux = l->first;
	for(i = 0; i < l->size; i++){
		if(aux->data == e){
			return i;
		}
		aux = aux->next;
	}
	return -1;
}

//procura um elemento na lista
int containsList(List* l, ItemType e){
	Node* aux = l->first;
	while(aux != NULL){
		if(e == aux->data)return 1;
		aux = aux->next;
	}
	return 0;
}

//retorna o tatal de elementos
int sizeList(List* l){
	return l->size;
}

//verifica se a lista está vazia
int isEmptyList(List* l){
	if(l->size == 0) return 1;
	return 0;
}

//imprime lista
void printList(List* l){
	Node* aux = l->first;
	if(aux == NULL){
		printf("Lista vazia!\n");
	}
	else{
		while(aux != NULL){
			printf("%d\n", aux->data);
			aux = aux->next;
		}
	}
}

int main(){
	List* newList;
	ItemType e;
	int recebe;

	newList = incializaList(newList);
	addLastList(newList, 10);
	addLastList(newList, 20);	
	addLastList(newList, 30);
	addLastList(newList, 40);
	addLastList(newList, 50);
	addLastList(newList, 60);

	addList(newList, 15, 2);

	recebe = removeList(newList, &e, 3);
	if(recebe != 0){
		printf("o elemento removido foi %d\n", e);
	}
	else{
		printf("indice invalido!");
	}

	recebe = removeElementList(newList, 590);
	if(recebe == 0){
		printf("o elemento nao encontrado\n");
	}

	recebe = getList(newList, 1, &e);
	if(recebe != 0){
		printf("O elemento eh %d\n", e);
	}
	else{
		printf("Posicao invalida!\n");
	}

	recebe = setList(newList, 4, 2);
	if(recebe == 0){
		printf("posicao invalida!\n");
	}

	recebe = indexOfList(newList, 2);
	if(recebe >= 0){
		printf("O elemento está na posicao %d\n", recebe);
	}
	else{
		printf("Elemento nao encontrado\n");
	}

	recebe = containsList(newList, 10);
	if(recebe != 0){
		printf("Elemento encontrado\n", recebe);
	}
	else{
		printf("Elemento nao encontrado\n");
	}

	recebe = sizeList(newList);
	printf("O tamanho da lista eh: %d\n", recebe);

	recebe = isEmptyList(newList);
	if(recebe == 1){
		printf("lista vazia!\n");
	}
	else{
		printf("lista nao esta vazia\n");
	}
	printList(newList);
	return 0;
}
