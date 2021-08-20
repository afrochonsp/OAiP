#include <iostream>

using namespace std;

float Recursion(float, float, float, float);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int input;
	float a, e = 0.0001f, result;
	cout << "Введите число\n";
	cin >> a;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	cout << "\n";
	if (input == 1) result = Recursion(0, 0.5 * (1 + a), a, e);
	else
	{
		float X = 0, Xn = 0.5 * (1 + a);
		while (abs(X - Xn) > e)
		{
			X = Xn;
			Xn = 0.5 * (Xn + a / Xn);
		}
		result = Xn;
	}
	cout << "Корень числа " << a << " равен " << result << "\n\n";
	goto Start;
}

float Recursion(float X, float Xn, float a, float e)
{
	if (abs(X - Xn) <= e) return Xn;
	X = Xn;
	Xn = 0.5 * (Xn + a / Xn);
	return Recursion(X, Xn, a, e);
}
