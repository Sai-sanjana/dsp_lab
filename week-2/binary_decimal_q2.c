//program for calculating decimal value from binary using single linked list
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 5
int list[max];
int len=0;
void insert();
void delet();
void display();
int evaluate();
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL,*rear=NULL;
void main(){
	int ch,i=0,sum,test;
	while(1)
	{
	    printf("\n Enter binary number(0 or 1), 9 as end of number: ");
        test = scanf("%d",&ch);
        if(test != 1)
        {
        	printf("\n Invalid number ");
        	exit(1);
		}
        if(ch==0) insert(ch);
        else if(ch==1)insert(ch);
        else if(ch==9){
            display();
            break;
        }
        else{
            printf("\n Invalid number");
        }

	}
	//printf("\n len is %d ",len);
	sum=evaluate();
	printf("\n\n ans is %d\n\n",sum);
}

void insert(int val){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(front==NULL){
		front=ptr;
		rear=ptr;
		ptr->data=val;
		ptr->next=NULL;
	}
	else{
		ptr->data = val;
		rear->next=ptr;
		rear=ptr;
		rear->next=NULL;
	}
}


void delet(){
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
	printf("\n list is empty");
	else{
		ptr=front;
		printf("\n");
		while(ptr!=NULL){
			printf("%d->",ptr->data);
			len++;
			ptr=ptr->next;
		}
		printf("NULL");
	}
}

int evaluate(){
    struct node *ptr;
    int sum=0,t;
    ptr=front;
    while(ptr!=NULL){
        t=ptr->data;
        sum=sum+(t*(pow(2,--len)));
        ptr=ptr->next;
    }
    return sum;
}













