#include "hospital.h"

void displayMenu() 
{
    printf("...Main Menu...\n");
    printf("1. Register patient\n");
    printf("2. View patient\n");
    printf("3. Search by ID\n");
    printf("4. Update patient info\n");
    printf("5. Discharge patient\n");
    printf("6. Enter your option");
    printf("7. Save and Exit\n");
}

//function to handle patient registration
void registerPatient() {
FILE *fp = fopen("patients.dat", "ab");
if (fp == NULL)
    { 
        printf("Error opening file\n");
        return;
                
            
     }
        

}

// function to view all patients
void viewPatients() {
    FILE *fp = fopen("patients.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    Patient patient;
    while (fread(&patient, sizeof(Patient), 1, fp)) {
        printf("ID: %d, Name: %s, Age: %d, Diagnosis: %s, Status: %s\n",
               patient.id, patient.name, patient.age, patient.diagnosis, patient.status);
    }
    
    fclose(fp);
}

//function for admin login
int adminLogin() {
char username[20], password[20];
printf("Enter admin username: ");
scanf("%s", username);
printf("Enter password: ");
scanf("%s", password);
if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0)
return 1;else {
printf("Login failed. Try again.\n");
return 0;
}
}
