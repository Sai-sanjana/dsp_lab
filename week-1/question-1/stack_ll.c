//program for stack using single linked list 
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;

void main(){
int x,check;
while(1){
printf(" \n Stack using Single Linked list \n 1 for push\n 2 for pop \n 3 for display \n 4 for exit the program \n");
printf(" Enter ur choice: ");
check = scanf("%d",&x);
if(check!=1)
{
	printf("\n Invalid choice...!!!");
	exit(1);
}
	if(x==1) push(); 
	else if(x==2)  pop(); 
	else if(x==3) display(); 
	else if(x==4) break;
	else { printf("\n Enter a valid choice \n\n"); }
}
}

void push(){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter node data : ");
	scanf("%d",&ptr->data);
	ptr->next=top;
	top=ptr;
}

void pop(){
	struct node *ptr;
	if(top==NULL) printf("\n empty");
	else{
		ptr=top;
		printf("\n deleted element is %d",ptr->data);
		top=ptr->next;
		free(ptr);
	}
}

void display(){
	struct node *ptr;
	if(top==NULL) printf("\n empty");
	else{
		ptr=top;
		while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	}
}

