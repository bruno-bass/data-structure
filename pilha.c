/*
 * pilha.c
 * Copyright (C) 2014 bruno <bruno@bruno-Iinux>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

int clearStack(Stack **top){
     Stack *p = *top;
 
     if(p==NULL){
         return 0;
     }
 	 else{
         while(p!=NULL){
		 	p = p->next;
		 }
     }
	 free(p);
	*top = p;
	 return 1;
}

void insertStack (Stack **top,int x){
	Stack *p = *top;
	if((p=malloc(sizeof(Stack)))==NULL)
		printf("Error!");
	
	p->info = x;
	p->next = *top;
	*top = p;
}

void printStack(Stack *top){
	Stack *p = top;
	if(p==NULL){
		printf("Empty List!");
	}
	else {
		while(p!=NULL){
			printf("%i; ",p->info);
			p = p->next;
		}
	}
}

int sizeofStack (Stack *top){
	int x=0;
	Stack *p = top;
	while(p!=NULL){
		x++;
		p=p->next;
	}
	return x;
}

int main(){
	Stack *topo;
	topo=NULL;
	system("clear");	
	insertStack(&topo,1);
	insertStack(&topo,2);
	insertStack(&topo,3);
	printf("\n\n %i \n\n",sizeofStack(topo));
	printStack(topo);
	__pause();
	clearStack(&topo);
	printStack(topo);
	printf("\n\n %i \n\n",sizeofStack(topo));
	__pause();

	return 1;
}


