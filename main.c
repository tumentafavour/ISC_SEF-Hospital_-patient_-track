#include "hospital.h"
int main() {
  // check for admin login success
if ((!adminLogin())) {
    printf("Access denied. Exiting...\n");
    return 1;
}
int choice;
do {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice); 
    switch (choice) {
        case 1:
            registerPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            // searchById(); // Function to be implemented
            break;
        case 4:
            // updatePatientInfo(); // Function to be implemented
            break;
        case 5:
            // dischargePatient(); // Function to be implemented
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }


}