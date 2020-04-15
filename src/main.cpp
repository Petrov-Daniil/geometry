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
    float perim = 0, ar = 0;
    cout << "Введите фигуру: " << endl;
    char name[100];
    cin.getline(name, 100);
    if (pars(name, a) == 1) {
        perim = perimeter(a[0], a[1], a[2]);
        if (perim != 0) {
            ar = circleToarea(a[0], a[1], a[2]);
            cout << name << endl;
            cout << "\tperimetr = " << perim << endl;
            cout << "\tarea = " << ar << endl;
        } else
            cout << "It's not correctly" << endl;
    } else
        cout << "It's not correctly" << endl;
}
