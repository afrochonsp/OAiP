#include <iostream>

using namespace std;

int Recursion(int, int);
int Iteration(int, int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int x, n, input, result;
	cout << "Введите число: ";
	cin >> x;
	cout << "Введите степень: ";
	cin >> n;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	if (input == 1) result = Recursion(x, n);
	else result = Iteration(x, n);
	cout << "Результат : " << result << "\n\n";
	goto Start;
}

int Recursion(int x, int n)
{
	if (n == 0) return 1;
	if (n % 2 == 0)
	{
		int temp = Recursion(x, n / 2);
		return temp * temp;
	}
	else return x * Recursion(x, n - 1);
}

int Iteration(int x, int n)
{
	int result = 1;
	while (n)
	{
		if (n % 2 == 1) result *= x;
		x *= x;
		n /= 2;
	}
	return result;
}