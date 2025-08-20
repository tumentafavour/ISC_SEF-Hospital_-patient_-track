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
            }
        
         Patient newPatient;
        //prompt patient details
        printf("Enter patient name:\n");
        scanf("%s\n", newPatient.name);
        printf("Enter patient age:\n");
        scanf("%d\n", &newPatient.age);
        printf("Enter diagnosis");
        scanf("%s\n", &newPatient.diagnosis);
        //assign a default id and doctor 
        // A more robust implementation would auto-increment the id 
        newPatient.id = 1;
        strcpy(newPatient.assignedDoctor.name, "Dr Yannick");
        strcpy(newPatient.assignedDoctor.specialization, "General physician");
        strcpy(newPatient.status, "admitted");// set initial status
        // write the new patient record to the file
        fwrite(&newPatient, sizeof(Patient), 1, fp);
        fclose(fp);
        printf("patient registered successfully");

        

}

// function to view all patients
void viewPatients() {
    FILE *fp = fopen("patients.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
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