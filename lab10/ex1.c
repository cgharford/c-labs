#include <stdio.h> 
#include <stdlib.h>  

 struct point { 
	int x;
	int y;
	struct point * next;
}
main() {
	int x;
	int y;
	int output = 0;					
	int counter = 0;				//loop counter
	struct point * currentPt, * firstPt;
	struct point * previousPt;
	
	do {
		counter++;
		//read in two points points from user
		scanf("%d %d",&x,&y);
		//if the point is (0,0), your last structure should point to null			
		if ((x == 0) && (y == 0)) {
			currentPt->next = NULL;
			break;
		}
		
		//allocate proper ammount of memory for the point	
		currentPt =  malloc(sizeof(struct point));

		if (counter == 1) {
			previousPt = malloc(sizeof(struct point));
		}
		
		//assign values to the fields within point
		currentPt->x = x;
		currentPt->y = y;
		previousPt->next = currentPt;
		previousPt = currentPt;

		if (counter == 1) {
			firstPt= currentPt;
		}

	} while ((x != 0) || (y != 0)); 

	while (firstPt) {
		//compute the distance squared, then print it out
		output =  firstPt->x * firstPt->x + firstPt->y * firstPt->y;
		printf("%d\n", output);
		firstPt = firstPt->next;
  	}
}