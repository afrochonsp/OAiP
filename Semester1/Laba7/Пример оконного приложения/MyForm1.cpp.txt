#include "MyForm1.h"
#include <Windows.h>

System::Void Variant1::MyForm1::MyForm1_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox1->Text = passedListBox->SelectedItem->ToString();
}

System::Void Variant1::MyForm1::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	passedListBox->Items[passedListBox->SelectedIndex] = textBox1->Text;
	Close();
}
