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
void menu()
{

	CityList* cache;
	cache = CityList_init();
	Account* account;
	account = account_init();
	account = account_create(account, cache);
	//Account

	FlightList* flightlist;
	flightlist = FlightList_init();
	flightlist = FlightList_create(flightlist);
	//FlightList

	CityList* citylist;
	citylist = CityList_init();
	citylist = CityList_create(citylist);
	Route* route;
	route = Route_init();
	route = Route_create(route, citylist, flightlist);
	//FLightRoute
	//start

	string menu, Accountlogin_menu, exit;
	char2string(&menu, "Menu.dat");
	char2string(&Accountlogin_menu, "AccountLogin_menu.dat");
	char2string(&exit, "exit.dat");
	//path
	int mode;
	int OP_level = -1;
	while (1)
	{
		menu_display(menu);
		scanf_s("%d", &mode);
		switch (mode)
		{
		case(0):
		{
			system("cls");
			menu_display(exit);
			break;
		}
		case(1):
		{
			system("cls");
			menu_display(Accountlogin_menu);

		}
		default:break;
		}
	}
}
#pragma once
