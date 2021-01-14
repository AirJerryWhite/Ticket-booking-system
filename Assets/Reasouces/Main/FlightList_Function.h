#include "struct.h"
#include "str_function.h"
#include "transmform_function.h"
FlightList* FlightList_init()
{
	FlightList* p;
	p = (FlightList*)malloc(sizeof(FlightList));
	p->next = nullptr;
	p->FlightNumber.length = 0;
	p->Site = SiteList_init();
	return p;
}
void FlightList_refresh(FlightList* head)
{
	int i;
	FlightList* p;
	p = head;
	do
	{
		p->No = i;
		i++;
		p = p->next;
	} while (p->next!=nullptr);
}
FlightList* FlightList_create(FlightList* head)
{
	FILE* fp;
	int line,count,m;
	char str[502],cache[502];
	fopen_s(&fp, "FlightList.dat", "r");
	fgets(str, 500, fp);
	line = char2int(str);
	if (line==0)
	{
		return FlightList_init();
	}
	else
	{
		FlightList* add;
		for (int i = 0; i < line; i++)
		{
			count = 0;
			fgets(str, 100, fp);
			for (int n = 0; n < 100; n++)
			{
				if (count == 6)	break;
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
					if (((str[n - 1] != ' ') && (str[n - 1] != '\n')) && ((str[n] == ' ') || (str[n] == '\n')))
					{
						switch (count)
						{
						default:
							break;
						}
					}
				}
			}
		}
	}
}
FlightList* FlightList_add(FlightList* head, string FlightNumber, string date, string time, int x, int y)
{
	FlightList* p, * add;
	add = FlightList_init();
	str_copy(&add->FlightNumber,FlightNumber);
	SiteList_add(add->Site, date, time, x, y);
	if (!FlightList_find(head, FlightNumber))
	{
		if (head->FlightNumber.length == 0) head = add;
		else
		{
			do
			{
				p = p->next;
			} while (p->next!=nullptr);
			p->next = add;
		}
	}
	return head;
}
FlightList* FlightList_find(FlightList* head, string FlightNumber)
{
	FlightList* p;
	p = head;
	do
	{
		if (str_compare(p->FlightNumber, FlightNumber))	return p;
		else p = p->next;
	} while (p->next!=nullptr);
	return nullptr;
}
FlightList* FlightList_edit(FlightList* head, string FlightNumber, string date, string new_date, string time, string new_time)
{
	FlightList* p;
	p = FlightList_find(head, FlightNumber);
	SiteList_edit(p->Site, date, new_date, time, new_time);
	return head;
}
FlightList* FlightList_refund(FlightList* head, string FlightNumber, string date, string time, string SiteNumber)
{
	FlightList* p;
	p = FlightList_find(head, FlightNumber);
	SiteList_refund(p->Site, date, time, SiteNumber);
	return head;
}
FlightList* FlightList_remove(FlightList* head, string FlightNumber, string date, string time)
{
	FlightList* p;
	p = FlightList_find(head, FlightNumber);
	SiteList_remove(p->Site, date, time);
	return head;
}
#pragma once
