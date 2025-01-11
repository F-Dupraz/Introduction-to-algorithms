#include <stdio.h>
#include <stdlib.h>

void strassens(int **A, int **B, int **C, int n)
{
  if(n % 2 != 0)
  {
    printf(" Matrix size is not a power of 2\n");
    return;
  }

  if(n == 2)
  {
    int P1 = A[0][0] * (B[0][1] - B[1][1]);
    int P2 = B[1][1] * (A[0][0] + A[0][1]);
    int P3 = B[0][0] * (A[1][0] + A[1][1]);
    int P4 = A[1][1] * (B[1][0] - B[0][0]);
    int P5 = A[0][0] * (B[0][0] + B[1][1]) + A[1][1] * (B[0][0] + B[1][1]);
    int P6 = A[0][1] * (B[1][0] + B[1][1]) - A[1][1] * (B[1][0] + B[1][1]);
    int P7 = A[0][0] * (B[0][0] + B[0][1]) - A[1][0] * (B[0][0] + B[0][1]);
  
    C[0][0] = P5 + P4 - P2 + P6;
    C[0][1] = P1 + P2;
    C[1][0] = P3 + P4;
    C[1][1] = P5 + P1 - P3 - P7;

    return;
  }
  else
  {
    // I know that the algorith doesnt end here, but I dont know how to implement it, so I will just print a message for now.
    printf(" n must be 2\n");
  }
}

int main()
{
  int n = 2;
  int **A = (int **)malloc(n * sizeof(int *));
  int **B = (int **)malloc(n * sizeof(int *));
  int **C = (int **)malloc(n * sizeof(int *));

  for(int i = 0; i < n; i++)
  {
    A[i] = (int *)malloc(n * sizeof(int));
    B[i] = (int *)malloc(n * sizeof(int));
    C[i] = (int *)malloc(n * sizeof(int));
  }

  A[0][0] = 1;
  A[0][1] = 3;
  A[1][0] = 7;
  A[1][1] = 5;

  B[0][0] = 6;
  B[0][1] = 8;
  B[1][0] = 4;
  B[1][1] = 2;

  strassens(A, B, C, n);

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf(" %d", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
