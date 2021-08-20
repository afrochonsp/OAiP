#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 6.251, y = 0.827, z = 25.001, pi = atan(1) * 4;
	cout << pow(y, pow(abs(x), 1.0 / 3.0)) + pow(cos(y), 3) * abs(x - y) * (1 + pow(sin(z), 2) / sqrt(x + y)) / (exp(abs(x - y)) + x / 2);
}