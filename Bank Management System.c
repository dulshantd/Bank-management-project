#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 50
#define MAX_PASS 20
#define FILENAME "accounts.dat"

typedef struct {
    int accNum;
    char name[MAX_NAME];
    char password[MAX_PASS];
    float balance;
} Account;

// Function prototypes
void mainMenu();
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAllAccounts();
int login(int accNum);
int accountExists(int accNum);
void clearInputBuffer();

int main() {
    int choice;

    printf("\n========================================\n");
    printf("   BANK MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    while(1) {
        mainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("\nThank you for using Bank Management System!\n");
                printf("Goodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void mainMenu() {
    printf("\n========================================\n");
    printf("           MAIN MENU\n");
    printf("========================================\n");
    printf("1. Create New Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Display All Accounts\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

void createAccount() {
    Account acc;
    FILE *fp;

    printf("\n========================================\n");
    printf("        CREATE NEW ACCOUNT\n");
    printf("========================================\n");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNum);
    clearInputBuffer();

    // Check if account already exists
    if(accountExists(acc.accNum)) {
        printf("\nAccount number already exists!\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    fgets(acc.name, MAX_NAME, stdin);
    acc.name[strcspn(acc.name, "\n")] = 0; // Remove newline

    printf("Set Password (max 20 characters): ");
    fgets(acc.password, MAX_PASS, stdin);
    acc.password[strcspn(acc.password, "\n")] = 0;

    printf("Enter Initial Deposit: $");
    scanf("%f", &acc.balance);
    clearInputBuffer();

    if(acc.balance < 0) {
        printf("\nInitial deposit cannot be negative!\n");
        return;
    }

    // Save to file
    fp = fopen(FILENAME, "ab");
    if(fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);

    printf("\n========================================\n");
    printf("Account created successfully!\n");
    printf("Account Number: %d\n", acc.accNum);
    printf("Account Holder: %s\n", acc.name);
    printf("Initial Balance: $%.2f\n", acc.balance);
    printf("========================================\n");
}

void deposit() {
    int accNum;
    float amount;
    Account acc;
    FILE *fp, *tempFp;
    int found = 0;

    printf("\n========================================\n");
    printf("          DEPOSIT MONEY\n");
    printf("========================================\n");

    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    clearInputBuffer();

    if(!login(accNum)) {
        return;
    }

    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    clearInputBuffer();

    if(amount <= 0) {
        printf("\nInvalid amount!\n");
        return;
    }

    fp = fopen(FILENAME, "rb");
    tempFp = fopen("temp.dat", "wb");

    if(fp == NULL) {
        printf("\nNo accounts found!\n");
        return;
    }

    while(fread(&acc, sizeof(Account), 1, fp)) {
        if(acc.accNum == accNum) {
            acc.balance += amount;
            found = 1;
            printf("\n========================================\n");
            printf("Deposit successful!\n");
            printf("New Balance: $%.2f\n", acc.balance);
            printf("========================================\n");
        }
        fwrite(&acc, sizeof(Account), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if(!found) {
        printf("\nAccount not found!\n");
    }
}

void withdraw() {
    int accNum;
    float amount;
    Account acc;
    FILE *fp, *tempFp;
    int found = 0;

    printf("\n========================================\n");
    printf("         WITHDRAW MONEY\n");
    printf("========================================\n");

    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    clearInputBuffer();

    if(!login(accNum)) {
        return;
    }

    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    clearInputBuffer();

    if(amount <= 0) {
        printf("\nInvalid amount!\n");
        return;
    }

    fp = fopen(FILENAME, "rb");
    tempFp = fopen("temp.dat", "wb");

    if(fp == NULL) {
        printf("\nNo accounts found!\n");
        return;
    }

    while(fread(&acc, sizeof(Account), 1, fp)) {
        if(acc.accNum == accNum) {
            found = 1;
            if(acc.balance >= amount) {
                acc.balance -= amount;
                printf("\n========================================\n");
                printf("Withdrawal successful!\n");
                printf("New Balance: $%.2f\n", acc.balance);
                printf("========================================\n");
            } else {
                printf("\nInsufficient balance!\n");
                printf("Current Balance: $%.2f\n", acc.balance);
            }
        }
        fwrite(&acc, sizeof(Account), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if(!found) {
        printf("\nAccount not found!\n");
    }
}

void checkBalance() {
    int accNum;
    Account acc;
    FILE *fp;
    int found = 0;

    printf("\n========================================\n");
    printf("         CHECK BALANCE\n");
    printf("========================================\n");

    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    clearInputBuffer();

    if(!login(accNum)) {
        return;
    }

    fp = fopen(FILENAME, "rb");

    if(fp == NULL) {
        printf("\nNo accounts found!\n");
        return;
    }

    while(fread(&acc, sizeof(Account), 1, fp)) {
        if(acc.accNum == accNum) {
            found = 1;
            printf("\n========================================\n");
            printf("Account Number: %d\n", acc.accNum);
            printf("Account Holder: %s\n", acc.name);
            printf("Current Balance: $%.2f\n", acc.balance);
            printf("========================================\n");
            break;
        }
    }

    fclose(fp);

    if(!found) {
        printf("\nAccount not found!\n");
    }
}

void displayAllAccounts() {
    Account acc;
    FILE *fp;
    int count = 0;

    printf("\n========================================\n");
    printf("        ALL ACCOUNTS\n");
    printf("========================================\n");

    fp = fopen(FILENAME, "rb");

    if(fp == NULL) {
        printf("\nNo accounts found!\n");
        return;
    }

    printf("\n%-10s %-30s %-15s\n", "Acc No.", "Name", "Balance");
    printf("--------------------------------------------------------\n");

    while(fread(&acc, sizeof(Account), 1, fp)) {
        printf("%-10d %-30s $%-14.2f\n", acc.accNum, acc.name, acc.balance);
        count++;
    }

    printf("--------------------------------------------------------\n");
    printf("Total Accounts: %d\n", count);
    printf("========================================\n");

    fclose(fp);
}

int login(int accNum) {
    char password[MAX_PASS];
    Account acc;
    FILE *fp;
    int found = 0;

    fp = fopen(FILENAME, "rb");

    if(fp == NULL) {
        printf("\nNo accounts found!\n");
        return 0;
    }

    while(fread(&acc, sizeof(Account), 1, fp)) {
        if(acc.accNum == accNum) {
            found = 1;
            printf("Enter Password: ");
            fgets(password, MAX_PASS, stdin);
            password[strcspn(password, "\n")] = 0;

            if(strcmp(password, acc.password) == 0) {
                fclose(fp);
                return 1;
            } else {
                printf("\nIncorrect password!\n");
                fclose(fp);
                return 0;
            }
        }
    }

    fclose(fp);

    if(!found) {
        printf("\nAccount not found!\n");
    }

    return 0;
}

int accountExists(int accNum) {
    Account acc;
    FILE *fp;

    fp = fopen(FILENAME, "rb");

    if(fp == NULL) {
        return 0;
    }

    while(fread(&acc, sizeof(Account), 1, fp)) {
        if(acc.accNum == accNum) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
