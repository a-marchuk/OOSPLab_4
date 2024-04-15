#include <stdio.h>
#include "ComputerComponent.h"

int main() {
    ComputerComponent cpu1 = {
            "Intel Core i7-10700K",
            "INTEL123",
            CPU,
            400.50,
            "Intel",
            24
    };

    printf("Component details:\n");
    printf("Name: %s\n", cpu1.name);
    printf("Code: %s\n", cpu1.code);
    printf("Type: %d\n", cpu1.type);
    printf("Price: %.2f\n", cpu1.price);
    printf("Manufacturer: %s\n", cpu1.manufacturer);
    printf("Warranty (months): %d\n", cpu1.warranty_months);

    FILE *outputFile = fopen("components.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }
    WriteComponentToFile(&cpu1, outputFile);
    fclose(outputFile);

    ComputerComponent cpu2;
    FILE *inputFile = fopen("components.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    ReadComponentFromFile(&cpu2, inputFile);
    fclose(inputFile);

    const char *searchName = "AMD Ryzen 9 5900X";
    int index = SearchComponentByName(&cpu2, 1, searchName);
    if (index != -1) {
        printf("Component found at index %d\n", index);
    } else {
        printf("Component not found\n");
    }

    return 0;
}
