#include <iostream>
#include <ctime>

using namespace std;

float Recursion(float, float, float);
float F(float);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int input;
	float e = 0.01f, result;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	cout << "\n";
	if (input == 1) result = Recursion(2, 6, e);
	else
	{
		float l = 2, r = 6;
		while (abs(r - l) > e)
		{
			float m = (l + r) / 2.0, y_l = F(m - e), y_r = F(m + e);
			y_l >= y_r ? l = m : r = m;
		}
		result = (l + r) / 2.0;
	}
	cout << "Минимум функции 7sin(x)^2 на отрезке [2, 6]: y = " << F(result) << " при x = " << result << "\n\n";
	goto Start;
}

float Recursion(float l, float r, float e)
{
	float m = (l + r) / 2, y_l = F(m - e), y_r = F(m + e);
	y_l >= y_r ? l = m : r = m;
	return abs(r - l) < e ? (l + r) / 2 : Recursion(l, r, e);
}

float F(float x)
{
	return 7 * pow(sin(x), 2);
}
