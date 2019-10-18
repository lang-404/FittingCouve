#pragma once

namespace FittingCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm ժҪ
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
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
		/// ����������������
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void);
#pragma endregion

	private: System::Void randomCreate_Click(System::Object^  sender, System::EventArgs^  e);// ���������

	private: System::Void FittingCouve_Click(System::Object^  sender, System::EventArgs^  e);// ��϶���ʽ����
	private: System::Void matPoint_CheckedChanged(System::Object^  sender, System::EventArgs^  e);// ɢ��ͼ��ʾ
	private: System::Void matCouve_CheckedChanged(System::Object^  sender, System::EventArgs^  e);// �������ͼ��ʾ
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);// ��ʱ��
	};
}
