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
	float x = (float)Convert::ToDouble(textBox1->Text);
	float y = (float)Convert::ToDouble(textBox2->Text);
	float z = (float)Convert::ToDouble(textBox3->Text);
	const float pi = atan(1) * 4;
	textBox4->Text += "??? x = " + x + "; " + "y = " + y + "; " + "z = " + z + "\r\n";
	textBox4->Text += "????????? = " + 2 * cos(x - pi / 6) * (1 + pow(z, 2) / (3 - pow(z, 2) / 5)) / (0.5 + pow(sin(y), 2)) + "\r\n";
}
