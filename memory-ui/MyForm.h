#pragma once
#include <iostream>
#include <Windows.h>
#include "Memory.h"
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>


namespace memoryui {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			memory = new Memory(100);
			InitializeMemoryGridView();
			InitializeChart();
			InitializeTimer();
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
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Panel^ memoryUsagePanel;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnWrite;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnLoadFile;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnDeleteAll;
	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	private: System::ComponentModel::IContainer^ components;

	private:

	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnWrite = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnLoadFile = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnDeleteAll = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 105);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(359, 349);
			this->dataGridView1->TabIndex = 0;
			// 
			// btnWrite
			// 
			this->btnWrite->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnWrite->Location = System::Drawing::Point(12, 460);
			this->btnWrite->Name = L"btnWrite";
			this->btnWrite->Size = System::Drawing::Size(100, 32);
			this->btnWrite->TabIndex = 1;
			this->btnWrite->Text = L"��������";
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
			this->btnDelete->Text = L"�������";
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
			this->btnLoadFile->Text = L"��������� ����";
			this->btnLoadFile->UseVisualStyleBackColor = true;
			this->btnLoadFile->Click += gcnew System::EventHandler(this, &MyForm::btnLoadFile_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox1->Location = System::Drawing::Point(12, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(359, 29);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox2->Location = System::Drawing::Point(12, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(359, 29);
			this->textBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(10, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(12, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"�����";
			// 
			// btnDeleteAll
			// 
			this->btnDeleteAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDeleteAll->Location = System::Drawing::Point(377, 460);
			this->btnDeleteAll->Name = L"btnDeleteAll";
			this->btnDeleteAll->Size = System::Drawing::Size(131, 32);
			this->btnDeleteAll->TabIndex = 10;
			this->btnDeleteAll->Text = L"������� ��";
			this->btnDeleteAll->UseVisualStyleBackColor = true;
			this->btnDeleteAll->Click += gcnew System::EventHandler(this, &MyForm::btnDeleteAll_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(377, 105);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(594, 349);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(983, 504);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->btnDeleteAll);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnLoadFile);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnWrite);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"PC Memory";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeMemoryGridView() {
			this->textBox1->Text = "0";
			this->textBox2->Text = "0";
			dataGridView1->ColumnCount = 2;
			dataGridView1->Columns[0]->Name = "������";
			dataGridView1->Columns[1]->Name = "������";
			dataGridView1->Columns["������"]->Width = 199;
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
			updateChart();
		}

		void InitializeTimer() {
			timer1 = gcnew Timer();
			timer1->Interval = 1000; // �������� 1 �������
			timer1->Tick += gcnew EventHandler(this, &MyForm::OnTimerTick);
			timer1->Start();
		}

		void OnTimerTick(Object^ sender, EventArgs^ e) {
			updateChart();
		}

		void InitializeChart() {
			chart1->Series->Clear();
			Series^ series = gcnew Series();
			series->ChartType = SeriesChartType::Line;
			chart1->Series->Add(series);
			chart1->ChartAreas[0]->AxisX->Title = "����� (�������)";
			chart1->ChartAreas[0]->AxisY->Title = "������������� ������";
			chart1->ChartAreas[0]->AxisY->Maximum = 256; // ������������ �������� ������������� ������
		}

		void updateChart() {
			Series^ series = chart1->Series[0];
			auto data = memory->getData();
			if (series->Points->Count > 60) { // ������������ ���������� ����� �� �������
				series->Points->RemoveAt(0);
			}
			int usage = 0;
			for (size_t i = 0; i < data.size(); i++) {
				if (data[i] != 0) {
					usage++;
				}
			}
			series->Points->AddY(usage);
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
				MessageBox::Show("������ ������� �����. ����������, ������� ���������� �������� ��������.");
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
			if (MessageBox::Show("�� �������????","",
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
