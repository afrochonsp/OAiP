﻿#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int type, size, result = 0, absMin = 0;
	srand(static_cast<unsigned int>(time(0)));
	cout << "Введите размер массива" << endl;
	cin >> size;
	int array[100];
	cout << "Выберите способ заполнения массива:\n1 - ввод с клавиатуры\n2 - случайное число от -10 до 10" << endl;
	cin >> type;
	for (int i = 0; i < size; i++)
	{
		if (type == 2)
		{
			array[i] = rand() % 21 - 10;
			cout << "[" << i << "]: " << array[i] << "\n";
		}
		else
		{
			cout << "[" << i << "]: ";
			cin >> array[i];
		}
	}
	for (int i = 0; i < size; i++) if (abs(array[i]) < abs(array[absMin])) absMin = i;
	for (int i = absMin + 1; i < size; i++) result += abs(array[i]);
	cout << "Результат = " << result << "\n\n";
	goto Start;
}