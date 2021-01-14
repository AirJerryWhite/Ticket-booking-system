#include "struct.h"
#include "account_function.h"
#include "CityList_function.h"
#include "FlightList_Function.h"
#include "Route_function.h"
#include "SeatList_Function.h"
#include "Stack_function.h"
#include "str_function.h"
#include "Dest_function.h"
#include <Windows.h>
void menu_display(string path)
{
	char PATH[100],str[100];
	string2char(PATH, &path);

	FILE* fp;
	fopen_s(&fp, PATH, "r");
	while (fgets(str, 100, fp))
	{
		printf("%s", str);
	}
}
void menu(int mode)
{
}
#pragma once
