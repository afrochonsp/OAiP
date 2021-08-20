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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int maxI = 0, maxJ = 0;
			for (int k = 0; k < m; k++)
			{
				if (matrix[i][k] > maxI) maxI = matrix[i][k];
				if (matrix[j][k] > maxJ) maxJ = matrix[j][k];
			}
			if (maxJ > maxI)
			{
				int *temp = matrix[i];
				matrix[i] = matrix[j];
				matrix[j] = temp;
			}
		}
	}
	cout << "\nТрансформированная матрица:\n\n";
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < m; j++) cout << matrix[i][j] << "\t";
	cout << "\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}