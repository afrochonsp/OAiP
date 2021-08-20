#include <iostream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
Start:
	int round = 0, square = 0, curly = 0, angle = 0;
	string text;
	cout << "Введите строку\n";
	getline(cin, text);
	for (int i = 0; i < (int)text.length(); i++)
	{
		if (text[i] == '(' || text[i] == ')') round++;
		if (text[i] == '[' || text[i] == ']') square++;
		if (text[i] == '{' || text[i] == '}') curly++;
		if (text[i] == '<' || text[i] == '>') angle++;
	}
	cout << "Ответ: " << round << " круглых, " << square << " квадратных, " << curly << " фигурных, " << angle << " угловых\n\n";
	goto Start;
}