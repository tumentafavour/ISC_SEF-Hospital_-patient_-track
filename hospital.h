#ifdef HOSPITAL_H
#define HOSPITAL_H

typedef struct {
    int id;
    char name[50];
    char password[20];
} Admin;
typedef struct {
char name[50];
char specialization[50];
} Doctor;

typedef struct {
int id;
char name[50];
int age;
char diagnosis[100];
char status[20]; // "Admitted" or "Discharged"
} Patient;


void save_and_exit();
void load_records();
void displplayMenu();
void adminLogin();
void registerPatient();
void viewPatients();
void searchbyID();
void updatePatientInfo();
void dischargePatient();
