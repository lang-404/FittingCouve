#pragma once

namespace FittingCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MyForm();
	private: System::Windows::Forms::Button^  randomCreate;
	protected:
	private: System::Windows::Forms::Button^  FittingCouve;
	private: System::Windows::Forms::Label^  lblnumber;
	private: System::Windows::Forms::TextBox^  tbnumber;
	private: System::Windows::Forms::TextBox^  tbResult;
	private: System::Windows::Forms::CheckBox^  matPoint;
	private: System::Windows::Forms::CheckBox^  matCouve;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void);
#pragma endregion

	private: System::Void randomCreate_Click(System::Object^  sender, System::EventArgs^  e);// 生成随机数

	private: System::Void FittingCouve_Click(System::Object^  sender, System::EventArgs^  e);// 拟合多项式曲线
	private: System::Void matPoint_CheckedChanged(System::Object^  sender, System::EventArgs^  e);// 散点图显示
	private: System::Void matCouve_CheckedChanged(System::Object^  sender, System::EventArgs^  e);// 拟合曲线图显示
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);// 计时器
	};
}
