#include <iostream>

using namespace std;

float Recursion(int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, k, input;
	float result = 0;
	cout << "Введите число: ";
	cin >> n;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	if (input == 1) result = Recursion(n);
	else for(int i = n; i > 0; i--) result = 1 / (1 + result);
	cout << "Результат : " << result << "\n\n";
	goto Start;
}

float Recursion(int n)
{
	if (n == 0) return 0;
	return 1 / (1 + Recursion(n-1));
}