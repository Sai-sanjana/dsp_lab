//program for queue using arrays
#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void display();

void main(){
	int ch,test;
	while(1)
	{
		printf("\n queue using array operations are: \n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit");
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
		else printf("\n Invalid choice, Enter a valid choice \n\n");
	}
}


void enqueue(){
	int element;
	if(rear==max-1)
	printf("\n queue over flow");
	else{
		if(front==-1)
		front=0;
		printf("\n Enter element to be inserted: ");
		scanf("%d",&element);
		rear++;
		queue[rear]=element;
	}
}

void dequeue(){
	if((front==-1)||(front>rear))
	printf("\n queue is underflow");
	else{
		printf("\n deleted elemented is %d",queue[front]);
		front++;
	}
}

void display(){
	int i;
	if((front==-1)&&(rear==-1)||(front>rear))
	printf("\n queue is empty");
	else{
		printf("\n queue elements are:\n");
		for(i=front;i<=rear;i++){
			printf("%d\t",queue[i]);
		}
	}
}




























