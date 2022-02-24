/* C program by Kevin Huy Trinh CS1311 Feb 2022

||=============================================================================||
||                                                                             ||
||  #    # ####### #     # ### #     #    ####### ######  ### #     # #     #  ||
||  #   #  #       #     #  #  ##    #       #    #     #  #  ##    # #     #  ||
||  #  #   #       #     #  #  # #   #       #    #     #  #  ##    # #     #  ||
||  ###    #####   #     #  #  #  #  #       #    ######   #  #  #  # #######  ||
||  #  #   #        #   #   #  #   # #       #    #   #    #  #   # # #     #  ||
||  #   #  #         # #    #  #    ##       #    #    #   #  #    ## #     #  ||
||  #    # #######    #    ### #     #       #    #     # ### #     # #     #  ||
||                                                                             ||                            
||=============================================================================||

* Author: Kevin Huy Trinh
* Class: CS1311 12:35pm
* Language: C
* Project Name: Collection Database Program #3

* Purpose: This program collects data about a users keyboard
* collection and stores the information in a linked list
* structure. After collecting all the data, it will output the
* items formatted and the total price, etc. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* records information of keyboards */
struct keyboards {

     char name[50];	
     char color[50];
     double price;
     struct games *next;
              
};
struct keyboards *start, *current, *last; 		/* pointers */
double totalPrice = 0, totalItems = 0; 			/* misc statistics */


/* puts information into list */
void add_keyboard (char keyboardName[]) {

	 char color[50];
	 double price;
	 
	 /* gets other information about keyboard */
	 printf("Enter color of key switches: ");
	 gets(color);
	 printf("Enter the price of keyboard: ");
	 scanf("%lf", &price);
	 getchar();
	 
	 /* copies info to list */
	 current = malloc(sizeof(struct keyboards));
	 strcpy(current -> name, keyboardName);
	 strcpy(current -> color, color);
	 current -> price = price;
	 current -> next = NULL;
	 if(start == NULL) {		/* first part of list */
         start = current;
	 }
	 else {						/* connects the lists */
         last -> next = current;
	 }
	 last = current;

}



void print_list(void) {

	 current = start;					/* start at the front of list */
	 
	 while(current != NULL) {			/* while not at end of list */
	 
        totalItems = totalItems + 1;	/* increment total items & price */
        totalPrice = totalPrice + current -> price;
        printf("Name: %-20s Color: %-20s Price: $%f\n", current -> name, current -> color, current -> price);
        current = current -> next;		/* move to next part */
	 
	 }
	 
	 printf("\nTotal keyboards in collection: %lf.\n", totalItems);
	 printf("Total worth of collection: $%lf.\n", totalPrice);
}



void main(void) {

	 char input[50];	/* input var that holds name or done */
	 
	 printf("This program gets information about a keyboard collection, then outputs the information and the total value of all the items. \n\n");
     start = NULL;		/* start at null */
     
     printf("Enter the name of your keyboard (Type \"Done\" to end program): ");
     gets(input);
     
     do {										/* runs while we dont have "done" */
	 
	 	add_keyboard(input);					/* adds keyboard to linked list */
	 	printf("Enter the name of your keyboard (Type \"Done\" to end program): ");
	 	gets(input);
	 
	 } while (strcasecmp(input, "Done") != 0);	/* checks for any variation of "Done" */
	 
	 
	 printf("\n");		/* just spacing */
	 print_list();		/* prints out list and misc info */

}
