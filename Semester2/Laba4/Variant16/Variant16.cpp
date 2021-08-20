#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Table
{
	string name;
	string faculty;
	string department;
	string position;
	int hours;
};

template<typename T = int>
void InputNumber(T &, string = "", T = numeric_limits<T>::min(), T = numeric_limits<T>::max());
int Select(const string *, int, string = "");
void ChangeTableInfo(Table &);
void ShowTableInfo(Table);
void ShowTablesInfo(Table[], int);
template<typename T = int>
void SelectionSort(Table[], int, T Table::* = &Table::hours);
template<typename T = int>
void QuickSort(Table[], int, int, T Table::* = &Table::hours);
template<typename T = int>
int LinearSearch(Table[], int, T, T Table::* = &Table::hours);
template<typename T = int>
int BinarySearch(Table[], int, int, T, T Table::* = &Table::hours);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, input, result;
	Table *tables;
	int key;
	string variants[][100] = { { "Да", "Нет" }, { "Прочесть файл", "Записать новый" },
	{ "Задание", "Сортировка прямым выбором", "Быстрая сортировка", "Линейный поиск", "Двоичный поиск" } };
	ifstream fin("Structures.txt", ios::binary);
	fin.seekg(0, ios::end);
	if ((int)fin.tellg() > 0 && Select(variants[1], 2) == 1)
	{
		n = (int)fin.tellg() / sizeof(Table);
		fin.seekg(0, ios::beg);
		tables = new Table[n]{};
		fin.read((char*)tables, sizeof(*tables) * n);
		fin.close();
		ShowTablesInfo(tables, n);
		while (1)
		{
			if (Select(variants[0], 2, "Изменить файл?") == 1)
			{
				InputNumber(input, "Какой номер (от 1)?\n", 1, n);
				cout << "\n";
				ChangeTableInfo(tables[input - 1]);
				ShowTablesInfo(tables, n);
			}
			else break;
		}
	}
	else
	{
		InputNumber(n, "Количество записей: ", 1);
		cout << "\n";
		tables = new Table[n]{};
		for (int i = 0; i < n; i++) ChangeTableInfo(tables[i]);
	}
	ofstream fout("Structures.txt", ios::binary);
	fout.write((char*)tables, sizeof(*tables) * n);
	fout.close();
	string *departments = new string[n];
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int contained = -1;
		for (int j = 0; j < c; j++) if (tables[i].department == departments[j]) contained = j;
		if (contained == -1) departments[c++] = tables[i].department;
	}
	switch (Select(variants[2], 5, "Выберите операцию:"))
	{
	case 1:
		QuickSort(tables, 0, n - 1);
		for (int i = 0; i < c; i++) 
			for (int j = 0; j < n; j++) if(departments[i] == tables[j].department) ShowTableInfo(tables[j]);
		break;
	case 2:
		SelectionSort(tables, n);
		ShowTablesInfo(tables, n);
		break;
	case 3:
		QuickSort(tables, 0, n - 1);
		ShowTablesInfo(tables, n);
		break;
	case 4:
		InputNumber(key, "Нужный объём нагрузки: ", 0);
		cout << "\n";
		result = LinearSearch(tables, n, key);
		if (result >= 0) ShowTableInfo(tables[result]);
		else cout << "Элемент не найден\n\n";
		break;
	case 5:
		if (Select(variants[0], 2, "Массив будет отсортирован, продолжить?") != 1) break;
		QuickSort(tables, 0, n - 1);
		ShowTablesInfo(tables, n);
		InputNumber(key, "Нужный объём нагрузки: ", 0);
		cout << "\n";
		result = BinarySearch(tables, 0, n, key);
		if (result >= 0) ShowTableInfo(tables[result]);
		else cout << "Элемент не найден\n\n";
		break;
	}
	goto Start;
}

template<typename T>
void InputNumber(T &n, string text, T minVlaue, T maxValue)
{
	cout << text;
	while (!(cin >> n) || n < minVlaue || n > maxValue)
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Select(const string *variants, int count, string question)
{
	int choice;
	if (question != "") cout << question << "\n";
	for (int i = 0; i < count; i++) cout << i + 1 << " - " << variants[i] << "\n";
	InputNumber(choice, "", 1, count);
	cout << "\n";
	return choice;
}

void ChangeTableInfo(Table &table)
{
	cout << "ФИО: ";
	getline(cin, table.name);
	cout << "Факультет: ";
	getline(cin, table.faculty);
	cout << "Кафедра: ";
	getline(cin, table.department);
	cout << "Должность: ";
	getline(cin, table.department);
	InputNumber(table.hours, "Объём нагрузки: ");
	cout << "\n";
}

void ShowTableInfo(Table table)
{
	cout << "ФИО: " << table.name << "\n";
	cout << "Факультет: " << table.faculty << "\n";
	cout << "Кафедра: " << table.department << "\n";
	cout << "Должность: " << table.position << "\n";
	cout << "Объём нагрузки: " << table.hours << "\n";
	cout << "\n";
}

void ShowTablesInfo(Table tables[], int n)
{
	for (int i = 0; i < n; i++) ShowTableInfo(tables[i]);
}

string ToLower(string text)
{
	for (auto &c : text) c = tolower(c);
	return text;
}

bool operator > (string left, string right)
{
	return fmax(ToLower(right).compare(ToLower(left)), 0);
}

bool operator < (string left, string right)
{
	return fmax(ToLower(left).compare(ToLower(right)), 0);
}

template<typename T>
void SelectionSort(Table array[], int n, T Table::*keyPtr)
{
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++) if (array[i].*keyPtr < array[j].*keyPtr) m = j;
		if (m == i) continue;
		Table temp = array[i];
		array[i] = array[m];
		array[m] = temp;
	}
}

template<typename T>
void QuickSort(Table array[], int begin, int end, T Table::*keyPtr)
{
	int left = begin, right = end, middle = (left + right) / 2;
	do
	{
		while (array[left].*keyPtr > array[middle].*keyPtr) left++;
		while (array[right].*keyPtr < array[middle].*keyPtr) right--;
		if (left <= right)
		{
			Table temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) QuickSort(array, begin, right, keyPtr);
	if (left < end) QuickSort(array, left, end, keyPtr);
}

template<typename T>
int LinearSearch(Table array[], int n, T key, T Table::*keyPtr)
{
	int result = -1;
	for (int i = 0; i < n; i++) if (array[i].*keyPtr == key) result = i;
	return result;
}

template<typename T>
int BinarySearch(Table array[], int left, int right, T key, T Table::*keyPtr)
{
	if (left > right) return -1;
	int middle = (left + right) / 2;
	if (array[middle].*keyPtr < key) return BinarySearch(array, left, middle - 1, key, keyPtr);
	if (array[middle].*keyPtr > key) return BinarySearch(array, middle + 1, right, key, keyPtr);
	return middle;
}