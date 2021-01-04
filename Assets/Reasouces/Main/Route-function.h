#include "struct.h"
#include "str_function.h"
#include "Dest_function.h"
#include "CityList_function.h"
#include "transmform_function.h"
Route* Route_init()
{
	Route* p;
	p = (Route*)malloc(sizeof(Route));
	p->Next = NULL;
	return p;
}
void Route_refresh(Route* p)
{
	int i = 0;
	do
	{
		p->No = i;
		i++;
		p = p->Next;
	} while (p);
}
Route* Route_create(Route* head, CityList* citylist)
{
	CityList* q;
	Route* p, * add;
	string origin, city, FlightNumber, date, time;
	int money, seat, line, count;
	char str[100], cache[100];
	string string;
	string = str_init();
	p = (Route*)malloc(sizeof(Route));
	p->Next = NULL;
	FILE* fp;

	fopen_s(&fp, "CityList.dat", "r");
	fgets(str, 5, fp);
	fclose(fp);
	line = char2int(str);
	if (line != 0)
	{
		q = citylist;
		do
		{
			Route_add(head, q->city);
			q = q->next;
		} while (p);
		fopen_s(&fp, "Route.dat", "r");
		if (fp)
		{
			fgets(str, 5, fp);
			line = char2int(str);
			for (int n = 0; n < line; n++)
			{
				count = 0;
				fgets(str, 100, fp);
				for (int m = 0; m < 100; m++)
				{
					if (count == 6)	break;
					count = 0;
					if (str[m] != ' ')
					{
						cache[n] = str[m];
						n++;
					}
					else
					{
						n = 0;
						if ((str[m - 1] != ' ') && (str[m] == ' '))
						{
							switch (count)
							{
							case(0):
							{
								char2string(&string, str);
								str_copy(&origin, string);
								count++;
								add = Route_find(head, origin);
								if (!add)
								{
									Route_add(head, origin);
									CityList_add(citylist, origin);
									add = Route_find(head, origin);
								}
								break;
							}
							case(1):
							{
								char2string(&string, str);
								str_copy(&city, string);
								count++;
								break;
							}
							case(2):
							{
								char2string(&string, str);
								str_copy(&FlightNumber, string);
								count++;
								break;
							}
							case(3):
							{
								char2string(&string, str);
								str_copy(&date, string);
								count++;
								break;
							}
							case(4):
							{
								char2string(&string, str);
								str_copy(&time, string);
								count++;
								break;
							}
							case(5):
							{
								money = char2int(str);
								count++;
								break;
							}
							case(6):
							{
								seat = char2int(str);
								count++;
								break;
							}
							case(7):
							{
								Dest_add(add->Destination, origin, city, FlightNumber, date, time, money, seat);
								count++;
								break;
							}
							default:
								break;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		fopen_s(&fp, "Route.dat", "r");
		if (fp)
		{
			fgets(str, 5, fp);
			line = char2int(str);
			for (int n = 0; n < line; n++)
			{
				count = 0;
				fgets(str, 100, fp);
				for (int m = 0; m < 100; m++)
				{
					if (count == 6)	break;
					count = 0;
					if (str[m] != ' ')
					{
						cache[n] = str[m];
						n++;
					}
					else
					{
						n = 0;
						if ((str[m - 1] != ' ') && (str[m] == ' '))
						{
							switch (count)
							{
							case(0):
							{
								char2string(&string, str);
								str_copy(&origin, string);
								count++;
								Route_add(head, origin);
								CityList_add(citylist, origin);
								add = Route_find(head, origin);
								break;
							}
							case(1):
							{
								char2string(&string, str);
								str_copy(&city, string);
								count++;
								break;
							}
							case(2):
							{
								char2string(&string, str);
								str_copy(&FlightNumber, string);
								count++;
								break;
							}
							case(3):
							{
								char2string(&string, str);
								str_copy(&date, string);
								count++;
								break;
							}
							case(4):
							{
								char2string(&string, str);
								str_copy(&time, string);
								count++;
								break;
							}
							case(5):
							{
								money = char2int(str);
								count++;
								break;
							}
							case(6):
							{
								seat = char2int(str);
								count++;
								break;
							}
							case(7):
							{
								Dest_add(add->Destination, origin, city, FlightNumber, date, time, money, seat);
								count++;
								break;
							}
							default:
								break;
							}
						}
					}
				}
			}
		}
	}
	fclose(fp);
	CityList_save(citylist);
}
Route* Route_add(Route* head, string city)
{
	Route* p;
	p = head;
	do
	{
		p = p->Next;
	} while (p);
	if (head->city.length == 0)	str_copy(&head->city, city);
	else str_copy(&p->city, city);
	return head;
}
void Route_transfer(Route* head, string origin, string transfer, string city, string FlightNumber, string date, string transfer_date, string time, string transfer_time, int money_origin2city, int money_origin2transfer, int money_transfer2city, int seat, int transfer_seat)
{
	Route* p;
	p = Route_find(head, origin);
	Dest_add(p->Destination, origin, city, FlightNumber, date, time, money_origin2city, seat);
	Dest_add(p->Destination, origin, transfer, FlightNumber, date, time, money_origin2transfer, seat);
	Dest_add(p->Destination, transfer, city, FlightNumber, transfer_date, transfer_time, money_transfer2city, transfer_seat);
}
Route* Route_find(Route* head, string city)
{
	Route* p;
	p = head;
	do
	{
		if (str_compare(p->city, city))	return p;
		else	p = p->Next;
	} while (p);
}
#pragma once
