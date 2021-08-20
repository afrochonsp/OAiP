#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 3.74 * pow(10, -2), y = -0.825, z = 0.16 * pow(10, 2), pi = atan(1) * 4;
	cout << (1 + pow(sin(x + y), 2)) / abs(x - 2 * y / (1 + pow(x, 2) * pow(y, 2))) * pow(x, abs(y)) + pow(cos(atan(1 / z)), 2);
}