#ifndef COMPUTERCOMPONENT_H
#define COMPUTERCOMPONENT_H

#include <stdio.h>

typedef enum {
    HDD,
    CPU,
    RAM,
    GPU,
    MOTHERBOARD,
    COOLING_SYSTEM
} ComponentType;

typedef struct {
    char name[100];
    char code[20];
    ComponentType type;
    float price;
    char manufacturer[100];
    int warranty_months;
} ComputerComponent;

void RemoveNewLineSymbol(char *str);
int ReadComponentFromFile(ComputerComponent *component, FILE *file);
int WriteComponentToFile(ComputerComponent *component, FILE *file);
int ReadComponentArrayFromFile(ComputerComponent *components, int size, FILE *file);
int WriteComponentArrayToFile(ComputerComponent *components, int size, FILE *file);
int ReadBinaryComponent(ComputerComponent *component, FILE *file, int record_number);
int SearchComponentByName(ComputerComponent *components, int size, const char *name);
int SearchComponentByPrice(ComputerComponent *components, int size, float price);

#endif /* COMPUTERCOMPONENT_H */
