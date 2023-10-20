#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
typedef struct {
    char name[50];
    char roll_number[10];
    float cgpa;
} Student;

// Comparison function for qsort to sort students by CGPA in descending order
int compare_students(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    if (studentA->cgpa < studentB->cgpa) return 1;
    if (studentA->cgpa > studentB->cgpa) return -1;
    return 0;
}

// Function to sort students based on CGPA in descending order
void sort_students(Student* students, int num_students) {
    qsort(students, num_students, sizeof(Student), compare_students);
}

int main() {
    // Test data with an array of student objects
    Student students[] = {
        {"Alice", "S101", 3.8},
        {"Bob", "S102", 3.5},
        {"Charlie", "S103", 3.9},
        {"David", "S104", 3.7},
        {"Eve", "S105", 4.0}
    };

    int num_students = sizeof(students) / sizeof(students[0]);

    printf("Unsorted students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s (%s) - CGPA: %.2f\n", students[i].name, students[i].roll_number, students[i].cgpa);
    }

    sort_students(students, num_students);

    printf("\nSorted students by CGPA (descending order):\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s (%s) - CGPA: %.2f\n", students[i].name, students[i].roll_number, students[i].cgpa);
    }

    return 0;
}
