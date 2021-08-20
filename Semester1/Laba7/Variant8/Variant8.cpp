#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int groupSize = 0, groupIndex = 0;
	bool dot = false, e = false;
	string groups[100];
	string group;
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && !(group == "0" || group == "-0" && text[i] != '.') && isdigit(text[i]) ||
			(text[i] == '-' && groupSize == 0) || groupSize > 0 && ((text[i] == '.' && !dot && !e && text[i - 1] != '-') ||
			(text[i] == 'e' && !e && isdigit(text[i - 1])) || (text[i] == '+' || text[i] == '-' && text[i - 1] == 'e')))
		{
			if (text[i] == '.') dot = true;
			if (text[i] == 'e') e = true;
			group += text[i];
			groupSize++;
		}
		else
		{
			if (text[i] == '-' || isdigit(text[i])) i--;
			if (e && isdigit(group[group.length() - 1])) groups[groupIndex++] = group;
			dot = e = false;
			groupSize = 0;
			group = "";
		}
	}
	cout << "Ответ: ";
	for (int i = 0; i <= groupIndex; i++) cout << groups[i] << " ";
	cout << "\n\n";
	goto Start;
}