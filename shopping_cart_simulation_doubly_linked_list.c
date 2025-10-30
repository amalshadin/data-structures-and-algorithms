#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char item [10];
    struct node * next, * prev;
};

struct node * head = NULL;

struct node * createNode(char * item){
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    strcpy(newNode->item,item);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(char * item){
    struct node * newNode = createNode(item);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void removeItem(char * item){
    if (head == NULL){
        printf("Empty List!\n");
        return;
    }

    if(head->next == NULL){
        if(strcmp(head->item,item) == 0){
            free(head);
            head = NULL;
        }
        else{
            printf("Item doesn't exist in cart\n");
        }
        return;
    }

    struct node * current = head;
    while(current != NULL && strcmp(current->item,item) != 0){
        current = current->next;
    }
    if(current == NULL){
        printf("Item doesn't exist in cart\n");
        return;
    }

    if(current->next == NULL){
        (current->prev)->next = NULL;
        free(current);
        printf("Successfully removed the item.\n");
        return;
    }
    (current->prev)->next = current->next;
    (current->next)->prev = current->prev;

    free(current);
    printf("Successfully removed the item.\n\n");
}

void displayForward(){
    if(head == NULL){
        printf("Empty List!\n\n");
        return;
    }
    struct node * current = head;

    while(current->next != NULL){
        printf("%s\n",current->item);
        current = current->next;
    }
    printf("%s\n\n",current->item);
}

void displayReverse(){
    if(head == NULL){
        printf("Empty List!\n\n");
        return;
    }
    struct node * current = head;
    while(current->next != NULL){
        current = current->next;
    }
    while(current->prev != NULL){
        printf("%s\n",current->item);
        current = current->prev;
    }
    printf("%s\n\n",current->item);
}

int main(){

    int option;
    char item[20];

    while(1){
        printf("1 - Add Item\n2 - Remove Item\n3 - Display Cart Forward\n4 - Display Cart Reverse\n5 - Exit Menu\n\n");
        scanf("%d",&option);

        switch(option){
            case 1 : printf("Enter the Item : ");
                scanf("%s",item);
                insertAtBeginning(item);
                break;
            case 2 : printf("Enter the Item you want to remove : ");
                scanf("%s",item);
                removeItem(item);
                break;
            case 3 : printf("Cart in forward : \n\n");
                displayForward();
                break;
            case 4 : printf("Cart in reverse: \n\n");
                displayReverse();
                break;
            case 5 : exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}
