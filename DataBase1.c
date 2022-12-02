#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Node {
    char name[MAX];
    char email[MAX];
    int ssn;
    struct Node * next;
} node;

int compare_node(struct Node * n1, struct Node * n2);
struct Node * add_node(struct Node * list, struct Node * node);
void print_list(struct Node * head);

int main() {

    node * head, * newNode;
    head = NULL;
    char name[MAX];
    char email[MAX];
    int ssn;
    int i;
    int amount;

    printf("How many employees?\n");
    scanf("%d", &amount);


    for (i = 0; i < amount; i++) {

        printf("\nEnter the First name: ");
        scanf("%s", name);

        printf("Enter the email: ");
        scanf("%s", email);

        printf("Enter the SSN: ");
        scanf("%d", &ssn);

        newNode = (node * ) malloc(sizeof(node));
        strcpy(newNode -> name, name);
        strcpy(newNode -> email, email);
        newNode -> ssn = ssn;

        newNode -> next = NULL;

        head = add_node(head, newNode);

    }

    printf("The following employees are sorted on the database: ");

    print_list(head);

    return 0;
}


struct Node * add_node(struct Node * list, struct Node * node) {
    struct Node * prev, * next;
    if (!list) {
        list = node;
    } else {
        prev = NULL;
        next = list;
        while (next && compare_node(node, next) > 0) {
            prev = next;
            next = next -> next;
        }
        if (!next) {
            prev -> next = node;
        } else {
            if (prev) {
                node -> next = prev -> next;
                prev -> next = node;
            } else {
                node -> next = list;
                list = node;
            }
        }
    }
    return list;
}


int compare_node(struct Node * n1, struct Node * n2) {
    return strcmp(n1 -> name, n2 -> name);
}


void print_list(struct Node * head) {
    while (head != NULL) {
        printf("\nName: %s \n", head -> name);
        printf("Email: %s \n", head -> email);
        printf("SSN: %d \n", head -> ssn);
        head = head -> next;
    }
}
