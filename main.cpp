#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
float P = 3.141592653589793238466;

void circle(float x, float y, float r) {
    float per = 2 * P * r;
    float area = P * pow(r, 2);
    cout << "circle(" << x << " " << y << ", " << r << ")" << endl <<
         " perimetr = " << per << endl << " area = " << area << endl;
}

int main() {
    float x, y, r;
    cin >> x >> y >> r;
    circle(x, y, r);
    return 0;
}

