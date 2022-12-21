#include "PrincipalScheme.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	IDZ_OOP::PrincipalScheme form;
	Application::Run(% form);
}
