#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, m;
	cout << "Введите количество строчек N\n";
	cin >> n;
	cout << "Введите количество столбцов M\n";
	cin >> m;
	int **matrix = new int*[n]();
	for (int i = 0; i < n; i++) matrix[i] = new int[m];
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент " << "[" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}
	cout << "\nИсходная матрица:\n\n";
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < m; j++) cout << matrix[i][j] << "\t";
	cout << "\nВектор B:\n\n";
	for (int i = 0; i < n; i++)
	{
		bool symetric = 1;
		for (int j = 0, k = m - 1; j < m >> 1; j++, k--) if (matrix[i][j] != matrix[i][k]) symetric = 0;
		cout << symetric << "\t";
	}
	cout << "\n\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}
