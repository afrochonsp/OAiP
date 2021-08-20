#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = -2.235 * pow(10, -2), y = 2.23, z = 15.221, pi = atan(1) * 4;
	cout << exp(abs(x - y)) * pow(abs(x - y), x + y) / (atan(x) + atan(z)) + pow(pow(x, 6) + pow(log(y), 2), 1.0 / 3.0);
}