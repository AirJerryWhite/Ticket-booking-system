#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
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
string str_init();
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
void CityList_FileInit();
CityList* CityList_init();
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
void Dest_refrsh(DestinationList* p);
DestinationList* Dest_add(DestinationList* head, string origin, string city, string FlightNumber, string date, string time, int money, int seat);
DestinationList* Dest_remove(DestinationList* head, string FlightNumber);
DestinationList* Dest_find_FlightNumber(DestinationList* head, string FlightNumber);
DestinationList* Dest_find_City(DestinationList* head, string city);
void Dest_display(DestinationList* head);
//===========================Route=============================//
typedef struct Route
{
	int No;
	string city;
	DestinationList* Destination;
	Route* Next;
}Route;
Route* Route_init();
void Route_refresh(Route* p);
Route* Route_create(Route* head);
Route* Route_add(Route* head, string city);
void Route_transfer(DestinationList* head, string origin, string transfer, string city, string FlightNumber, string date, string transfer_date, string time,string transfer_time, int money_origin2city,int money_origin2transfer,int money_transfer2city, int seat,int transfer_seat);
Route* Route_find(Route* head, string city);
//===========================transform=============================//
void char2string(string* S, char* str);
void string2char(char* str, string* S);	
void int2char(int length, char* str);
int char2int(char* str);
#pragma once
