/*
 * Static Queue 
 * Copyright (C) 2014 bruno <bruno@bruno-linux>
 *
 * Distributed under terms of the MIT license.
 */

//Queue - FIFO

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"
#define MAX 6

typedef struct queue{
		int begin, end;
		int item[MAX];
}SQueue;

void _push(SQueue *queue, int x){
	if(queue->begin == ((queue->end+1)%MAX))
		printf("Full Queue!\n");
	else{
		queue->end=(queue->end+1)%MAX;
		queue->item[queue->end]=x;
	}

}

void printQueue(SQueue *queue){
	SQueue ss=*queue;
	printf("  P| V \n");
	printf("---+---\n");
	if(ss.end == ss.begin){
		printf("Lista Vazia");
						
	}
	else{
		while (ss.begin!=ss.end){
			ss.begin=(ss.begin+1)%MAX;
			printf("%3d|",ss.begin);
			printf(" %d\n",ss.item[ss.begin]);			
		}
						
	}
	printf("\n\n");
}

void _pop(SQueue *queue){
	if(queue->begin != queue->end)
		queue->begin = (queue->begin+1)%MAX;
	else
		printf("Empty Queue!\n");

}



int main(){
	SQueue queue;
	queue.begin = queue.end = 0;
	
	_push(&queue,1);
	_push(&queue,2);
	_push(&queue,3);
	_push(&queue,4);
	_push(&queue,5);
	
	printQueue(&queue);
	
	_pop(&queue);

	printQueue(&queue);
	
	_push(&queue,1);

	printQueue(&queue);
}




