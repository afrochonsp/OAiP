#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 3.981 * pow(10, -2), y = -1.625 * pow(10, 3), z = 0.512, pi = atan(1) * 4;
	cout << pow(2, -x) * sqrt(x + pow(abs(y), 1.0 / 4.0)) * pow(exp(x - 1 / sin(z)), 1.0 / 3.0);
}