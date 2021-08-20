#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int k = 0, i = 0;
	string text, substring1, substring2;
	cout << "Введите строку\n";
	getline(cin, text);
	cout << "Введите k-ю позицию\n";
	cin >> k;
	cin.ignore();
	for (i = k; i > 0 && text[i - 1] != ' '; i--);
	for (int j = 0; j < i - 1; j++) substring1 += text[j];
	for (i; i < (int)text.length(); i++) substring2 += text[i];
	cout << "Подстрока 1: " << substring1 << "\nПодстрока 2: " << substring2 << "\n\n";
	goto Start;
}