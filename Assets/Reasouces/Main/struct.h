#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
	char str[100]={};
	int length=0;
}string;
void str_create(string* S);
void str_copy(string* S,string T);
void char2string(string* S, char* str);
int str_compare(string S, string T);
void str_show(string S);	//for test

typedef struct CityList
{
	int No=0;
	string city;
	struct CityList* next=NULL;
}CityList;
CityList* CityList_init();
void CityList_refresh(CityList* head);
CityList* CityList_create(CityList* head);
void CityList_display(CityList* head);
void* find(CityList* head, string city);
#pragma once
