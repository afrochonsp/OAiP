#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int groupSize = 0, groupIndex = 0;
	string groups[100];
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && groups[groupIndex][0] != '0' && isdigit(text[i]))
		{
			groups[groupIndex] += text[i];
			groupSize++;
		}
		else
		{
			if (groupSize == 1 && text[i - 1] == '0' && groups[groupIndex][0] == '0') i--;
			if (groupSize > 0) groupIndex++;
			groupSize = 0;
		}
	}
	cout << "Ответ: ";
	for (int i = 0; i < groupIndex; i++) if(stoi(groups[i]) % 2 == 0) cout << groups[i] << " ";
	cout << "\n\n";
	goto Start;
}