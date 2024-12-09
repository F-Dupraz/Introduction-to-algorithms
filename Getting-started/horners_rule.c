#include <stdio.h>
#include <stdlib.h>

float horners_rule(int *A, int n, int x)
{
  float p = 0;
  for(int i = n; i >= 0; --i)
    p = A[i] + x * p;

  return p;
}

int main(void)
{
  int polynomial[4] = {4, 3, 2, 1};
  float value = horners_rule(polynomial, 4, 0);

  printf(" %f", value);

  return 0;
}
