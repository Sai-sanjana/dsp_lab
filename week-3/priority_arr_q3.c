//program for queue using arrays
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
int queue[max];
char s_name[max][10];
int Gate_score[max];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void display();

void main(){
	int ch;
	while(1)
	{
		printf("\n Priority queue using array operations are: \n 1.Enqueue \n 2.Dequeue \n 3.Display \n 0.Exit");
		printf("\n Enter ur choice:");
		if(scanf("%d",&ch)==1){
            if(ch==1) enqueue();
            else if(ch==2) dequeue();
            else if(ch==3) display();
            else if(ch==0) break;
            else printf("\n Invalid choice, Enter a valid choice: ");
		}
		else{
            printf("Error invalid datatype");
            exit(0);
		}
	}
}


void enqueue(){
	int p,i;
	char element[10];
	if((rear==max-1)&&(front==0))
	printf("\n queue over flow");
	else{
        printf("\n Enter name of the student to be inserted: ");
        scanf("%s",&element);
		printf("\n Enter Gate score of the new student: ");
		scanf("%d",&p);
		if(p>1000){
                printf("\n Invalid gate score, try again...");
                return;
        }
		if(front==-1){
            front=0;
            rear=0;
            //queue[rear]=element;
            //s_name[rear][0]=element;
            strcpy(s_name[rear],element);
            Gate_score[rear]=p;
		}
		else if(rear==max-1){
            for(i=front;i<=rear;i++){
                //queue[i-front]=queue[i];
                strcpy(s_name[i-front],s_name[i]);
                Gate_score[i-front]=Gate_score[i];
                rear=rear-front;
                front=0;
                for(i=rear;i>front;i--){
                    if(p>Gate_score[i]){
                        //queue[i+1]=queue[i];
                        strcpy(s_name[i+1],s_name[i]);
                        Gate_score[i+1]=Gate_score[i];
                    }
                    else
                        break;
                    //queue[i+1]=element;
                    strcpy(s_name[i+1],element);
                    Gate_score[i+1]=p;
                    rear++;
                }
            }
		}
		else{
		    for(i=rear;i>=front;i--){
                if(p>Gate_score[i]){
                    //queue[i+1]=queue[i];
                    strcpy(s_name[i+1],s_name[i]);
                    Gate_score[i+1]=Gate_score[i];
                }
                else
                    break;
		    }
		    strcpy(s_name[i+1],element);
		    Gate_score[i+1]=p;
		    rear++;
		}
	}
}

void dequeue(){
	if((front==-1)||(front>rear))
	printf("\n queue is underflow");
	else{
		printf("\n deleted name is %s and Gate score is %d\n",s_name[front],Gate_score[front]);
		if(front==rear)
            front=rear=-1;
        else
            front++;
	}
}

void display(){
	int i;
	if((front==-1)&&(rear==-1)||(front>rear))
	printf("\n queue is empty");
	else{
		printf("\n queue elements are:");
		for(i=front;i<=rear;i++){
			printf("\n Student name is %s\t Gate score is %d",s_name[i],Gate_score[i]);
		}
		printf("\n");
	}
}

