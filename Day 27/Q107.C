#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 30

// Define the Employee Salary Structure
typedef struct {
    int id;
    char name[50];
    double base_salary;
    double hra;        // House Rent Allowance
    double ta;         // Travel Allowance
    double pf;         // Provident Fund Deduction
    double net_salary; // Total Take-Home Pay
} SalaryRecord;

// Global variables simulating our database
SalaryRecord payroll_db[MAX_EMPLOYEES];
int record_count = 0;

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Automatically calculates allowances, deductions, and net pay based on base salary
void calculate_payroll_metrics(SalaryRecord *emp) {
    // Standard corporate formula configurations:
    emp->hra = emp->base_salary * 0.20; // HRA is 20% of Base Salary
    emp->ta = emp->base_salary * 0.10;  // TA is 10% of Base Salary
    emp->pf = emp->base_salary * 0.12;  // PF Deduction is 12% of Base Salary

    // Net Salary = Base + Allowances - Deductions
    emp->net_salary = (emp->base_salary + emp->hra + emp->ta) - emp->pf;
}

// Add a new profile to the system
void add_salary_record() {
    if (record_count >= MAX_EMPLOYEES) {
        printf("\n❌ Ledger Limit Reached! Cannot add more profiles.\n");
        return;
    }

    SalaryRecord new_record;

    printf("\nEnter Employee ID: ");
    if (scanf("%d", &new_record.id) != 1) {
        printf("❌ Invalid ID format.\n");
        clear_buffer();
        return;
    }

    // Verify ID doesn't already exist
    for (int i = 0; i < record_count; i++) {
        if (payroll_db[i].id == new_record.id) {
            printf("❌ Conflict: Employee ID %d already exists.\n", new_record.id);
            return;
        }
    }

    printf("Enter Employee Name: ");
    clear_buffer();
    fgets(new_record.name, sizeof(new_record.name), stdin);
    new_record.name[strcspn(new_record.name, "\n")] = '\0';

    printf("Enter Base Monthly Salary: $");
    if (scanf("%lf", &new_record.base_salary) != 1 || new_record.base_salary < 0) {
        printf("❌ Invalid Base Salary Amount.\n");
        clear_buffer();
        return;
    }

    // Automatically compute financial subsets via pointer
    calculate_payroll_metrics(&new_record);

    // Save into database
    payroll_db[record_count] = new_record;
    record_count++;
    printf("✅ Financial record processed and locked successfully!\n");
}

// Display a detailed spreadsheet-style ledger
void display_salary_ledger() {
    if (record_count == 0) {
        printf("\n📭 The salary management registry is completely empty.\n");
        return;
    }

    printf("\n%-6s %-18s %-12s %-10s %-10s %-10s %-12s\n", 
           "ID", "Name", "Base Sal", "HRA(20%)", "TA(10%)", "PF(12%)", "Net Salary");
    printf("------------------------------------------------------------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("%-06d %-18s $%-11.2f $%-9.2f $%-9.2f $%-9.2f $%-11.2f\n",
               payroll_db[i].id, 
               payroll_db[i].name, 
               payroll_db[i].base_salary, 
               payroll_db[i].hra, 
               payroll_db[i].ta, 
               payroll_db[i].pf, 
               payroll_db[i].net_salary);
    }
}

// Give a percentage increment to a specific employee
void process_salary_increment() {
    if (record_count == 0) {
        printf("\n📭 No records available to modify.\n");
        return;
    }

    int target_id;
    double raise_percentage;

    printf("\nEnter Employee ID for Raise: ");
    if (scanf("%d", &target_id) != 1) {
        printf("❌ Invalid Entry.\n");
        clear_buffer();
        return;
    }

    for (int i = 0; i < record_count; i++) {
        if (payroll_db[i].id == target_id) {
            printf("Current Base Salary for %s is $%.2f\n", payroll_db[i].name, payroll_db[i].base_salary);
            printf("Enter salary increase percentage (e.g., 10 for 10%%): ");
            if (scanf("%lf", &raise_percentage) != 1 || raise_percentage < 0) {
                printf("❌ Invalid percentage calculation.\n");
                clear_buffer();
                return;
            }

            // Adjust the base salary and trigger recalculations
            payroll_db[i].base_salary += (payroll_db[i].base_salary * (raise_percentage / 100.0));
            calculate_payroll_metrics(&payroll_db[i]);

            printf("🎉 Success! New Net Take-Home Salary: $%.2f\n", payroll_db[i].net_salary);
            return;
        }
    }
    printf("❌ Employee ID %d not discovered in registry.\n", target_id);
}

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("💰     Corporate Salary System     💰\n");
        printf("====================================\n");
        printf("1. Add Employee & Compute Payroll\n");
        printf("2. View Full Salary Ledger Sheet\n");
        printf("3. Apply Salary Raise / Increment\n");
        printf("4. Shutdown System\n");
        printf("Select accounting option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Selection execution failed. Use numbers only.\n");
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1: add_salary_record(); break;
            case 2: display_salary_ledger(); break;
            case 3: process_salary_increment(); break;
            case 4: 
                printf("\n👋 Exiting financial accounting systems safely. Goodbye!\n");
                return 0;
            default: 
                printf("❌ Value error. Input out of bound constraints.\n");
        }
    }
    return 0;
}