#include "program.h"


int probing_choice;
static int size = 0;
int max ;


int hashDate(int* value){
    return  FACTOR*FACTOR*value[0] + FACTOR*value[1] + value[2];
}
/* this function returns corresponding index of the given key */
int hashcode(int key)
{
	return (key % max);
}

/* this  function initializes the hash table array */
void init_array()
{
	int i;
	for (i = 0; i < max; i++)
    {
		array[i].flag = 0;

	}
}

void PrintStruct(student s){
    printf("\n");
    printf(" Name: %s\n",s.Name);
    printf(" ID: %d\n",s.ID);
    printf(" Date: %d/%d/%d\n",s.Date[0],s.Date[1],s.Date[2]);
    printf(" Score: %d\n", s.Score);
    printf("\n");
}


 //this function inserts an element in the hash table *
void insert(int key, int * value)
{

	int index = hashcode(key);
	int i = index;
	int h = 1;

	//probing through the array until an empty space is found
	while (array[i].flag == 1)
    {

		if (array[i].data.key == key)
        {
			/* case when already present key matches the given key */
			printf("\n This key is already present in hash table, hence updating it's value \n");
			array[i].data = new_item;
			return;

		}
		switch(probing_choice)
		{
			case 1:
				i=(i+1)%max;
				break;
			case 2:
				i = (i + (h * h)) % max;
				h++;
				break;
			default:
				i=(i+1)%max;
				break;
		}
		if (i == index)
        {
			printf("\n Hash table is full, cannot add more elements \n");
			return;
		}

	}

	array[i].flag = 1;
	array[i].data = new_item;
	printf("\n Key (%d) has been inserted\n", key);
	size++;
}


void search(int key)
{

	int index = hashcode(key);
	int i = index;
	int h = 1;

	/* probing through the hash table until we reach at location where there had not been an element even once */
	while (array[i].flag != 0)
        {
		if (array[i].flag == 1  &&  array[i].data.key == key)
        {
			/* case where data exists at the location and its key matches to the given key */
			printf("\n Key (%d) is found \n", key);
			PrintStruct(array[i].data.s);
			return;
		}
		switch(probing_choice)
		{
			case 1:
				i=(i+1)%max;
				break;
			case 2:
				i = (i + (h * h)) % max;
				h++;
				break;
			default:
				i=(i+1)%max;
				break;
		}
		if (i == index)
        {
			break;
		}
	}
	printf("\n Key does not exist \n");

}

/* to remove an element form the hash table array */
void remove_element(int key)
{
	int index = hashcode(key);
	int i = index;
	int h = 1;

	/* probing through the hash table until we reach at location where there had not been an element even once */
	while (array[i].flag != 0)
        {
		if (array[i].flag == 1  &&  array[i].data.key == key)
                {

			/* case where data exists at the location and its key matches to the given key */
			array[i].flag = 2;

			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;

		}
		switch(probing_choice)
		{
			case 1:i=(i+1)%max;break;
			case 2:i = (i + (h * h)) % max;
			h++;
			break;
			default:i=(i+1)%max;break;
		}
		if (i == index)
        {
			break;
		}
	}
	printf("\n Key does not exist \n");

}

/* to display the contents of hash table */
void display()
{

	int i;
	for(i = 0; i < max; i++)
        {
		if (array[i].flag != 1)
        {
			printf("\n Array[%d] has no elements \n", i);
		}
		else
        {
			printf("\n Array[%d] has elements \n  %d (key) \n", i, array[i].data.key);
             PrintStruct(array[i].data.s);
		}
	}

}

int size_of_hashtable()
{
	return size;
}

