#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, m, minElement = 0, maxElement = 0, minRow = 0, maxRow = 0;
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] < minElement || (matrix[i][j] == minElement && minRow == maxRow) || (i == 0 && j == 0))
			{
				minElement = matrix[i][j];
				minRow = i;
			}
			if (matrix[i][j] > maxElement || (matrix[i][j] == maxElement && minRow == maxRow) || (i == 0 && j == 0))
			{
				maxElement = matrix[i][j];
				maxRow = i;
			}
		}
	}
	int *temp = matrix[minRow];
	matrix[minRow] = matrix[maxRow];
	matrix[maxRow] = temp;
	cout << "\nТрансформированная матрица:\n\n";
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < m; j++) cout << matrix[i][j] << "\t";
	cout << "\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}