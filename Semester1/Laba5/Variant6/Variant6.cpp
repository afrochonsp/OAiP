#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int type, size, result = 0, firstNegative = 0, Negative = 0;
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
	for (int i = 0; i < size; i++)
	{
		if (array[i] < 0)
		{
			if (array[firstNegative] >= 0) firstNegative = i;
			else if (Negative == 0) Negative = i;
		}
	}
	for (int i = firstNegative + 1; i < Negative; i++) result += array[i];
	cout << "Результат = " << result << "\n\n";
	goto Start;
}