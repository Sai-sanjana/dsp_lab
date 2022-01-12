//merge sort program
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000


void swap(int* a, int* b) //swaping two values
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


void merge_fun(int number[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int LeftArray[n1], RightArray[n2];

    /* Copy data to temp arrays LeftArray[] and RightArray[] */
    for (i = 0; i < n1; i++)
        LeftArray[i] = number[left + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = number[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            number[k] = LeftArray[i];
            i++;
        }
        else {
            number[k] = RightArray[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        number[k] = LeftArray[i];
        i++;
        k++;
    }


    while (j < n2) {
        number[k] = RightArray[j];
        j++;
        k++;
    }
}


void merge_Sort(int number[], int left, int right)
{
    if (left < right) {

        int middle = left + (right - left) / 2;

        merge_Sort(number, left, middle);
        merge_Sort(number, middle + 1, right);

        merge_fun(number, left, middle, right);
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


int main()
{
   int i, count, number[n];   
    count=n;
    for(i=0;i<count;i++)
    {
    	number[i]=(rand()%100);
	}
	printf("\n Merge Sort with n value as %d\n",n);
	
	//printf("\n Before sorting: \n");
	//display(number,count);
	
	//giving unsorted array as input
	clock_t begin1 = clock();
	merge_Sort(number, 0, count - 1);
	clock_t end1 = clock();

	//printf("\n After Sorting :\n ");
	//display(number,count);

	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving unsorted array(random elements as input) and sorted array as output is %lf seconds\n",time_spent1);
	

   	
   	//printf("\n\n Before sorting: \n");
   	//display(number,count);

   	//giving sorted array as input
   	clock_t begin2 = clock();
	merge_Sort(number, 0, count - 1);
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
	merge_Sort(number, 0, count - 1);
	clock_t end3 = clock();
	double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
	printf("\n\n\n time spent on giving almost sorted array as input and sorted array as output is %lf seconds\n",time_spent3);
	
	//printf("\n After Sorting :\n ");
	//display(number,count);
   	
	return 0;
}
