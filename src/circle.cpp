#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>

using namespace std;

float const P = 3.1415;



void circle(float x, float y, float r, char name[]) 
{
    float per = 2 * P * r;
    float area = P * pow(r, 2);
    cout << name << endl;
    cout << " \tperimetr = " << per << endl;
    cout << "\tarea = " << area << endl;
}