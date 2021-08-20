#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	float x, k, m, n, z, f, variant;
	cout << "Введите K\n";
	cin >> k;
	cout << "Введите M\n";
	cin >> m;
	cout << "Введите N\n";
	cin >> n;
	cout << "Введите Z\n";
	cin >> z;
	cout << "Выберите функцию F(x):\n1 - 2x\n2 - x^2\n3 - x/3\n";
	cin >> variant;
	x = z > 1 ? z : pow(z, 2) + 1;
	f = variant == 1 ? 2 * x : variant == 2 ? pow(x, 2) : x / 3;
	cout << "Y = " << sin(n * f) + cos(k * x) + log(m * x);
}
