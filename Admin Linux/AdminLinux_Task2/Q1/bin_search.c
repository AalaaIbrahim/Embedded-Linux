#include <stdio.h>
#include <stdlib.h>

int binary_search(int* arr, int arr_size, int value);

int main()
{
//	clrscr();

	int arr[]= {3,5,7,15,20};
	int index, i;

	printf("Searching for numbers from 1 to 5...\n\n");

	for(i=1; i<6; i++)
	{
		index = binary_search(arr, 5, i);
 
		if(index != -1)
		{	
			printf("%d is the element at index %d in the array.\n", i, index);
		}
		else printf("The value '%d' is not in the array!\n", i);
	}

	getchar();
	//clrscr();
	return 0;
}


int binary_search(int* arr, int arr_size, int value)
{
	int mid=arr_size/2, start=0, end=arr_size-1;
	
	while(start<=end)
	{
		if(arr[mid] == value) return mid;
		else if(value < arr[mid])
		{
			end=mid-1;
			mid=(start+end)/2;
		}
		else
		{
			start = mid+1;
			mid = (start+end)/2;
		}
	}

	return -1;
}




