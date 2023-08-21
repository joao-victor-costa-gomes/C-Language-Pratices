#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese"); // Variables to assist in the program's operation 
    int option = 0, top = -1, i = 0; // The variable controls the stack, indicating when it's full or empty
    int element[5]; // Variable for the element to be inserted (a stack with a maximum of 5 elements)
                            
    while (option != 4) { 
        system("cls"); 
	    printf("WHAT DO YOU WANT TO DO?\n"); 
	    printf("1 - INSERT\n"); 
	    printf("2 - REMOVE\n"); // Shows the options
	    printf("3 - TRAVERSAL\n"); // Receives an integer value from the user representing the chosen option
	    printf("4 - EXIT\n");
	    printf("\nYOUR CHOICE: "); 
	    scanf("%d", &option); 
	
        switch (option) {
	        case 1:
                if (top == 4) {
                    printf("\nSTACK FULL\n\n"); // Displays this message when the stack is full (top == 4)
                    system("pause"); 	
                } else {
                    top++; // The top is always incremented by 1 for each inserted element
                    printf("Element to be inserted: "); 
                    scanf("%d", &element[top]); 
                }	
	            break; 

            case 2:		
                if (top == -1) {
                    printf("\nEMPTY STACK\n\n"); // Displays this message when the stack is empty (top == -1)
                    system("pause"); 	
                } else {
                    top--; // The top is always decremented by 1 for each removed element
                } // Resulting in the number of elements in the stack also being decremented by 1 
                break;

            case 3:	
                if (top == -1) {
                    printf("\nEMPTY STACK\n\n"); // Displays this message when the stack is empty (top == -1)
                    system("pause"); 	
                } else {
                    for (i = top; i >= 0; i--) {
                        printf("\n%d\n", element[i]); // Displays the elements in stack format 
                    }
                    printf("\n"); 
                    system("pause"); 
                }	
                break; 

	        case 4: 
	            printf("\nEND OF PROGRAM");       
	            getch(); 
	            break; 

            default: 
	            printf("\nINVALID OPTION\n"); 
	            getch(); 
	            break; 			 
        }	 
    }			
    return 0;
}
