#include <iostream>

using namespace std;

bool Contains(int *, int, int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, m, setSize = 0;
	cout << "Введите количество строчек N\n";
	cin >> n;
	cout << "Введите количество столбцов M\n";
	cin >> m;
	int *set = new int[n * m]();
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
			if (!Contains(set, setSize, matrix[i][j]))
			{
				set[setSize] = matrix[i][j];
				setSize++;
			}
		}
	}
	cout << "\nРезультат = " << setSize << "\n\n";
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	goto Start;
}

bool Contains(int *array, int size, int n)
{
	bool inArray = false;
	for (int i = 0; i < size; i++) if (array[i] == n) inArray = true;
	return inArray;
}