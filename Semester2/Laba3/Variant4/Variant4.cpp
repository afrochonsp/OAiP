#include <iostream>

using namespace std;

int Recursion(int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, input, result = 0;
	cout << "Введите число\n";
	cin >> n;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	cout << "\n";
	if (input == 1) result = Recursion(n);
	else
	{
		for (int i = 0, j = -1, k = 0; i < n; i++)
		{
			result = abs(j + k);
			j = k;
			k = result;
		}
	}
	cout << "Число Фибоначчи: " << result << "\n\n";
	goto Start;
}

int Recursion(int n)
{
	return n < 2 ? n : Recursion(n - 1) + Recursion(n - 2);
}
