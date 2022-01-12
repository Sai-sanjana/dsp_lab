/* C program to implement BFS(breadth-first search) and DFS(depth-first search) algorithm */

#include<stdio.h>
#include<stdlib.h>

int create_graph();
void bfs(int s,int n);
void dfs(int s,int n);
void enqueue(int data);
int dequeue();
void push(int data);
int pop();
int a[20][20],vis[20],stack[20],q[20];
int top=-1,front=-1,rear=-1,n;



void main()
{
int i,s,ch,j,flag=0;
while(1)
{
	for(i=1;i<=n;i++)
	vis[i]=0;
	printf("\n\n\n MENU");
	printf("\n 1 Create a graph");
	printf("\n 2 B.F.S traversal of graph ");
	printf("\n 3 D.F.S traversal of graph");
	printf("\n 0 Exit");
	printf("\n ENTER YOUR CHOICE : ");
	if(scanf("%d",&ch)==1)
	{
		if(ch==1)
		{
			if(flag==0) // to check if graph is already created or not
			{
				flag = create_graph();
			}
			else
			{
				printf("\n Graph already created...\n");
			}
		}

		else if(ch==2)
		{
			if(flag==0)
			{
				printf("\n Graph has not been created, Create graph\n\n");
			}
			else
			{
				printf("\n Enter source vertex :");
				scanf("%d",&s);
				printf("\n BFS Traversal of graph : ");
				bfs(s,n);
			}
			
		}
		else if(ch==3)
		{
			if(flag==0)
			{
				printf("\n Graph has not been created, Create graph\n\n");
			}
			else
			{
				printf("\n Enter source vertex :");
				scanf("%d",&s);
				printf("\n DFS Traversal of graph : ");
				dfs(s,n);
			}	
		}
		else if(ch==0)
		{
			exit(0);
		}
		else
		{
			printf("\n Invalid choice.... Try again\n");
		}
	}
	else
	{
		printf("\n Invalid choice\n");
		exit(0);
	}

}

}

int create_graph()
{
	int i,j,k; 
	printf("\n Enter the number of nodes : ");
	scanf("%d",&n);
	printf("\n Enter Adjacency Matrix (Enter 1 if there is an edge else Enter 0) : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\n Is there an edge between node-%d and node-%d : ",i,j);
			if(scanf("%d",&k)==1) //checking if given input is integer or not
			{
				a[i][j]=k;
			}
			else
			{
				printf("\n Invalid choice...\n");
				return 0;
			}
		}
	}
	printf("\n\nTHE ADJACENCY MATRIX IS\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" %d",a[i][j]);
		}
		printf("\n");
	}
	return 1;
}

//**************BFS(breadth-first search) code**************//
void bfs(int s,int n)
{
	int p,i;
	enqueue(s);
	vis[s]=1;
	p=dequeue();
	if(p!=0)
		printf(" %d",p);
	while(p!=0)
	{
		for(i=1;i<=n;i++)
			if((a[p][i]!=0)&&(vis[i]==0))
			{
				enqueue(i);
				vis[i]=1;
			}
		p=dequeue();
		if(p!=0)
	printf(" %d ",p);
	}
	for(i=1;i<=n;i++)
	if(vis[i]==0)
	bfs(i,n);
}


void enqueue(int data)
{
	if(rear==19)
	printf("QUEUE FULL");
	else
	{
		if(rear==-1)
		{
			q[++rear]=data;
			front++;
		}
		else
		q[++rear]=data;
	}
}


int dequeue()
{
	int k;
	if((front>rear)||(front==-1))
		return(0);
	else
	{
		k=q[front++];
		return(k);
	}
}


//***************DFS(depth-first search) code******************//
void dfs(int s,int n)
{
	int i,k;
	push(s);
	vis[s]=1;
	k=pop();
	if(k!=0)
		printf(" %d ",k);
	while(k!=0)
	{
		for(i=1;i<=n;i++)
		if((a[k][i]!=0)&&(vis[i]==0))
		{
			push(i);
			vis[i]=1;
		}
		k=pop();
		if(k!=0)
		printf(" %d ",k);
	}
	for(i=1;i<=n;i++)
	if(vis[i]==0)
	dfs(i,n);
}


void push(int data)
{
	if(top==19)
		printf("Stack overflow ");
	else
		stack[++top]=data;
}


int pop()
{
	int k;
	if(top==-1)
		return(0);
	else
	{
		k=stack[top--];
		return(k);
	}
}

