#include <stdio.h>
main() {

	float num1, num2, num3;
	float sum, product;	

	printf("Enter three floating-point numbers:\n");
	scanf("%f  %f %f", &num1, &num2, &num3);

	sum = num1 + num2 + num3;
	product = num1 * num2 * num3;

	printf("Sum is %.4f\n", sum);
	printf("Product is %.4f\n", product);
}


