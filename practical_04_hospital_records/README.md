# Practical 4: Hospital Patient Records

## Problem Statement
Maintain patient name, age and temperature using pointer-to-structure functions: input, display, and update temperature with an alert.

## Concepts Used
Pointer to structure, `->` operator, call by reference

## Approach
`inputPatient(Patient*)`, `displayPatient(const Patient*)`, `updateTemperature(Patient*, float)`; alert for fever (>= 100.4 F) or very low temperature (< 95 F). Menu driven.

## Complexity
| Time | Space |
|------|-------|
| O(1) per operation | O(n) |

## How to Run
```bash
gcc -Wall -std=c11 -o hospital_records hospital_records.c
./hospital_records < input.txt
```

## Sample Input (`input.txt`)
```
1
Ravi Kumar
34
98.6
1
Sita Devi
28
101.5
2
3
2
98.2
3
1
94.0
3
7
98
2
0
```

## Sample Output
```

--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: Enter details of patient 1:
  Name        :   Age         :   Temperature : 
--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: Enter details of patient 2:
  Name        :   Age         :   Temperature : 
--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: 1.  Name: Ravi Kumar           Age: 34  Temp: 98.6 F
2.  Name: Sita Devi            Age: 28  Temp: 101.5 F

--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: Patient number: New temperature:   Temperature of Sita Devi updated to 98.2 F.
  Temperature is within the normal range.

--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: Patient number: New temperature:   Temperature of Ravi Kumar updated to 94.0 F.
  *** ALERT: Dangerously low body temperature! ***

--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: Patient number: Invalid patient number.

--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: Invalid choice.

--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: 1.  Name: Ravi Kumar           Age: 34  Temp: 94.0 F
2.  Name: Sita Devi            Age: 28  Temp: 98.2 F

--- Hospital Menu ---
1. Add patient
2. Display all patients
3. Update patient temperature
0. Exit
Choice: Goodbye!
```
