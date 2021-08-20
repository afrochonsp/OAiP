#pragma once

namespace Variant1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBox1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(70, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите строки";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(105, 216);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Ответ:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 178);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 35);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Пуск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"10110 101101 11 010 110", L"1101 10101 1011 01111 10 101",
					L"01010 100 01011 10101 0010 11 010"
			});
			this->listBox1->Location = System::Drawing::Point(12, 36);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(260, 95);
			this->listBox1->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 137);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 35);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Добавить строку";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(147, 137);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 35);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Удалить строку";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(147, 178);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(125, 35);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Close";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 246);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Лабораторная 7";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void listBox1_OnMouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void listBox1_OnMouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
};
}
