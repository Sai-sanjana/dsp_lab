#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define MAX 100
struct Stack {
    int top;
    int maxSize;
    int* array;
};
char var;
int temp1=0,flag=0,count_parenthesis=0;

struct Stack* create(int max)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = max;
    stack->top = -1;
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
    if(stack->top == stack->maxSize - 1){
        printf("stack over flow\n");
    }

    return stack->top == stack->maxSize - 1;
}


int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}


void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}


int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}


int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}


int check_operand(char var)
{
    return (var >= 'a' && var <= 'z') || (var >= 'A' && var <= 'Z');
}
int precedence(char var)
{
    switch (var)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;

}

int infix_to_postfix(char* expression)
{
    int i, j;


    struct Stack* stack = create(strlen(expression));
    if(!stack)
        return -1 ;

    for (i = 0, j = -1; expression[i]; ++i)
    {

        if (check_operand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(stack, expression[i]);

        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++j] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // flag expression
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                expression[++j] = pop(stack);
            push(stack, expression[i]);
        }

    }


    while (!isEmpty(stack))
        expression[++j] = pop(stack);

    expression[++j] = '\0';
    printf( "%s", expression);
}
int getPostfix(char* expression)
{
    int i, j;
    struct Stack* stack = create(strlen(expression));
    if(!stack)
        return -1 ;

    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (check_operand(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push(stack, expression[i]);
        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++j] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                expression[++j] = pop(stack);
            push(stack, expression[i]);
        }

    }

    while (!isEmpty(stack))
        expression[++j] = pop(stack);

    expression[++j] = '\0';

}
void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void parenthesis_check(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
/*void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}*/
void infix_to_prefix(char *exp){

    int size = strlen(exp);


    reverse(exp);

    parenthesis_check(exp);

    getPostfix(exp);

    reverse(exp);
}
//Checking for operator
int is_operator (char token)
{
  if (token == '+' || token == '-' || token == '*' || token == '/'
      || token == '^')
    {
      return 1;
    }
  return 0;
}
/*
int validate(char expr[])
{
    int n = strlen(expr);
    int i;



    if(is_operator(expr[0]) || is_operator(expr[n-1]) )
    {
        return 0;
    }



    for( i=0; i<n-1; i++)
    {
        if(is_operator(expr[i]) && is_operator(expr[i+1]) )
        {
            return 0;
        }
    }

    return 1;
}
*/
void validate_infix(char infixexp[]){
  int s[50];
  int top=-1;
  count_parenthesis=0,temp1=0;
  int i=0;
  for(i=0; i<strlen(infixexp); i++ ){
  	var=infixexp[i];
  	if((i==0 || (i==strlen(infixexp)-1)) && (var =='+'|| var=='-'||var=='*'||var=='/'||var=='^')){
  		flag=1;
		return;
	  }
	else{
		if((var == '(' || var=='{' || var=='[') && temp1==0 ){
			s[++top]=var;
		}
		else if(((var == ')' && s[top]=='(')||(var==']' && s[top]=='[') ||(var=='}' && s[top]=='{'))&& temp1==1 ){
		top--;
		}
		else if((var =='+'|| var=='-'||var=='*'||var=='/'||var=='^') && temp1 == 1 ){
			temp1=0;
		}
		else if (isalpha(var) && temp1 == 0){
			temp1=1;
		}
		else{
			flag=1;
			return;
		}
	}

  }
  if(top!= -1)
  flag=1;
}

void main(){
	char infix_exp[100]={},exp[100]={},prefix_exp[100]={};
	int i,j,k,len,n,choice;
	printf("\n Enter infix expression: ");
	gets(infix_exp);
	len = strlen(infix_exp);
	printf("\n Given infix expression is %s",infix_exp);
	while(1){
		printf("\n\n 1. Check if given infix expression is valid or not");
		printf("\n 2. Convert infix expression to postfix expression");
		printf("\n 3. Convert infix expression to prefx expression");
		printf("\n 0. Exit\n");
		if(scanf("%d",&choice)==1){
			if(choice==1){

                    validate_infix(infix_exp);
                    if(flag==0)
                    printf("\nGiven Infix expression is valid\n");
                    else
                    printf("\nGiven Infix expression is invalid\n");
			}
			else if(choice==2){
				printf("\n postfix expression is ");
               infix_to_postfix(infix_exp);
			}
			else if(choice==3){
                    strcpy(prefix_exp,infix_exp);
				  infix_to_prefix(prefix_exp);
                printf("\n prefix expression is %s",prefix_exp);
			}
			else if(choice==0){
				break;
			}
			else{
				printf(" \nInvalid choice.. Try again\n");
			}
		}
		else{
			printf("\n Invalid input");
			exit(0);
		}
	}

}



