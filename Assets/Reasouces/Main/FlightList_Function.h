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
	string FLightNumber, date, time, SiteNumber;
	int line, count, m, x, y;
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
		FlightList* p, * add;
		for (int i = 0; i < line; i++)
		{
			count = 0;
			fgets(str, 100, fp);
			add = FlightList_init();
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
						case(0):
						{
							char2string(&FLightNumber, str);
							str_copy(&add->FlightNumber, FLightNumber);
							count++;
							break;
						}
						case(1):
						{
							char2string(&date, str);
							count++;
							break;
						}
						case(2):
						{
							char2string(&time, str);
							count++;
							break;
						}
						case(3):
						{
							char2string(&SiteNumber, str);
							SiteNumber2int(SiteNumber, x, y);
							SiteList_add(add->Site, date, time, x, y);
							count++;
							break;
						}
						case(4):
						{
							if (head->FlightNumber.length == 0)
							{
								head = add;
								p = head;
							}
							else
							{
								do
								{
									p = p->next;
								} while (p->next!=nullptr);
								p->next = add;
							}
						}
						default:
							break;
						}
					}
				}
			}
		}
	}
	return head;
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
void FlightList_save(FlightList* head)
{
	FlightList_refresh(head);
	int line;
	FlightList* p;
	SiteList* q;
	p = head;
	do
	{
		p = p->next;
	} while (p->next!=nullptr);
	line = p->No + 1;

	FILE* fp;
	char str[502];
	fopen_s(&fp, "FlightList.dat", "w");
	int2char(line, str);
	fputs(str, fp);
	fputc('\n', fp);
	p = head;
	for (int i = 0; i < line; i++)
	{
		q = p->Site;
		do
		{
			string2char(str, &p->FlightNumber);
			fputs(str, fp);
			fputc(' ', fp);
			string2char(str, &q->date);
			fputs(str, fp);
			fputc(' ', fp);
			string2char(str, &q->time);
			fputs(str, fp);
			fputc(' ', fp);
			for (int m = 0; m < sizeof(q->site[m]); m++)
			{
				for (int n = 0; n < sizeof(q->site); n++)
				{
					if (q->site[m][n]==0)	putc('0', fp);
					else putc('1', fp);
				}
			}
			fputc('\n', fp);
			q = q->next;
		} while (q->next!=nullptr);
		p = p->next;
	}
}
#pragma once
