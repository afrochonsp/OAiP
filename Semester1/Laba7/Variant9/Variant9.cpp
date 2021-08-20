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
	for (int i = 0; i < groupIndex; i++)
	{
		for (int j = 0; j < groupIndex - 1; j++)
		{
			if (stoi(groups[j]) > stoi(groups[i]))
			{
				string temp = groups[j];
				groups[j] = groups[i];
				groups[i] = temp;
			}
		}
	}
	cout << "Ответ: ";
	for (int i = 0; i < groupIndex; i++) cout << groups[i] << " ";
	cout << "\n\n";
	goto Start;
}