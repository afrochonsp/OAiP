#include <iostream>
#include <ctime>

using namespace std;

int Recursion(int[], int, int);
int Iteration(int[], int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int size, *array, input, result = 0;
	srand(static_cast<unsigned int>(time(0)));
	cout << "Введите размер массива\n";
	cin >> size;
	array = new int[size];
	cout << "Выберите способ заполнения массива:\n1 - ввод с клавиатуры\n2 - случайное число от -10 до 10" << endl;
	cin >> input;
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "]: ";
		if (input == 2)
		{
			array[i] = rand() % 21 - 10;
			cout << array[i] << "\n";
		}
		else cin >> array[i];
	}
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	cout << "\n";
	if (input == 1) result = Recursion(array, 0, size - 1);
	else result = Iteration(array, size);
	cout << "Максимальный элемент: " << result << "\n\n";
	goto Start;
}

int Recursion(int array[], int l, int r)
{
	if (abs(l - r) < 2) return array[l] > array[r] ? array[l] : array[r];
	int m = (l + r) / 2;
	int x1 = Recursion(array, l, m), x2 = Recursion(array, m, r);
	return x1 > x2 ? x1 : x2;
}

int Iteration(int array[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++) if (array[i] > array[max]) max = i;
	return array[max];
}