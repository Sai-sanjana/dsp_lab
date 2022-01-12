// c program to check balance of parenthesis
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void check_parenthesis();
char word[100]={};
void evaluate();
void push(char );
char pop();
void display();
struct node
{
	char data;
	struct node *next;
};
struct node *top=NULL;


void main(){
	int n,i,j,temp[100]={0},flag=0;
	printf("Enter string (Enter only parenthesis): ");
	gets(word);
	n=strlen(word);
	for(i=0;i<n;i++){
		if((word[i]=='(')||(word[i]==')')||(word[i]=='{')||(word[i]=='}')||(word[i]=='[')||(word[i]==']')){
			temp[i]=0;
		}
		else{
			temp[i]=1;
		}
	}
	for(i=0;i<n;i++){
		if(temp[i]==1){
			flag=1;
		}
	}
	if(flag==1){
		printf("\n Invalid string \n\n ");
	}
	else{
		//printf("\n len is %d\n",n);
		puts(word);
		evaluate();
	}

}


void evaluate(){
	int i,j,n,val=1;
	char x,y;
	n=strlen(word);
	for(i=0;i<n;i++){
		if((word[i]=='(')||(word[i]=='{')||(word[i]=='[')){
			push(word[i]);
		}
		else{
			x=pop();
			if((x=='(')&&(word[i]==')')){
				val=1;
			}
			else if((x=='{')&&(word[i]=='}')){
				val=1;
			}
			else if((x=='[')&&(word[i]==']')){
				val=1;
			}
			else if(x=='a') {
			val=0;
			break;
			}
			else{
				val=0;
			}
		}
		if(i==(n-1)){
			y=pop();
			if(y!='a')	{
				val=0;
			}
		}
	}
	if(val==1){
		printf("\n True\n");
	}
	else{
		printf("\n False\n");
	}
}


void push(char val){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->next=top;
	top=ptr;
}

char pop(){
	struct node *ptr;
	char val;
	if(top==NULL){
	 return 'a';
	}
	else{
		ptr=top;
		val=ptr->data;
		top=ptr->next;
		free(ptr);
		return val;
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









