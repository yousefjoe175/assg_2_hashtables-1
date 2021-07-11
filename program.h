#ifndef PROGRAM_H_
#define PROGRAM_H_


#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/*Algorithm for hashing
1. take the string name
2. iterate on the name's chars
3. find if the first character is capital or small
    4. for capital, subtract 'A'
    5. for small, subtract 'a'
6. define a factor g that will be multiplied by each char in different order
7. declare a varible hash with initial = 0
8. get the name length
9.  for(i[0:length])    hash = hash*g + name[i]
10. compress in size of the array
*/

/* both size of array and the factor of hashing are prime numbers */
#define SIZE 13
#define FACTOR 7


/*the struct of the node inserted in the hash table */
struct Node{
    student s;  //the structure that contains the data of the student
    int id;     //id is the hash key produced from the hash function 
    struct Node* next;
};
typedef struct Node Node;


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



void init();

void StoringData(student* input);

void printStruct(student s);

int HashName(char* name);

void InsertbyName(student s_parameter);

void SearchbyName(void);

void DeletebyName(void); 




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