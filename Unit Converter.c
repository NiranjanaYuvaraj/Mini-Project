#include <stdio.h>

// Function prototypes
void displayMenu();
float convertToMeter(float, int);
void displayResult(float, int);

int main() {
    int choice;
    float value, result;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter the value to convert: ");
            scanf("%f", &value);
            result = convertToMeter(value, choice);
            displayResult(result, choice);
        } else if (choice != 5) {
            printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the conversion menu
void displayMenu() {
    printf("\nUnit Converter Menu\n");
    printf("1. Inches to Meters\n");
    printf("2. Feet to Meters\n");
    printf("3. Yards to Meters\n");
    printf("4. Miles to Meters\n");
    printf("5. Exit\n");
}

// Function to convert the given value to meters based on the choice
float convertToMeter(float value, int choice) {
    switch (choice) {
        case 1:
            return value * 0.0254; // Inches to meters
        case 2:
            return value * 0.3048; // Feet to meters
        case 3:
            return value * 0.9144; // Yards to meters
        case 4:
            return value * 1609.34; // Miles to meters
        default:
            return 0.0;
    }
}

// Function to display the result of the conversion
void displayResult(float result, int choice) {
    switch (choice) {
        case 1:
            printf("Result: %.2f inches = %.2f meters\n", result / 0.0254, result);
            break;
        case 2:
            printf("Result: %.2f feet = %.2f meters\n", result / 0.3048, result);
            break;
        case 3:
            printf("Result: %.2f yards = %.2f meters\n", result / 0.9144, result);
            break;
        case 4:
            printf("Result: %.2f miles = %.2f meters\n", result / 1609.34, result);
            break;
    }
}
