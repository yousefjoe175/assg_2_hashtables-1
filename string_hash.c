#include "program.h"

//the array that contains the head pointers of the hash table
Node* chain[SIZE];  //size = 13

//initialize the array of pinters to be all NULL
void init(){
    for(int i =0; i<SIZE; i++){
        chain[i] = NULL;
    }
}

//to store the data of the student need to be inserted
void StoringData(student* input){

	 printf("Enter Name: \n");
	 scanf("%s",input->Name);
     if(input->Name[0] >= 97){  //first letter is small
        input->Name[0] -= ('a' - 'A'); //turn it into a capital letter
     }
	 printf("Enter ID: \n");
	 scanf("%d",&input->ID);
	 printf("Enter Date of birth (Day): \n");
	 scanf("%d",&input->Date[0]);
	 printf("Enter Date of birth (Month): \n");
	 scanf("%d",&input->Date[1]);
	 printf("Enter Date of birth (Year): \n");
	 scanf("%d",&input->Date[2]);
	 printf("Enter score of the last year): \n");
	 scanf("%d",&input->Score);
}

//print out the data of the student searched for
void printStruct(student s){
    printf("\n");
    printf("Name: %s\n",s.Name);
    printf("ID: %d\n",s.ID);
    printf("Date: %d/%d/%d\n",s.Date[0],s.Date[1],s.Date[2]);
    printf("Score: %d\n", s.Score);
    printf("\n");
}

//the function that hashes the string name and produce the hash key
int HashName(char* name){
    //implement the hash function
    int len,factor, hash;
    factor = FACTOR;    // the factor is 7
    len = 0;
    while(name[len] != '\0'){
        len++;
    }
    hash = 0;
    for(int i = 0; i<len; i++){
        int m = 
        hash = factor*hash + name[i];         //the hashing equation: name[0]*factor^(len) + name[1]*factor^(len-1)+ ..
    }
    return hash;
}

//inserting a new student function 
void InsertbyName(student s_parameter){

    int n = HashName(s_parameter.Name);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->s = s_parameter;
    newNode->id = n;
    newNode->next = NULL;
    int m = n%SIZE;
    if(chain[m] == NULL){
        chain[m] = newNode;
    }
    else{
        Node* temp = chain[m];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

}
//search for a node by the name by hashing the name inputted and search for the hash key in nodes' id then print out the data structure s
void SearchbyName(void){
    char name[30];
    printf("Enter the Name You want to search for: ");
    scanf("%s", name);

     if(name[0] >= 97){  //first letter is small
        name[0] -= ('a' - 'A'); //turn it into a capital letter
     }
    int n = HashName(name);
    int m = n%SIZE;
    Node* temp = chain[m];
    while(temp != NULL){
        if(temp->id == n){
            printStruct(temp->s);   //print the struct s of the node identified by the hash key
            return;
        }else{
            temp = temp->next;
        }

    }
    printf("Name Doesn't Exist!\n\n");
    return;

}

//delete the node that contains the name inputted by hashing the name and search for the key value in nodes' id then delete the node.
void DeletebyName(void){
    char name[30];
    printf("Enter the name you want to delete: ");
    scanf("%s",name);

    if(name[0] >= 97){  //first letter is small
        name[0] -= ('a' - 'A'); //turn it into a capital letter
    }

    int n = HashName(name);
    int m = n%SIZE;
    Node* temp;
    if(chain[m] == NULL){
        //go to the final statement
    }
    else if(chain[m]->id == n){
        temp = chain[m];
        chain[m] = chain[m]->next;
        free(temp);
        printf("%s has been deleted successfully!\n\n");
        return;
    }else{
        temp = chain[m]->next;
        Node* prev = chain[m];
        while(temp != NULL){
            if(temp->id == n){
                prev->next = temp->next;
                free(temp);
                printf("%s has been deleted successfully!\n\n");
                return;
            }else{
                temp = temp->next;
                prev = prev->next;
            }
        }
    }

    printf("Name Doesn't Exist!\n\n");
    return;
}


/*
void main(void){
    int choice;
    init();
    student S_Parameters;
    
    while (1)
    {
        printf("1. Insert New Student.\n");
        printf("2. Search for a student.\n");
        printf("3. Delete a student.\n");
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
            default:
                printf("Enter a valid number 1, 2 or 3\n");
                break;
        }
    
    }
   
    

    system("pause");



}

*/