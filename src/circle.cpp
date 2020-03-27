#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>

using namespace std;

float const P = 3.1415;

void circleToarea(float x, float y, float r)
{
    float area = P * pow(r, 2);
    cout << "\tarea = " << area << endl;
}