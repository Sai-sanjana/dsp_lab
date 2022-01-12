// hashing using quadratic probing 

#include <stdio.h>
#include<stdlib.h>
#define SIZE 11
#define PRIME 8

int hashtable[SIZE]={0};


int hash1(int key)
{
	return (key%SIZE);
}


int hash2(int key)
{
	return (PRIME - (key % PRIME));
}


int is_empty()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(hashtable[i]==0)
		{
			return 1;
		}
		return 0;
	}
}


void insert(int value)
{
	
	int index,i,index2,index3;
	index = hash1(value);
	
	if(!is_empty)
	{
		printf("\n hash table is full ");
	}
	
	else
	{
		if(hashtable[index]==0)
		{
			hashtable[index]=value;
			printf("\n Value inserted in to hash table\n\n");
		}
		else
		{
			index2 = hash2(value);
			i=1;
			while(1)
			{
				index3 = (index + (i * index2))%SIZE;
				if(hashtable[index3]==0)
				{
					hashtable[index3]=value;
					printf("\n Value inserted in to hash table\n\n");
					break;
				}
				i++;
			}		
		}
	}
	

}




void search(int element)
{
	int i,value,check=0;
	for(i=0;i<SIZE; i++)
	{
		value=(element+i)%SIZE;
		if(hashtable[value]==element)
		{
			printf("\nelement is found at index %d\n\n",value);
			check=1;
			break;
		}
	}
	if(i == SIZE && check ==0 )
	printf("\n element not found\n\n");
}

void delet(int element)
{
	int i,value,check=0;
	for(i=0;i<SIZE; i++)
	{
		value=(element+i)%SIZE;
		if(hashtable[value]==element)
		{
			hashtable[value]=0;
			printf("element %d is deleted from hash table \n\n",element);
			check=1;
			break;
		}
	}
	
	
	
	if(i == SIZE && check==0)
	printf("\n element not found\n");
}



void print_hashtable()
{
	int i;
	printf("\n Hash table elements are : \n");
	for(i=0;i< SIZE; i++)
	{
		printf("\n index  no - %d  \t element - %d",i,hashtable[i]);
	}
	printf("\n\n\n");
}


void load_factor()
{
	int count,i;
	double lfactor=0.000000;
	for(i=0;i<SIZE;i++)
	{
		if(hashtable[i]!=0)
		{
			count++;
		}
	}
	lfactor = (double)(((double)count)/SIZE);
	printf("\n load faactor is %lf\n\n",lfactor);
	
}




 void main()
{
    int choice,i,num,check=0;
    while(1)
    {
    	printf("\n Double hashing with hash table size %d",SIZE);
        printf("\n 1. Insert \n 2. Search \n 3. Delete \n 4. Display \n 5. load factor \n 0. exit \n");
        printf("\n Enter your choice: ");
        if(scanf("%d",&choice)==1)
        {
        	if(choice == 1)
        	{
        		//insert
        		check=1;
        		printf("\n Enter element to insert: ");
        		scanf("%d",&num);
        		insert(num);        		
			}
			else if(choice == 2)
			{
				if(check == 0)
				{
					printf("\n No element is inserted \n\n");
				}
				else
				{
				//search
					printf("\n Enter element to search: ");
					scanf("%d",&num);
					search(num);
				}
			}
			else if(choice ==3)
			{
				if(check == 0)
				{
					printf("\n No element is inserted \n\n");
				}
				else
				{
					//delete
					printf("\n Enter element to delete: ");
					scanf("%d",&num);
					delet(num);
				}
			}
			else if(choice ==4)
			{
				//display
				if(check == 0)
				{
					printf("\n No element is inserted \n\n");
				}
				else
				{
					print_hashtable();
				}
			}
			else if(choice ==5)
			{
				//load factor
				load_factor();
			}
			else if(choice == 0)
			{
				break;
			}
			else
			{
				printf("\n Invalid input.... try again  !!!\n");
			}        	
		}
		else
		{
			printf("\n Invalid input\n\n\n");
			exit(0);
		}
 
    }
}
