#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n;
	cout << "Введите порядок матрицы\n";
	cin >> n;
	bool symmetric = true;
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
		for (int j = 0; j < n; j++) if (matrix[i][j] != matrix[n - j - 1][n - i - 1] && j != (n - 1 - i)) symmetric = false;
	cout << "\nОтвет: " << (symmetric ? "матрица симметрична" : "матрица не симметрична") << " по побочной диагонали." << "\n\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}