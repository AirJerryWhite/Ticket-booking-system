#include "struct.h"
#include "str_function.h"
#include "Dest_function.h"
#include "CityList_function.h"
#include "transmform_function.h"
#include "FlightList_Function.h"
Route* Route_init()
{
	Route* p;
	p = (Route*)malloc(sizeof(Route));
	p->city.length = 0;
	p->Destination = Dest_init();
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
Route* Route_create(Route* head, CityList* citylist,FlightList* flightlist)
{
	CityList* q;
	Route* p, * add;
	string origin, city, FlightNumber, date, time,SiteSize;
	int money, seat, line, count,m=0,x,y;
	char str[105], cache[100];
	string string,path;
	string = str_init();
	p = (Route*)malloc(sizeof(Route));
	add = Route_init();
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
			head=Route_add_city(head, q->city);
			q = q->next;
		} while (p);
		fopen_s(&fp, "Route.dat", "r");
		if (fp)
		{
			fgets(str, 5, fp);
			line = char2int(str);
			for (int i = 0; i < line; i++)
			{
				count = 0;
				fgets(str, 100, fp);
				for (int n = 0; n < 100; n++)
				{
					if (count == 7)	break;
					count = 0;
					if ((str[n] != ' ') && (str[n] != '\n'))
					{
						cache[m] = str[n];
						m++;
					}
					else
					{
						cache[m] = '\0';
						m = 0;
						if (((str[n - 1] != ' ') && (str[n-1] != '\n')) && ((str[n] == ' ') || (str[n] == '\n')))
						{
							switch (count)
							{
							case(0):
							{
								char2string(&string, cache);
								str_copy(&origin, string);
								count++;
								add = Route_init();
								add = Route_find(head, origin);
								if (!add)
								{
									head = Route_add_city(head, origin);
									citylist = CityList_add(citylist, origin);
									add = Route_find(head, origin);
								}
								break;
							}
							case(1):
							{
								char2string(&string, cache);
								str_copy(&city, string);
								citylist = CityList_add(citylist, city);
								count++;
								break;
							}
							case(2):
							{
								char2string(&string, cache);
								str_copy(&FlightNumber, string);
								count++;
								break;
							}
							case(3):
							{
								char2string(&string, cache);
								str_copy(&date, string);
								count++;
								break;
							}
							case(4):
							{
								char2string(&string, cache);
								str_copy(&time, string);
								count++;
								break;
							}
							case(5):
							{
								money = char2int(cache);
								count++;
								break;
							}
							case(6):
							{
								char2string(&string, cache);
								str_copy(&SiteSize, string);
								SeatNumber2int(SiteSize, x, y);
								FlightList_add(flightlist, FlightNumber, date, time, x, y);
							}
							case(7):
							{
								seat = char2int(cache);
								count++;
								add->Destination = Dest_add(add->Destination, origin, city, FlightNumber, date, time, money, seat);
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
			for (int i = 0; i < line; i++)
			{
				count = 0;
				fgets(str, 100, fp);
				for (int n = 0; n < 100; n++)
				{
					if (count == 7)	break;
					if (str[n] != ' ' && str[n] != '\n')
					{
						cache[m] = str[n];
						m++;
					}
					else
					{
						cache[m] = '\0';
						m = 0;
						if (((str[n - 1] != ' ') && (str[n - 1] != '\n')) && ((str[n] == ' ') || (str[n] == '\n')))
						{
							switch (count)
							{
							case(0):
							{
								char2string(&string, cache);
								str_copy(&origin, string);
								count++;
								head=Route_add_city(head, origin);
								citylist=CityList_add(citylist, origin);
								add = Route_init();
								add = Route_find(head, origin);
								break;
							}
							case(1):
							{
								char2string(&string, cache);
								str_copy(&city, string);
								citylist = CityList_add(citylist, city);
								count++;
								break;
							}
							case(2):
							{
								char2string(&string, cache);
								str_copy(&FlightNumber, string);
								count++;
								break;
							}
							case(3):
							{
								char2string(&string, cache);
								str_copy(&date, string);
								count++;
								break;
							}
							case(4):
							{
								char2string(&string, cache);
								str_copy(&time, string);
								count++;
								break;
							}
							case(5):
							{
								money = char2int(cache);
								count++;
								break;
							}
							case(6):
							{
								seat = char2int(cache);
								count++;
								add->Destination = Dest_add(add->Destination, origin, city, FlightNumber, date, time, money, seat);
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
	char2string(&path, "CityList.dat");
	FlightList_save(flightlist);
	CityList_save(citylist,path);
	return head;
}
Route* Route_add_city(Route* head, string city)
{
	Route* p, * add;
	add = Route_init();
	str_copy(&add->city, city);
	p = head;
	while (p->Next != nullptr)
	{
		p = p->Next;
	}
	if (head->city.length == 0)	head = add;
	else
	{
		p->Next = add;
		p->Next->Destination = Dest_init();
	}
	return head;
}
Route* Route_add_flight(Route* head,CityList* citylist ,string origin, string city, string FlightNumber, string date, string time, int money, int seat,string path)
{
	Route* p;
	citylist=CityList_add(citylist, origin);
	citylist=CityList_add(citylist, city);
	p = Route_find(head, origin);
	p->Destination=Dest_add(p->Destination, origin, city, FlightNumber, date, time, money, seat);
	CityList_save(citylist,path);
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
void Route_save(Route* head,char* path)
{
	int line,Dest_line;
	char str[105];
	Route_refresh(head);
	Route* p;
	DestinationList* q;
	p = head;
	while (p->Next != NULL)
	{
		p = p->Next;
	}
	line = p->No+1;

	FILE* fp;
	fopen_s(&fp, path , "w");
	int2char(line, str);
	fputs(str, fp);
	fputc('\n', fp);
	p = head;
	for (int i = 0; i < line; i++)
	{
		q = p->Destination;
		while (q)
		{
			string2char(str, &q->origin);
			fputs(str, fp);
			fputc(' ', fp);
			string2char(str, &q->city);
			fputs(str, fp);
			fputc(' ', fp);
			string2char(str, &q->FlightNumber);
			fputs(str, fp);
			fputc(' ', fp);
			string2char(str, &q->date);
			fputs(str, fp);
			fputc(' ', fp);
			string2char(str, &q->time);
			fputs(str, fp);
			fputc(' ', fp);
			int2char(q->money, str);
			fputs(str, fp);
			fputc(' ', fp);
			int2char(q->seat, str);
			fputs(str, fp);
			fputc('\n', fp);
			q = q->next;
		}
		p = p->Next;
	}
	fclose(fp);
}
#pragma once
