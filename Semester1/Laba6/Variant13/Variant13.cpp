#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, max = 0;
	cout << "Введите порядок матрицы\n";
	cin >> n;
	int **matrix = new int*[n]();
	for (int i = 0; i < n; i++) matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < n; j++)
		{
			cout << "Введите элемент " << "[" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}
	cout << "\nИсходная матрица:\n";
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < n; j++) cout << matrix[i][j] << "\t";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i > n - 1 - j && matrix[i][j] > max) max = matrix[i][j];
	cout << "\nРезультат = " << max << "\n\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}