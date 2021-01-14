#include "struct.h"
#include "str_function.h"
#include "transmform_function.h"
SiteList* SiteList_init()
{
	SiteList* p;
	p = (SiteList*)malloc(sizeof(SiteList));
	p->date.length = 0;
	p->next = nullptr;
	return p;
}
SiteList* SiteList_loadSite(SiteList* head, string date, string time, string Site)
{
	int x=0, y=0;
	SiteList* p;
	p = SiteList_find(head, date, time);
	for (int i = 0; i < Site.length; i++)
	{
		p->site[x][y] = Site.str[i] - '0';
		x++;
		if (x>sizeof(p->site))
		{
			x = 0;
			y++;
		}
	}
	return head;
}
SiteList* SiteList_add(SiteList* head, string date, string time, int x, int y)
{
	SiteList* p, * add;
	str_copy(&add->date, date);
	str_copy(&add->time, time);
	add->site = (bool**)malloc(sizeof(int) * x);
	for (int i = 0; i < x; i++)
	{
		add->site[i] = (bool*)malloc(sizeof(int) * y);
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
void SiteList_refresh(SiteList* head)
{
	int i = 0;
	SiteList* p;
	p = head;
	do
	{
		p->No = i;
		i++;
		p = p->next;
	} while (p->next!=nullptr);
}
SiteList* SiteList_find(SiteList* head, string date, string time)
{
	SiteList* p;
	p = head;
	do
	{
		if (str_compare(p->date, date) && str_compare(p->time, time))	return p;
		else p = p->next;
	} while (p);
	return nullptr;
}
SiteList* SiteList_bookingSite(SiteList* head, string date, string time, string SiteNumber, bool& success)
{
	int x, y;
	SiteList* p;
	SiteNumber2int(SiteNumber, x, y);
	p = SiteList_find(head, date, time);
	if (p->site[x][y]==0)
	{
		p->site[x][y] = 1;
		success = true;
	}
	else
	{
		success = false;
	}
	return head;
}
SiteList* SiteList_edit(SiteList* head, string date, string new_date, string time, string new_time)
{
	SiteList* p;
	p = SiteList_find(head, date, time);
	str_copy(&p->date,new_date);
	str_copy(&p->time, new_time);
	return head;
}
SiteList* SiteList_refund(SiteList* head, string date, string time, string SiteNumber)
{
	SiteList* p;
	p = SiteList_find(head, date, time);
	int x, y;
	SiteNumber2int(SiteNumber, x, y);
	p->site[x][y] = 0;
	return head;
}
SiteList* SiteList_remove(SiteList* head, string date, string time)
{
	SiteList_refresh(head);
	SiteList* p,*pre;
	pre = head;
	p = SiteList_find(head, date, time);
	do
	{
		if (pre->No == (p->No--)) break;
		else pre = pre->next;
	} while (pre->next!=nullptr);
	pre->next = p->next;
	return head;
}
#pragma once
