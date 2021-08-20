#include <iostream>

using namespace std;

int Recursion(int, int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int m, n, input, result = 0;
	cout << "Введите первое число\n";
	cin >> n;
	cout << "Введите второе число\n";
	cin >> m;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	cout << "\n";
	if (input == 1) result = Recursion(n, m);
	else
	{
		for (int temp; (n != 0 ? true : (n = m, false)) && m % n != 0; temp = n, n = m % n, m = temp);
		result = abs(n);
		//while (m && n) abs(m) > abs(n) ? m %= n : n %= m;
		//result = abs(m | n);
	}
	cout << "НОД: " << result << "\n\n";
	goto Start;
}

int Recursion(int n, int m)
{
	return abs(n == 0 ? m : m % n == 0 ? n : Recursion(m % n, n));
}
