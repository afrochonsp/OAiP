#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = -4.5, y = 0.75 * pow(10, -4), z = 0.845 * pow(10, 2), pi = atan(1) * 4;
	cout << pow((8 + pow(abs(x - y), 2) + 1), 1.0 / 3.0) / (pow(x, 2) + pow(y, 2) + 2) - exp(abs(x - y)) * pow((pow(tan(z), 2) + 1), x);
}