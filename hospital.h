#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
} Doctor;

typedef struct {
int id;
char name[50];
int age;
char status[20]; // "Admitted" or "Discharged"
char diagnosis[100];
Doctor assignedDoctor;
} Patient;

void save_and_exit();
void load_fromfile();
void displayMenu();
int adminLogin();
void registerPatient();
void viewPatients();
void searchbyID();
void updatePatientInfo();
void dischargePatient();

#endif // HOSPITAL_H