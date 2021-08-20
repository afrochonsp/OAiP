#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double a = 4, b = 7, h = 0.01, eps = 0.001;

double F(double);
double FindRoot(double, double, double);

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
			cout << "x" + to_string(n) + " = " + to_string(FindRoot(x, x + h, eps)) + "\n";
		}
	}
	if (n == 0) cout << "Корней нет\n";
}

double F(double x)
{
	return exp(x) / pow(x, 3) - pow(sin(x), 3) - 2;
}

double FindRoot(double x0, double x1, double epsilon)
{
	double x2, de;
	double y0 = F(x0);
	double y1 = F(x1);
	do
	{
		x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
		de = fabs(x1 - x2);
		x0 = x1;
		x1 = x2;
		y0 = y1;
		y1 = F(x2);
	} while (de > eps);
	return x1;
}