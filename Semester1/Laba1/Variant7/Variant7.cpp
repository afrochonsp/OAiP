#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 0.1722, y = 6.33, z = 3.25 * pow(10, -4), pi = atan(1) * 4;
	cout << 5 * atan(x) - 1.0 / 4.0 * acos(x) * (x + 3 * abs(x - y) + pow(x, 2)) / (abs(x - y) * z + pow(x, 2));
}