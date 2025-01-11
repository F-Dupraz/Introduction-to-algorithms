#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE] = {100, 7, 6, 45, 84, 87, 94, 95, 96, 97, 32, 14, 56, 89, 21, 8, 39, 1, 74, 35, 63, 18, 49, 27, 64, 92, 83, 41, 2, 88, 59, 50, 91, 68, 44, 66, 12, 72, 23, 57, 25, 99, 28, 47, 70, 78, 51, 16, 71, 85, 11, 60, 4, 22, 34, 5, 24, 73, 15, 65, 40, 20, 26, 29, 53, 55, 30, 58, 31, 77, 80, 17, 3, 48, 76, 69, 79, 61, 33, 75, 52, 10, 37, 46, 93, 67, 62, 43, 86, 82, 38, 54, 42, 36, 90, 81, 98, 9, 13, 65};

void bubble_sort(int *A, int n)
{
  for(int i = 0; i < n; ++i)
  {
    for(int j = n-1; j > i; --j)
    {
      if(A[j] < A[j-1])
      {
        int pivot = A[j];
        A[j] = A[j-1];
        A[j-1] = pivot;
      }
    }
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

  for(int n = 0; n < SIZE; ++n)
		unsorted_array[n] = arr[n];
  
  bubble_sort(unsorted_array, SIZE);

  for(int m = 0; m < SIZE; ++m)
    printf(" %d", unsorted_array[m]);

  free(unsorted_array);

  return 0;
}
