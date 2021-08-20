#include "MyForm.h"
#include <Windows.h>

using namespace Variant1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
}

int n, m;

System::Void Variant1::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	button1_Click(sender, e);
	dataGridView1->TopLeftHeaderCell->Value = "�������";
}

System::Void Variant1::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	n = Convert::ToInt32(textBox1->Text);
	m = Convert::ToInt32(textBox2->Text);
	if (n == 0)
	{
		dataGridView1->ColumnCount = 0;
		return;
	}
	for (int i = abs(n - dataGridView1->RowCount); i > 0; i--)
	{
		if (n > dataGridView1->RowCount)
		{
			DataGridViewTextBoxColumn ^ column = gcnew DataGridViewTextBoxColumn;
			column->Name = Convert::ToString("j=" + (dataGridView1->ColumnCount + 1));
			column->SortMode = DataGridViewColumnSortMode::NotSortable;
			column->MaxInputLength = 2;
			column->Width = 30;
			dataGridView1->Columns->Add(column);
			dataGridView1->Rows->Add(1);
			dataGridView1->Rows[dataGridView1->RowCount - 1]->HeaderCell->Value = Convert::ToString("i=" + (dataGridView1->RowCount));
		}
		else dataGridView1->Rows->RemoveAt(dataGridView1->RowCount - 1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = abs(m - dataGridView1->ColumnCount); j > 0; j--)
		{
			if (m > dataGridView1->ColumnCount)
			{
				DataGridViewTextBoxColumn ^ column = gcnew DataGridViewTextBoxColumn;
				column->Name = Convert::ToString("j=" + (dataGridView1->ColumnCount + 1));
				column->SortMode = DataGridViewColumnSortMode::NotSortable;
				column->MaxInputLength = 2;
				column->Width = 30;
				dataGridView1->Columns->Add(column);
			}
			else dataGridView1->Columns->RemoveAt(dataGridView1->ColumnCount - 1);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (Convert::ToString(dataGridView1->Rows[i]->Cells[j]->Value) == "") dataGridView1->Rows[i]->Cells[j]->Value = 0;
}

System::Void Variant1::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	dataGridView2->ColumnCount = 0;
	if (n == 0) return;
	for (int j = 0; j < m; j++)
	{
		int b = 0;
		for (int i = 0; i < n; i++) if (Convert::ToInt32(dataGridView1->Rows[i]->Cells[j]->Value) != 0) b = 1;
		DataGridViewTextBoxColumn ^ column = gcnew DataGridViewTextBoxColumn;
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
		column->MaxInputLength = 2;
		column->Width = 30;
		dataGridView2->Columns->Add(column);
		if (dataGridView2->RowCount == 0) dataGridView2->Rows->Add(1);
		dataGridView2->Rows[0]->Cells[dataGridView2->ColumnCount - 1]->Value = b;
	}
}
