/*
 * Static Stack 
 * Copyright (C) 2014 Bruno Oliveira <brunohdbass@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"
#define MAX 6

typedef struct stack{
	int item[MAX];
	int top;
} SStack;

void _push(SStack *stack,int x){
	if(stack->top < MAX-1){
		stack->top++;
		stack->item[stack->top] = x;
	}
	else{
		printf("Full Stack!\n");
	}
}

void _print(SStack stack){
	SStack ss = stack;
	if(ss.top != 0){
		while (ss.top!=0){
			printf("%d| ",ss.item[ss.top]);
			ss.top--;
	    }
	}
	else{
		printf("Empty List!\n");
	}
					
}

void _pop(SStack *stack){
	if(stack->top != 0)
		stack->top--;
	else
		printf("Empty List!\n");
}



int main (){
	SStack stack;
	stack.top=0;
	
	_push(&stack,1);
	_push(&stack,2);
	_push(&stack,3);
	_push(&stack,4);
	_push(&stack,5);
	
	_print(stack);
	__pause();
	_pop(&stack);
	_print(stack);
	__pause();
	_pop(&stack);
	_print(stack);
	__pause();
	_pop(&stack);
	_print(stack);
	__pause();
	_pop(&stack);
	_print(stack);
	__pause();
	_pop(&stack);
	_print(stack);
	__pause();

	return 1;


}
