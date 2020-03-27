#include "circle.hpp"
#include "perimeter.hpp"
#include "pars.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>

using namespace std;

int main()
{
    float a[3];
    cout << "Введите фигуру: " << endl;
    char name[100];
    cin.getline(name, 100);
    pars(name, a);
    perimeter(a[0], a[1], a[2]);
    circleToarea(a[0], a[1], a[2]);
}
