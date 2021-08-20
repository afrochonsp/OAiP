#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 16.55 * pow(10, -3), y = -2.75, z = 0.15, pi = atan(1) * 4;
	cout << sqrt(10 * (pow(x, 1.0 / 3.0) + pow(x, y + 2))) * (pow(asin(z), 2) - abs(x - y));
}