
#include <stdio.h>
main() {
	int input;
	int i;

	printf("Please enter a number from 1 to 5: ");
	scanf("%d", &input);

	if ((input > 5) || (input < 1)) {
		printf("Number is not in the range from 1 to 5\n");
	} 
	else {
		for (i = 0; i < input; i++) {
			printf("Hello World\n");
		}
	}
}
