#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 3.251, y = 0.325, z = 0.466 * pow(10, -4), pi = atan(1) * 4;
	cout << pow(2, pow(y, x)) + pow(pow(3, x), y) - y * (atan(z) - pi / 6) / (abs(x) + 1 / (pow(y, 2) + 1));
}