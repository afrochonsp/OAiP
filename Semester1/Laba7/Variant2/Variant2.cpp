#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int groupSize = 0, groupIndex = -1, min = -1;
	string groups[100];
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && text[i] == '0' || text[i] == '1')
		{
			if (groupSize == 0) groupIndex++;
			groups[groupIndex] += text[i];
			groupSize++;
		}
		else groupSize = 0;
	}
	for (int i = 0; i <= groupIndex; i++) if (min == -1 || groups[i].length() < groups[min].length()) min = i;
	cout << "Ответ: " << (min == -1 ? "групп нет" : groups[min]) << "\n\n";
	goto Start;
}