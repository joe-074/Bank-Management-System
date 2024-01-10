#ifndef BANK_H
#define BANK_H

// Define structures to represent customer accounts
struct Transaction
{
    char type;
    double amount;
};

struct Customer
{
    int accountNumber;
    char name[100];
    char dob[15];
    char id[20];
    char address[100];
    char phoneNumber[15];
    double balance;

    int numTransactions;
    struct Transaction transactions[10];
};

// Global variables
extern struct Customer customers[10]; // adjust the array size as needed
extern int numCustomers;

// Function prototypes
void main_menu();
void new_account();
void delete_account();
void customer_list();
void customer_edit();
void account_list();
void transact();

#endif