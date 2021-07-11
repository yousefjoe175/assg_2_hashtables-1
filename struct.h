#include <stdio.h>
#include <conio.h>

struct Student
{
    char Name[30];
    int ID;
    int Date[3]; 
    int Score;
};


typedef struct Student student;
#define SIZE 13
#define FACTOR 7