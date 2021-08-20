#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int wordSize = 0, wordIndex = 0, minSize = 0, minIndex = -1;
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && text[i] != ' ') wordSize++;
		else
		{
			if (wordSize > 0)
			{
				if (wordSize < minSize || minSize == 0)
				{
					minSize = wordSize;
					minIndex = wordIndex;
				}
				wordIndex++;
			}
			wordSize = 0;
		}
	}
	cout << "Ответ: номер слова " << minIndex + 1 << ", длина " << minSize << "\n\n";
	goto Start;
}