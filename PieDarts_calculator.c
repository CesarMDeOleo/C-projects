#include <stdio.h>


#include <stdlib.h>

#include <time.h>
#include <math.h>




double rand_double_x() {
    return ((double)rand()) / ((double) RAND_MAX);
}


double rand_double_y() {
    return ((double)rand()) / ((double)RAND_MAX);
}



int main(int argc, char* argv[])
{
    double distance;
    double cx = 0;
    double cy = 0;
    double diameter = 1;

    double circle_radius = 0.5;

    const double pi = 3.1416;

    double area_square = 1;
    double area_circle = pi * (circle_radius * circle_radius);
    double area = (area_circle/area_square) * 4;




    srand(time(NULL));

    double length= 1000000;

    double number_in_circle =0;
    double number_in_square = 0;

    for (int i = 0; i < length; i++) {

        distance = sqrt( pow( (rand_double_x() - cx), 2 ) + pow( (rand_double_y() - cy), 2 ) );

        if(distance < diameter)
        {

            number_in_circle = number_in_circle + 1;
        }
        else if(distance > diameter)
        {

            number_in_square = number_in_square + 1;
        }
        else
        {

            number_in_circle = number_in_circle + 1;
        }
    }

    number_in_square= number_in_circle + number_in_square;
    printf ("Number in circle: ");
    printf ("%.1f\n", number_in_circle);
    printf ("Number in square: ");
    printf ("%.1f\n", number_in_square);


    double inside_dart = (number_in_circle)/number_in_square;

    double the_pie = (inside_dart*4);
    printf ("\n%0.4f\n", the_pie);
    printf("%0.4f\n" , area);


    return 0;
}