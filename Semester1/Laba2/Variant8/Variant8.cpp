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
	x = z >= 0 ? 2 * z + 1 : log(pow(z, 2) - z);
	f = variant == 1 ? 2 * x : variant == 2 ? pow(x, 2) : x / 3;
	cout << "Y = " << pow(sin(f), 2) + a * pow(cos(pow(x, 3)), 5) + c * log(pow(x, 2.0f / 5.0f));
}
