#ifndef BIRTH_HASH_H_
#define  BIRTH_HASH_H_

#include<stdio.h>
#include<stdlib.h>
#include "struct.h"


/* to store a data (consisting of key and value) in hash table array */
struct item
{
    int key;
	student s;
	int index;
}new_item;


/* each hash table item has a flag (status) and data (consisting of key and value) */
struct hashtable_item
{

	int flag;
	/*
	 * flag = 0 : data does not exist
	 * flag = 1 : data exists at given array location
	 * flag = 2 : data was present at least once
	*/
	struct item data;

}*array;


int hashDate(int* value);

int hashcode(int key);

void init_array();

void PrintStruct(student s);

void insert(int key, int * value);

void search(int key);

void remove_element(int key);

void display();

int size_of_hashtable();


#endif