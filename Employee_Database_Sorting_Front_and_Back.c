#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX 100

typedef struct Node {
    char name[MAX];
    char email[MAX];
    int ssn;
    struct Node * next;
    struct Node * back;
} node;

int compare_node(struct Node * n1, struct Node * n2);
struct Node * add_node(struct Node * list, struct Node * node);
void print_list_front(struct Node * head);


int compare_back_node(struct Node * n1, struct Node * n2);
struct Node * add_opp_node(struct Node * list, struct Node * node);
void print_list_back(struct Node * opp);



int main() {

    node * head, * newNode;
    head = NULL;

    node * opp;
    opp = NULL;

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
        newNode -> back = NULL;

        head = add_node(head, newNode);

        opp = add_opp_node(opp, newNode);

    }

    printf("\nThe following employees are sorted from A to Z on the database: \n");

    print_list_front(head);

    printf("\nEnd of A to Z sorting.\n");

    printf("\nThe following employees are sorted from Z to A on the database: \n");

    print_list_back(opp);

    printf("\nEnd of Z to A sorting of the database.\n");

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



void print_list_front(struct Node * head) {
    while (head != NULL) {
        printf("\nName: %s \n", head -> name);
        printf("Email: %s \n", head -> email);
        printf("SSN: %d \n", head -> ssn);
        head = head -> next;
    }
}


struct Node * add_opp_node(struct Node * list, struct Node * node) {

    struct Node * prev, * next;
    if (!list) {
        list = node;
    } else {
        prev = NULL;
        next = list;
        while (next && compare_back_node(node, next) < 0) {
            prev = next;
            next = next -> back;
        }
        if (!next) {
            prev -> back = node;
        } else {
            if (prev) {
                node -> back = prev -> back;
                prev -> back = node;
            } else {
                node -> back = list;
                list = node;
            }
        }
    }

    return list;

}


int compare_back_node(struct Node * n1, struct Node * n2) {

    return strcmp(n1 -> name, n2 -> name);

}


void print_list_back(struct Node * opp) {

    while (opp != NULL) {
        printf("\nName: %s \n", opp -> name);
        printf("Email: %s \n", opp -> email);
        printf("SSN: %d \n", opp -> ssn);
        opp = opp -> back;
    }

}
