#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int groupSize = 0, groupIndex = 0;
	bool dot = false;
	string groups[100];
	string group;
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && !(group == "0" || group == "-0" && text[i] != '.') && isdigit(text[i]) ||
			(text[i] == '-' && groupSize == 0) || (text[i] == '.' && !dot && groupSize > 0 && text[i - 1] != '-'))
		{
			if (text[i] == '.') dot = true;
			group += text[i];
			groupSize++;
		}
		else
		{
			if (text[i] == '-' || isdigit(text[i])) i--;
			if (dot && group[group.length() - 1] == '0') i -= 2;
			for (int j = group.length() - 1; j > 0 && group[j] == '0' && group[j - 1] != '.'; j--) group.erase(j);
			if (dot && group[group.length() - 1] != '.') groups[groupIndex++] = group;
			dot = false;
			groupSize = 0;
			group = "";
		}
	}
	cout << "Ответ: ";
	for (int i = 0; i <= groupIndex; i++) cout << groups[i] << " ";
	cout << "\n\n";
	goto Start;
}