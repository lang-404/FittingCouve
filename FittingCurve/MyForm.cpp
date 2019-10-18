#include "MyForm.h"
#include<ctime> 
#include<iostream>
#include<cstdlib>
#include<vector>
#include<opencv2\opencv.hpp>

namespace FittingCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace cv;

	MyForm::MyForm(void)
	{
		InitializeComponent();
		timer1->Enabled = true;

	}
	MyForm::~MyForm()
	{
		timer1->Enabled = false;
		if (components)
		{
			delete components;
		}
	}

	vector<Point2i> points;
	vector<Point2i> couvePoints;
	Mat matRead;
	// 获取散列分布点
	System::Void MyForm::randomCreate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// 读取图片
		Mat matColor,matValue;
		System::Windows::Forms::OpenFileDialog ^ ofd01;
		ofd01 = (gcnew System::Windows::Forms::OpenFileDialog());
		ofd01->InitialDirectory = System::Windows::Forms::Application::StartupPath;
		ofd01->FileName = "";
		if (ofd01->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			MessageBox::Show("没有读入图片");
			return;
		}

		matRead = imread((char*)(void*)Marshal::StringToHGlobalAnsi(ofd01->FileName), 1);
		// 灰度化，二值化
		cvtColor(matRead,matColor,CV_BGR2GRAY);

		threshold(matColor,matValue,20,255,THRESH_BINARY);
		
		for (int i = 0; i < matValue.cols; i++)
		{
			for (int j = 0; j < matValue.rows; j++)
			{
				int k = matValue.at<uchar>(j, i);
				if (k > 0)
				{
					points.push_back(Point2i(i, j));
				}

			}
		}
		MessageBox::Show("散列数存储完成！");
	}
	
	// 求多项式系数
	void polynomial_curve_fit(vector<Point2i> key_point, int n, Mat& A)
	{
		// 求系数矩阵  X* A = Y
		// 构造矩阵X
		int i, j, k;
		int N = key_point.size();
		// 构造矩阵X
		Mat X = Mat::zeros(n + 1, n + 1, CV_64FC1);
		for (i = 0; i < n + 1; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				for (k = 0; k < N; k++)
				{
					X.at<double>(i, j) = X.at<double>(i, j) + std::pow(key_point[k].x, i + j);
				}
			}
		}
		// 构造矩阵Y
		Mat Y = Mat::zeros(n + 1, 1, CV_64FC1);
		for (i = 0; i < n + 1; i++)
		{
			for (k = 0; k < N; k++)
			{
				Y.at<double>(i, 0) = Y.at<double>(i, 0) + std::pow(key_point[k].x, i)*key_point[k].y;
			}
		}

		A = Mat::zeros(n + 1, 1, CV_64FC1);
		// 求系数矩阵A
		solve(X, Y, A, DECOMP_LU);
	}

	
	// 拟合多项式曲线
	System::Void MyForm::FittingCouve_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// 获取拟合多项式次数
		int n=2;
		Mat A;
		couvePoints.clear();
		vector<Point2i>().swap(couvePoints);
		int imin = points[0].x, imax = points[points.size()-1].x;
		try 
		{
			n = int::Parse(tbnumber->Text);
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show(e->Message);
		}

		polynomial_curve_fit(points, n, A);// 调用函数 获取系数矩阵
		System::String^ mess = "y=";
		System::String^x = "*x^";
		for (int i = A.rows-1; i >=0; i--)
		{
			if (i != 0 && (int)A.at<double>(i, 0)>=0)
			{
				mess += A.at<double>(i, 0).ToString("f6") + x + (i).ToString() + "+";
			}
			else
			{
				mess += A.at<double>(i, 0).ToString("f6") + x + (i).ToString();
			}
		}
		tbResult->Text = mess;
		mess = "";
		double y;
		for (int i = 0; i < points.size(); i++)
		{
			if (imin > points[i].x)
			{
				imin = points[i].x;
			}
			if (imax < points[i].x)
			{
				imax = points[i].x;
			}
		}
		for (int x = imin; x < imax+1; x++)
		{
			y = 0;
			for (int i = 0; i < n + 1; i++)
			{
				y += A.at<double>(i, 0)*std::pow(x, i);
			}
			if (y < 0)
			{
				y = 0;
			}
			couvePoints.push_back(cv::Point(x, y));// 存储拟合曲线上的点
		}
	}


	// 散点图显示
	System::Void MyForm::matPoint_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		Mat matPointShow = Mat::zeros(matRead.size(), matRead.type());
		if (matPoint->Checked == true)
		{
			for (int i = 0; i < points.size(); i++)
			{
				matPointShow.at<Vec3b>(points[i])[0] = 255;
			}
			namedWindow("散点图", 1);
			imshow("散点图",matPointShow);
			
		}
		else
		{
			destroyWindow("散点图");
			matPointShow.release();
			return;
		}
	}

	// 拟合曲线图
	System::Void MyForm::matCouve_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		Mat matCouveShow = Mat::zeros(matRead.size(), matRead.type());
		if (couvePoints.size() == 0)
		{
			return;
		}
		if (matCouve->Checked == true)
		{
			for (int i = 0; i < couvePoints.size(); i++)
			{
				matCouveShow.at<Vec3b>(couvePoints[i])[2] = 255;
			}
			for (int i = 0; i < points.size(); i++)
			{
				matCouveShow.at<Vec3b>(points[i])[0] = 255;
				matCouveShow.at<Vec3b>(points[i])[1] = 255;
			}
			namedWindow("曲线图", 1);
			imshow("曲线图", matCouveShow);

		}
		else
		{
			destroyWindow("曲线图");
			matCouveShow.release();
			return;
		}
	}

	// 计时器
	System::Void MyForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (points.size() == 0)
		{
			matPoint->Enabled = false;
		}
		else
		{
			matPoint->Enabled = true;
		}
		if (couvePoints.size() == 0)
		{
			matCouve->Enabled = false;
		}
		else
		{
			matCouve->Enabled = true;
		}
	}
}