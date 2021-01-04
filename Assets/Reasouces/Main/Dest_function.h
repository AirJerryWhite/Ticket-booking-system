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
DestinationList* Dest_create(DestinationList* head, string origin, string city, string FlightNumber, string date, string time, int money, int seat)
{
	str_copy(&head->origin, origin);
	str_copy(&head->city, city);
	str_copy(&head->FlightNumber, FlightNumber);
	str_copy(&head->date, date);
	str_copy(&head->time, time);
	head->money = money;
	head->seat = seat;
	head->next = NULL;
	return head;
}
DestinationList* Dest_add(DestinationList* head, string origin, string city, string FlightNumber, string date, string time, int money, int seat)
{
	DestinationList* p, * add;
	Dest_refrsh(head);
	p = head;
	{
		add = (DestinationList*)malloc(sizeof(DestinationList));
		add->next = NULL;
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
	pre = (DestinationList*)malloc(sizeof(DestinationList));
	pre->next = NULL;
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
DestinationList* Dest_find_City(DestinationList* head, string city)
{
	int i = 0;
	DestinationList* p, * q,*cache;
	cache = (DestinationList*)malloc(sizeof(DestinationList));
	cache->next = NULL;
	p = head;
	q = cache;
	do
	{
		if (str_compare(p->city, city))
		{
			if (i==0)	Dest_create(cache, p->origin, p->city, p->FlightNumber, p->date, p->time, p->money, p->seat);
			else Dest_add(cache, p->origin, p->city, p->FlightNumber, p->date, p->time, p->money, p->seat);
			i++;
		}
		p = p->next;
	} while (p);
	Dest_refrsh(cache);
	return cache;
}
void Dest_display(DestinationList* head)
{
	Dest_refrsh(head);
	DestinationList* p;
	p = head;
	do
	{
		printf("%d.", p->No);
		str_display(p->FlightNumber);
		printf(" ");
		str_display(p->origin);
		printf(" ");
		str_display(p->city);
		printf(" ");
		str_display(p->date);
		printf(" ");
		str_display(p->time);
		printf(" %d %d\n", p->seat, p->money);
		p = p->next;
	} while (p);
}
#pragma once
