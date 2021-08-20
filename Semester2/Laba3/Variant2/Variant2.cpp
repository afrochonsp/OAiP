#include <iostream>

using namespace std;

int Recursion(int *, int, int, int = 0);
void BubbleSort(int *, int);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int key, size, input, result = -1;
	cout << "Введите размер массива" << endl;
	cin >> size;
	cout << "\nИсходный массив:\n";
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "]: ";
		cin >> array[i];
	}
	BubbleSort(array, size);
	cout << "\n" << "Отсортированный массив:\n";
	for (int i = 0; i < size; i++) cout << "[" << i << "]: " << array[i] << "\n";
	cout << "\n" << "Введите нужное число\n";
	cin >> key;
	cout << "\n" << "Использовать рекурсивную функцию? (да - 1, нет - 2)\n";
	cin >> input;
	cout << "\n";
	if (input == 1) result = Recursion(array, key, size);
	else
	{
		int right = size;
		for (int left = 0, middle; left < right; array[middle] >= key ? right = middle : left = middle + 1) middle = (left + right) / 2;
		if (array[right] == key) result = right;
	}
	if(result != -1) cout << "Индекс элемента " << key << " в массиве равен " << result << "\n\n";
	else cout << "Элемент отсутствует\n\n";
	goto Start;
}

int Recursion(int *array, int key, int right, int left)
{
	if (left > right) return -1;
	int middlePoint = (left + right) / 2;
	if (array[middlePoint] > key) return Recursion(array, key, middlePoint - 1, left);
	else if (array[middlePoint] < key) return Recursion(array, key, right, middlePoint + 1);
	else return middlePoint;
}

void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}