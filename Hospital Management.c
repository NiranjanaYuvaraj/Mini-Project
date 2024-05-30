#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Patient
struct Patient {
    char name[50];
    int age;
    char gender[10];
    char disease[100];
    int roomNumber;
};

// Function prototypes
void addPatient(struct Patient[], int *);
void displayPatients(struct Patient[], int);
void searchPatient(struct Patient[], int);

int main() {
    struct Patient patients[100];
    int patientCount = 0;
    int choice;

    do {
        // Display menu
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                searchPatient(patients, patientCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a patient
void addPatient(struct Patient patients[], int *patientCount) {
    struct Patient newPatient;
    
    printf("Enter patient name: ");
    scanf(" %[^\n]s", newPatient.name);
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    printf("Enter patient gender: ");
    scanf(" %[^\n]s", newPatient.gender);
    printf("Enter patient disease: ");
    scanf(" %[^\n]s", newPatient.disease);
    printf("Enter patient room number: ");
    scanf("%d", &newPatient.roomNumber);
    
    patients[*patientCount] = newPatient;
    (*patientCount)++;
}

// Function to display all patients
void displayPatients(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("No patients in the hospital.\n");
        return;
    }
    
    printf("\nPatient Details\n");
    printf("Name\t\tAge\tGender\tDisease\t\tRoom\n");
    for (int i = 0; i < patientCount; i++) {
        printf("%-15s\t%d\t%-6s\t%-15s\t%d\n", patients[i].name, patients[i].age, patients[i].gender, patients[i].disease, patients[i].roomNumber);
    }
}

// Function to search for a patient by name
void searchPatient(struct Patient patients[], int patientCount) {
    char name[50];
    printf("Enter patient name to search: ");
    scanf(" %[^\n]s", name);
    
    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(name, patients[i].name) == 0) {
            found = 1;
            printf("\nPatient Found\n");
            printf("Name\t\tAge\tGender\tDisease\t\tRoom\n");
            printf("%-15s\t%d\t%-6s\t%-15s\t%d\n", patients[i].name, patients[i].age, patients[i].gender, patients[i].disease, patients[i].roomNumber);
            break;
        }
    }
    if (!found) {
        printf("Patient not found.\n");
    }
}
