// quick sort program by taking median of first middle and last element as pivot
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000


void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int number[], int first, int last)
{
	int pivot,i,j;
	pivot = number[last];
	i = (first - 1);

	for ( j = first; j < last; j++) {
		if (number[j] < pivot) {
		swap(&number[++i], &number[j]);
		}
	}

	swap(&number[i + 1], &number[last]);
	return (i + 1);
}


int find_median(int number[], int first, int last) {

	int pivot;
	int mid = (first + last) / 2;
	if (number[mid] < number[first])
		swap(&number[mid], &number[first]);
	if (number[last] < number[first])
		swap(&number[last], &number[first]);
	if (number[last] < number[mid])
		swap(&number[last], &number[mid]);
	swap(&number[mid], &number[last-1]);

	pivot = number[last];

	return partition(number, first, last);
}

void quickSort(int number[], int first, int last) {
	if (first < last) {
		int pi = find_median(number, first, last);

		quickSort(number, first, pi - 1);
		quickSort(number, pi + 1, last);
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
	printf("\n Quick sort by taking median of(1st,middle and last) element as pivot with n value as %d\n",n);
	
	//printf("\n Before sorting: \n");
	//display(number,count);
	
	//giving unsorted array as input
	srand(time(0));
	clock_t begin1 = clock();
	//quickSort(number, 0, size - 1);
	quickSort(number,0,count-1);
	clock_t end1 = clock();

	//printf("\n After Sorting :\n ");
	//display(number,count);

	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving unsorted array(random elements as input) and sorted array as output is %lf seconds\n",time_spent1);
	
   	
   	
   	//printf("\n\n Before sorting: \n");
   	//display(number,count);

   	//giving sorted array as input
   	srand(time(0));
   	clock_t begin2 = clock();
	quickSort(number,0,count-1);
	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving sorted array as input and sorted array as output is %lf seconds\n",time_spent2);
	//printf("\n After Sorting :\n ");
	//display(number,count);

	
	//giving almost sorted array as input
	almost_sorted(number);
	//printf("\n Before sorting: \n");
	//display(number,count);

	srand(time(0));
	clock_t begin3 = clock();
	quickSort(number,0,count-1);
	clock_t end3 = clock();
	double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving almost sorted array as input and sorted array as output is %lf seconds\n",time_spent3);
	//printf("\n After Sorting :\n ");
	//display(number,count);
   	
	return 0;
}
