//Stack using array 
#include<stdio.h>
#include<stdlib.h>
#define size 5
void push();
void pop();
void display();
int stack[size]={};
int top=-1;



void main(){
int x,check;
while(1){
printf(" \n Stack using array \n 1 for push\n 2 for pop \n 3 for display \n 4 for exit the program \n");
printf(" Enter ur choice: ");
check = scanf("%d",&x);
if(check!=1)
{
	printf("\n Invalid choice...!!!");
	exit(1);
}
printf("\n %d",x);

	if(x==1) push(); 
	else if(x==2)  pop(); 
	else if(x==3) display(); 
	else if(x==4) break;
	else { printf("\n Enter a valid choice \n\n "); }
}
}

void push(){
	int val;
	if (top==size-1)
	{
		printf("\n stack overflow\n");
	}
	else{
		printf("\n Enter the element to be inserted: ");
		scanf("%d",&val);
		top++;
		stack[top]=val;
		
	}
}

void display(){
	int i;
		if (top==-1)
	{
		printf("\n stack underflow\n");
	}
	else{
		printf("\n stack elements are: ");
		for(i=0;i<=top;i++){
			printf("	%d",stack[i]);
		}		
	}
}

void pop(){
		int i;
		if (top==-1)
	{
		printf("\n stack underflow\n");
	}
	else{
		i=stack[top];
		top--;
		printf("\ndeleted element is %d\n",i);
	}	
}











