#include "struct.h"
#include "str_function.h"
#include "transmform_function.h"

void CityList_FileInit()
{
	FILE* fp;
	fopen_s(&fp, "CityList.dat", "w");
	fputc('0', fp);
}
CityList* CityList_init()
{
	CityList* head;
	head = (CityList*)malloc(sizeof(CityList));
	head->city.length = 0;
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
	p->next = NULL;
	char str[100];
	int line=0;
	FILE* fp;
	fopen_s(&fp,"CityList.dat", "r");
	if (fp)
	{
		fgets(str, 5, fp);
		line=char2int(str);
		if (line != 0)
		{
			for (int i = 0; i < line; i++)
			{
				add = (CityList*)malloc(sizeof(CityList));
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
	}
	fclose(fp);
	return head;
}
CityList* CityList_add(CityList* head, string city)
{
	if (CityList_find(head, city) == -1)
	{
		CityList* p, * add;
		add = (CityList*)malloc(sizeof(CityList));
		add->next = NULL;
		p = head;
		str_copy(&add->city, city);
		if (head->city.length == 0)
		{
			head = add;
			p = head;
		}
		else
		{
			while (p->next != NULL)
			{
				p = p->next;
			}
			add->No = p->No++;
			p->next = add;
		}
	}
	return head;
}
void CityList_display(CityList* head)
{
	CityList_refresh(head);
	CityList* p;
	p = head;
	do
	{
		printf("%d.",p->No);
		str_display(p->city);
		printf("\n");
		p = p->next;
	} while (p);
}
int CityList_find(CityList* head, string city)
{
	int no=-1;
	CityList* p;
	p = head;
	do
	{
		if (str_compare(p->city, city))
		{
			no=p->No;
			break;
		}
		else p = p->next;
	} while (p);
	return no;
}
void CityList_save(CityList* head)
{
	CityList* p;
	int length = 0;
	char string[100];
	p = head;
	CityList_refresh(p);
	do
	{
		if (p->next == NULL)
		{
			length = p->No++;
			break;
		}
		p = p->next;
	} while (p);
	length++;
	FILE* fp;
	fp = NULL;
	fopen_s(&fp, "CityList.dat", "w");
	if (fp != NULL)
	{
		int2char(length, string);
		fputs(string, fp);
		fputc('\n', fp);
		p = head;
		for (int i = 0; i < length; i++)
		{
			string2char(string, &p->city);
			fputs(string, fp);
			fputc('\n', fp);
			p = p->next;
		}
		fclose(fp);
	}
}
#pragma once
