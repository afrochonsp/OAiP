#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	float x, a, b, z, f, variant, pi = atan(1.0f) * 4;
	cout << "Введите A\n";
	cin >> a;
	cout << "Введите B\n";
	cin >> b;
	cout << "Введите Z\n";
	cin >> z;
	cout << "Выберите функцию F(x):\n1 - 2x\n2 - x^2\n3 - x/3\n";
	cin >> variant;
	x = z < 1 ? z : pow(z, 3.0f / 2.0f);
	f = variant == 1 ? 2 * x : variant == 2 ? pow(x, 2) : x / 3;
	cout << "Y = " << -pi * f + a * pow(cos(pow(x, 3)), 2) + b * pow(sin(pow(x, 2)), 3);
}
