#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 17.421, y = 10.365 * pow(10, -3), z = 0.828 * pow(10, 5), pi = atan(1) * 4;
	cout << pow(y + pow(x - 1, 1.0 / 3.0), 1.0 / 4.0) / abs(x - y) / (pow(sin(z), 2) + tan(z));
}