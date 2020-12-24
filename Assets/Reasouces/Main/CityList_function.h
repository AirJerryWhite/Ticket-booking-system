#include "struct.h"
#include "str_function.h"

CityList* CityList_init()
{
	CityList* head;
	head = (CityList*)malloc(sizeof(CityList));
	head->next = NULL;
	return head;
}
void CityList_refresh(CityList* head)
{
	CityList* p;
	p = head;
	int no = 0;
	do
	{
		p->No = no;
		no++;
		p = p->next;
	} while (p);
}
CityList* CityList_create(CityList* head)
{
	string a;
	CityList* p, * add;
	p = (CityList*)malloc(sizeof(CityList));
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
			add=(CityList*)malloc(sizeof(CityList));
			add->next = NULL;
			fgets(str, 20, fp);
			char2string(&add->city, str);
			if (i == 0)
			{
				head = add;
				p = head;
			}
			else
			{
				p->next = add;
				p = add;
			}
		}
	}
	fclose(fp);
	return head;
}
void CityList_display(CityList* head)
{
	CityList* p;
	p = head;
	if (p)
		do
		{
			printf("%d.",p->No);
			str_show(p->city);
			printf("\n");
			p = p->next;
		} while (p);
}
#pragma once
