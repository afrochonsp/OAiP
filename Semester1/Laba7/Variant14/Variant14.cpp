#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int wordSize = 0, wordIndex = 0, maxSize = 0, maxIndex = -1, maxPosition = 0;
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && text[i] != ' ') wordSize++;
		else
		{
			if (wordSize > maxSize)
			{
				maxSize = wordSize;
				maxPosition = i - wordSize;
				maxIndex = wordIndex;
			}
			if (wordSize > 0) wordIndex++;
			wordSize = 0;
		}
	}
	cout << "Ответ: номер слова " << maxIndex + 1 << ", позиция " << maxPosition << "\n\n";
	goto Start;
}