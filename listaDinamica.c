#include <stdio.h>
#include <stdlib.h>
#define ItemType int

typedef struct node{
	ItemType data;
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

//insere elemento no final 
void addLastList(List* l, ItemType e){
	Node* new;
	new = (Node*) calloc(1,sizeof(Node));
	new->data = e;
	if(l->first == NULL && l->last == NULL){
		l->first = new;
		l->last = new;
		l->last->next = NULL;
		l->size++;
	}
	else{
		l->last->next = new;
		l->last = new;
		l->last->next == NULL;
		l->size++;		
	}
}

//insere em qualquer lugar da lista
void addList(List* l, ItemType e, int index){
	int i;
	Node* new;
	Node* aux = l->first->next;
	Node* anterior = l->first;
	new = (Node*) calloc(1,sizeof(Node));
	new->data = e;

	if(index <= 0){
		new->next = l->first;
		l->first = new;
		l->size++;
	}

	else if(index >= l->size){
		l->last->next = new;
		l->last = new;
		new->next = NULL;
		l->size++;
	}
	else{
		for(i = 0; i <= l->size; i++){
			if(i == index){
				anterior->next = new;
				new->next = aux;
				l->size++;
				break;
			}
		anterior = aux;
		aux = aux->next;
		}
	}
}

//remove elemento de acordo com a posicao
int removeList(List* l, int index, ItemType* e){
	int i;
	Node* aux = l->first;
	Node* anterior;

	if(index == 0){
		*e = l->first->data;
		aux = l->first->next;
		free(l->first);
		l->first = aux; 
			if(l->size == 1){
				l->last = l->first;		
			}
		l->size--;
		return 1;
	}
	if(index > l->size || index < 0){
		return 0;	
	}
	else{
		for(i = 0; i <= l->size; i++){
			if(i == index){
				*e = aux->data;
				anterior->next = aux->next;
				free (aux);
				l->size--;						
				return 1;
			}
		anterior = aux;
		aux = aux->next;
		}
	}
}

//remove por elemento
int removeElementList(List* l, ItemType e){
	Node* aux = l->first;
	Node* anterior;	
	int i;
	if(e  == l->first->data){
		l->first = l->first->next;
		free(l->first);
		l->size--;
		return 1;
	}
	else{
		for(i = 0; i < l->size; i++){
			if(aux->data == e){
				anterior->next = aux->next;
				free(aux);
				l->size--;
				return 1;
			}
		anterior = aux;
		aux = aux->next;
		}
	return 0;
	}
}
//ele devolve o elemento de acordo com o indice
int getList(List* l, int index, ItemType* e){
	int i;
	Node* aux = l->first;
	if(index > l->size || index < 0){
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
	
	if(index > l->size || index < 0){
		return 0;
	}
	else{
		for(i = 0; i <= l->size; i++){
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
		if(e == aux->data){
			return i;
		}
	aux = aux->next;
	}
return -1;
}

//procura um elemento na lista
int containsList(List* l, ItemType e){
	int i;
	Node* aux = l->first;
	for(i = 0; i < l->size; i++){
		if(e == aux->data){
			return 1;
		}
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

//imprime a lista
void printList(List* l){
	int i;
	Node* new = l->first;
	while(new != NULL){
		printf("%d\n", new->data);
		new = new->next;
	}
}
int main(){
	int recebe;
	ItemType e;
	List* newList;

	newList = incializaList(newList);
	
	addLastList(newList, 10);
	addLastList(newList, 20);
	addLastList(newList, 30);
	addLastList(newList, 40);
	addLastList(newList, 50);

	addList(newList, 5, 0);
	addList(newList, 35, 3);
	
	recebe = removeList(newList, 3,&e);
	if(recebe != 0){
		printf("elemento removido %d\n", e);
	}
	else{
		printf("Indice invalido, impossivel remover!\n");
	}

	recebe = removeElementList(newList, 222);
	if(recebe != 0){
		printf("elemento removido!\n");
	}
	else{
		printf("elemento nao encontrado impossivel remover!\n");
	}

	recebe = getList(newList, 1, &e);
	if(recebe != 0){
		printf("O elemento eh %d\n", e);
	}
	else{
		printf("Posicao invalida!\n");
	}

	recebe = setList(newList, 4, 2);
	if(recebe != 0){
		printf("elemento trocado!\n");
	}
	else{
		printf("posicao invalida!\n");
	}

	recebe = indexOfList(newList, 35);
	if(recebe >= 0){
		printf("O elemento está na posicao %d\n", recebe);
	}
	else{
		printf("Elemento nao encontrado\n");
	}
	
	recebe = containsList(newList, 89999);
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

