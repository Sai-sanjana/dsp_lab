//quick sort program by choosing random element as pivot
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000
 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition(int number[25],int first,int last){
	int i, j, pivot, temp,size;
	size=(last-first);
	int randomIndex = first + rand() % size; //choosing random value from array
   
	swap(&number[randomIndex],&number[first]); //swapping random value with first value in array
    
	pivot=first;
	i=first;
	j=last;

	while(i<j){
		while(number[i]<=number[pivot]&&i<last)
			i++;
	    while(number[j]>number[pivot])
	        j--;
	    if(i<j)
		{
	        swap(&number[i],&number[j]);
	    }
	}
		
	swap(&number[pivot],&number[j]);
	return j;
}

void quicksort(int number[25],int first,int last)
{
	int p;
	if(first<last)
	{
		p = partition(number,first,last);
		quicksort(number,first,(p-1));
		quicksort(number,p+1,last);
		
	}
}


void almost_sorted(int number[n])
{
	int i,k;
	k=(n/100); //calculating 1% of n
	for(i=0;i<k;i++)
	{
		swap(&number[i],&number[(k+i)]); //swapping 1% of values 
	}
}


void display(int number[n],int count)
{
	int i;
	for(i=0;i<count;i++)
		{
			printf("  %d",number[i]);
		}
		
}


int main(){
   int i, count, number[n];   
    count=n;
    for(i=0;i<count;i++)
    {
    	number[i]=(rand()%100);
	}
	printf("\n Quick sort by taking Random element as pivot with n value as %d\n",n);
	
	//printf("\n Before sorting: \n");
	//display(number,count);
	
	//giving unsorted array as input
	clock_t begin1 = clock();
	quicksort(number,0,count-1);
	clock_t end1 = clock();

	//printf("\n After Sorting :\n ");
	//display(number,count);

	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving unsorted array(random elements as input) and sorted array as output is %lf seconds\n",time_spent1);
	
   	
   	
   	//printf("\n\n Before sorting: \n");
   	//display(number,count);

   	//giving sorted array as input
   	clock_t begin2 = clock();
	quicksort(number,0,count-1);
	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving sorted array as input and sorted array as output is %lf seconds\n",time_spent2);
	//printf("\n After Sorting :\n ");
	//display(number,count);

	
	//giving almost sorted array as input
	almost_sorted(number);
	//printf("\n Before sorting: \n");
	//display(number,count);

	clock_t begin3 = clock();
	quicksort(number,0,count-1);
	clock_t end3 = clock();
	double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving almost sorted array as input and sorted array as output is %lf seconds\n",time_spent3);
	//printf("\n After Sorting :\n ");
	//display(number,count);
   	
	return 0;
}
