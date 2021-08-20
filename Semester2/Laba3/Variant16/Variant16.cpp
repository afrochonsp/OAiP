#include <iostream>
#include <ctime>

using namespace std;

void Recursion(int[], int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int size, *array, input;
	srand(static_cast<unsigned int>(time(0)));
	cout << "Введите размер массива\n";
	cin >> size;
	array = new int[size];
	cout << "\n" << "Выберите способ заполнения массива:\n1 - ввод с клавиатуры\n2 - случайное число от -10 до 10" << endl;
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
	if (input == 1) Recursion(array, size - 1);
	else for (int i = 0; i < size; i++) if (array[i] == 1) array[i + 1] = 0, array[i - 1] = 0;
	cout << "Новый массив: " << "\n";
	for (int i = 0; i < size; i++) cout << "[" << i << "]: " << array[i] << "\n";
	cout << "\n";
	goto Start;
}

void Recursion(int array[], int count)
{
	if (count < 0) return;
	if (array[count] == 1)
	{
		array[count - 1] = 0;
		array[count + 1] = 0;
	}
	Recursion(array, count - 1);
}
