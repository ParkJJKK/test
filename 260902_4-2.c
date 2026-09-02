#include <stdio.h> 

int main (void)
{
  double apple;
  int banana;
  int orange;

  apple = 5.1/1.6;
  banana = 7/2;
  orange = 9%2;

  printf("apple : %.1lf\n", apple);
  printf("banana : %d\n", banana);
  printf("orange : %d\n", orange);

  return 0;
}