#include <stdio.h>
main() {

	int num;

	while (1 == 1) {

		printf("Number [1-100]: ?\n");
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		int i;
		int divisor = 0;
		for (i = 2; i < num; i++) {  
			if (num % i == 0) {
				divisor = i; 
		     		printf("Non-prime, divisible by %d\n", divisor); 
				break;
			}
		}
		if (divisor == 0) {
			printf("Prime\n");
		}
	}
	printf("Done\n");
}
