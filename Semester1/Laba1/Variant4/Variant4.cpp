#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 0.4 * pow(10, 4), y = -0.875, z = -0.475 * pow(10, -3), pi = atan(1) * 4;
	cout << pow(abs(cos(x) - cos(y)), 1 + 2 * pow(sin(y), 2)) * (1 + z + pow(z, 2) / 2 + pow(z, 3) / 3 + pow(z, 4) / 4);
}