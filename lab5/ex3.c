/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for string functions */
#include <stdlib.h> /* Need for pointer stuff */

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

main()
{
  char* Strings[NUM];
  char* tempSwap;
  char temp[LEN];
  int i, j, k, m;
  int swapped, compared; 

  printf("Please enter %d strings, one per line:\n", NUM);

  /* Write a for loop here to read NUM strings, using fgets(). */

  for (i = 0; i < NUM; i++) {

    /* Read one line of input into a temp string that is long enough (LEN long) */

    fgets(temp, LEN-2, stdin);

    /* Allocate memory space for String[i] that is only large enough to copy the
       string just read into it.  Suppose the length of the string read into
       temp is "length", then you can use the following: */
    int length = strlen(temp);
    Strings[i] = malloc(length+1); /* Plus one for the NULL at end */
    strcpy(Strings[i], temp);
  }

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */

  for (i = 0; i < NUM; i++) {
	printf("%s", Strings[i]);
  }
  
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by strcmp() or strncmp().

       (ii) The swap of two strings must be done by swapping pointer values.
            You must not swap two string using strcpy()/strncpy() or using your 
            own loop to swap them a character at a time.
  */
     for (i = 0; i < NUM; i++) {
	swapped = 0; 
	for (j = 0; j < NUM - i - 1; j++) { 
		int NumOfChars = strlen(Strings[j]);
		for (k = 0; k < NumOfChars; k++) {
			compared  =  strcmp(Strings[j], Strings[j + 1]);
			if (compared > 0) {
				swapped = 1;
				for (m = 0; m < LEN; m++) {
					tempSwap =  Strings[j];
					Strings[j] = Strings[j+1];
					Strings[j+1] = tempSwap; 
					break;
				}
			}
		} 
	}  
	if (swapped == 0) {
		break;
	}
     } 
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     


  /* Write a for loop here to print all the strings. */

  for (i = 0; i < NUM; i++) {
	printf("%s", Strings[i]);
  }
  /* Write a loop here to use free() to free up space allocated 
     for all of the strings above.  */

  for (i = 0; i < NUM; i++) {
	free(Strings[i]);
  }

  return 0;
}
