#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, maxRow = 0, maxColumn = 0;
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
	cout << "\nИсходная матрица:\n\n";
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < n; j++) cout << matrix[i][j] << "\t";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (abs(matrix[i][j]) > abs(matrix[maxRow][maxColumn]))
			{
				maxRow = i;
				maxColumn = j;
			}
		}
	}
	n--;
	for (int i = maxRow; i < n; i++) matrix[i] = matrix[i + 1];
	for (int i = 0; i < n; i++)
		for (int j = maxColumn; j < n; j++) matrix[i][j] = matrix[i][j + 1];
	cout << "\nТрансформированная матрица:\n\n";
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < n; j++) cout << matrix[i][j] << "\t";
	cout << "\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}