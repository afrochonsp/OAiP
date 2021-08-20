#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	float x, a, b, z, f, variant;
	cout << "Введите A\n";
	cin >> a;
	cout << "Введите B\n";
	cin >> b;
	cout << "Введите Z\n";
	cin >> z;
	cout << "Выберите функцию F(x):\n1 - 2x\n2 - x^2\n3 - x/3\n";
	cin >> variant;
	x = z > 0 ? 1 / (pow(z, 2) + 2 * z) : 1 - pow(z, 3);
	f = variant == 1 ? 2 * x : variant == 2 ? pow(x, 2) : x / 3;
	cout << "Y = " << (2.5f * a * exp(-3 * x) - 4 * b * pow(x, 2)) / (log(abs(x)) + f);
}
