#include <iostream>

using namespace std;

float Recursion(int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, input;
	float result = 0.5;
	cout << "Количество итераций: ";
	cin >> n;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	if (input == 1) result = Recursion(n);
	else for (int _n = 1; _n <= n; _n++) result = 1 / (_n + result);
	cout << "Результат : " << result << "\n\n";
	goto Start;
}

float Recursion(int n)
{
	if (n == 0)	return 0.5;
	return 1 / (n + Recursion(n - 1));
}