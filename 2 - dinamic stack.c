#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct dynamic {
    int element;
    struct dynamic *previous;
};

struct dynamic *insert(int new_element, struct dynamic *top) {
    struct dynamic *aux;
    aux = (struct dynamic *) malloc(sizeof(struct dynamic));
    aux->element = new_element;
    aux->previous = top;
    top = aux;
    return top;
}

struct dynamic *removeElement(struct dynamic *top) {
    struct dynamic *aux;
    aux = top;
    top = top->previous;
    free(aux);
    return top;
}

void traversal(struct dynamic *top) {
    while (top != NULL) {
        printf("\n%x - %d - %x\n", top, top->element, top->previous);
        top = top->previous;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int new_element, option = 0;
    struct dynamic *t = NULL;

    while (option != 4) {
        system("cls");
        printf("WHAT DO YOU WANT TO DO?\n");
        printf("1 - ADD ELEMENT\n");
        printf("2 - REMOVE ELEMENT\n");
        printf("3 - VIEW STACK ELEMENTS\n");
        printf("4 - EXIT THE PROGRAM\n");
        printf("YOUR CHOICE: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nWHAT NEW ELEMENT TO INSERT? ");
                scanf("%d", &new_element);
                t = insert(new_element, t);
                printf("\n"); 
                break;

            case 2:
                if (t == NULL) {
                    printf("\nEMPTY STACK\n");
                    system("pause");
                } else {
                    t = removeElement(t);
                }
                printf("\n"); 
                break;

            case 3:
                if (t == NULL) {
                    printf("\nEMPTY STACK\n");
                    system("pause");
                } else {
                    traversal(t);
                    system("pause");
                }
                printf("\n"); 
                break;

            case 4:
                printf("\nEND OF PROGRAM");
                printf("\n"); 
                break;

            default:
                printf("\nINVALID OPTION ENTERED");
                printf("\n"); 
                system("pause");
        }
    }
    return 0;
}
