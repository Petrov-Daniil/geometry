#include "circle.hpp"
#include "pars.hpp"
#include "perimeter.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>

using namespace std;

int main()
{
    float a[3] = {0, 0, 0};
    char name[100];
    float perim = 0, ar = 0;
    printf("Введите фигуру:\n");
    cin.getline(name, 100);
    if (pars(name, a) == 1) {
        perim = perimeter(a[0], a[1], a[2]);
        if (perim != 0) {
            ar = circleToarea(a[0], a[1], a[2]);
            printf("%s\n", name);
            printf("\tperimetr = %f\n", perim);
            printf("\tarea = %f\n", ar);
        } else
            printf("It's not correctly\n"); 
    } else
        printf("It's not correctly\n");
}
