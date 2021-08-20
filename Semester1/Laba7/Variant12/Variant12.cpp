#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int k = 0, i = 0;
	string text, word;
	cout << "Введите строку\n";
	getline(cin, text);
	cout << "Введите k-ю позицию\n";
	cin >> k;
	cin.ignore();
	for (i = k; i > 0 && text[i] == ' '; i--);
	for (i; i > 0 && text[i-1] != ' '; i--);
	for (i; text[i] != ' ' && i < (int)text.length(); i++) word += text[i];
	cout << "Ответ: " << word << "\n\n";
	goto Start;
}