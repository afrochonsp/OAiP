#include <iostream>
#include <cmath>

using namespace std;

float Y(float, float);
float S(float, float);
float DistanceYS(float, float);
void Out_Rez(float(*function)(float, float), float, float, float, float);
const float pi = atan(1.0f) * 4;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	float b = 1, n = 10, h = 0.1f, x = 0.1f;
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
	cout << "Выберите функцию:\n1 - Y(x)\n2 - S(x)\n3 - |Y(x) - S(x)|\n";
	cin >> q;
	float(*function)(float, float) = q == '1' ? Y : q == '2' ? S : DistanceYS;
	Out_Rez(function, x, b, h, n);
	goto Start;
}

void Out_Rez(float(*f)(float, float), float x, float b, float h, float n)
{
	for (int c = (int)floor(abs(b - x) / h); c >= 0; c--, x += h * (1 - 2 * (x > b)))
		cout << "x = " << x << "\n" << (f == Y ? "Y(x)" : f == S ? "S(x)" : "|Y(x) - S(x)|") << " = " << f(x, n) << "\n";
	cout << "\n";
}

float Y(float x, float n)
{
	return -0.5f * log(1 - 2 * x * cos(pi / 3) + pow(x, 2));
}

float S(float x, float n)
{
	float s = 0;
	for (int k = 1; k <= n; k++) s += pow(x, k) * cos(k * pi / 3) / k;
	return s;
}

float DistanceYS(float x, float n)
{
	return abs(Y(x, n) - S(x, n));
}
