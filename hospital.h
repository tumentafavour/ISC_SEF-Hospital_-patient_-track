#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    int age;
    char diagnosis[100];
    char status[20]; // "Admitted" or "Discharged"
} Patient;

// Add Function
void addPatient(Patient patients[], int *count);
void displayPatients(Patient patients[], int count);
void updatePatients(Patient patients[], int count);

int main()
{
    Patient patients[100]; // Array stores patients
    int patientCount = 0;
    int choice;

    for (int i = 0; i < count; i++)
    {
        printf("\nHospital patient tracker\n");
        printf(1. Add patient\n);
        printf(2. Display patient\n);
        printf(3. Update patient\n);
        printf(4. Exit\n);
        printf(Enter your option);
        scanf(% d & option);
        // OPTION
        if (option == 1)
        {
            addPatient(patients, &patientCount);
        }
        if (option == 2)
        {
            displayPatients(patients, patientCount);
        }

        else if (option == 3)
        {
            updatePatients(Patients, patientCount);
        }

        else
        {
            printf("Exit program...\n");
        }
        else
        {
            printf("Invalid option. Please try again\n");
        }

        return 0;
    }
}
