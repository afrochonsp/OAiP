#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float x = 12.3 * pow(10, -1), y = 15.4, z = 0.252 * pow(10, 3), pi = atan(1) * 4;
	cout << pow(y, x + 1) / (pow(abs(y - 2), 1.0 / 3.0) + 3) + (x + y / 2) / 2 / abs(x + y) * pow(x + 1, -1 / sin(z));
}