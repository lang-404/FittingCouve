#include "MyForm.h"

namespace FittingCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void MyForm::InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		this->randomCreate = (gcnew System::Windows::Forms::Button());
		this->FittingCouve = (gcnew System::Windows::Forms::Button());
		this->lblnumber = (gcnew System::Windows::Forms::Label());
		this->tbnumber = (gcnew System::Windows::Forms::TextBox());
		this->tbResult = (gcnew System::Windows::Forms::TextBox());
		this->matPoint = (gcnew System::Windows::Forms::CheckBox());
		this->matCouve = (gcnew System::Windows::Forms::CheckBox());
		this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		// 
		// randomCreate
		// 
		this->randomCreate->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->randomCreate->Location = System::Drawing::Point(12, 22);
		this->randomCreate->Name = L"randomCreate";
		this->randomCreate->Size = System::Drawing::Size(279, 44);
		this->randomCreate->TabIndex = 0;
		this->randomCreate->Text = L"获取随机点";
		this->randomCreate->UseVisualStyleBackColor = true;
		this->randomCreate->Click += gcnew System::EventHandler(this, &MyForm::randomCreate_Click);
		// 
		// FittingCouve
		// 
		this->FittingCouve->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->FittingCouve->Location = System::Drawing::Point(12, 169);
		this->FittingCouve->Name = L"FittingCouve";
		this->FittingCouve->Size = System::Drawing::Size(279, 41);
		this->FittingCouve->TabIndex = 1;
		this->FittingCouve->Text = L"拟合多项式曲线";
		this->FittingCouve->UseVisualStyleBackColor = true;
		this->FittingCouve->Click += gcnew System::EventHandler(this, &MyForm::FittingCouve_Click);
		// 
		// lblnumber
		// 
		this->lblnumber->AutoSize = true;
		this->lblnumber->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->lblnumber->Location = System::Drawing::Point(12, 106);
		this->lblnumber->Name = L"lblnumber";
		this->lblnumber->Size = System::Drawing::Size(142, 19);
		this->lblnumber->TabIndex = 2;
		this->lblnumber->Text = L"拟合多项式次数";
		// 
		// tbnumber
		// 
		this->tbnumber->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->tbnumber->Location = System::Drawing::Point(240, 106);
		this->tbnumber->Name = L"tbnumber";
		this->tbnumber->Size = System::Drawing::Size(51, 28);
		this->tbnumber->TabIndex = 3;
		// 
		// tbResult
		// 
		this->tbResult->Enabled = false;
		this->tbResult->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->tbResult->Location = System::Drawing::Point(12, 264);
		this->tbResult->Name = L"tbResult";
		this->tbResult->Size = System::Drawing::Size(594, 28);
		this->tbResult->TabIndex = 4;
		// 
		// matPoint
		// 
		this->matPoint->AutoSize = true;
		this->matPoint->Enabled = false;
		this->matPoint->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->matPoint->Location = System::Drawing::Point(394, 34);
		this->matPoint->Name = L"matPoint";
		this->matPoint->Size = System::Drawing::Size(126, 23);
		this->matPoint->TabIndex = 5;
		this->matPoint->Text = L"散点图显示";
		this->matPoint->UseVisualStyleBackColor = true;
		this->matPoint->CheckedChanged += gcnew System::EventHandler(this, &MyForm::matPoint_CheckedChanged);
		// 
		// matCouve
		// 
		this->matCouve->AutoSize = true;
		this->matCouve->Enabled = false;
		this->matCouve->Font = (gcnew System::Drawing::Font(L"宋体", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->matCouve->Location = System::Drawing::Point(394, 179);
		this->matCouve->Name = L"matCouve";
		this->matCouve->Size = System::Drawing::Size(164, 23);
		this->matCouve->TabIndex = 6;
		this->matCouve->Text = L"拟合曲线图显示";
		this->matCouve->UseVisualStyleBackColor = true;
		this->matCouve->CheckedChanged += gcnew System::EventHandler(this, &MyForm::matCouve_CheckedChanged);
		// 
		// timer1
		// 
		this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(764, 329);
		this->Controls->Add(this->matCouve);
		this->Controls->Add(this->matPoint);
		this->Controls->Add(this->tbResult);
		this->Controls->Add(this->tbnumber);
		this->Controls->Add(this->lblnumber);
		this->Controls->Add(this->FittingCouve);
		this->Controls->Add(this->randomCreate);
		this->Name = L"MyForm";
		this->Text = L"MyForm";
		this->ResumeLayout(false);
		this->PerformLayout();

	}

}