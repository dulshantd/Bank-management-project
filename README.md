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
## Demonstration

### Screenshot 1
![Screenshot 1](https://raw.githubusercontent.com/dulshantd/Bank-management-project/main/ss1.png)

### Screenshot 2
![Screenshot 2](https://raw.githubusercontent.com/dulshantd/Bank-management-project/main/ss2.png)

### Screenshot 3
![Screenshot 3](https://raw.githubusercontent.com/dulshantd/Bank-management-project/main/ss3.png)

### Screenshot 4
![Screenshot 4](https://raw.githubusercontent.com/dulshantd/Bank-management-project/main/ss4.png)

### Screenshot 5
![Screenshot 5](https://raw.githubusercontent.com/dulshantd/Bank-management-project/main/ss5.png)

