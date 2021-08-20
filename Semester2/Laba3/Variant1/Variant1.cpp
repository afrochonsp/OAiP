#include <iostream>
#include <string>

using namespace std;

string Recursion(int, int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	string result;
	int n, p, input;
	cout << "Введите число\n";
	cin >> n;
	cout << "\nВведите систему счисления\n";
	cin >> p;
	cout << "\nИспользовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	if (input == 1) result = Recursion(n, p);
	else for (; n != 0 || result == ""; n /= p) result = to_string(n / p == 0 ? n % p : abs(n % p)) + result;
	cout << "\nРезультат : " << result << "\n\n";
	goto Start;
}

string Recursion(int n, int p)
{
	return n / p == 0 ? to_string(n % p) : Recursion(n / p, p) + to_string(abs(n % p));
}