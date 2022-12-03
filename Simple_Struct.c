#include <stdio.h>

#define MAX 50


struct Person {
    char name[MAX];
    int citNo;
    float salary;
} person1;


int main() {

    printf("\nWhat is your name?\n");
    fgets(person1.name, MAX, stdin);

    printf("\nWhat is your Citizenship No.?\n");
    scanf("%d", & person1.citNo);

    printf("\nWhat is your current yearly salary?\n");
    scanf("%f", & person1.salary);

    printf("\nName: %s", person1.name);
    printf("Citizenship No.: %d\n", person1.citNo);
    printf("Salary: $%.2f\n", person1.salary);

    return 0;
}