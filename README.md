# Bank Management System (C)

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=flat-square"/>
  <img src="https://img.shields.io/badge/Type-Console%20App-success?style=flat-square"/>
  <img src="https://img.shields.io/badge/Status-Complete-brightgreen?style=flat-square"/>
</p>


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
![Screenshot 1](https://github.com/dulshantd/Bank-management-project/blob/main/Demonstrations/ss1.png)

### Screenshot 2
![Screenshot 2](https://github.com/dulshantd/Bank-management-project/blob/main/Demonstrations/ss2.png)

### Screenshot 3
![Screenshot 3](https://github.com/dulshantd/Bank-management-project/blob/main/Demonstrations/ss3.png)

### Screenshot 4
![Screenshot 4](https://github.com/dulshantd/Bank-management-project/blob/main/Demonstrations/ss4.png)

### Screenshot 5
![Screenshot 5](https://github.com/dulshantd/Bank-management-project/blob/main/Demonstrations/ss5.png)

