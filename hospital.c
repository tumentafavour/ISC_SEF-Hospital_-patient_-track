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
FILE *fp = fopen("patients.dat", "ab"); //opens the file in append binary mode
if (fp == NULL){
         
            printf("Error opening file\n");
            return;
            fclose(fp);    
            
    
             }
             if (fwrite(&newPatient, sizeof(Patient), 1, fp) != 1){
                fprintf(stderr, "Error writing to file\n");
                fclose(fp);
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
//function to create a new patient
Patient newPatient() {
    Patient patient;
    printf("Enter patient ID: ");
    scanf("%d", &patient.id);
    printf("Enter patient name: ");
    scanf("%s", patient.name);
    printf("Enter patient age: ");
    scanf("%d", &patient.age);
    printf("Enter diagnosis: ");
    scanf("%s", patient.diagnosis);
    strcpy(patient.status, "Admitted"); // Default status
    return patient;
}
//function to search for a patient by ID
void searchbyID() {
    int id;
    printf("Enter patient ID to search: ");
    scanf("%d", &id);
    FILE *fp = fopen("patients.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
}