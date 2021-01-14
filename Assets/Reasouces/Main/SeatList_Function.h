#include "struct.h"
#include "str_function.h"
#include "transmform_function.h"
SeatList* SeatList_init()
{
	SeatList* p;
	p = (SeatList*)malloc(sizeof(SeatList));
	p->date.length = 0;
	p->next = nullptr;
	return p;
}
SeatList* SeatList_loadSite(SeatList* head, string date, string time, string seat)
{
	int x=0, y=0;
	SeatList* p;
	p = SeatList_find(head, date, time);
	for (int i = 0; i < seat.length; i++)
	{
		p->seat[x][y] = seat.str[i] - '0';
		x++;
		if (x>sizeof(p->seat))
		{
			x = 0;
			y++;
		}
	}
	return head;
}
SeatList* SeatList_add(SeatList* head, string date, string time, int x, int y)
{
	SeatList* p, * add;
	add = SeatList_init();
	str_copy(&add->date, date);
	str_copy(&add->time, time);
	add->seat = (bool**)malloc(sizeof(int) * x);
	for (int i = 0; i < x; i++)
	{
		add->seat[i] = (bool*)malloc(sizeof(int) * y);
	}
	for (int m = 0; m < x; m++)
	{
		for (int n = 0; n < y; n++)
		{
			add->seat[m][n] = 0;
		}
	}
	if (head->date.length == 0)
	{
		head = add;
	}
	else
	{
		p = head;
		while (p->next == nullptr)
		{
			p = p->next;
		}
		p->next = add;
	}
	return head;
}
void SeatList_refresh(SeatList* head)
{
	int i = 0;
	SeatList* p;
	p = head;
	do
	{
		p->No = i;
		i++;
		p = p->next;
	} while (p->next!=nullptr);
}
SeatList* SeatList_find(SeatList* head, string date, string time)
{
	SeatList* p;
	p = head;
	do
	{
		if (str_compare(p->date, date) && str_compare(p->time, time))	return p;
		else p = p->next;
	} while (p);
	return nullptr;
}
SeatList* SeatList_bookingSite(SeatList* head, string date, string time, string SiteNumber, bool& success)
{
	int x, y;
	SeatList* p;
	SeatNumber2int(SiteNumber, x, y);
	p = SeatList_find(head, date, time);
	if (p->seat[x][y]==0)
	{
		p->seat[x][y] = 1;
		success = true;
	}
	else
	{
		success = false;
	}
	return head;
}
SeatList* SeatList_edit(SeatList* head, string date, string new_date, string time, string new_time)
{
	SeatList* p;
	p = SeatList_find(head, date, time);
	str_copy(&p->date,new_date);
	str_copy(&p->time, new_time);
	return head;
}
SeatList* SeatList_refund(SeatList* head, string date, string time, string SiteNumber)
{
	SeatList* p;
	p = SeatList_find(head, date, time);
	int x, y;
	SeatNumber2int(SiteNumber, x, y);
	p->seat[x][y] = 0;
	return head;
}
SeatList* SeatList_remove(SeatList* head, string date, string time)
{
	SeatList_refresh(head);
	SeatList* p,*pre;
	pre = head;
	p = SeatList_find(head, date, time);
	do
	{
		if (pre->No == (p->No--)) break;
		else pre = pre->next;
	} while (pre->next!=nullptr);
	pre->next = p->next;
	return head;
}
#pragma once
