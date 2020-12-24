#include <stdio.h>
#include <string.h>
typedef struct string
{
	char str[100]={};
	int length;
}string;
void strcreate(string* S);
void strshow(string S);	//for test

typedef string city;
typedef struct city_list
{
	city info[10];
	struct city_list* next;
}city_list;
city_list* init();
void* find(city_list* head, city* city);
#pragma once
