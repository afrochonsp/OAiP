#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	float x, a, c, z, f, variant;
	cout << "Введите A\n";
	cin >> a;
	cout << "Введите C\n";
	cin >> c;
	cout << "Введите Z\n";
	cin >> z;
	cout << "Выберите функцию F(x):\n1 - 2x\n2 - x^2\n3 - x/3\n";
	cin >> variant;
	x = z <= 1 ? pow(z, 2) + 1 : 1 / sqrt(z - 1);
	f = variant == 1 ? 2 * x : variant == 2 ? pow(x, 2) : x / 3;
	cout << "Y = " << a * pow(sin(pow(f, 2) - 1), 3) + c * log(abs(x)) + exp(x);
}
