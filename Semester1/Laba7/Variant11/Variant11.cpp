#include <iostream>
#include <string>

using namespace std;

string LowerCase(string);

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int wordSize = 0, wordIndex = 0;
	string words[100];
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i <= (int)text.length(); i++)
	{
		if (i < (int)text.length() && text[i] != ' ')
		{
			words[wordIndex] += text[i];
			wordSize++;
		}
		else
		{
			if (wordSize > 0) wordIndex++;
			wordSize = 0;
		}
	}
	for (int i = 0; i < wordIndex; i++)
	{
		for (int j = 0; j < wordIndex - 1; j++)
		{
			if (LowerCase(words[j]).compare(LowerCase(words[i])) > 0)
			{
				string temp = words[j];
				words[j] = words[i];
				words[i] = temp;
			}
		}
	}
	cout << "Ответ: ";
	for (int i = 0; i < wordIndex; i++) cout << words[i] << " ";
	cout << "\n\n";
	goto Start;
}

string LowerCase(string text)
{
	for (int i = 0; i < (int)text.length(); i++) text[i] = tolower(text[i]);
	return text;
}