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
void str_display(string S);	/*for test*/
//===========================CityList==============================//
typedef struct CityList
{
	int No=0;
	string city;
	struct CityList* next=NULL;
}CityList;
CityList* CityList_init();
void CityList_malloc(CityList* p);
void CityList_refresh(CityList* head);
CityList* CityList_create(CityList* head);
CityList* CityList_add(CityList* head, string city);
void CityList_display(CityList* head);	/*for test*/
int CityList_find(CityList* head, string city);
void CityList_save(CityList* head);
//===========================DestinationList==============================//
typedef struct DestinationList
{
	int No;
	string origin;
	string city;
	string FlightNumber;
	string date;
	string time;
	int money;
	int seat;
	struct DestinationList* next = NULL;
}DestinationList;
DestinationList* Dest_init();
void Dest_malloc(DestinationList* p);
void Dest_refrsh(DestinationList* p);
DestinationList* Dest_add(DestinationList* head, string origin, string city, string FlightNumber, string date, string time, int money, int seat);
DestinationList* Dest_remove(DestinationList* head, string FlightNumber);
DestinationList* Dest_find_FlightNumber(DestinationList* head, string FlightNumber);
void Dest_find_City(DestinationList* head,DestinationList* cache, string city);
//===========================Route=============================//
typedef struct Route
{
	int No;
	string city;
	DestinationList* Destination;
	Route* Next;
}Route;
Route* Route_init();
//===========================transform=============================//
void char2string(string* S, char* str);
void string2char(char* str, string* S);	
void int2char(int length, char* str);
int char2int(char* str);
#pragma once
