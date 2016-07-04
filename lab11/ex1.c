#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

void bubble_sort_generic(char* array[1000], int counter, int num, int (*f)(char*, char*));
int compare_fn(char x[1000], char y[1000]);

main() {

	int i;
	int counter = 0;
	int keepGoing = 1;
	float fvalue;
	char* array[1000];
  	char input[1000];


	for (i = 0; i < 1000; i++) {
	    	fgets(input, 1000-2, stdin);
		fvalue = atof(input);
		if (fvalue == 0) {
			break;
		}
		else {
			counter++;
			size_t ln = strlen(input) - 1;
			if (input[ln] == '\n') {
    				input[ln] = '\0';
			}
			int length = strlen(input);
    			array[i] = malloc(length+1);
   			strcpy(array[i], input);
		}
  	} 
	
	printf("The original values are:\n");
	
	for (i = 0; i < counter; i++) {
		printf("%s  ", array[i]);
  	}

	printf("\n");

	bubble_sort_generic(array, counter, 1, compare_fn);

	printf("The sorted values are:\n");

	for (i = 0; i < counter; i++) {
		printf("%s  ", array[i]);
	}

	printf("\n");

	bubble_sort_generic(array, counter, 0, compare_fn);
	
	printf("The sorted values are:\n");		

	for (i = 0; i < counter; i++) {
		if (i == (counter - 1))  {
			printf("%s ", array[i]);
			break;
		}
		printf("%s  ", array[i]);
	}

	printf("\n");
}


void  bubble_sort_generic(char* array[1000], int counter, int num, int (*f)(char*, char*)) {
	int i, j;
	char* tmp;
	for (i = 0; i < counter; i++) {
		for (j = 0; j < counter - 1; j++) {
			if (num == 1) {
				if ((*f)(array[j], array[j+1]) == 1) {
					tmp = array[j+1];
					array[j+1] = array[j];
					array[j] = tmp;
				}
			}
			
			if (num == 0) {
				if ((*f)(array[j], array[j+1]) == 0) {
					tmp = array[j+1];
					array[j+1] = array[j];
					array[j] = tmp;
				}
			}
		}
	}
}

int compare_fn(char x[1000], char y[1000]) {
	float value1 = atof(x);
	float value2 = atof(y);
	if (value1 >= value2) {
		return 1;
	}
	else if (value1 < value2) {
		return 0;
	}
}