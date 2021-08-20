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
	float x, y, a, z, F, variant;
	a = (float)Convert::ToDouble(textBox1->Text);
	z = (float)Convert::ToDouble(textBox2->Text);
	variant = radioButton1->Checked ? 0 : radioButton2->Checked ? 1.0f : 2.0f;
	x = z < 1 ? pow(z, 2) : z + 1;
	F = variant == 0 ? 2 * x : variant == 1 ? pow(x, 2) : x / 3;
	y = a * log(1 + pow(x, 1.0f / 5.0f)) + pow(cos(F + 1), 2);
	textBox3->Text += "F(x) = " + (variant == 0 ? "2x" : variant == 1 ? "x^2" : "x/3") + " = " + F + "\r\n";
	textBox3->Text += "Y = " + Convert::ToString(y) + "\r\n";
}
