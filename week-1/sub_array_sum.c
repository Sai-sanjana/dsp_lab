#include <stdio.h>
#include<stdlib.h>

int temp;
int min_subarray(int Arr[], int n, int x)
{
	// Initialize length of smallest subarray as n+1
	int min_len = n + 1,j;
	int i;
	for ( i=0; i<n; i++)
    {
		int curr_sum = Arr[i];
		if (curr_sum > x) return 1;
		j = i+1;
		 while(j<n)
		 {
			curr_sum += Arr[j];
			if (curr_sum > x && (j - i + 1) < min_len){
				min_len = (j - i + 1);
				temp = i;
			}
			j++;
		}
	}
	return min_len;
}


int main()
{
	int Arr1[] = {1,4,45,6,0,19};
	int Arr_temp[10],i,j,sum;
	int n = sizeof(Arr1)/sizeof(Arr1[0]);
    printf("\n Given array is \n");
	for( i=0;i<n;i++){
	    printf(" %d ",Arr1[i]);
	}

	printf("\n Enter the value \n ");
	scanf("%d",&sum);



	int value = min_subarray(Arr1, n,sum);
	if(value == n+1)
	{
	    printf("\n No sub array exist \n");
	}
	else
	{
		printf("\n\n minimal subarray length is %d\n",value);
	}

    printf("\n minimal sub array is \n");
    for( i=temp;i<temp+value;i++){
        printf(" %d ",Arr1[i]);
    }

    printf("\n minimal sub array after adding length of array is \n");
    for( i =temp,j=0;i<temp+value;i++,j++){
        Arr_temp[j] =Arr1[i]+ value;
        printf(" %d ",Arr_temp[j]);
    }

	return 0;
}
