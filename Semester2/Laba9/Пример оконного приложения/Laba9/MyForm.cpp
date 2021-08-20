#include "MyForm.h" 
#include <Windows.h> 
#include <cmath>

using namespace Laba9;

double a = -2, b = 2, h = 0.01, eps = 0.001;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

double F(double x)
{
	return 4 * x - 7 * sin(x);
}

System::Void Laba9::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	chart1->Series[0]->Points->Clear();
	textBox2->Text = Convert::ToString(a);
	textBox3->Text = Convert::ToString(b);
	textBox4->Text = Convert::ToString(h);
	textBox5->Text = Convert::ToString(eps);
	for (double x = a; x <= b; x += h) chart1->Series[0]->Points->AddXY(x, F(x));
}

double FindRoot(double x0, double epsilon, double q)
{
	double x1 = x0 - F(x0) * q / (F(x0) - F(x0 - q));
	while (fabs(x1 - x0) > eps)
	{
		x0 = x1;
		x1 = x1 - F(x1) * q / (F(x1) - F(x1 - q));
	}
	return x0;
}

System::Void Laba9::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try
	{
		a = Convert::ToDouble(textBox2->Text);
		b = Convert::ToDouble(textBox3->Text);
		h = Convert::ToDouble(textBox4->Text);
		eps = Convert::ToDouble(textBox5->Text);
	}
	catch (...)
	{
		MessageBox::Show("Введите корректные значения");
		return;
	}
	int n = 0;
	chart1->Series[0]->Points->Clear();
	for (double x = a; x <= b; x += h) chart1->Series[0]->Points->AddXY(x, F(x));
	textBox1->Text += "При параметрах:\r\na = " + Convert::ToString(a) + "\r\nb = " + Convert::ToString(b) + "\r\nh = " + Convert::ToString(h) + "\r\ne = " + Convert::ToString(eps) + "\r\n";
	for (double x = a; x <= b; x += h)
	{
		if (F(x) * F(x + h) < 0)
		{
			n++;
			textBox1->Text += "x" + Convert::ToString(n) + " = " + Convert::ToString(FindRoot(x + h, eps, h)) + "\r\n";
		}
	}
	if (n == 0) textBox1->Text += "Корней нет" + "\r\n";
}

System::Void Laba9::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox1->Text = "";
}
