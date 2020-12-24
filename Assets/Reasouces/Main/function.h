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
#pragma once
