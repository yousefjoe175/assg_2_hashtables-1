#include<stdio.h>
#include<stdlib.h>
int probing_choice;
struct item new_item ;
/* to store a data (consisting of key and value) in hash table array */
struct item
{
	int key;
	int birth_day[3];
	int index;
};

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

};

struct hashtable_item *array;
int size = 0;
int max ;

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
			array[i].data.birth_day[0] = value[0];
			array[i].data.birth_day[1] = value[1];
			array[i].data.birth_day[2] = value[2];
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
			printf("\n Hash table is full, cannot add more elements \n");
			return;
		}

	}

	array[i].flag = 1;
	array[i].data.key = new_item.key;
	array[i].data.birth_day[0] = new_item.birth_day[0];
	array[i].data.birth_day[1] = new_item.birth_day[1];
	array[i].data.birth_day[2] = new_item.birth_day[2];
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
			printf("birthday:%d/%d/%d",array[i].data.birth_day[0],array[i].data.birth_day[1],array[i].data.birth_day[2]);
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
			printf("\n Array[%d] has elements \n  %d (key) and %d/%d/%d (birthday) \n", i, array[i].data.key, array[i].data.birth_day[0],array[i].data.birth_day[1],array[i].data.birth_day[2]);
		}
	}

}

int size_of_hashtable()
{
	return size;
}

int main()
{printf("Start\n");
printf("Enter_Size:\n");
scanf("%d",&max);

	int choice, key, value[3], n, c;
int search_key;
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item*));
	init_array();

printf("In case of collision ,Choose Type :\n");
printf("[1]Linear Probing\n");
printf("[2]Quadratic Probing\n");
scanf("%d",&probing_choice);

	do {
            switch(probing_choice){
            case 1:printf("Implementation of Hash Table in C with linear Probing.\n\n");break;
            case 2:printf("Implementation of Hash Table in C with Quadratic Probing.\n\n");break;
            default:printf("Implementation of Hash Table in C with linear Probing.\n\n");break;
            }

		printf("MENU-: \n1.Inserting item in the Hash table"
                              "\n2.Removing item from the Hash table"
                              "\n3.Check the size of Hash table"
                              "\n4.Display Hash table"
                              "\n5.Search"
		       "\n\n Please enter your choice-:");

		scanf("%d", &choice);

		switch(choice)
                {

		case 1:

		      printf("Inserting element in Hash table \n");
		      printf("Enter birthday and value-:\t");
		      scanf("%d",&value[0]);
              scanf("%d",&value[1]);
              scanf("%d",&value[2]);
		      key=value[0]+value[1]+value[2];

    new_item.key = key;
	new_item.birth_day[0] = value[0];
    new_item.birth_day[1] = value[1];
    new_item.birth_day[2] = value[2];

            insert(key, value);

		      break;

		case 2:

		      printf("Deleting in Hash table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);

		      break;

		case 3:

		      n = size_of_hashtable();
		      printf("Size of Hash table is-:%d\n", n);

		      break;

		case 4:

		      display();

		      break;
        case 5:

            printf("Enter Search Key:\n");
            scanf("%d",&search_key);
            search(search_key);
            break;

		default:

		       printf("Wrong Input\n");

		}

		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);

	}while(c == 1);

getch();
    return 0;


}

