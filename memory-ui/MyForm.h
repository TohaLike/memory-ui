#pragma once
#include <iostream>
#include <Windows.h>
#include "Memory.h"
#include <msclr/marshal_cppstd.h>

namespace memoryui {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			memory = new Memory(100);
			InitializeMemoryGridView();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete memory;
		}
	private: Memory* memory;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnWrite;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnLoadFile;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnDeleteAll;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnWrite = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnLoadFile = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnDeleteAll = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 130);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(359, 324);
			this->dataGridView1->TabIndex = 0;
			// 
			// btnWrite
			// 
			this->btnWrite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnWrite->Location = System::Drawing::Point(12, 460);
			this->btnWrite->Name = L"btnWrite";
			this->btnWrite->Size = System::Drawing::Size(100, 32);
			this->btnWrite->TabIndex = 1;
			this->btnWrite->Text = L"Записать";
			this->btnWrite->UseVisualStyleBackColor = true;
			this->btnWrite->Click += gcnew System::EventHandler(this, &MyForm::btnWrite_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDelete->Location = System::Drawing::Point(118, 460);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(100, 32);
			this->btnDelete->TabIndex = 2;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
			// 
			// btnLoadFile
			// 
			this->btnLoadFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnLoadFile->Location = System::Drawing::Point(224, 460);
			this->btnLoadFile->Name = L"btnLoadFile";
			this->btnLoadFile->Size = System::Drawing::Size(147, 32);
			this->btnLoadFile->TabIndex = 3;
			this->btnLoadFile->Text = L"Загрузить файл";
			this->btnLoadFile->UseVisualStyleBackColor = true;
			this->btnLoadFile->Click += gcnew System::EventHandler(this, &MyForm::btnLoadFile_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox1->Location = System::Drawing::Point(12, 43);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(766, 29);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->Location = System::Drawing::Point(7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 26);
			this->label1->TabIndex = 6;
			this->label1->Text = L"PC Memory";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox2->Location = System::Drawing::Point(12, 95);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(766, 29);
			this->textBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(10, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Данные";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(12, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Адрес";
			// 
			// btnDeleteAll
			// 
			this->btnDeleteAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDeleteAll->Location = System::Drawing::Point(377, 460);
			this->btnDeleteAll->Name = L"btnDeleteAll";
			this->btnDeleteAll->Size = System::Drawing::Size(131, 32);
			this->btnDeleteAll->TabIndex = 10;
			this->btnDeleteAll->Text = L"Удалить всё";
			this->btnDeleteAll->UseVisualStyleBackColor = true;
			this->btnDeleteAll->Click += gcnew System::EventHandler(this, &MyForm::btnDeleteAll_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(790, 504);
			this->Controls->Add(this->btnDeleteAll);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnLoadFile);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnWrite);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeMemoryGridView() {
			this->textBox1->Text = "0";
			this->textBox2->Text = "0";
			dataGridView1->ColumnCount = 2;
			dataGridView1->Columns[0]->Name = "Адрес";
			dataGridView1->Columns[1]->Name = "Ячейки";
			dataGridView1->Columns["Ячейки"]->Width = 199;
			DataGridViewCellStyle^ cellStyle = gcnew DataGridViewCellStyle();
			dataGridView1->RowCount = memory->getData().size();
			cellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			for each (DataGridViewColumn^ column in dataGridView1->Columns) {
				column->DefaultCellStyle = cellStyle;
				column->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
			}
			updateMemoryView();
		}

		void updateMemoryView() {
			auto data = memory->getData();
			for (size_t i = 0; i < data.size(); i++) {
				String^ addressHex = gcnew String(Memory::addressToHexadecimalString(i).c_str());
				dataGridView1->Rows[i]->Cells[0]->Value = addressHex;
				dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(Memory::byteToBinaryString(data[i]).c_str());
			}
		}

#pragma endregion
		private: System::Void btnWrite_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				size_t address = System::Convert::ToUInt32(textBox1->Text);
				int32_t value = System::Convert::ToInt32(textBox2->Text);
				memory->writeInt(address, value);
				updateMemoryView();
			}
			catch (FormatException^ ex) {
				MessageBox::Show("Ошибка формата ввода. Пожалуйста, введите корректные числовые значения.");
			}
		}

		private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			size_t address = System::Convert::ToUInt32(textBox1->Text);
			memory->clear(address);
			updateMemoryView();
		}

		private: System::Void btnLoadFile_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				size_t address = System::Convert::ToUInt32(textBox1->Text);
				std::string filename = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
				memory->writeFromFile(address, filename);
				updateMemoryView();
			}
		}

		private: System::Void btnDeleteAll_Click(System::Object^ sender, System::EventArgs^ e) {
			auto data = memory->getData();
			if (MessageBox::Show("Вы уверены????","",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == 
				System::Windows::Forms::DialogResult::Yes) {
				for (int i = 0; i < data.size(); i++) {
					memory->clear(i);
					updateMemoryView();
				}
			}
		}
	};
}
