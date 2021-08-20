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

System::Void Variant1::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	float a, b, n, h, x, k, y, s;
	a = (float)Convert::ToDouble(textBox1->Text);
	b = (float)Convert::ToDouble(textBox2->Text);
	n = (float)Convert::ToDouble(textBox3->Text);
	h = (float)Convert::ToDouble(textBox4->Text);
	x = a;
	for (int c = (int)floor(abs(b - a) / h); c >= 0; c--, x += h * (1 - 2 * (x > b)))
	{
		y = sin(x);
		for (k = 0, s = 0; k <= n; k++)
		{
			int factorial = 1;
			for (int i = 1; i <= 2 * k + 1 || i == 1; i++) factorial *= i;
			s += pow(-1.0f, k) * pow(x, 2 * k + 1) / factorial;
		}
		textBox5->Text += "x = " + Convert::ToString(x) + "\r\n";
		textBox5->Text += "Y(x) = " + Convert::ToString(y) + "\r\n";
		textBox5->Text += "S(x) = " + Convert::ToString(s) + "\r\n";
		textBox5->Text += "|Y(x) - S(x)| = " + Convert::ToString(abs(y - s)) + "\r\n";
	}
}

System::Void Variant1::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox5->Text = "";
}
