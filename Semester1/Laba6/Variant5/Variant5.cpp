#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, m, specialCount = 0;
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
		for (int j = 0; j < m; j++) if(j > 0 && j < m - 1 && matrix[i][j - 1] > matrix[i][j] && matrix[i][j + 1] < matrix[i][j]) specialCount++;
	cout << "\nРезультат = " << specialCount << "\n\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}