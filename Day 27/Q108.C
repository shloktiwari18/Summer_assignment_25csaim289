#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 30
#define NUM_SUBJECTS 5

// Define the Marksheet Structure
typedef struct {
    int roll_number;
    char name[50];
    float marks[NUM_SUBJECTS];
    float total;
    float percentage;
    char grade[3];
    char status[5]; // "PASS" or "FAIL"
} Marksheet;

// Global array database
Marksheet report_db[MAX_STUDENTS];
int student_count = 0;

const char* subject_names[NUM_SUBJECTS] = {
    "Mathematics", "Science", "English", "History", "Computer Sci"
};

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Academic calculation engine
void calculate_marksheet_metrics(Marksheet *student) {
    student->total = 0;
    int failed_any_subject = 0;

    // Sum up marks and check for individual subject failure (passing mark is 40)
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        student->total += student->marks[i];
        if (student->marks[i] < 40.0) {
            failed_any_subject = 1;
        }
    }

    // Compute percentage (Assuming each subject is out of 100)
    student->percentage = (student->total / (NUM_SUBJECTS * 100.0)) * 100.0;

    // Assign Status
    if (failed_any_subject) {
        strcpy(student->status, "FAIL");
        strcpy(student->grade, "F");
    } else {
        strcpy(student->status, "PASS");
        
        // Assign Letter Grade based on percentage bounds
        if (student->percentage >= 90.0) strcpy(student->grade, "A+");
        else if (student->percentage >= 80.0) strcpy(student->grade, "A");
        else if (student->percentage >= 70.0) strcpy(student->grade, "B");
        else if (student->percentage >= 60.0) strcpy(student->grade, "C");
        else if (student->percentage >= 50.0) strcpy(student->grade, "D");
        else strcpy(student->grade, "E");
    }
}

// Generate and add a single marksheet record
void create_marksheet() {
    if (student_count >= MAX_STUDENTS) {
        printf("\n❌ Registry limit reached! Cannot add more marksheet records.\n");
        return;
    }

    Marksheet new_report;

    printf("\nEnter Student Roll Number: ");
    if (scanf("%d", &new_report.roll_number) != 1) {
        printf("❌ Invalid input format.\n");
        clear_buffer();
        return;
    }

    // Verify unique Roll Number
    for (int i = 0; i < student_count; i++) {
        if (report_db[i].roll_number == new_report.roll_number) {
            printf("❌ Conflict: Roll Number %d already exists.\n", new_report.roll_number);
            return;
        }
    }

    printf("Enter Student Name: ");
    clear_buffer();
    fgets(new_report.name, sizeof(new_report.name), stdin);
    new_report.name[strcspn(new_report.name, "\n")] = '\0';

    // Loop to collect marks for all subjects
    printf("\nEnter marks obtained out of 100:\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        while (1) {
            printf(" 👉 %s: ", subject_names[i]);
            if (scanf("%f", &new_report.marks[i]) == 1 && new_report.marks[i] >= 0 && new_report.marks[i] <= 100) {
                break; // Valid input received
            } else {
                printf("    ❌ Invalid score. Please enter a value between 0 and 100.\n");
                clear_buffer();
            }
        }
    }

    // Trigger statistical evaluations
    calculate_marksheet_metrics(&new_report);

    // Commit to memory array
    report_db[student_count] = new_report;
    student_count++;
    printf("\n✅ Marksheet data processed and saved successfully!\n");
}

// Search and print a beautifully formatted single Marksheet Report Card
void generate_report_card() {
    if (student_count == 0) {
        printf("\n📭 No records available to print.\n");
        return;
    }

    int search_roll;
    printf("\nEnter Roll Number to generate report card: ");
    if (scanf("%d", &search_roll) != 1) {
        printf("❌ Selection input error.\n");
        clear_buffer();
        return;
    }

    for (int i = 0; i < student_count; i++) {
        if (report_db[i].roll_number == search_roll) {
            // Visual Print formatting for an individual Marksheet
            printf("\n==================================================\n");
            printf("          🎓 OFFICIAL STUDENT MARKSHEET 🎓         \n");
            printf("==================================================\n");
            printf(" Roll No: %-10d | Name: %s\n", report_db[i].roll_number, report_db[i].name);
            printf("--------------------------------------------------\n");
            printf(" %-25s  %-15s\n", "SUBJECTS", "MARKS OBTAINED");
            printf("--------------------------------------------------\n");
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                printf(" %-25s  %5.1f / 100\n", subject_names[j], report_db[i].marks[j]);
            }
            printf("--------------------------------------------------\n");
            printf(" Aggregate Total:  %5.1f / %d\n", report_db[i].total, NUM_SUBJECTS * 100);
            printf(" Final Percentage: %.2f%%\n", report_db[i].percentage);
            printf(" Status / Result:  %s\n", report_db[i].status);
            printf(" Letter Grade:     %s\n", report_db[i].grade);
            printf("==================================================\n");
            return;
        }
    }
    printf("❌ Roll Number %d not found in the academic system.\n", search_roll);
}

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("📋    Marksheet Generation System    📋\n");
        printf("====================================\n");
        printf("1. Input Student Subject Marks\n");
        printf("2. Generate Individual Report Card\n");
        printf("3. Exit Evaluation System\n");
        printf("Select system option (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Format error. Numbers only.\n");
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1: create_marksheet(); break;
            case 2: generate_report_card(); break;
            case 3: 
                printf("\n👋 Exiting mark processing software. Systems closed safely.\n");
                return 0;
            default: 
                printf("❌ Value error. Selection out of range.\n");
        }
    }
    return 0;
}