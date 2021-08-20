#include <iostream>

using namespace std;

float Recursion(int, int = 1);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, input;
	float result = 0;
	cout << "Количество итераций: ";
	cin >> n;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	if (input == 1) result = Recursion(n);
	else for (int i = n; i > 0; i--) result = sqrt(i + result);
	cout << "Результат : " << result << "\n\n";
	goto Start;
}

float Recursion(int n, int i)
{
	if (i == n)	return sqrt(n + 0.0f);
	return sqrt(i + Recursion(n, i + 1));
}