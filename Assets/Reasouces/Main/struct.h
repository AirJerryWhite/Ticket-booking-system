#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=============================stack==============================//
typedef struct stack
{
	int stack[5];
	int head;
}stack;
stack stack_init();
void stack_push(stack* S,int data);
int stack_pull(stack* S);
//============================string==============================//
typedef struct string
{
	char str[100]={};
	int length=0;
}string;
void str_create(string* S);
void str_copy(string* S,string T);
int str_compare(string S, string T);
void str_display(string S);	//for test
//===========================CityList==============================//
typedef struct CityList
{
	int No=0;
	string city;
	struct CityList* next=NULL;
}CityList;
CityList* CityList_init();
void CityList_refresh(CityList* head);
CityList* CityList_create(CityList* head);
CityList* CityList_add(CityList* head, string city);
void CityList_display(CityList* head);	//for test
int CityList_find(CityList* head, string city);
void CityList_save(CityList* head);
//===========================transform=============================//
void char2string(string* S, char* str);
void string2char(char* str, string* S);	
void int2char(int length, char* str);
int char2int(char* str);
#pragma once
