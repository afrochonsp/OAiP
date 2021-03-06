#include "MyForm.h"
#include "MyForm1.h"
#include <Windows.h>

using namespace Variant1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
}

System::Void Variant1::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	listBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Variant1::MyForm::listBox1_OnMouseDoubleClick);
	listBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Variant1::MyForm::listBox1_OnMouseClick);
}

System::Void Variant1::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int groupCount = 0, groupSize = 0;
	if (listBox1->SelectedItem != nullptr)
	{
		String ^ text = listBox1->SelectedItem->ToString();
		for (int i = 0; i <= (int)text->Length; i++)
		{
			if (i < (int)text->Length && (text[i] == '0' || text[i] == '1')) groupSize++;
			else
			{
				if (groupSize == 5) groupCount++;
				groupSize = 0;
			}
		}
	}
	label2->Text = Convert::ToString("?????: " + groupCount);
}

System::Void Variant1::MyForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (listBox1->Items->Count < 9) listBox1->Items->Add("????? ??????");
	listBox1->SetSelected(listBox1->Items->Count - 1, true);
}

System::Void Variant1::MyForm::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (listBox1->Items->Count > 0 && listBox1->SelectedItem != nullptr)
	{
		int lastIndex = listBox1->SelectedIndex;
		listBox1->Items->RemoveAt(listBox1->SelectedIndex);
		if (listBox1->Items->Count > 0) listBox1->SetSelected(lastIndex == listBox1->Items->Count ? lastIndex - 1 : lastIndex, true);
	}
}

System::Void Variant1::MyForm::button4_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Close();
}

void Variant1::MyForm::listBox1_OnMouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	if (listBox1->IndexFromPoint(e->Location) == ListBox::NoMatches && listBox1->SelectedItem != nullptr) listBox1->SetSelected(0, false);
}

void Variant1::MyForm::listBox1_OnMouseDoubleClick(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	int index = listBox1->IndexFromPoint(e->Location);
	if (listBox1->IndexFromPoint(e->Location) == ListBox::NoMatches) return;
	MyForm1 ^ myForm1 = gcnew MyForm1(listBox1);
	myForm1->ShowDialog();
}