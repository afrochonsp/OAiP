#include <iostream>
#include <stack>

using namespace std;

int Recursion(int, int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int m, n, input, result = 0;
	cout << "Введите первое число\n";
	cin >> m;
	cout << "Введите второе число\n";
	cin >> n;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	cout << "\n";
	if (input == 1) result = Recursion(m, n);
	else
	{
		stack <int> s;
		s.push(m);
		while (!s.empty())
		{
			m = s.top();
			s.pop();
			if (m == 0) n += m + 1;
			else if (n == 0)
			{
				n++;
				s.push(--m);
			}
			else 
			{
				s.push(--m);
				s.push(++m);
				n--;
			}
		}
		result = n;
	}
	cout << "Значение функции Аккермана: " << result << "\n\n";
	goto Start;
}

int Recursion(int m, int n)
{
	if (m == 0) return n + 1;
	else if (n == 0) return Recursion(m - 1, 1);
	else return Recursion(m - 1, Recursion(m, n - 1));
}
