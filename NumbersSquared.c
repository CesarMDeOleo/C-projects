#include<stdio.h>

#include<math.h>


int main() {

    double number;
    double second_number, second_result;
    double power = 2;
    double result;

    printf("Enter the number that will be squared: ");
    scanf("%lf", & number);

    printf("Enter the number that will be squared root: ");
    scanf("%lf", & second_number);

    result = pow(number, power);

    second_result = sqrt(second_number);

    printf("\nYour new squared number will be: %.2lf \n", result);
    printf("Your new number after the square root is: %.2lf \n", second_result);

    return 0;

}