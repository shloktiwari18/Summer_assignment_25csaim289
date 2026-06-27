#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 50

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char department[30];
    double salary;
} Employee;

// Global array and counter to simulate a database table
Employee staff_db[MAX_EMPLOYEES];
int employee_count = 0;

// Utility function to flush input buffers safely
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a new employee
void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\n❌ Database full! Cannot add more employees.\n");
        return;
    }

    Employee new_emp;

    printf("\nEnter unique Employee ID: ");
    if (scanf("%d", &new_emp.id) != 1) {
        printf("❌ Invalid ID type. Operation canceled.\n");
        clear_buffer();
        return;
    }

    // Enforce primary key uniqueness (ID checking)
    for (int i = 0; i < employee_count; i++) {
        if (staff_db[i].id == new_emp.id) {
            printf("❌ ID Conflict: Employee ID %d already exists.\n", new_emp.id);
            return;
        }
    }

    printf("Enter Employee Name: ");
    clear_buffer();
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = '\0'; // Strip newline

    printf("Enter Department: ");
    fgets(new_emp.department, sizeof(new_emp.department), stdin);
    new_emp.department[strcspn(new_emp.department, "\n")] = '\0';

    printf("Enter Monthly Salary: $");
    if (scanf("%lf", &new_emp.salary) != 1 || new_emp.salary < 0) {
        printf("❌ Invalid Salary. Operation canceled.\n");
        clear_buffer();
        return;
    }

    staff_db[employee_count] = new_emp;
    employee_count++;
    printf("✅ Employee record saved successfully!\n");
}

// Function to print all employee records
void display_employees() {
    if (employee_count == 0) {
        printf("\n📭 No employee records found in the system.\n");
        return;
    }

    printf("\n%-6s %-25s %-20s %-12s\n", "ID", "Name", "Department", "Salary");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%-06d %-25s %-20s $%-11.2f\n", 
               staff_db[i].id, staff_db[i].name, staff_db[i].department, staff_db[i].salary);
    }
}

// Function to search employee records by ID
void search_employee() {
    if (employee_count == 0) {
        printf("\n📭 System database is empty.\n");
        return;
    }

    int search_id;
    printf("\nEnter Employee ID to search: ");
    if (scanf("%d", &search_id) != 1) {
        printf("❌ Invalid search parameters.\n");
        clear_buffer();
        return;
    }

    for (int i = 0; i < employee_count; i++) {
        if (staff_db[i].id == search_id) {
            printf("\n🔎 Employee Found:\n");
            printf("----------------------------------\n");
            printf("ID:         %06d\n", staff_db[i].id);
            printf("Name:       %s\n", staff_db[i].name);
            printf("Department: %s\n", staff_db[i].department);
            printf("Salary:     $%.2f\n", staff_db[i].salary);
            return;
        }
    }
    printf("❌ No records match Employee ID %d.\n", search_id);
}

// Function to calculate aggregate financial statistics
void calculate_payroll() {
    if (employee_count == 0) {
        printf("\n📊 Total Monthly Payroll Expense: $0.00 (0 Employees)\n");
        return;
    }

    double total_payroll = 0;
    for (int i = 0; i < employee_count; i++) {
        total_payroll += staff_db[i].salary;
    }

    printf("\n📊 Corporate Payroll Metrics Summary:\n");
    printf("----------------------------------\n");
    printf("Active Staff Count:    %d\n", employee_count);
    printf("Total Monthly Payout:  $%.2f\n", total_payroll);
    printf("Average Salary Struct: $%.2f\n", total_payroll / employee_count);
}

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("💼    Employee Management System    💼\n");
        printf("====================================\n");
        printf("1. Add New Employee\n");
        printf("2. List All Staff Records\n");
        printf("3. Search Staff by ID\n");
        printf("4. Financial Payroll Metrics\n");
        printf("5. Exit System\n");
        printf("Select system operational mode (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Interface error. Please insert numeric parameters only.\n");
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1: add_employee(); break;
            case 2: display_employees(); break;
            case 3: search_employee(); break;
            case 4: calculate_payroll(); break;
            case 5: 
                printf("\n👋 Securely shutting down HR database engines