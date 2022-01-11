#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void push(int symbol);
int pop();
void infix_to_postfix();
int priority(char symbol);
int isEmpty();
int white_space(char);
int eval_post();


char infix[100], postfix[100];
int stack[100];
int top,val;

int main()
{
    top=-1;
    printf("\n Enter infix: ");
    gets(infix);
    infix_to_postfix();
    printf(" Postfix expsn is :");
    puts(postfix);
    val=eval_post();
    printf("\n%d",val);
    return 1;
}


void infix_to_postfix()
{
    int i,p=0;
    char next;
    char symbol;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        if(!white_space(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='(')
                    postfix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
                    postfix[p++]=pop();
                push(symbol);
                break;
            default:
                postfix[p++]=symbol;
            }
        }
    }
    while(!isEmpty( ))
        postfix[p++]=pop();
    postfix[p]='\0';
}

int priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default :
        return 0;
    }
}

void push(int symbol)
{
    if(top>100)
    {
        printf("\n stack overflow\n");
        exit(1);
    }
    stack[++top]=symbol;
}
/*
void push(int symbol)
{
    if(top>100)
    {
        printf("\n stack overflow\n");
        exit(1);
    }
    if (! isEmpty() && stack[top] >= 0 && stack[top] <= 9) {
      stack[top] *= 10;
      stack[top] += symbol;
    }
    else {
      stack[++top]=symbol;
    }
}*/

int pop()
{
    if( isEmpty() )
    {
        printf("\n stack undeflow");
        exit(1);
    }
    return (stack[top--]);
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int white_space(char symbol)
{
    if( symbol == ' ' || symbol == '\t' )
        return 1;
    else
        return 0;
}

int eval_post()
{
    int a,b,i,temp,result;
    for(i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
                temp=b+a;
                break;
            case '-':
                temp=b-a;
                break;
            case '*':
                temp=b*a;
                break;
            case '/':
                temp=b/a;
                break;
            case '%':
                temp=b%a;
                break;
            case '^':
                temp=pow(b,a);
            }
            push(temp);
        }
    }
    result=pop();
    return result;
}
