#include <stdlib.h>


int main()
{
  
  int** M; 
  M = malloc (5 * sizeof (int *));
  for (int i = 0; i < 5; ++i)
    M[i] = malloc (4 * sizeof (int));


  M[0][0] = 10;
  M[2][3] = 100;
  M[4][1] = 20;

}