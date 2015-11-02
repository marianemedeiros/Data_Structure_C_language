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
// inciliza a a estrutura
Stack* inicializaStack(Stack* p){
	p = (Stack*) calloc(1, sizeof(Stack)); 
	p->top = NULL;
	p->size = 0;
	return p;
}
//insere o elemento
void push(Stack *s, ItemType e){   
	Node* aux;
	aux = (Node*) calloc(1,sizeof(Node)); 
	aux->data = e;
	aux->next = s->top;
	s->top = aux;
	s->size ++;
}
//remove o elemento do topo
int pop(Stack* s, ItemType* e){
	if(s->size == 0)return 0;
	Node* aux;
	aux = s->top;
	*e = aux->data;
	s->top = aux->next;
	s->size --;
	free(aux);
	return 1;
}

//imprime a pilha
void printStack(Stack* s){
	int i;
	Node* aux;
	aux = s->top;
	for(i = 0; i < s->size; i++){
		printf("elemento %d = %d\n", i, aux->data);
		aux = aux->next;
	}
}
//funcao verifica se tem um elemento na fila
int containsStack(Stack* s, ItemType e){
	int i, cont = 0; 
	Node* aux;
	aux = s->top;
	for(i = 0; i < s->size; i++){
		if(e == aux->data){
			cont++;
		}
		aux = aux->next;
	}
	if(cont > 0){
		return 1;
	}
	else{
		return 0;
	}
}
//funcao que retrona tamanho da Stack
int sizeStack(Stack* s){
	return s->size;
}

//funcao que retorna o elemento do topo
void topStack(Stack* s, ItemType *e){
	*e = s->top->data;
}

//funcao que verifica se a fila esta vazia
int isEmptyStack(Stack* s){
	return(s->size == 0? 0 : 1);
} 
int main (){
	Stack * newStack;
	int tam, recebe,i;
	ItemType e = 0;
	newStack = inicializaStack(newStack);
	push(newStack, 5);
	push(newStack, 10);
	push(newStack, 20);
	push(newStack, 30);
	push(newStack, 40);
	push(newStack, 50);

	recebe = pop(newStack, &e);
	if(recebe == 1){
		printf("O elemento removido foi: %d\n", e);
	}
	else{
		printf("Pilha vazia\n");
	}

	printStack(newStack);
	printf("Digite o elemento a ser procurado:");
	scanf("%d", &e);
	recebe = containsStack(newStack, e);
	if(recebe == 1){
		printf("Elemento encontrado: %d\n", e);
	}
	else{
		printf("Elemento nao encontrado!\n");
	}

	recebe = sizeStack(newStack);
	printf("A quantidade de elementos eh: %d\n", recebe);

	topStack(newStack, &e);
	printf("topo: %d\n", e);
	recebe = isEmptyStack(newStack);
	if(recebe == 1){
		printf("A pilha nao esta vazia\n");
	}
	else{
		printf("A pilha esta vazia\n");
	}
	return 0;
}
