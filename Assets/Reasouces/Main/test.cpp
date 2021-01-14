#include "system.h"
#include "transmform_function.h"
int main()
{
	string path;
	char2string(&path, "Menu.dat");
	menu_display(path);
}