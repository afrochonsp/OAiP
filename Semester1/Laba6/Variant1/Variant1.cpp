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
	for (int j = 0; j < m; j++)
	{
		cout << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << "Введите элемент " << "[" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}
	cout << "\nИсходная матрица:\n\n";
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < m; j++) cout << matrix[i][j] << "\t";
	cout << "\nВектор B:\n\n";
	if (n > 0) for (int j = 0; j < m; j++)
	{
		bool notNull = 0;
		for (int i = 0; i < n; i++) if (matrix[i][j] != 0) notNull = 1;
		cout << notNull << "\t";
	}
	cout << "\n\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}