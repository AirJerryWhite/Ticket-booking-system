#include "struct.h"
#include "str_function.h"

void CityList_init(CityList* p)
{
	p = (CityList*)malloc(sizeof(string));
}
void CityList_refresh(CityList* head)
{
	CityList* p;
	p = head;
	int No = 0;
	if (p)
		while (p)
		{
			p->No = No;
			No++;
			p = p->next;
	}
}
CityList* CityList_create(CityList* head)
{
	string a;
	CityList* p,add;
	p = head;
	CityList_init(p);
	char str[100];
	int line=0;
	FILE* fp;
	fopen_s(&fp,"CityList.dat", "r");
	if (fp)
	{
		fgets(str, 5, fp);
		for (int i = 0; i < 5; i++)
		{
			if (str[i] == '\n' || str[i] == '\0') break;
			else
			{
				line = line * 10 + (str[i] - '0');
			}
		}
		for (int i = 0; i < line; i++)
		{
			CityList_init(&add);
			fgets(str, 20, fp);
			char2string(&add.city, str);
			add.next = NULL;
			if (i==0)	p = &add;
			else
			{
				p->next = &add;
				p = &add;
			}
		}
	}
	return head;
}
void CityList_display(CityList* head)
{
	CityList* p;
	p = head;
	if (p)
		while (p)
		{
			printf("%d.  ",p->No);
			str_show(p->city);
			printf("\n");
			p = p->next;
		}
}
#pragma once
