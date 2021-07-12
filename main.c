/***************************************************
* Authors:
*   يوسف خالد محمد عبد المجيد (sec : 4) (B.N.: 54)
*   أدهم محمد أحمد عبد الرحيم (sec : 1) (B.N.: 23)
*   ايمان زكريا شعبان عرفه    (sec : 1) (B.N.: 36)
*
*****************************************************/



#include "program.h"



extern int probing_choice;

extern int max ;

void HashbyString(void);

void HashbyDate(void);

int main(){
    int choice;
    printf("Welcome!\n");
        while(1){
        printf("1. Hash by String.\n"
               "2. Hash by Birthday.\n"
               "3. Exit the program.\n"
               "Choose an Answer: ");
        scanf("%d",&choice);
        if(choice == 1){
            HashbyString();
        }else if( choice == 2){
            HashbyDate();
        }else if(choice == 3){
            return 0;
        }
        else{
            printf("Choose a valid number!\n");
        }

    }

    return 0;
}




void HashbyString(void){
    int choice;
    init();
    student S_Parameters;
    
    while (1)
    {
        printf("1. Insert New Student.\n");
        printf("2. Search for a student.\n");
        printf("3. Delete a student.\n");
        printf("4. Exit.\n");
        printf("Choose the number of the operation: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                StoringData(&S_Parameters);
                InsertbyName(S_Parameters);
                break;
            case 2:
                SearchbyName();
                break;
            case 3:
                DeletebyName();
                break;
            case 4:
                return;
            default:
                printf("Enter a valid number 1, 2 or 3\n");
                break;
        }
    
    }
   
    

  return;

}


void HashbyDate(void){
    printf("Enter_Size:\n");
	scanf("%d",&max);

	int choice, key, value[3], n, c;
	int search_key;
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item*));
	init_array();
    //printf("%d",new_item->key);
	printf("In case of collision ,Choose Type :\n");
	printf("[1]Linear Probing\n");
	printf("[2]Quadratic Probing\n");
	scanf("%d",&probing_choice);

	do 
	{
		switch(probing_choice){
			case 1:
				printf("Implementation of Hash Table in C with linear Probing.\n\n");
				break;
			case 2:
				printf("Implementation of Hash Table in C with Quadratic Probing.\n\n");
				break;
			default:
				printf("Implementation of Hash Table in C with linear Probing.\n\n");
				break;
		}

		printf("MENU-: \n1.Inserting item in the Hash table"
					  "\n2.Removing item from the Hash table"
					  "\n3.Check the size of Hash table"
					  "\n4.Display Hash table"
					  "\n5.Search"
                      "\n6.exit"
				"\n\n Please enter your choice-:");

		scanf("%d", &choice);

		switch(choice)
		{

			case 1:

				printf("Inserting element in Hash table \n");
                printf("Enter Name: \n");
	            scanf("%s",new_item.s.Name);
                if(new_item.s.Name[0] >= 97){  //first letter is small
                    new_item.s.Name[0] -= ('a' - 'A'); //turn it into a capital letter
                }
                printf("Enter ID: \n");
                scanf("%d",&(new_item.s.ID));
				printf("Enter birthday-:\n");
                printf("Enter day: ");
				scanf("%d",&value[0]);
                printf("Enter month: ");
				scanf("%d",&value[1]);
                printf("Enter year: ");
				scanf("%d",&value[2]);
                printf("Enter score of the last year): \n");
	            scanf("%d",&(new_item.s.Score));

				key = FACTOR*FACTOR*value[0] + FACTOR*value[1] + value[2];
				new_item.key = key;
				new_item.s.Date[0] = value[0];
				new_item.s.Date[1] = value[1];
				new_item.s.Date[2] = value[2];
				
				insert(key, value);
				break;

			case 2:
				printf("Enter birthday-:\n");
                printf("Enter day: ");
				scanf("%d",&value[0]);
                printf("Enter month: ");
				scanf("%d",&value[1]);
                printf("Enter year: ");
				scanf("%d",&value[2]);
				search_key = hashDate(value);
				remove_element(search_key);
				break;

			case 3:
				n = size_of_hashtable();
				printf("Size of Hash table is-:%d\n", n);
				break;

			case 4:
				display();
				break;
			
			case 5:
				printf("Enter birthday-:\n");
                printf("Enter day: ");
				scanf("%d",&value[0]);
                printf("Enter month: ");
				scanf("%d",&value[1]);
                printf("Enter year: ");
				scanf("%d",&value[2]);
				search_key = hashDate(value);
				search(search_key);
				break;
            case 6:
                return;
			default:
				printf("Wrong Input\n");

		}

		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);

	}while(c == 1);

    return;
}
