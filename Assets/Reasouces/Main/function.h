#include "struct.h"
void strcreate(string* S)
{
	char input;
	S->length = 0;
	while ((input = getchar()) != '\n')
	{
		S->str[S->length] = input;
		S->length++;
	}
	S->str[S->length] = '\0';
}
void strshow(string S)
{
		printf("%s", S.str);
		printf("\n");
}
int strcompare(string S, string T)
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
#pragma once
