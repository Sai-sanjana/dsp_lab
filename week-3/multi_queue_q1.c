#include <stdio.h>
#include<stdlib.h>
#define arr_size 40
//given no of queues as 4
#define no_of_q 4
#define q_size (arr_size/no_of_q)
int multi_q_arr[arr_size]={0};
//given initial values as 5,,3,2,6
int rear[no_of_q]={5,3,2,6};
void creat();
void display_all();
void display2();
void initialize();
void insert();
void delet();
// total size of array is 40
// number of queues are 4 
// size of each queue is 40/4 = 10


void main(){
	int choice,i,j,k;
	k=0;
	while(1){
		printf("\n Implementing multi level queue in single array\n");
		printf("\n 1. Initialize the multi level queues with given default sizes");
		printf("\n 2. Insertion in queue with minimum nuber of elements");
		printf("\n 3. Deletion from queue with maximum number of elements");
		printf("\n 4. Display all queues");
		printf("\n 0. Exit");
		printf("\n\n Enter your choice: ");
		if(scanf("%d",&choice)==1){
			if(choice == 1){
				//checking wheather queue has already initialized or not
				if(k==1){
					printf("\nMulti level Queue already initialized\n");
				}
				else if(k==0){
					initialize();
					k=1;
					printf("\n");
				}
				else{ }	
			}
			else if (choice == 2){
				//checking wheather queue has already initialized or not
				if(k==0){
					printf("\n Multi level queue has not been initialized\n\n");
				}
				else{
					insert();
				}
			}
			else if (choice == 3){
				//checking wheather queue has already initialized or not
				if(k==0){
					printf("\n Multi level queue has not been initialized\n\n");
				}
				else{
					delet();
				}
			}
			else if (choice == 4){
				//checking wheather queue has already initialized or not
				if(k==0){
					display_all();
					printf("\n Multi level queue has not been initialized\n\n");
				}
				else{
					display2();
				}
			}
			else if (choice ==0){
				break;
			}
			//checking for other numbers
			else{
				printf("\n Invalid choice.. Enter a valid choice\n");
			}
		}
		// exception handling other alphabets
		else{
			printf("\n Invalid choice\n\n");
			exit(0);
		}
	}	
}

// function to initialize multi leve queue
// queue1 , q2,q3,q4 with 5,3,2,4 number of elements respectively
void initialize(){
	int i,j,temp,k;
	for(j=0;j<no_of_q;j++){
		i=q_size*j;
		for(k=0;k<rear[j];k++,i++){
			multi_q_arr[i]=(i+1);			
		}
	}
	printf("\n Multi level queue initialized\n");
	display2();
}

void insert(){
	int val,front,j,k,temp,min,index;
	min=rear[0];
	index=0;
	//finding minimum queue in multi level queue
	for(front=0;front<no_of_q;front++){
		if(rear[front]<min){
			min=rear[front];
			index=front;
		}
	}
	printf("\n queue %d has minimum number of elements",index+1);
	printf("\n minimum number of elements in queue %d are %d\n",index+1,min);
	//inserting in to minimum queue
	front=q_size*index;
	printf("\n Enter the valued to be inserted in to queue %d:  ",index+1);
	scanf("%d",&multi_q_arr[front+min]);
	printf("\n Inserted valued is %d\n\n",multi_q_arr[front+min]);
	//incrementing rear value
	rear[index]=rear[index]+1;
	
}


void delet(){
	int val,front,j,k,temp,max,index;
	max=rear[0];
	index=0;
	//finding maximum queue in multi level queue
	for(front=0;front<no_of_q;front++){
		if(rear[front]>max){
			max=rear[front];
			index=front;
		}
	}
	printf("\n queue %d has maxinum number of elements ",index+1);
	printf("\n maximum number of elements in queue %d are %d\n",index+1,max);
	
	front=q_size*index;
	printf("\n last elemented from queue %d is deleted and deleted value is %d\n",index+1,multi_q_arr[front+max-1]);
	//inserting in to minimum queue
	multi_q_arr[front+max-1]=0;
	//Decrementing rare value
	rear[index]=rear[index]-1;	
	
}

//function to display complete array of multi level queue
void display_all(){
	int front,j,temp;
	printf("\n Multi level queue: ");
	for(j=0;j<no_of_q;j++){
		printf("\n Queue no - %d\n",j+1);
		front=q_size*j;
		temp=q_size;
		while(temp--){
			printf("%d\t",multi_q_arr[front++]);
		}
		printf("\n");
	}
}


// function to display multi level queues
void display2(){
	int j,k,front;
	printf("\n Multi level queue: \n");
	for(j=0;j<no_of_q;j++){
		printf("\n Queue no - %d\n",j+1);
		front=q_size*j;
		for(k=0;k<rear[j];k++,front++){
			printf("%d\t",multi_q_arr[front]);			
		}
		printf("\n");
	}
}




