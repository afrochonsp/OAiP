#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int groupCount = 0, groupSize = 0;
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && text[i] == '0' || text[i] == '1') groupSize++;
		else
		{
			if (groupSize == 5) groupCount++;
			groupSize = 0;
		}
	}
	cout << "Ответ: " << groupCount << "\n\n";
	goto Start;
}