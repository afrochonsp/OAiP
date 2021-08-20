#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	float x, a, d, z, f, variant;
	cout << "Введите A\n";
	cin >> a;
	cout << "Введите D\n";
	cin >> d;
	cout << "Введите Z\n";
	cin >> z;
	cout << "Выберите функцию F(x):\n1 - 2x\n2 - x^2\n3 - x/3\n";
	cin >> variant;
	x = z > 0 ? -3 * z : pow(z, 2);
	f = variant == 1 ? 2 * x : variant == 2 ? pow(x, 2) : x / 3;
	cout << "Y = " << 2 * f * (a * sin(x) + d * exp(-(x+3)));
}
