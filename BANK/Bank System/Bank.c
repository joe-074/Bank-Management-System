#include <stdio.h>
#include <stdlib.h>    //system(cls)
#include <string.h>
#include "Bank.h"

//#include <conio.h>   //is not a standard C library header NOT allowed by certain coding standards such as MISRA-C     getch()

// Global variables
struct Customer customers[10]; // adjust the array size as needed
int numCustomers = 0;

int main()
{
    main_menu();
    return 0;
}

// Compare function for qsort to sort customers by name
int compareCustomersByName(const void *a, const void *b)
{
    return strcmp(((struct Customer *)a)->name, ((struct Customer *)b)->name);
}






void main_menu()
{
    int choice;

    // Display the main menu options
    printf("\n\n\n\t\t\t(< Bank Management System >)\n");
    printf("\t\t\t----------------------------\n");
    printf("1. New Account\n");
    printf("2. Delete Account\n");
    printf("3. Customer List\n");
    printf("4. Edit Customer Information\n");
    printf("5. Account List\n");
    printf("6. Transaction\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    //system("cls");

    switch (choice) {
        case 1:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            new_account();
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            delete_account();
            break;
        case 3:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            customer_list();
            break;
        case 4:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            customer_edit();
            break;
        case 5:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            account_list();
            break;
        case 6:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            transact();
            break;
        /*
        case 7:
            // Exit the program
            printf("Exiting the Bank Management System. Goodbye!\n");
            exit(0);
        */
        default:
            printf("Invalid choice. Please try again later.\n");
            //printf("\nPress any key to exit...");
            //getch();
            //system("cls");
        }

}

void new_account()
{
    struct Customer newCustomer;

    // Prompt the user to enter customer details
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Enter the following customer details...\n");

    // Account Number
    printf("\nAccount Number: ");
    scanf("%d", &newCustomer.accountNumber);

    // Name
    printf("Name: ");
    scanf(" %99[^\n]", &newCustomer.name);

    // Date of Birth
    printf("Date of Birth (DD/MM/YYYY): ");
    scanf("%s", &newCustomer.dob);

    // (ID or Passport Number)
    printf("ID or Passport Number: ");
    scanf("%s", &newCustomer.id);

    // Address
    printf("Address: ");
    scanf(" %99[^\n]", &newCustomer.address);

    // Phone Number
    printf("Phone Number: ");
    scanf("%s", &newCustomer.phoneNumber);

    // Initialize the new customer's transaction history
    newCustomer.balance = 0;
    newCustomer.numTransactions = 0;



    // Initial Balance
    printf("Initial Balance: ");
    scanf("%lf", &newCustomer.balance);

    // to add the new customer to the array
    customers[numCustomers] = newCustomer;
    numCustomers++;

    printf("Congratulations!\nAccount created successfully!\n");

    //getch();
    //system("cls");
    main_menu();
}

void delete_account()
{
    int i, j, accountNumber;
    int found = 0;
    printf("Enter the Account Number to delete: ");
    scanf("%d", &accountNumber);

    for (i = 0; i < numCustomers; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            found = 1;
            // Move all accounts after this one up by one position
            for (j = i; j < numCustomers - 1; j++)
            {
                customers[j] = customers[j + 1];
            }

            numCustomers--;
            printf("Account ( %d ) has been successfully deleted.\n", accountNumber);
            break; // Account found and deleted, exit the loop
        }
    }
    if (!found) // Account number given are not match with account number
    {
    printf("Customer with Account Number %d not found.\n", accountNumber);
    }

    //getchar(); // Clear the newline character
    //printf("\nPress any key to continue...");
    //getchar();
    //system("cls");
    main_menu();
}

void customer_list()
{
    //            Sort the customer array alphabetically by name
    qsort(customers, numCustomers, sizeof(struct Customer), compareCustomersByName);

    // Display the customer list in a table form
    printf("\nCustomer List (Sorted by Name)\n\n");
    printf("%-15s %-30s %-20s %-20s %-30s %-15s %-10s\n", "Account #", "Name", "Birth", "ID", "Address", "Phone #", "Current Balance");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < numCustomers; i++)
    {
        struct Customer currentCustomer = customers[i];
        printf("%-15d %-30s %-20s %-20s %-30s %-15s %.2lf L.E\n",
               currentCustomer.accountNumber,
               currentCustomer.name,
               currentCustomer.dob,
               currentCustomer.id,
               currentCustomer.address,
               currentCustomer.phoneNumber,
               currentCustomer.balance);
    }

    //printf("\nPress any key to continue...");
    //getch();
    //system("cls");
    main_menu();
}


void customer_edit()
{
    int accountNumber;
    int found = 0; // To check if the customer account exists
    printf("Enter the Account Number of the customer to edit: ");
    scanf("%d", &accountNumber);


    // Search for the customer account
    for (int i = 0; i < numCustomers; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            found = 1;

            printf("\nEdit Customer Information for Account ( %d ):\n", accountNumber);
            printf("-------------------------------------------------\n");
            printf("1. Name                               (current: %s)\n", customers[i].name);
            printf("2. Date of Birth (DD/MM/YYYY)         (current: %s)\n", customers[i].dob);
            printf("3. ID                                 (current: %s)\n", customers[i].id);
            printf("4. Address                            (current: %s)\n", customers[i].address);
            printf("5. Phone Number                       (current: %s)\n", customers[i].phoneNumber);
            printf("6. Current Balance                    (current: %.2lf)\n", customers[i].balance);

            int choice_edit;
            printf("\nEnter your choice: ");
            scanf("%d", &choice_edit);

            switch (choice_edit)
            {
                case 1:
                     // Edit customer's name
                    printf("Enter new Name: ");
                    scanf(" %99[^\n]", customers[i].name);
                    break;
                case 2:
                    // Edit customer's date of birth
                    printf("Enter new Date of Birth (DD/MM/YYYY): ");
                    scanf("%s", customers[i].dob);
                    break;
                case 3:
                    // Edit customer's ID
                    printf("Enter new ID: ");
                    scanf("%s", customers[i].id);
                    break;
                case 4:
                    // Edit customer's address
                    printf("Enter new Address: ");
                    scanf(" %99[^\n]", customers[i].address);
                    break;
                case 5:
                    // Edit customer's phone number
                    printf("Enter new Phone Number: ");
                    scanf("%s", customers[i].phoneNumber);
                    break;
                case 6:
                    // Edit customer's balance
                    printf("Enter new Balance: ");
                    scanf("%lf", &customers[i].balance);
                    break;
                default:
                    printf("Invalid choice. Please try again later.\n");
                    break;
            }
        }
    }
    if (!found)
    {
    printf("Customer with Account Number %d not found.\n", accountNumber);
    }

    //printf("\nPress any key to continue...");
    //getch();
    //system("cls");
    main_menu();
}




void account_list()
{
    // Sort the customer array alphabetically by name
    qsort(customers, numCustomers, sizeof(struct Customer), compareCustomersByName);

    // Display the account list in a table form
    printf("\nAccount List (Sorted by Name)\n\n");
    printf("%-15s %-30s %-20s %-20s %-20s\n", "Account #", "Name", "Current Balance", "Total Deposits", "Total Withdrawals");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < numCustomers; i++)
    {
        struct Customer currentCustomer = customers[i];
        double totalDeposits = 0, totalWithdrawals = 0;

        // Calculate total deposits and withdrawals for the current account
        for (int j = 0; j < currentCustomer.numTransactions; j++)
        {
            if (currentCustomer.transactions[j].type == 'D')
            {
                totalDeposits += currentCustomer.transactions[j].amount;
            }
            else if (currentCustomer.transactions[j].type == 'W')
            {
                totalWithdrawals += currentCustomer.transactions[j].amount;
            }
        }

        // Calculate the current balance by adding total ( + ) deposits and subtracting ( - ) total withdrawals
        double balance = currentCustomer.balance + totalDeposits - totalWithdrawals;

        // Print account information in table row
        printf("%-15d %-30s %.2lf\t\t\t%-20.2lf %-20.2lf\n",
            currentCustomer.accountNumber,
            currentCustomer.name,
            customers[i].balance,
            totalDeposits,
            totalWithdrawals);
    }

    //printf("\nPress any key to continue...");
    //getch();
    //system("cls");
    main_menu();
}


void transact()
{

    int accountNumber;
    double amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    int found = 0; // Flag to remember me if the account was found

    for (int i = 0; i < numCustomers; i++)  // Find the account with the given account number
    {
        if (customers[i].accountNumber == accountNumber)
        {
            int transact_choice;
            found = 1; // Account found
            printf("1. Deposit\n");
            printf("2. Withdraw\n");
            printf("Enter your choice: ");
            scanf("%d", &transact_choice);

            if (transact_choice == 1)     // Deposit الايداع
            {
                printf("Enter the amount to deposit: ");
                scanf("%lf", &amount);

                if (amount >= 0)
                {
                    // Update the customer's balance by adding the deposit amount
                    customers[i].balance += amount;
                    printf("\nDeposit of %.2lf L.E. was successful.\n", amount);
                    printf("(current Balance: %.2lf L.E.)\n", customers[i].balance);

                    // Record the transaction in the customer's transaction history
                    struct Transaction newTransaction;
                    newTransaction.type = 'D'; // 'D' for a deposit
                    newTransaction.amount = amount;

                    // Add the new transaction to the customer's transaction history
                    customers[i].transactions[customers[i].numTransactions] = newTransaction;
                    customers[i].numTransactions++;
                }
                else
                {
                    printf("Invalid amount. Please enter a positive value.\n");
                }
            }
            else if (transact_choice == 2)  // Withdraw السحب
            {
                printf("Enter the amount to withdraw: ");
                scanf("%lf", &amount);

                if (amount < 0)
                {
                    printf("Invalid amount. Please enter a positive value.\n");
                }
                else if (amount > customers[i].balance)
                {
                    printf("Insufficient balance. Withdraw failed.\n");
                }
                else
                {
                    // Update the customer's balance by subtracting ( - ) the deposit amount
                    customers[i].balance -= amount;
                    printf("\nWithdrawal of %.2lf L.E. was successful.\n", amount);
                    printf("(current Balance: %.2lf L.E.)\n", customers[i].balance);

                    // Record the transaction in the customer's transaction history
                    struct Transaction newTransaction;
                    newTransaction.type = 'W';
                    newTransaction.amount = amount;
                    // Add the new transaction to the customer's transaction history
                    customers[i].transactions[customers[i].numTransactions] = newTransaction;
                    customers[i].numTransactions++;
                }
            }
            else
            {
                printf("Invalid choice. Please try again later.\n");
            }

            break; // Exit the loop after processing the transaction
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }
    //printf("\nPress any key to continue...");
    //getch();
    //system("cls");
    main_menu();
}


