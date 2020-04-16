#include "circle.h"
#include "pars.h"
#include "perimeter.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[3] = {0, 0, 0};
    char name[100];
    float perim = 0, ar = 0;
    printf("Введите фигуру:\n");
    fgets(name, 100, stdin);
    if (pars(name, a) == 1) {
        perim = perimeter(a[0], a[1], a[2]);
        if (perim != 0) {
            ar = circleToarea(a[0], a[1], a[2]);
            printf("%s", name);
            printf("\tperimetr = %f\n", perim);
            printf("\tarea = %f\n", ar);
        } else
            printf("It's not correctly\n");
    } else
        printf("It's not correctly\n");
}
