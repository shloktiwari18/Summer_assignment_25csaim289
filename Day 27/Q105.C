#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the Student structure
typedef struct {
    int roll_number;
    char name[50];
    float gpa;
} Student;

// Global array to store student records and a counter
Student database[MAX_STUDENTS];
int student_count = 0;

// Function to clear input buffer issues
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a new student record
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("\n❌ Error: Database is full. Cannot add more students.\n");
        return;
    }

    Student new_student;

    printf("\nEnter Roll Number: ");
    if (scanf("%d", &new_student.roll_number) != 1) {
        printf("❌ Invalid input. Record creation failed.\n");
        clear_buffer();
        return;
    }

    // Check if roll number already exists
    for (int i = 0; i < student_count; i++) {
        if (database[i].roll_number == new_student.roll_number) {
            printf("❌ Error: A student with Roll Number %d already exists.\n", new_student.roll_number);
            return;
        }
    }

    printf("Enter Student Name: ");
    clear_buffer(); // Clear buffer before reading string with spaces
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter GPA (0.0 - 4.0): ");
    if (scanf("%f", &new_student.gpa) != 1 || new_student.gpa < 0.0 || new_student.gpa > 4.0) {
        printf("❌ Invalid GPA. Record creation failed.\n");
        clear_buffer();
        return;
    }

    // Save into our database array
    database[student_count] = new_student;
    student_count++;
    printf("✅ Student record added successfully!\n");
}

// Function to display all student records
void display_students() {
    if (student_count == 0) {
        printf("\n📭 The student database is currently empty.\n");
        return;
    }

    printf("\n%-12s %-25s %-5s\n", "Roll Number", "Name", "GPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-12d %-25s %-5.2f\n", database[i].roll_number, database[i].name, database[i].gpa);
    }
}

// Function to search for a student by roll number
void search_student() {
    if (student_count == 0) {
        printf("\n📭 The student database is empty. Nothing to search.\n");
        return;
    }

    int search_roll;
    printf("\nEnter Roll Number to search: ");
    if (scanf("%d", &search_roll) != 1) {
        printf("❌ Invalid input.\n");
        clear_buffer();
        return;
    }

    for (int i = 0; i < student_count; i++) {
        if (database[i].roll_number == search_roll) {
            printf("\n🔍 Student Found:\n");
            printf("-------------------------\n");
            printf("Roll Number: %d\n", database[i].roll_number);
            printf("Name:        %s\n", database[i].name);
            printf("GPA:         %.2f\n", database[i].gpa);
            return;
        }
    }

    printf("❌ Student with Roll Number %d not found.\n", search_roll);
}

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("🎓 Student Record Management System 🎓\n");
        printf("====================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid menu choice. Please type a number.\n");
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                printf("\n👋 Exiting Student Management System. Goodbye!\n");
                return 0;
            default:
                printf("❌ Out of range. Please choose an option between 1 and 4.\n");
        }
    }

    return 0;
}