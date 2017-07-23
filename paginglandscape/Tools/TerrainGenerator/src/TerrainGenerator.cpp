// TerrainGenerator.cpp : main project file.
#include "BaseMenu.h"

using namespace TerrainGenerator;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew TerrainGenerator::BaseMenu());
	return 0;
}
