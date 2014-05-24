#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 * linked-list.h
 * Copyright (C) 2014 bruno <brunohdbass@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

/* Simple Linked List Declaration */
typedef struct SList {
	int info;
	struct SList *next;
} SList;
/*For Stack*/ 
typedef struct Stack {
	int info;
	struct Stack *next;
} Stack;

/* Double Linked List Declaration */
typedef struct DList {
	int info;
	struct DList *left;
	struct DList *right;
} DList;

/* SList Functions */ 
void sl_Print(SList *list);
void sl_Insert(SList **list, int x);
/*Stack Functions*/


/* DList Functions */
/* Circular Lists */
void cl_Concatena(SList **head, SList **head2);
/* General Functions */
char __exit(void);
void __pause(void);


/* Functions */
void sl_Print(SList *list){
	SList *p = list;
  	if(p==NULL){
       printf("Empty List!");
    }   
    else{
  while(p!=NULL){
       printf("%d; ",p->info);
        p=p->next;
     }   
  }   

}

char __exit(void){
    char op;
    printf("You want to finish de program? Y/N\n>>");
    __fpurge(stdin);
    op = getchar();
    return toupper(op);
}

void __pause(void){
	__fpurge(stdin); getchar();
}
					



void sl_Insert(SList **list, int x){
	SList *p;
	if((p=malloc(sizeof(SList)))==NULL)
    	 printf("No memory!\n");
  	else{
        p->info=x;
        p->next=*list;
         *list=p;
   }   
         
 }

void cl_Concatena(SList **head, SList **head2){
	SList *p1, *p2;
	p1 = *head;
  
     while(p1->next!=*head){
		p1=p1->next; 
	}   
	    
	p1->next=(*head2)->next;
							 
	while(p1->next!=*head2){
	    p1=p1->next;
	}   
													 
	p1->next=*head;
	(*head2)->next = *head2;
													 
													 
}

void cl_Print(SList *head){ 
    SList *p; 
    p=head->next; 
	 
    while(p!=head){ 
    	printf("%i; ",p->info); 
		p=p->next; 
	}   
	__pause(); 

}

#endif
