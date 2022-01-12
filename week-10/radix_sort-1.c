// Radix Sort in C Programming

#include<stdio.h>
#include<stdlib.h>

int find_max(int array[], int n)  // function to find maximum value in given array
{
	int i;
	int max = array[0];
	for (i = 1; i < n; i++)
    	if (array[i] > max)
      		max = array[i];
	return max;
}


void Counting_sort(int array[], int size, int place) 
{
	int bucket[size + 1];
	int max = (array[0] / place) % 10;
	int count[max + 1];
	int i;
	for (i = 1; i < size; i++) 
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	for (i = 0; i < max; ++i)
		count[i] = 0;

  // Calculate count of elements
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

  // Place the elements in sorted order
	for (i = size - 1; i >= 0; i--) 
	{
		bucket[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = bucket[i];
}

//function to implement radix sort
void radixsort(int array[], int size) 
{
	int max = find_max(array, size);	//get maximum element
	int place;
	for (place = 1; max / place > 0; place *= 10) 	//iterate counting sort based on place value
		Counting_sort(array, size, place);
}


void display_array(int array[], int n) 
{
	int i;
	for (i = 0; i < n; ++i) 
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

// Driver code
int main() 
{  
	int n,arr[100]={},i;
	printf("\n Enter n value (number of elements): ");
	scanf("%d",&n);
	printf("\n Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	radixsort(arr, n);
	display_array(arr, n);
}
