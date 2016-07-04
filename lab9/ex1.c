#include <stdio.h>

 unsigned int fibonacci(unsigned int n);

main() {

	int value;
	int keepGoing = 1;

	while (keepGoing == 1) {

		scanf("%d", &value);
		value = fibonacci(value);
		printf("%u\n", value);
		if (value == 0) {
			return;
		}
	} 	

}

unsigned int fibonacci(unsigned int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}


