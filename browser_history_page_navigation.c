#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char url[20];
    struct node * next, * prev;
};

struct node * head = NULL, * currentPage = NULL;
struct node home;

struct node * create_node(char * url){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->url,url);
    newNode->next = NULL;
    newNode->prev = currentPage;
    return newNode;
}

void create_home_page(){
    strcpy(home.url,"Home Page");
    home.prev = NULL;
    home.next = NULL;
    head = &home;
    currentPage = &home;
}

void new_page(char * url){
    struct node * newNode = create_node(url);
    if(home.next == NULL){
        home.next = newNode;
        currentPage = newNode;
    }
    else{
        if(currentPage->next == NULL){
            currentPage->next = newNode;
            currentPage = currentPage->next;
        }
        else{
            struct node * temp = currentPage->next, *temp2;
            currentPage->next = newNode;
            currentPage = currentPage->next;

            while(temp->next != NULL){
                temp2 =temp->next;
                free(temp);
                temp = temp2;
            }
            free(temp);
        }
    }
    printf("%s\n",currentPage->url);
}

void backward () {
    if (currentPage == NULL || currentPage->prev == NULL){
        printf("No previous page!\n");
    }
    else{            
        currentPage = currentPage->prev;
        printf("%s\n",currentPage->url);
    }
}

void forward() {
    if (currentPage == NULL || currentPage->next == NULL){
        printf("No next page!\n");
    }
    else{
        currentPage = currentPage->next;
        printf("%s\n",currentPage->url);
    }
}

int main() {
    int option;
    char url[20];
    create_home_page();

    printf("Select:\n1-add url\n2-backward\n3-forward\n4-exit\n");
    while(1){
        printf("select : ");
        scanf("%d",&option);
    switch(option){
        case 1 : printf("Enter the url : ");
            scanf("%s",url);
            new_page(url);
            break;
        case 2 : backward();
            break;
        case 3 : forward();
            break;
        case 4 : exit(0);
        default : printf("Inavlid input choice! Try again!\n\n");
    }}
    return 0;
}