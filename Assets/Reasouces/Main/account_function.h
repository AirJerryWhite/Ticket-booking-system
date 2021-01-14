#include "struct.h"
#include "str_function.h"

Account* account_init()
{
	Account* head;
	head = (Account*)malloc(sizeof(Account));
	head->Flight = Route_init();
	head->username.length = 0;
	head->next = NULL;
	return head;
}
void account_refresh(Account* head)
{
	int i = 0;
	Account* p;
	p = head;
	do
	{
		p->No = i;
		i++;
		p = p->next;
	} while (p);
}
Account* account_create(Account* head)
{
	FILE* fp;
	int line,n=0,count;
	Account* p, * add;
	string string, username, passport, origin, city, FlightNumber, date, time, SeatNumber;
	int money, seat;
	char str[100];
	char cache[100];
	fopen_s(&fp,"Account","r");
	if (fp)
	{
		fgets(str, 5, fp);
		line=char2int(str);
		if (line == 0)
		{
			account_input();
		}
		for (int i = 0; i < line; i++)
		{
			fgets(str,100, fp);
			for (int m = 0; m < 100; m++)
			{
				if (count == 6)	break;
				count = 0;
				if ((str[m] != ' ') || (str[m] != '\n'))
				{
					cache[n] = str[m];
					n++;
				}
				else
				{
					n = 0;
					if (((str[m-1] != ' ') || (str[m-1] != '\n'))&&((str[m] == ' ') || (str[m] == '\n')))
					{
						switch (count)
						{
						case(0):
						{
							char2string(&string, cache);
							str_copy(&username, string);
							count++;
							break;
						}
						case(1):
						{
							char2string(&string, cache);
							str_copy(&passport, string);
							head = account_add(head, username, passport);
							add = account_find(head, username);
							count++;
							break;
						}
						case(2):
						{
							char2string(&string, cache);
							str_copy(&origin, string);
							count++;
							break;
						}
						case(3):
						{
							char2string(&string, cache);
							str_copy(&city, string);
							count++;
							break;
						}
						case(4):
						{
							char2string(&string, cache);
							str_copy(&FlightNumber, string);
							count++;
							break;
						}
						case(5):
						{
							char2string(&string, cache);
							str_copy(&date, string);
							count++;
							break;
						}
						case(6):
						{
							char2string(&string, cache);
							str_copy(&time, string);
							count++;
							break;
						}
						case(7):
						{
							money = char2int(cache);
							count++;
							break;
						}
						case(8):
						{
							seat = char2int(cache);
							count++;
							break;
						}
						default:
							break;
						}
					}
				}
			}
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
	return head;
}
void account_input()
{
	string username, passport;
	int line;
	char str[100];
	FILE* fp;
	fopen_s(&fp, "Account.dat", "w");
	scanf_s("%d",&line);
	int2char(line, str);
	fputs(str, fp);
	fputc('\n', fp);
	for (int i = 0; i < line; i++)
	{
		str_refresh(&username);
		str_refresh(&passport);
		str_create(&username);
		str_create(&passport);
		encryp_passport(&passport);
		string2char(str, &username);
		fputs(str, fp);
		fputc(' ', fp);
		string2char(str, &passport);
		fputs(str, fp);
		fputc('\n', fp);
	}
}
void account_FileInit()
{
	FILE* fp;
	fopen_s(&fp, "Account.dat", "w");
	fputc('0', fp);
	fclose(fp);
}
void account_edit(Account* head, string username, string new_passport)
{
	Account* p;
	p = account_find(head, username);
	encryp_passport(&new_passport);
	str_copy(&p->passport, new_passport);
}
Account* account_find(Account* head, string username)
{
	Account* p;
	p = head;
	do
	{
		if (str_compare(p->username, username))
		{
			break;
		}
		else p = p->next;
	} while (p);
}
Account* account_add(Account* head, string username, string passport)
{
	Account* p, * add;
	p = head;
	if (!account_find(head, username))
	{
		do
		{
			p = p->next;
		} while (p);
		encryp_passport(&passport);
		add->No = p->No++;
		str_copy(&add->username, username);
		str_copy(&add->passport, passport);
		if (head->username.length == 0)
		{
			head = add;
			p = head;
		}
		else p = add;
		return head;
	}
}
void account_save(Account* head)
{
	FILE* fp;
	int line;
	Account* p;
	Route* route;
	DestinationList* dest;
	char str[100];
	account_refresh(head);
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	line = p->No++;
	p = head;
	fopen_s(&fp, "Account", "w");
	int2char(line, str);
	fputs(str, fp);
	fputc('\n', fp);
	for (int i = 0; i < line; i++)
	{
		route = p->Flight;
		dest = route->Destination;
		do
		{
			do
			{
				string2char(str, &p->username);
				fputs(str, fp);
				fputc(' ', fp);
				string2char(str, &p->passport);
				fputs(str, fp);
				fputc(' ', fp);
				string2char(str, &route->city);
				fputs(str, fp);
				fputc(' ', fp);
				string2char(str, &dest->city);
				fputs(str, fp);
				fputc(' ', fp);
				string2char(str, &dest->FlightNumber);
				fputs(str, fp);
				fputc(' ', fp);
				string2char(str, &dest->date);
				fputs(str, fp);
				fputc(' ', fp);
				string2char(str, &dest->time);
				fputs(str, fp);
				fputc(' ', fp);
				int2char(dest->money, str);
				fputs(str, fp);
				fputc(' ', fp);
				int2char(dest->seat, str);
				fputs(str, fp);
				fputc(' ', fp);
				string2char(str, &dest->SeatNumber);
				fputs(str, fp);
				fputc('\n', fp);
				dest = dest->next;
			} while (dest->next!=nullptr);
			route = route->Next;
		} while (route->Next!=nullptr);
		p = p->next;
	}
}
int account_login(Account* head, string username, string passport)
{
	Account* p;
	p = account_find(head, username);
	if (p)
	{
		if (str_compare(decrypt_passpore(p->passport), passport))
		{
			printf("密码正确，登陆成功\n");
			return 1;
		}
		else
		{
			printf("密码错误，登录失败\n");
			return 0;
		}
	}
	else
		printf("不存在该用户\n");
}
void account_display(Account* head)
{
	Account* p;
	p = head;
	if (p)
	{
		do
		{
			printf("%d.", p->No);
			str_display(p->username);
			printf("\n");
			p = p->next;
		} while (p);
	}
}
void encryp_passport(string* passport)
{
	for (int i = 0; i < passport->length; i++)
	{
		passport->str[i] = passport->str[i] + 5;
	}
}
string decrypt_passpore(string p)
{
	string passport;
	str_copy(&passport, p);
	for (int i = 0; i < passport.length; i++)
	{
		passport.str[i] = passport.str[i] - 5;
	}
	return passport;
}
#pragma once
