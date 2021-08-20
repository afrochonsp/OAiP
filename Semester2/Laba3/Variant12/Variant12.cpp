#include <iostream>

using namespace std;

float Recursion(int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, input;
	float result = 1;
	cout << "Чётное количество сомножителей больше или равное 2: ";
	cin >> n;
	if (n % 2 == 1 || n < 2)
	{
		cout << "Неправильное число";
		goto Start;
	}
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	if (input == 1) result = Recursion(n);
	else for (int _n = 1; _n <= n; _n++) result *= (_n * 2.0f) / (_n * 2 - 1) * (_n * 2) / (_n * 2 + 1);
	cout << "Результат : " << result << "\n\n";
	goto Start;
}

float Recursion(int n)
{
	if (n == 0)	return 1;
	return (n * 2.0f) / (n * 2 - 1) * (n * 2) / (n * 2 + 1) * Recursion(n - 1);
}