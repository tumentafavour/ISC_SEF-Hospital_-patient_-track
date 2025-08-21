#include "hospital.h"


void displayMenu() 
{
    printf("...Main Menu...\n");
    printf("1. Register patient\n");
    printf("2. View patient\n");
    printf("3. Search by ID\n");
    printf("4. Update patient info\n");
    printf("5. Discharge patient\n");
    printf("6. Save and Exit\n");
}


// Function to handle patient registration
void registerPatient() {
    FILE *fp = fopen("patients.dat", "ab+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Patient newPatient;
    Patient tempPatient;
    
    // Prompt for patient details 
    printf("Enter patient name: ");
    scanf(" %[^\n]s", newPatient.name);
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    printf("Enter diagnosis: ");
    scanf(" %[^\n]s", newPatient.diagnosis);
    
    // Assign a default ID and doctor 
    // A more robust implementation would auto-increment the ID

 
    

    // Determine the next available ID
    int maxId = 0;
    
    // Seek to the beginning of the file to read existing records
    fseek(fp, 0, SEEK_SET);

    // Read all existing patient records to find the maximum ID
    while (fread(&tempPatient, sizeof(Patient), 1, fp) == 1) {
        if (tempPatient.id > maxId) {
            printf("it worked\n");
            maxId = tempPatient.id;
        
        }
    }
     newPatient.id = maxId + 1; //assigns the next available id
     
    



    strcpy(newPatient.assignedDoctor.name, "Dr. Yannick");
    strcpy(newPatient.assignedDoctor.specialization, "General Physician");
    strcpy(newPatient.status, "Admitted"); // Set initial status 
    
    {
        
    }
    

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

// Function to search for a patient by ID 
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
if (strcmp(username, "ispark") == 0 && strcmp(password, "1234") == 0)
return 1;else {
printf("Login failed. Try again.\n");
return 0;
}
}

//function to search for a patient by ID

void searchbyID(int id) {
    FILE *fp = fopen("patients.dat", "rb");
    if (fp == NULL) {
        printf("No patient records found.\n");
        return;
    
    
    }

        printf("Enter patient ID to search: ");
    scanf("%d", &id);

    Patient patient;
    while (fread(&patient, sizeof(Patient), 1, fp) == 1) {
        if (patient.id == id) {
            printf("Patient found:\n");
            printf("ID: %d, Name: %s, Age: %d, Diagnosis: %s, Status: %s, Doctor: %s\n", patient.id, patient.name, patient.age, patient.diagnosis, patient.status, patient.assignedDoctor.name);
            fclose(fp);
            return;
        }
    }

    printf("Patient with ID %d not found.\n", id);
    fclose(fp);
}

void updatePatientInfo() {
    FILE *fp = fopen("patients.dat", "rb+");
    if (fp == NULL) {
        printf("No patient records found.\n");
        return;
    }

    Patient patient;
    int id;
    char name[50];
    

    printf("Enter patient ID to update: ");
    scanf("%d", &id);
    

    // Find the patient record
    while (fread(&patient, sizeof(Patient), 1, fp) == 1) {
        if (patient.id == id) {
            printf("Patient found:\n");
            printf("ID: %d, Name: %s, Age: %d, Diagnosis: %s, Status: %s, Doctor: %s\n", patient.id, patient.name, patient.age, patient.diagnosis, patient.status, patient.assignedDoctor.name);

            // Update patient information
            printf("Enter new patient name: ");
            scanf(" %[^\n]s", patient.name);
            printf("Enter new patient age: ");
            scanf("%d", &patient.age);
            printf("Enter new diagnosis: ");
            scanf(" %[^\n]s", patient.diagnosis);

            // Update the record
            fseek(fp, -sizeof(Patient), SEEK_CUR);
            fwrite(&patient, sizeof(Patient), 1, fp);
            fclose(fp);
            printf("Patient record updated successfully!\n");
            return;
        }
    }

    printf("Patient with ID %d not found.\n", id);
    fclose(fp);
}
void dischargePatient() {
    FILE *fp = fopen("patients.dat", "rb+");
    if (fp == NULL) {
        printf("No patient records found.\n");
        return;
    }

    Patient patient;
    int id;

    printf("Enter patient ID to discharge: ");
    scanf("%d", &id);

    // Find the patient record
    while (fread(&patient, sizeof(Patient), 1, fp) == 1) {
        if (patient.id == id) {
            printf("Patient found:\n");
            printf("ID: %d, Name: %s, Age: %d, Diagnosis: %s, Status: %s, Doctor: %s\n", patient.id, patient.name, patient.age, patient.diagnosis, patient.status, patient.assignedDoctor.name);

            // Discharge the patient
            strcpy(patient.status, "Discharged");

            // Update the record
            fseek(fp, -sizeof(Patient), SEEK_CUR);
            fwrite(&patient, sizeof(Patient), 1, fp);
            fclose(fp);
            printf("Patient discharged successfully!\n");
            return;
        }
    }

    printf("Patient with ID %d not found.\n", id);
    fclose(fp);
}

