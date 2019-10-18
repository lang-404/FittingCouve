#include "MyForm.h"

using namespace FittingCurve;

[STAThreadAttribute]

int main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
}