#include <intrin.h>
#include "ComputerComponent.h"

void RemoveNewLineSymbol(char *str) {
    while (*str) {
        if (*str == '\n' || *str == '\r') {
            *str = '\0';
            return;
        }
        str++;
    }
}

int ReadComponentFromFile(ComputerComponent *component, FILE *file) {
    if (!fgets(component->name, 100, file))
        return 0;
    RemoveNewLineSymbol(component->name);
    if (!fgets(component->code, 20, file))
        return 0;
    RemoveNewLineSymbol(component->code);
    char type_str[20];
    if (!fgets(type_str, 20, file))
        return 0;
    RemoveNewLineSymbol(type_str);
    if (strcmp(type_str, "HDD") == 0)
        component->type = HDD;
    else if (strcmp(type_str, "CPU") == 0)
        component->type = CPU;
    else if (strcmp(type_str, "RAM") == 0)
        component->type = RAM;
    else if (strcmp(type_str, "GPU") == 0)
        component->type = GPU;
    else if (strcmp(type_str, "Motherboard") == 0)
        component->type = MOTHERBOARD;
    else if (strcmp(type_str, "Cooling System") == 0)
        component->type = COOLING_SYSTEM;
    else
        return 0;
    fscanf(file, "%f", &component->price);
    fscanf(file, "%s", component->manufacturer);
    fscanf(file, "%d", &component->warranty_months);
    return 1;
}

int WriteComponentToFile(ComputerComponent *component, FILE *file) {
    fprintf(file, "%s\n%s\n", component->name, component->code);
    switch (component->type) {
        case HDD:
            fprintf(file, "HDD\n");
            break;
        case CPU:
            fprintf(file, "CPU\n");
            break;
        case RAM:
            fprintf(file, "RAM\n");
            break;
        case GPU:
            fprintf(file, "GPU\n");
            break;
        case MOTHERBOARD:
            fprintf(file, "Motherboard\n");
            break;
        case COOLING_SYSTEM:
            fprintf(file, "Cooling System\n");
            break;
    }
    fprintf(file, "%.2f\n%s\n%d\n", component->price, component->manufacturer, component->warranty_months);
    return 1;
}

int ReadComponentArrayFromFile(ComputerComponent *components, int size, FILE *file) {
    for (int i = 0; i < size; i++) {
        if (!ReadComponentFromFile(&components[i], file))
            return 0;
    }
    return 1;
}

int WriteComponentArrayToFile(ComputerComponent *components, int size, FILE *file) {
    for (int i = 0; i < size; i++) {
        if (!WriteComponentToFile(&components[i], file))
            return 0;
    }
    return 1;
}

int ReadBinaryComponent(ComputerComponent *component, FILE *file, int record_number) {
    fseek(file, record_number * sizeof(ComputerComponent), SEEK_SET);
    if (fread(component, sizeof(ComputerComponent), 1, file) != 1)
        return 0;
    return 1;
}

int SearchComponentByName(ComputerComponent *components, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(components[i].name, name) == 0)
            return i;
    }
    return -1;
}

int SearchComponentByPrice(ComputerComponent *components, int size, float price) {
    for (int i = 0; i < size; i++) {
        if (components[i].price == price)
            return i;
    }
    return -1;
}
