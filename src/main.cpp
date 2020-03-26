#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include "pars.hpp"
#include "circle.hpp"


using namespace std;

int main() {
    float a[3];
    cout << "Введите фигуру: " << endl;
    char name[100];
    cin.getline(name, 100);
    pars(name, a);
    circle(a[0], a[1], a[2], name);
}
