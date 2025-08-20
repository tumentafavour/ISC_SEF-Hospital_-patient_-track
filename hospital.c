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


// Function to handle patient registration
void registerPatient() {
    FILE *fp = fopen("patients.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Patient newPatient;
    
    // Prompt for patient details 
    printf("Enter patient name: ");
    scanf(" %[^\n]s", newPatient.name);
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    printf("Enter diagnosis: ");
    scanf(" %[^\n]s", newPatient.diagnosis);
    
    // Assign a default ID and doctor 
    // A more robust implementation would auto-increment the ID
    newPatient.id = 1; 
    strcpy(newPatient.assignedDoctor.name, "Dr. Yannick");
    strcpy(newPatient.assignedDoctor.specialization, "General Physician");
    strcpy(newPatient.status, "Admitted"); // Set initial status 

    // Write the new patient record to the file 
    fwrite(&newPatient, sizeof(Patient), 1, fp);
    fclose(fp);
    printf("Patient registered successfully!\n");
}


// Function to view all patient records
void viewPatients() {
    FILE *fp = fopen("patients.dat", "rb");
    if (fp == NULL) {
        printf("No patient records found.\n");
        return;
    }

    Patient patient;
    printf("\n--- All Patient Records ---\n");
    // Read and display each record from the file 
    while(fread(&patient, sizeof(Patient), 1, fp) == 1) {
        printf("ID: %d, Name: %s, Age: %d, Diagnosis: %s, Status: %s, Doctor: %s\n", 
               patient.id, patient.name, patient.age, patient.diagnosis, 
               patient.status, patient.assignedDoctor.name);
    }
    fclose(fp);
}

// Function to search for a patient by ID or name
void searchPatient() {
    // Search implementation as described in the flow overview 
    printf("Search function is not yet fully implemented.\n");
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