#include <stdio.h>

void bedtimestory(char words[20][15], int current, int number) {
	int i;

	for (i = 0; i < current*2; i++) {	//print out two spaces for 
		printf(" ");			//each recursive call
	}


	if (current == number - 1) {		//last thing to print
		printf("... who fell asleep.\n");
		return;
	}

	
	if(current==0) {			//first line that will print
		printf("A %s couldn't sleep, so her mother told a story about a little %s,\n", words[current], words[current+1]);

	}
	else {	//will print throughout recursive call
		printf("who couldn't sleep, so the %s's mother told a story about a little %s,\n", words[current], words[current+1]);

	
}	
	
	bedtimestory(words, ++current, number);	//recursive call to get the next animal name
	
	
		
	for (i=(current-1)*2; i > 0; i--) {	//print spaces again
		printf(" ");
	}
	
	if ((current-1) == 0) {			//last thing to print
		printf("... and then the %s fell asleep.\n", words[current-1]);
	}
	else {					// prints at end of each rec call except for last time
		printf("... and then the little %s fell asleep;\n", words[current-1]);
	}

}	
	
main() {

	char names[20][15];	//max 20 strings, max 15 characters per string
	int i, number;

	for (number = 0; number < 20; number++) {
		fgets(names[number], 15, stdin);		//reads in strings from user
		
		for (i = 0; i < 15; i++) {				
			if (names[number][i] == '\n') {		// if end of string (terminated by new line, change NL to null so that we can control where the NL prints
				names[number][i] = '\0';
				break;
			}
		}
		if ((strcmp(names[number], "END")) == 0) {	//reached the end of the input
			break;
		}
	}
	
	bedtimestory(names, 0, number);				//call bedtimestory
}
