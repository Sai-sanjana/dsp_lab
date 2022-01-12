// C program for single circular linked list operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char info[3][10];
	struct node *link;
};
struct node *head;
int c=0,num=0;
void creat();
void display();
void check_match(int);
void display_second();
void replace_fun(int);



void main(){
    int ch,len;
    printf("\n Enter the number of node to  create: ");
    scanf("%d",&ch);
    len=ch;
    while(ch--){creat();}
    display();
    check_match(len);
    display_second();
    replace_fun(len);
    display();
    check_match(len);
}


void creat(){
    int i;
    if(c==0){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter 3 strings of node %d:\n",++num);
    for (i = 0; i < 3; i++)
    scanf("%s", &ptr->info[i][0]);
	head=ptr;
	ptr->link=head;
	printf("Linked list created\n");
	c=1;
    }
    else{
    struct node *ptr,*cptr;
	ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter 3 strings of node %d:\n",++num);
    for (i = 0; i < 3; i++)
    scanf("%s", &ptr->info[i][0]);
	cptr=head;
	while(cptr->link!=head) {
		cptr=cptr->link;
	}
	cptr->link=ptr;
	ptr->link=head;
    }
}


void display(){
	struct node *ptr;
	int i;
	if(head==NULL)
	printf("\n Linked list is empty");
	else{
		printf("\n linked list elements are :\n");
		ptr=head;
		while(ptr->link!=head){
            for(i=0;i<3;i++){
            printf("%s  ",ptr->info[i]);
            }
			ptr=ptr->link;
			printf("\n");
		}
		for(i=0;i<3;i++){
            printf("%s  ",ptr->info[i]);
        }
        printf("\n");
	}
}

void check_match(int len){
    struct node *ptr1,*ptr2;
	int i=1,val,flag=1,j;
	ptr1=head;
	while(i<=len){
		j=i+1;
		if(i==len){j=1;}
        ptr2=ptr1;
        ptr1=ptr1->link;
        val=strcmp(ptr2->info[2],ptr1->info[0]);
        if(val!=0){
            printf("\n Third string value of node %d is not matching with first sring value of node %d",i,j);
            flag=0;
            break;
        }
        i++;
	}
	if(flag==1&&val==0){printf("\n matching");}
	else{printf("\n no matching");}

}

void display_second(){
	struct node *ptr;
	int i;
	if(head==NULL)
	printf("\n Linked list is empty");
	else{
		printf("\n\n second string value of linked list elements are :");
		ptr=head;
		while(ptr->link!=head){
			printf("\n%s",ptr->info[1]);
			ptr=ptr->link;
		}
		printf("\n%s",ptr->info[1]);
        printf("\n");
	}
}

 void replace_fun(int len){
 	int n1,n2,i,j;
 	char new_str[10];
 	struct node *ptr;
 	while(1){
 	printf("\n Do you want to replace string 1-yes, 0- no: ");
 	scanf("%d",&j);
 	if(j==1){
 	printf("\n Enter node number and string number to replace: ");
 	scanf("%d%d",&n1,&n2);
 	if(n1>len){printf("\n Enter a valid node number"); }
 	if(n2>2){printf("\n Enter a valid string number"); }
 	ptr=head;
 	for(i=1;i<n1;i++){
 		ptr=ptr->link;
	 }
 	printf(" Enter new string:");
 	scanf("%s",ptr->info[--n2]);
 	}
 	else if(j==0){
        break;
 	}
 	else{
        printf("Invalid choice, Enter 0 or 1");
 	}
 	}

 }












