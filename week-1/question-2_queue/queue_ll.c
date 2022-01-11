//program for queue using single linked list
#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
void enqueue();
void dequeue();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL,*rear=NULL;


void main(){
	int ch,test;
	while(1)
	{
		printf("\n queue using Single linked list operations are: \n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit");
		printf("\n Enter ur choice:");
		test = scanf("%d",&ch);
		if(test != 1)
		{
			printf("\n Invalid choice...!!!\n\n");
			exit(1);
		}
		if(ch==1) enqueue();
		else if(ch==2) dequeue();
		else if(ch==3) display();
		else if(ch==4) break;
		else printf("\n Invalid choice, Enter a valid choice: ");
	}
}

void enqueue(){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(front==NULL){
		front=ptr;
		rear=ptr;
		printf("\n Enter the data: ");
		scanf("%d",&ptr->data);
		ptr->next=NULL;
	}
	else{
		printf("\n Enter the data: ");
		scanf("%d",&ptr->data);
		rear->next=ptr;
		rear=ptr;
		rear->next=NULL;
	}
}


void dequeue(){
	struct node *ptr;
	if(front==NULL)
	printf("\nQueue is empty");
	else{
		ptr=front;
		printf("\n deleted element is %d", ptr->data);
		front=ptr->next;
		free(ptr);
	}
}

void display(){
	struct node *ptr;
	if(front==NULL)
	printf("\n Queue is empty");
	else{
		ptr=front;
		while(ptr!=NULL){
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("NULL");
	}
}






















