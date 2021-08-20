#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double a = -4, b = 4, h = 0.01, eps = 0.001;

double F(double);
double Fd(double x);
double FindRoot(double, double);

int main()
{
	system("chcp 1251");
	system("cls");
	int n = 0;
	cout << "При параметрах:\na = " + to_string(a) + "\nb = " + to_string(b) + "\nh = " + to_string(h) + "\ne = " + to_string(eps) + "\n\n";
	for (double x = a; x <= b; x += h)
	{
		if (F(x) * F(x + h) < 0)
		{
			n++;
			cout << "x" + to_string(n) + " = " + to_string(FindRoot(x, eps)) + "\n";
		}
	}
	if (n == 0) cout << "Корней нет\n";
}

double F(double x)
{
	return 0.1 * pow(x, 3) + pow(x, 2) - 10 * sin(x) - 8;
}

double Fd(double x)
{
	return 0.3 * pow(x, 2) + 2 * x - 10 * cos(x);
}

double FindRoot(double x0, double eps)
{
	double x1 = x0 - F(x0) / Fd(x0);
	while (fabs(x1 - x0) > eps)
	{
		x0 = x1;
		x1 = x1 - F(x1) / Fd(x1);
	}
	return x0;
}