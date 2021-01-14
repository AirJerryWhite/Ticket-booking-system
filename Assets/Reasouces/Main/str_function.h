#include "struct.h"
string str_init()
{
	string p;
	p.length = 0;
	return p;
}
void str_create(string* S)
{
	char input;
	if (S->length == 0)
	{
		while ((input = getchar()) != '\n')
		{
			S->str[S->length] = input;
			S->length++;
		}
		S->str[S->length] = '\0';
	}
}
void str_copy(string* S,string T)
{
		S->length = T.length;
		for (int i = 0; i <= T.length; i++)
		{
			S->str[i] = T.str[i];
		}
}
void str_display(string S)
{
		printf("%s", S.str);
}
int str_compare(string S, string T)
{
	int flag;
	if (S.length == T.length)
	{
		flag = 1;
		for (int i = 0; i < S.length; i++)
		{
			if (S.str[i] != T.str[i])
			{
				flag = 0;
				break;
			}
		}
	}
	else flag = 0;
	return flag;
}
void str_refresh(string* S)
{
	string p;
	p.length = 0;
	str_copy(S, p);
}
#pragma once
