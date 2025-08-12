#ifndef HOSPITAL_H
#define HOSPITAL_H

typedef struct
{
    int id;
    char name[50];
    char password[20];
} Admin;
typedef struct
{
    char name[50];
    char specialization[50];
    char date[12];
} Doctor;

typedef struct
{
    int id;
    char name[50];
    int age;
    char diagnosis[100];
    char status[20]; // "Admitted" or "Discharged"
    char date[12];
} Patient;

int main()
{
    int d;

    while (1)
    {
        system("clear");
        printf("...Welcome to this Hospital system...\n");
        printf("1. Admit Patient\n");
        printf("Patient list\n");
        printf("")

#endif