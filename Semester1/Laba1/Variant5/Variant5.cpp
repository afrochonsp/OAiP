#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = -15.246, y = 4.642 * pow(10, -2), z = 20.001 * pow(10, 2), pi = atan(1) * 4;
	cout << log(pow(y, -sqrt(abs(x)))) * (x - y / 2) + pow(sin(atan(z)), 2);
}