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
void enQueue(Queue* q, ItemType e){
	Node* aux;
	aux = (Node*) calloc(1, sizeof(Node));
	aux->data = e;
	if((q->first == NULL) && (q->last == NULL)){
		q->last = aux;
		q->first = aux;
		q->size++;
		aux->next = NULL; 
		printf("Elemento inserido na 1°opcao.\n");
	}
	else{
		q->last->next = aux;
		aux->next = NULL;
		q->last = aux;
		q->size++;
		printf("Elemento inserido com sucesso.\n");
	}
}

int deQueue(Queue* q, ItemType*e){
	Node* aux;
	if(q->first == NULL){
		return -1;
	}
	else{
		*e = q->first->data;
		aux = q->first;
		q->first = aux->next;
		free(aux);
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
	Node* aux = q->first;
	while(aux != NULL){
		if(aux->data == e){
			return 0;
		}
		else{
			aux = aux->next;
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
	Node* aux = q->first;
	while(aux != NULL){
		printf("%d\n", aux->data);
		aux= aux->next;
	}
}

int main (){
	Queue* newQueue;
	ItemType e = 10, e1 = 20, e2 = 30, e3 = 40, e4 = 50, e5 = 60, elemento;
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

