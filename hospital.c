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

// Function to update patient information
void updatePatientInfo()
{
    int id;
    printf("Enter patient ID to update: ");
    scanf("%d", &id);

    // Search for patient in your data structure
    Patient *patient = findPatientById(id);
    if (patient == NULL)
    {
        printf("Patient with ID %d is not found \n");
        return 1;
    }
    // Display current info
    printf("\nCurrent Patient information\n");
    printf("ID: %d\n", patient->id);
    printf("Name: %s\n", patient->name);
    printf("Age: %d\n", patient->age);
    printf("Diagnosis: %s\n", patient->diagnosis);
    printf("Doctor: %s\n", patient->assignedDoctor);
    printf("Status: %s\n", patient->status);

    // Updating the information
    printf("\nEnter new information or press 8 to keep current info:\n");

    // Updating Diagnosis
    printf("Diagnosis [%s]: ", patient->diagnosis);
    char newDiagnosis[100];
    getchar();
    fgets(newDiagnosis, sizeof(newDiagnosis), stdin);

    newDiagnosis[strcspn99(newDiagnosis, "\n")] = '\0';
    if (strlen(newDiagnosis) > 0)
    {
        strcpy(patient->diagnosis, newDiagnosis);
    }

    // Update Assigned Doctor
    printf("Assigned Doctor [%s]: ", patient->assignedDoctor);
    char newDoctor[100];
    fgets(newDoctor, sizeof(newDoctor), stdin);
    newDoctor[strcspn(newDoctor, "\n")] = '\0';

    if (strlen(newDoctor) > 0)
    {
        strcpy(patient->assignedDoctor, newDoctor);
    }

    // Update status: Admitted or Discharged
    printf("Status (A for Admitted and D for Discharged) [%s]:", patient->status);
    char statusChoice[20];
    scanf("%c", &statusChoice);
    if (statusChoice == 'A' || statusChoice == 'a')
    {
        strcpy(patient->status, "Admitted");
    }
    else if (statusChoice == 'D' || statusChoice == 'd')
    {
        strcpy(patient->status, "Discharged");
    }
    printf("\nPatient information updated successfully.\n");

    // Display updated information
    printf("...Updated information...\n");
    printf("ID: %d\n", patient->id);
    printf("Name: %s\n", patient->name);
    printf("Age: %d\n", patient->age);
    printf("Diagnosis: %s\n", patient->diagnosis);
    printf("Doctor: %s\n", patient->doctor);
    printf("Status: %s\n", patient->status);
}

// Discharge Patient
void dischargePatient()
{
    int id;
    printf("Enter patient ID to discharge: ");
    scanf("%d", &id);

    // Here is to search for patient
    Patient *patient = findPatientById(id);

    if (patient == NULL)
    {
        printf("Patient with ID %d not found.\n", id);
        return 1;
    }

    // Confirm Discharge
    printf("Are you sure you want to get discharged %s (ID: %d)? (y/n): ",
           patient->name, patient->id);
    char confirm;
    scanf("%c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        // Remove a particular patient from the data structure
        removePatient(id);
        printf("Patient discharged successfully.\n");
    }
    else
    {
        printf("Discharge Cancelled.\n");
    }
}

// Save and Exit
void save_and_exit()
{
    FILE *file = fopen("patients.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file for saving.\n");
        return 1;
    }
    // Save all patients to file
    for (int i = 0; i < patientCount; i++)
    {
        fwrite(&patients[i], sizeof(Patient), 1, file);
    }

    fclose(file);
    printf("Patient data saved successfully. Exiting...\n");
}