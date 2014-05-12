#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked-list.h"
//	Lista Circular

void concatena(SList **head, SList **head2){
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



void print(SList *head){
	SList *p;
	p=head->next;

	while(p!=head){
		printf("%i; ",p->info);
		p=p->next;
	}
	__fpurge(stdin); getchar();
}

int menu(void){
	int o;
	printf("Menu:\n");
	printf("1 - Search a number.\n");
	printf("2 - Insert a number in the beginning.\n");
	printf("3 - Insert a number in the ending.\n");
	printf("4 - Print a list.\n");
	printf("5 - Make 2 list became 1!\n");
	printf("0 - Exit\n>> ");
	scanf("%i",&o);
	return o;
	
}


void search(SList *head){
	SList *p;
	int x;
	printf("Insert the number to search:\n>>");
	scanf("%i",&x);
	
	head->info = x;
	p = head->next;

	while(p->info!=x){
		p=p->next;
	}

	if (p==head)
		printf("The number %d do not exist!",x);
	else
		printf("The number %d was finded!",x);

	__fpurge(stdin); getchar();
}

void insert1(SList *head){
	SList *p, *q=head;
	int x;

	if((p=malloc(sizeof(SList)))==NULL)
		printf("Error! Memory not allocated.");
	
	printf("Put the number to insert:\n>>");
	scanf("%i",&x);
	
	p->info=x;
	p->next=q->next;
	q->next = p;

	head=q;
	
	
}

void insert2(SList *head){
	SList *p,*q;
	q=head;

	int x;
	if((p=malloc(sizeof(SList)))==NULL)
		printf("Error! Memory not allocated.");
	
	printf("Put the numbert to insert:\n>>");
	scanf("%i",&x);

	p->info = x;
	p->next = head;

	if(head->next==head){
		head->next=p;
	}

	else{
		while(q->next != head){
			q=q->next;
		}
		q->next=p;
	}
	
}




void main(){
 	SList *head, *head2;
	int x,y,z,o;
	char op='N';
	if((head=malloc(sizeof(SList)))==NULL)
		printf("Error! Memory not allocated.");
	head->next=head;
	if((head2=malloc(sizeof(SList)))==NULL)
		printf("Error! Memory not allocated.");
	head2->next=head2;

	do{
		system("clear");
		o = menu();
		switch(o){
			case 1:
				printf("Choose '1' for List 1 or '2' for List 2:\n>>");
				scanf("%i",&x);
				if(x==1)
					search(head);
				else
					search(head2);
			break;

			case 2:
				printf("Choose '1' for List 1 or '2' for List 2:\n>>");
				scanf("%i",&x);
				if(x==1)
					insert1(head);
				else
					insert1(head2);
			break;

			case 3:
				printf("Choose '1' for List 1 or '2' for List 2:\n>>");
				scanf("%i",&x);
				if(x==1)
					insert2(head);
				else
					insert2(head2);
			break;

			case 4:
				printf("Choose '1' for List 1 or '2' for List 2:\n>>");
				scanf("%i",&x);
				if(x==1)
					print(head);
				else
					print(head2);
			break;

			case 5:
				concatena(&head,&head2);
			break;


			case 0:
			    op = __exit();
			break;
			
			default:
				printf("Invalid option!\n");
				__fpurge(stdin);getchar();
			break;
		}
	}while(op=='N');


}
