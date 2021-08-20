#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 2.444, y = 0.869 * pow(10, -2), z = -0.13 * pow(10, 3), pi = atan(1) * 4;
	cout << (pow(x, y + 1) + exp(y - 1)) / (1 + x * abs(y - tan(z))) * (1 + abs(y - x)) + pow(abs(y - x), 2) / 2 - pow(abs(y - x), 3) / 3;
}