#include "MyForm.h"
#include <Windows.h>
#include <cmath>

using namespace Variant1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
}

int Factorial(int);
float Y(float, float);
float S(float, float);
float DistanceYS(float, float);
void Out_Rez(float(*function)(float, float), float, float, float, float, TextBox ^ textBox);

System::Void Variant1::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	float b, n, h, x;
	x = (float)Convert::ToDouble(textBox1->Text);
	b = (float)Convert::ToDouble(textBox2->Text);
	n = (float)Convert::ToDouble(textBox3->Text);
	h = (float)Convert::ToDouble(textBox4->Text);
	float(*function)(float, float) = radioButton1->Checked ? Y : radioButton2->Checked ? S : DistanceYS;
	Out_Rez(function, x, b, h, n, textBox5);
}

System::Void Variant1::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox5->Text = "";
}

void Out_Rez(float(*f)(float, float), float x, float b, float h, float n, TextBox ^ textBox)
{
	for (int c = (int)floor(abs(b - x) / h); c >= 0; c--, x += h * (1 - 2 * (x > b)))
		textBox->Text += "x = " + x + "\r\n" + (f == Y ? "Y(x)" : f == S ? "S(x)" : "|Y(x) - S(x)|") + " = " + f(x, n) + "\r\n";
}

int Factorial(int n)
{
	int f = 1;
	for (int i = 1; i <= n; i++) f *= i;
	return f;
}

float Y(float x, float n)
{
	return sin(x);
}

float S(float x, float n)
{
	float s = 0;
	for (int k = 0; k <= n; k++) s += pow(-1.0f, k) * pow(x, 2 * k + 1) / Factorial(2 * k + 1);
	return s;
}

float DistanceYS(float x, float n)
{
	return abs(Y(x, n) - S(x, n));
}
