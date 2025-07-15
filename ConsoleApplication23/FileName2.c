#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h> // For strcpy
#include"FileName.h"

// Function to set car details
void set_car(car* c, const char* n, float g) {
    // Allocate memory for the name string
    // +1 for the null terminator
    c->name = (char*)malloc(strlen(n) + 1);
    if (c->name == NULL) {
        perror("Failed to allocate memory for name");
        exit(EXIT_FAILURE); // Exit if allocation fails
    }
    strcpy(c->name, n); // Copy the string
    c->gas = g;
}

void set_car_show(void) {
    car* ca; // Declare a pointer to a car

    // Allocate memory for the car struct itself
    ca = (car*)malloc(sizeof(car));
    if (ca == NULL) {
        perror("Failed to allocate memory for car struct");
        return 1; // Indicate an error
    }

    // Call set_car to initialize the allocated car struct
    set_car(ca, "kix", 14.5);

    // Print the car details
    printf("Car Name: %s\n", ca->name);
    printf("Gas Level: %lf\n", ca->gas);

    // --- IMPORTANT: Free allocated memory ---
    free(ca->name); // Free the memory for the name string
    free(ca);       // Free the memory for the car struct

    return 0;
}