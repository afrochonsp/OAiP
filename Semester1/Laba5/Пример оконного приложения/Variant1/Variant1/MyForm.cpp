#include "MyForm.h"
#include <Windows.h>

using namespace Variant1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
}

int size;

System::Void Variant1::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	button1_Click(sender, e);
}

System::Void Variant1::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	size = Convert::ToInt32(textBox1->Text);
	for (int i = abs(size - dataGridView1->ColumnCount); i > 0; i--)
	{
		if (size > dataGridView1->ColumnCount)
		{
			DataGridViewTextBoxColumn ^ column = gcnew DataGridViewTextBoxColumn;
			column->SortMode = DataGridViewColumnSortMode::NotSortable;
			column->MaxInputLength = 2;
			column->Width = 30;
			dataGridView1->Columns->Add(column);
			if (dataGridView1->RowCount == 0) dataGridView1->Rows->Add(1);
			dataGridView1->Rows[0]->Cells[dataGridView1->ColumnCount - 1]->Value = 0;
		}
		else dataGridView1->Columns->RemoveAt(dataGridView1->ColumnCount - 1);
	}
}

System::Void Variant1::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int result = 0, min = 0, max = 0;
	int array[100];
	for (int i = 0; i < size; i++) array[i] = Convert::ToInt32(dataGridView1->Rows[0]->Cells[i]->Value);
	for (int i = 0; i < size; i++)
	{
		if (array[i] < array[min]) min = i;
		if (array[i] > array[max]) max = i;
	}
	if (abs(max - min) > 1)
	{
		result = 1;
		for (int i = min + 1 - 2 * (max < min); i != max; max > min ? i++ : i--) result *= array[i];
	}
	label2->Text = Convert::ToString("?????: " + result);
}
