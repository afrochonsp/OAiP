#include "MyForm.h"
#include <Windows.h>
#include <ctime>
#include <cmath>

using namespace Laba8;

Point startLocation;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
}

System::Void Laba8::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	chart1->ChartAreas[0]->AxisY->Minimum = -1.5;
	chart1->ChartAreas[0]->AxisY->Maximum = 2;
	chart1->ChartAreas[0]->AxisX->Minimum = -2.5;
	chart1->ChartAreas[0]->AxisX->Maximum = 2.5;
	chart2->ChartAreas[0]->AxisX->Minimum = -10;
	chart2->ChartAreas[0]->AxisX->Maximum = 10;
	startLocation = pictureBox2->Location;
}

System::Void Laba8::MyForm::MyForm_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	Graphics ^g1 = pictureBox2->CreateGraphics();
	Graphics ^g2 = pictureBox3->CreateGraphics();
	Drawing::Rectangle rect1 = Drawing::Rectangle(0, 0, 100, 20);
	Drawing::Rectangle rect2 = Drawing::Rectangle(0, 20, 100, 40);
	Drawing::Rectangle rect3 = Drawing::Rectangle(0, 40, 100, 60);
	Drawing::Rectangle rect4 = Drawing::Rectangle(0, 0, 100, 30);
	Drawing::Rectangle rect5 = Drawing::Rectangle(0, 30, 100, 60);
	Brush ^brush1 = gcnew SolidBrush(Color::White);
	Brush ^brush2 = gcnew SolidBrush(Color::Blue);
	Brush ^brush3 = gcnew SolidBrush(Color::Red);
	Brush ^brush4 = gcnew SolidBrush(Color::Yellow);
	g1->FillRectangle(brush1, rect1);
	g1->FillRectangle(brush2, rect2);
	g1->FillRectangle(brush3, rect3);
	g2->FillRectangle(brush2, rect4);
	g2->FillRectangle(brush4, rect5);
}

System::Void Laba8::MyForm::timer1_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	double a = -10, b = 10, h = 0.1;
	chart2->Series[0]->Points->Clear();
	for (double x = a; x <= b; x += h)
	{
		double y = pow(sin(x - clock() / 300.0 + Math::PI / 4), 8);
		chart2->Series[0]->Points->AddXY(x, y);
	}
	chart1->Series[0]->Points->Clear();
	a = -1.5, b = 1.5, h = 0.01;
	for (double x = a; x <= b; x += h)
	{
		double y1 = (2.0 * sqrt(abs(x)) + sqrt(-4.0 * x * x + 4.0 + 2.0 * pow(sin(clock() / 300.0), 16.0))) / 2.0;
		double y2 = (2.0 * sqrt(abs(x)) - sqrt(-4.0 * x * x + 4.0 + 2.0 * pow(sin(clock() / 300.0), 16.0))) / 2.0;
		chart1->Series[0]->Points->AddXY(x, y1);
		chart1->Series[0]->Points->AddXY(x, y2);
	}
	pictureBox2->Location = Point(startLocation.X, startLocation.Y - pow(sin(clock() / 250.0), 8) * 30);
}
