#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 14.26, y = -1.22, z = 3.5 * pow(10, -2), pi = atan(1) * 4;
	cout << 2 * cos(x - pi / 6) * (1 + pow(z, 2) / (3 - pow(z, 2) / 5)) / (0.5 + pow(sin(y), 2));
}