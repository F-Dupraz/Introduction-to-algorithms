#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE] = {7, 6, 45, 84, 87, 94, 95, 96, 97, 32, 14, 56, 89, 21, 8, 39, 1, 74, 35, 63, 18, 49, 27, 64, 92, 83, 41, 2, 88, 59, 50, 91, 68, 44, 66, 12, 72, 23, 57, 25, 99, 28, 47, 70, 78, 51, 16, 71, 85, 11, 60, 4, 22, 34, 5, 24, 73, 15, 36, 65, 40, 20, 26, 29, 53, 55, 30, 58, 31, 77, 80, 17, 3, 48, 76, 69, 79, 61, 33, 75, 52, 10, 37, 46, 93, 67, 62, 43, 86, 82, 38, 54, 42, 36, 90, 81, 98, 9, 13, 65};

void insertion_sort(int* A, int n)
{
	for(int i = 1; i < n; ++i)
	{
		int key = A[i];
		int j = i - 1;
		while(j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = key;
	}
}

int main(void)
{
	int *unsorted_array = (int*)malloc(SIZE * sizeof(int));
	if(unsorted_array == NULL)
	{
		printf("Error with the memory allocator!\n");
		return 1;
	}

	for(int k = 0; k < SIZE; ++k)
		unsorted_array[k] = arr[k];

	insertion_sort(unsorted_array, SIZE);

	for(int k = 0; k < SIZE; ++k)
		printf(" %d", unsorted_array[k]);

	free(unsorted_array);

	return 0;
}

