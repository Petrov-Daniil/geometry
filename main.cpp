#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

double P = 3.1415;

void circle(double x, double y, double r) {
    float per = 2 * P * r;
    float area = P * pow(r, 2);
    cout << "circle(" << x << " " << y << ", " << r << ")" << endl <<
         " perimetr = " << per << endl << " area = " << area << endl;
}

struct circle {
    string name;
    string sc;
    double x;
    double y;
    double r;
} c;

int main() {
    cout << "Введите фигуру: " << endl; //example circle( 0 0, 1.5)
    cin>>c.name>>c.x>>c.y>>c.sc>>c.r;
    circle(c.x, c.y, c.r);
    return 0;
}
