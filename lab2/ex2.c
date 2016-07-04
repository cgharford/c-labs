/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

main()
{
  float r, a;

  do {  
  printf("Enter the circle's radius (in centimeters): ");
  scanf("%f", &r);
  r /= 2.54;
  a = PI * r * r;

  printf("Its area is %3.2f square inches.\n", a);

  } while (r != 0.0);
  return;
}