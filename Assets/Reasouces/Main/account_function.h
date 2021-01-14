#include "struct.h"
#include "str_function.h"

Account* account_init()
{
	Account* head;
	head = (Account*)malloc(sizeof(Account));
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
	string string;
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
				if ((str[m] != ' ') || (str[m] != '.'))
				{
					cache[n] = str[m];
					n++;
				}
				else
				{
					n = 0;
					if (((str[m-1] != ' ') || (str[m-1] != '.'))&&((str[m] == ' ') || (str[m] == '.')))
					{
						switch (count)
						{
						case(0):
						{
							add->No = char2int(cache);
							count++;
							break;
						}
						case(1):
						{
							char2string(&string, str);
							str_copy(&add->username, string);
							count++;
							break;
						}
						case(2):
						{
							char2string(&string, str);
							str_copy(&add->passport, string);
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
void account_save(Account* head)
{
	FILE* fp;
	int line;
	Account* p;
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
		int2char(p->No, str);
		fputs(str, fp);
		fputc('.', fp);
		string2char(str, &p->username);
		fputs(str, fp);
		fputc(' ', fp);
		string2char(str, &p->passport);
		fputs(str, fp);
		fputc('/n', fp);
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
			printf("������ȷ����½�ɹ�\n");
			return 1;
		}
		else
		{
			printf("������󣬵�¼ʧ��\n");
			return 0;
		}
	}
	else
		printf("�����ڸ��û�\n");
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
