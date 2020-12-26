#include "struct.h"
#include "transmform_function.h"
#include "str_function.h"

DestinationList* Dest_init()
{
	DestinationList* p;
	p = (DestinationList*)malloc(sizeof(DestinationList));
	p->next = NULL;
	return p;
}
void Dest_malloc(DestinationList* p)
{
	DestinationList* p;
	p = (DestinationList*)malloc(sizeof(DestinationList));
	p->next = NULL;
}
void Dest_refrsh(DestinationList* head)
{
	DestinationList* p;
	int i = 0;
	p = head;
	do
	{
		p->No = i;
		i++;
		p = p->next;
	} while (p);
}
DestinationList* Dest_add(DestinationList* head, string origin, string city, string FlightNumber, string date, string time, int money, int seat)
{
	DestinationList* p, * add;
	p = head;
	{
		Dest_malloc(add);
		str_copy(&add->origin, origin);
		str_copy(&add->city, city);
		str_copy(&add->FlightNumber, FlightNumber);
		str_copy(&add->date, date);
		str_copy(&add->time, time);
		add->money = money;
		add->seat = seat;
		add->next = NULL;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = add;
	return head;
}
DestinationList* Dest_remove(DestinationList* head, string FlightNumber)
{
	DestinationList* q, * pre;
	Dest_refrsh(head);
	q = head;
	do
	{
		if (str_compare(q->FlightNumber, FlightNumber))
		{
			pre->next = q->next;
			break;
		}
		else
		{
			if (q->No == 0)
			{
				pre = head;
				q = q->next;
			}
			else
			{
				pre = pre->next;
				q = q->next;
			}
		}
	} while (q);
	return head;
}
DestinationList* Dest_find_FlightNumber(DestinationList* head, string FlightNumber)
{
	DestinationList* p;
	p = head;
	do
	{
		if (str_compare(p->FlightNumber, FlightNumber))	break;
		else p = p->next;
	} while (p);
	return p;
}
void Dest_find_City(DestinationList* head, DestinationList* cache, string city)
{
	DestinationList* p, * q;
	p = head;
	q = cache;
	do
	{
		if (str_compare(p->city, city))
		{
			if (cache == NULL)
			{
				str_copy(&q->city, p->city);
				str_copy(&q->date, p->date);
				str_copy(&q->FlightNumber, p->FlightNumber);
				str_copy(&q->time, p->time);
				str_copy(&q->origin, p->origin);
				q->money = p->money;
				q->seat = p->seat;
			}
			else Dest_add(q, p->origin, p->city, p->FlightNumber, p->date, p->time, p->money, p->seat);
			q = q->next;
		}
	} while (p);
	Dest_refrsh(cache);
}
#pragma once
