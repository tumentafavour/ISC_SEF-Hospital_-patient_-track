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
void registerPatient(); {
FILE *fp = fopen("patients.dat", "ab");
if (fp = = NULL)
    { 
        printf("Error opening file\n");
        return;
                
            
     }
        

}