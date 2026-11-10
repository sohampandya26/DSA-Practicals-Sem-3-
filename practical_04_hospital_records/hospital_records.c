/*
 * Practical 4 : Hospital patient records using pointer to structure
 * Concepts    : struct pointers, '->' operator, call by reference
 */
#include <stdio.h>

#define MAX_PATIENTS 20
#define FEVER_F      100.4f   /* temperature (deg F) at/above which a fever alert is raised */
#define LOW_F        95.0f

typedef struct {
    char  name[50];
    int   age;
    float temperature;   /* deg Fahrenheit */
} Patient;

/* 1. Input patient details through a structure pointer */
void inputPatient(Patient *p)
{
    printf("  Name        : ");
    scanf(" %49[^\n]", p->name);
    printf("  Age         : ");
    scanf("%d", &p->age);
    printf("  Temperature : ");
    scanf("%f", &p->temperature);
}

/* 2. Display patient details */
void displayPatient(const Patient *p)
{
    printf("  Name: %-20s Age: %-3d Temp: %.1f F\n", p->name, p->age, p->temperature);
}

/* 3. Update temperature and print an alert when abnormal */
void updateTemperature(Patient *p, float newTemp)
{
    p->temperature = newTemp;
    printf("  Temperature of %s updated to %.1f F.\n", p->name, p->temperature);
    if (newTemp >= FEVER_F)
        printf("  *** ALERT: High fever! Doctor must examine the patient immediately. ***\n");
    else if (newTemp < LOW_F)
        printf("  *** ALERT: Dangerously low body temperature! ***\n");
    else
        printf("  Temperature is within the normal range.\n");
}

int main(void)
{
    Patient list[MAX_PATIENTS];
    int count = 0, choice;

    do {
        printf("\n--- Hospital Menu ---\n1. Add patient\n2. Display all patients\n"
               "3. Update patient temperature\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
        case 1:
            if (count == MAX_PATIENTS) { printf("Record book is full.\n"); break; }
            printf("Enter details of patient %d:\n", count + 1);
            inputPatient(&list[count]);
            count++;
            break;
        case 2:
            if (count == 0) printf("No patients yet.\n");
            for (int i = 0; i < count; i++) {
                printf("%d.", i + 1);
                displayPatient(&list[i]);
            }
            break;
        case 3: {
            int no; float t;
            printf("Patient number: ");
            scanf("%d", &no);
            if (no < 1 || no > count) { printf("Invalid patient number.\n"); break; }
            printf("New temperature: ");
            scanf("%f", &t);
            updateTemperature(&list[no - 1], t);
            break;
        }
        case 0: printf("Goodbye!\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
