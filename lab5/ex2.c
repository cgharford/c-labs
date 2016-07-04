/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

main()
{
  char Strings[NUM][LEN], temp[LEN];       /*String array and temp array for swapping */
  int i, j, k, m;			   /*for loop variables*/
  int swapped;				   /*works as boolean; keeps track of when bubble sort is done*/
  int compared;

  printf("Please enter %d strings, one per line:\n", NUM);

  /* Write a for loop here to read NUM strings.*/

	for (i = 0; i < NUM; i++) {
		fgets(Strings[i], LEN, stdin);
	}
	
   /*  Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */

	for (i = 0; i < NUM; i++) {
		printf("%s", Strings[i]);
	}
  
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order */

   for (i = 0; i < NUM; i++) {
	swapped = 0; 
	for (j = 0; j < NUM - i - 1; j++) { 
		int NumOfChars = strlen(Strings[j]);
		for (k = 0; k < NumOfChars; k++) {
			compared  =  strcmp(Strings[j], Strings[j + 1]);
			if (compared > 0) {
				swapped = 1;
				for (m = 0; m < LEN; m++) {
					strncpy(temp, Strings[j], LEN);
					strncpy(Strings[j], Strings[j + 1], LEN);
					strncpy(Strings[j + 1], temp, LEN);
					break;
				}
			}
		} 
	}  
	if (swapped == 0) {
		break;
	}
  } 


  /*   Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) The swap of two strings must be done by copying them 
            (using a temp variable of your choice) one character at a time,
            without using any C string library functions.
            That is, write your own while/for loop to do this.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     

	for (i = 0; i < NUM; i++) {
		printf("%s", Strings[i]);
	}
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

  return 0;
}

