#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE] = {7, 6, 45, 84, 87, 94, 95, 96, 97, 32, 14, 56, 89, 21, 8, 39, 1, 74, 35, 63, 18, 49, 27, 64, 92, 83, 41, 2, 88, 59, 50, 91, 68, 44, 66, 12, 72, 23, 57, 25, 99, 28, 47, 70, 78, 51, 16, 71, 85, 11, 60, 4, 22, 34, 5, 24, 73, 15, 36, 65, 40, 20, 26, 29, 53, 55, 30, 58, 31, 77, 80, 17, 3, 48, 76, 69, 79, 61, 33, 75, 52, 10, 37, 46, 93, 67, 62, 43, 86, 82, 38, 54, 42, 36, 90, 81, 98, 9, 13, 65};

void merge(int *A, int p, int q, int r)
{
  int nL = q - p + 1;
  int nR = r - q; 
  int *L = (int*)malloc(nL * sizeof(int));
  int *R = (int*)malloc(nR * sizeof(int));

  for(int i = 0; i < nL; i++)
    L[i] = A[p + i];

  for(int j = 0; j < nR; j++)
    R[j] = A[q + j + 1];

  int i = 0, j = 0, k = p;

  while(i < nL && j < nR)
  {
    if(L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < nL)
  {
    A[k] = L[i];
    i++;
    k++;
  }

  while(j < nR)
  {
    A[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

void merge_sort(int *A, int p, int r)
{
  if(p >= r)
    return;

  int q = (p + r) / 2;
  
  merge_sort(A, p, q);
  merge_sort(A, q + 1, r);

  merge(A, p, q, r); 
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
  
  int min = 0;
  int max = SIZE - 1;

  merge_sort(unsorted_array, min, max);

  for(int m = 0; m < SIZE; ++m)
    printf(" %d", unsorted_array[m]);

  free(unsorted_array);

  return 0;
}
