#include <stdio.h> 
#include <stdlib.h>  
#include <locale.h>

//Basic structure of a doubly linked list node
typedef struct node {
    int value;
    struct node *next;
    struct node *previous;
} Node;

//Function to insert at the beginning of the list
void insert_at_beginning(Node **list, int num) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node) {
        new_node->value = num;
        new_node->next = *list;
        new_node->previous = NULL;
        
        if (*list) {
            (*list)->previous = new_node;
        }
        
        *list = new_node;
    } else {
        printf("Memory allocation error!\n");
    }
}

//Function to insert at the end of the list
void insert_at_end(Node **list, int num) {
    Node *aux, *new_node = (Node *)malloc(sizeof(Node));

    if (new_node) {
        new_node->value = num;
        new_node->next = NULL;

        if (*list == NULL) {
            *list = new_node;
            new_node->previous = NULL;
        } else {
            aux = *list;
            while (aux->next) {
                aux = aux->next;
            }
            aux->next = new_node;
            new_node->previous = aux;
        }
    } else {
        printf("Memory allocation error!\n");
    }
}

//Function to print the elements of the list
void print_list(Node *node) {
    printf("\n"); 
    while (node) {
        printf("%d\n", node->value); 
        node = node->next;
    }
    printf("\n");
}

//Function to remove element from the beginning of the list
void remove_from_beginning(Node **list) {
    Node *removed_node = *list;
    *list = removed_node->next;

    if (removed_node->next != NULL) {
        removed_node->next->previous = NULL;
        free(removed_node);
    }
}

//Function to remove element from the end of the list
void remove_from_end(Node **list) {
    Node *removed_node = *list;

    while (removed_node->next != NULL) {
        removed_node = removed_node->next;
    }

    if (removed_node->previous == NULL) {
        *list = removed_node->next;
    } else {
        removed_node->previous->next = NULL;
    }
    
    free(removed_node);
}

//Main function
int main() {
    setlocale(LC_ALL, "Portuguese");
    int option, value;
    Node *removed, *list = NULL;

    do {
        system("cls");
        printf("DOUBLY LINKED LIST\n");
        printf("1 - INSERT AT BEGINNING\n");
        printf("2 - INSERT AT END\n");
        printf("3 - PRINT LIST\n");
        printf("4 - REMOVE FROM BEGINNING\n");
        printf("5 - REMOVE FROM END\n");
        printf("0 - EXIT\n");
        printf("YOUR CHOICE: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                insert_at_beginning(&list, value);
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", &value);
                insert_at_end(&list, value);
                break;
            case 3:
                if (list == NULL) {
                    printf("\nEMPTY LIST\n");
                    system("pause");
                } else {
                    print_list(list);
                    system("pause");
                }
                break;
            case 4:
                if (list == NULL) {
                    printf("\nEMPTY LIST\n");
                    system("pause");
                } else {
                    remove_from_beginning(&list);
                    system("pause");
                }
                break;
            case 5:
                if (list == NULL) {
                    printf("\nEMPTY LIST\n");
                    system("pause");
                } else {
                    remove_from_end(&list);
                    system("pause");
                }
                break;
            default:
                if (option != 0) {
                    printf("Invalid option!\n");
                }
        }

    } while (option != 0);

    return 0;
}
