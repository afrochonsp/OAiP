#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 1.825 * pow(10, 2), y = 18.225, z = -3.298 * pow(10, -2), pi = atan(1) * 4;
	cout << abs(pow(x, y / x) - pow(y / x, 1.0 / 3.0)) + (y - x) * (cos(y) - z / (y - x)) / (1 + pow(y - x, 2));
}