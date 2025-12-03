# Bank Management System (C)

A simple console-based Bank Management System written in C using file handling.

## Features

- Create new account
- Secure login using password
- Deposit money
- Withdraw money
- Check account balance
- Display all accounts
- Data stored in binary file (`accounts.dat`)

## How It Works

Accounts are stored as a binary struct:

```c
typedef struct {
    int accNum;
    char name[50];
    char password[20];
    float balance;
} Account;

```
- Demonstration
  
Screenshot 1:
https://github.com/dulshantd/Bank-management-project/blob/main/ss1.png
Screenshot 2:
https://github.com/dulshantd/Bank-management-project/blob/main/ss2.png
Screenshot 3:
https://github.com/dulshantd/Bank-management-project/blob/main/ss3.png
Screenshot 4:
https://github.com/dulshantd/Bank-management-project/blob/main/ss4.png
Screenshot 5:
https://github.com/dulshantd/Bank-management-project/blob/main/ss5.png
