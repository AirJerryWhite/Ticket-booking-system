#include <stdio.h>
#include <string.h>

typedef struct string
{
	char str[100]={};
	int length=0;
}string;
void str_create(string* S);
void str_copy(string* S,string T);
int str_compare(string S, string T);
void str_show(string S);	//for test

typedef struct CityList
{
	string city;
	struct CityList* next;
}CityList;
CityList* CityList_init();
void* find(CityList* head, string city);
#pragma once
