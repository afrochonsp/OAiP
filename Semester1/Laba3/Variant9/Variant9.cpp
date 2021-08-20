#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	float b = 1, n = 10, h = 0.1f, x = 0.1f, k, y, s;
	char q;
	cout << "Использовать стандартные занчения? (y - да, n - нет)\n";
	cin >> q;
	if (q != 'y')
	{
		cout << "Введите a\n";
		cin >> x;
		cout << "Введите b\n";
		cin >> b;
		cout << "Введите n\n";
		cin >> n;
		cout << "Введите h\n";
		cin >> h;
	}
	for (int c = (int)floor(abs(b - x) / h); c >= 0; c--, x += h * (1 - 2 * (x > b)))
	{
		y = (1 + pow(x, 2)) / 2 * atan(x) - x / 2;
		for (k = 1, s = 0; k <= n; k++) s += pow(-1.0f, k + 1) * pow(x, 2 * k + 1) / (4 * pow(k, 2) - 1);
		cout << "x = " << x << "\n" << "Y(x) = " << y << "\n" << "S(x) = " << s << "\n" << "|Y(x) - S(x)| = " << abs(y - s) << "\n";
	}
	cout << "\n";
	goto Start;
}