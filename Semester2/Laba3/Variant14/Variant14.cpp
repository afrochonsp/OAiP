#include <iostream>

using namespace std;

int F_R(int);
int F(int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, k, input;
	float result = 1;
	cout << "Введите первое число: ";
	cin >> n;
	cout << "Введите второе число: ";
	cin >> k;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	if (input == 1) result = F_R(n) / F_R(k) / F_R(n - k);
	else result = F(n) / F(k) / F(n - k);
	cout << "Результат : " << result << "\n\n";
	goto Start;
}

int F_R(int n)
{
	return (n == 0) ? 1 : n * F_R(n - 1);
}

int F(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++) result *= i;
	return result;
}