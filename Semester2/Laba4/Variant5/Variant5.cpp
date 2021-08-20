#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct Table
{
	string name;
	string phoneNumber;
	string cityPhoneNumber;
	time_t date;
	int time;
	int code;
	int	tariff;
};

struct City
{
	string name;
	int code;
	int time;
	int sum;
};

template<typename T = int>
void InputNumber(T &, string = "", T = numeric_limits<T>::min(), T = numeric_limits<T>::max());
int Select(const string *, int, string = "");
void ChangeTableInfo(Table &);
void ShowTableInfo(Table);
void ShowTablesInfo(Table[], int);
void InputDate(time_t &, string = "");
void ShowDate(time_t, string = "");
void ShowCityInfo(City);
void ShowCitiesInfo(City[], int);
template<typename T = int>
void SelectionSort(City[], int, T City::* = &City::time);
template<typename T = int>
void QuickSort(City[], int, int, T City::* = &City::time);
template<typename T = int>
int LinearSearch(City[], int, T, T City::* = &City::time);
template<typename T = int>
int BinarySearch(City[], int, int, T, T City::* = &City::time);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int n, input, result;
	Table *tables;
	City *cities;
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
	cities = new City[n]{};
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int contained = -1;
		for (int j = 0; j < c; j++) if (tables[i].code == cities[j].code) contained = j;
		if (contained == -1)
		{
			cities[c].name = tables[i].name;
			cities[c].code = tables[i].code;
			cities[c].time = tables[i].time;
			cities[c].sum = tables[i].tariff * tables[i].time;
			c++;
		}
		else
		{
			cities[contained].time += tables[i].time;
			cities[contained].sum += tables[i].tariff * tables[i].time;
		}
	}
	cout << "Города:\n\n";
	ShowCitiesInfo(cities, c);
	switch (Select(variants[2], 5, "Выберите операцию:"))
	{
	case 1:
		ShowCitiesInfo(cities, c);
		break;
	case 2:
		SelectionSort(cities, c);
		ShowCitiesInfo(cities, c);
		break;
	case 3:
		QuickSort(cities, 0, c - 1);
		ShowCitiesInfo(cities, c);
		break;
	case 4:
		InputNumber(key, "Нужное общее время разговоров: ", 0);
		cout << "\n";
		result = LinearSearch(cities, c, key);
		if (result >= 0) ShowCityInfo(cities[result]);
		else cout << "Элемент не найден\n\n";
		break;
	case 5:
		if (Select(variants[0], 2, "Массив будет отсортирован, продолжить?") != 1) break;
		QuickSort(cities, 0, c - 1);
		ShowCitiesInfo(cities, c);
		InputNumber(key, "Нужное общее время разговоров: ", 0);
		cout << "\n";
		result = BinarySearch(cities, 0, c, key);
		if (result >= 0) ShowCityInfo(cities[result]);
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

void InputDate(time_t &time, string text)
{
	cout << text;
	tm date{};
	InputNumber(date.tm_mday, "День: ", 1, 31);
	InputNumber(date.tm_mon, "Месяц: ", 1, 12);
	InputNumber(date.tm_year, "Год: ", 1970);
	date.tm_year -= 1900;
	date.tm_mon--;
	int temp = date.tm_mday;
	time = mktime(&date);
	if (date.tm_mday != temp) ShowDate(time, "Дата исправлена: ");
}

void ShowDate(time_t time, string text)
{
	cout << text;
	tm date;
	localtime_s(&date, &time);
	cout << (date.tm_mday < 10 ? "0" : "") << date.tm_mday << "." <<
		(date.tm_mon + 1 < 10 ? "0" : "") << date.tm_mon + 1 << "." << date.tm_year + 1900;
}

void ChangeTableInfo(Table &table)
{
	InputDate(table.date, "Дата разговора:\n");
	InputNumber(table.code, "Код города: ", 1);
	cout << "Название города: ";
	getline(cin, table.name);
	InputNumber(table.time, "Время разговора: ", 0);
	InputNumber(table.tariff, "Тариф: ", 0);
	cout << "Номер телефона в этом городе: ";
	getline(cin, table.cityPhoneNumber);
	cout << "Номер телефона абонента: ";
	getline(cin, table.phoneNumber);
	cout << "\n";
}

void ShowTableInfo(Table table)
{
	ShowDate(table.date, "Дата разговора: ");
	cout << "\n";
	cout << "Код города: " << table.code << "\n";
	cout << "Название города: " << table.name << "\n";
	cout << "Время разговора: " << table.time << "\n";
	cout << "Тариф: " << table.tariff << "\n";
	cout << "Номер телефона в этом городе: " << table.cityPhoneNumber << "\n";
	cout << "Номер телефона абонента: " << table.cityPhoneNumber << "\n\n";
}

void ShowTablesInfo(Table tables[], int n)
{
	for (int i = 0; i < n; i++) ShowTableInfo(tables[i]);
}

void ShowCityInfo(City city)
{
	cout << "Название города: " << city.name << "\n";
	cout << "Код города: " << city.code << "\n";
	cout << "Общее время разговоров: " << city.time << "\n";
	cout << "Сумма: " << city.sum << "\n\n";
}

void ShowCitiesInfo(City cities[], int n)
{
	for (int i = 0; i < n; i++) ShowCityInfo(cities[i]);
}

template<typename T>
void SelectionSort(City array[], int n, T City::*keyPtr)
{
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++) if (array[i].*keyPtr < array[j].*keyPtr) m = j;
		if (m == i) continue;
		City temp = array[i];
		array[i] = array[m];
		array[m] = temp;
	}
}

template<typename T>
void QuickSort(City array[], int begin, int end, T City::*keyPtr)
{
	int left = begin, right = end, middle = (left + right) / 2;
	do
	{
		while (array[left].*keyPtr > array[middle].*keyPtr) left++;
		while (array[right].*keyPtr < array[middle].*keyPtr) right--;
		if (left <= right)
		{
			City temp = array[left];
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
int LinearSearch(City array[], int n, T key, T City::*keyPtr)
{
	int result = -1;
	for (int i = 0; i < n; i++) if (array[i].*keyPtr == key) result = i;
	return result;
}

template<typename T>
int BinarySearch(City array[], int left, int right, T key, T City::*keyPtr)
{
	if (left > right) return -1;
	int middle = (left + right) / 2;
	if (array[middle].*keyPtr < key) return BinarySearch(array, left, middle - 1, key, keyPtr);
	if (array[middle].*keyPtr > key) return BinarySearch(array, middle + 1, right, key, keyPtr);
	return middle;
}