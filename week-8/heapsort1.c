//heap sort program 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
int number[MAX]={0};
int count=0;
int flag=0;


  // Function to swap the the position of two elements
void swap(int *ele1, int *ele2) 
{
	int variable;
    variable = *ele1;
    *ele1 = *ele2;
    *ele2 = variable;
}


// Function to max heapify elements
void max_heapify(int number[], int n, int i) 
{
  // Find largest among root, left child and right child
  int max = i;
  int left = ( 2 * i) + 1;				//location of left child is 2i+1
  int right = (2 * i )+ 2;				//location of right child is 2i+2

  if (left < n && number[left] > number[max])
 	{
	 	max = left;
	}

  if (right < n && number[right] > number[max])
  {
  	    max = right;
  }

    // Swap and continue heapifying if root is not max
    if (max != i) 
	{
      swap(&number[i], &number[max]);
      max_heapify(number, n, max);
  	}
}



//Function to min heapify elements
void min_heapify(int number[], int n, int i) 
{
  // Find smallest among root, left child and right child
  int min = i;
  int left = (2 * i) + 1; 		//location of left child is 2i+1
  int right = (2 * i)+ 2;		//location of right child is 2i+2

  if (left < n && number[left] < number[min])
  {
  	 min = left;
  }
   

  if (right < n && number[right] < number[min])
  {
  	 min = right;
  }
   

    // Swap and continue heapifying if root is not min
    if (min != i) 
	{
      swap(&number[i], &number[min]);
      min_heapify(number, n, min);
  	}
}



//Function to display array elements
void display(int array[],int n)
{
	int i;
	printf("\n numberay elements are: ");
	for(i=0;i<n;i++)
	{
		printf("  %d",array[i]);
	}
	printf("\n\n");
}



//Function to build heap
void build_heap()
{
	int n,size,i;
	printf("\n Enter number of elements: ");
	scanf("%d",&n);
	count = n;
	printf("\n Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&number[i]);
	}
	display(number,n);
	// Build heap (rearrange numberay)
	if(flag==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	max_heapify(number, n, i);
		}
		printf("\n Max heap bulid sucessfully....\n");
	}
	else if (flag == 2)
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	min_heapify(number, n, i);
		}
		printf("\n Min heap bulid sucessfully....\n");
		
	}	
}



//Function to insert elements in to heap
void insert()
{
	int key,i,j,n;
	printf("\n Enter key value to be inserted in to heap: ");
	scanf("%d",&key);
	n=count;
	number[n]=key;
	count++; //incrementing number of elements
	n++;
	// Build heap (rearrange numberay)
	if(flag==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	max_heapify(number, n, i);
		}
	}
	else if(flag==2)
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	min_heapify(number, n, i);
		}		
	}
    printf("\n Element %d inserted in to heap sucessufully....\n\n",key);
	
	
}


//Function to delete elements from heap
void delet()
{
	int i,j,key,n,index,k=0;
	printf("\n Enter node value to be deleted: ");
	scanf("%d",&key);
	n=count;
	for(i=0;i<n;i++)		//finding index value of node
	{
		if(number[i]==key)
		{
			k=1;
			index=i;
			break;
		}		
	}
	if(k==0)
	{
		printf("\n Element not found\n\n");
		return;
	}
	swap(&number[index],&number[n-1]);
	number[n-1]=0;		//deleting node from heap
	n--;
	count--;     //decrementing number of elements
	// Build heap (renumberange array) after deleting element
	if(flag==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	max_heapify(number, n, i);
		}
	}
	else
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	min_heapify(number, n, i);
		}		
	}
    printf("\n Element deleted sucessfully from heap...\n\n");
	
}



//Function for heap sort
void heapsort()
{
	int i,j,n;
	n=count;
	int number2[n];
	for(i=0;i<n;i++)
	{
		number2[i]=number[i];
	}	
	    // Heap sort
    
	if(flag==1)
	{	
		//Max heap
		for (i = n - 1; i >= 0; i--) 
		{
	      swap(&number2[0], &number2[i]);
	
	      // Heapify root element to get highest element at root again
	      max_heapify(number2, i, 0);
	    }
	}
	else
	{
		//Min heap
		for (i = n - 1; i >= 0; i--) 
		{
	      swap(&number2[0], &number2[i]);
	
	      // Heapify root element to get lowest element at root again
	      min_heapify(number2, i, 0);
	    }
		
	}
    display(number2,n);	
}



//Function to print heap tree
void print_tree()
{
	int i,j,k,n,temp,flag=1,no,p=0,h;
	int number2[count];
	n=count;
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		number2[i]=number[i];
	}
	h = log(count);
	h++;
	no=pow(2,h);
	for(j=0;j<=h;j++)
	{
		printf("\n");
	temp=pow(2,j);
	k=temp;
		while(k--)
		{
			for(i=0;i<no/temp;i++)
			{
				printf("   ");				
			}
			printf("%d",number2[p++]);
			if(p==n) 
			{
				flag=0;
				break;
			}
			for(i=0;i<no/temp;i++)
			{
				printf("   ");				
			}
		}
	
	}
	printf("\n\n\n");
}



void main()
{
	int i,choice1,choice2,check=0,val;
	printf("\n Heap sort\n");
	printf("\n 1. Max heapify");
	printf("\n 2. Min heapify");
	printf("\n\n Enter ur choice: ");
	val = scanf("%d",&choice1);
	
	if(val!=1)
	{
		printf("\n Invaid choice... !!!");
		exit(0);
	}
	if(choice1==1 || choice1==2)
	{
		flag=choice1;
		while(1)
		{
			if(choice1==1)
			{
				printf("\n\n Max heapify");
			}
			else if (choice1 == 2)
			{
				printf("\n\n Min heapify");
			}
			printf("\n 1. Bulid heap by inserting some intergers..");
			printf("\n 2. Insert a key in to heap ");
			printf("\n 3. Delete function ");
			printf("\n 4. Sort fuction");
			printf("\n 5. Display heap tree");
			printf("\n 0. exit");
			printf("\n\n Enter ur choice: ");
			scanf("%d",&choice2);
			if(choice2 == 1)
			{
				//build heap			
				if(check==0)
				{
					build_heap();				
					check=1;
				}
				else
				{
					printf("\n Heap already build\n");
				}
			}
			else if(choice2 == 2)
			{
				//insert a key
				if(check==0)
				{
					printf("\n Heap has not build yet, build heap...\n\n");
				}
				else
				{
					insert();
				}
			}
			else if(choice2==3)
			{
				//delete
				if(check==0)
				{
					printf("\n Heap has not build yet, build heap...\n\n");
				}
				else
				{
					delet();
				}
				
			}
			else if(choice2==4)
			{
				//sort function
				if(check==0)
				{
					printf("\n Heap has not build yet, build heap...\n\n");
				}
				else
				{
					heapsort();
				}
			}
			else if(choice2==5)
			{
				//display heap tree
				if(check==0)
				{
					printf("\n Heap has not build yet, build heap...\n\n");
				}
				else
				{
					print_tree();
				}
			}
			else if(choice2==0)
			{
				break;
			}
			else
			{
				printf("\n Invalid input.. Try again...!!!");
			}			
		}
	}
	else
	{
		printf("\n Invalid choice... !!!");
	}

}




