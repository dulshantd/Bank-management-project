# 🏦 Bank Management System

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)

**A comprehensive bank management system with secure authentication and file-based storage**

[Features](#Demonstrations) • [Installation](#installation) • [Usage](#usage) • [Documentation](#documentation)

</div>

---

## 🌟 Features

<table>
<tr>
<td>

- ✅ **Create Account** - Register new accounts with unique IDs
- 💰 **Deposit Money** - Add funds securely
- 💸 **Withdraw Money** - Withdraw with balance verification
- 📊 **Check Balance** - View account details instantly
- 📋 **Display All Accounts** - Comprehensive account listing
- 🔐 **Password Protection** - Secure authentication system

</td>
</tr>
</table>

---

## 📂 Project Structure

```
bank-management-system/
├── 📄 main.c           # Main program entry point
├── 📄 account.c        # Account management functions
├── 📄 transaction.c    # Transaction operations
├── 📄 utils.c          # Utility functions
├── 📄 bank.h           # Header file with declarations
├── 📄 Makefile         # Build configuration
├── 📄 README.md        # Documentation
└── 📄 .gitignore       # Git ignore rules
```

---

## 🚀 Installation

### Prerequisites

> **Note**: Make sure you have GCC compiler installed on your system.

```bash
# Check if GCC is installed
gcc --version
```

### Clone the Repository

```bash
git clone https://github.com/yourusername/bank-management-system.git
cd bank-management-system
```

### Compile the Project

**Option 1: Using Makefile** ⭐ (Recommended)

```bash
make
```

**Option 2: Manual Compilation**

```bash
gcc -Wall -Wextra -std=c99 -c main.c
gcc -Wall -Wextra -std=c99 -c account.c
gcc -Wall -Wextra -std=c99 -c transaction.c
gcc -Wall -Wextra -std=c99 -c utils.c
gcc -o bank main.o account.o transaction.o utils.o
```

---

## 💻 Usage

### Run the Program

```bash
./bank
```

Or with Makefile:

```bash
make run
```

### Main Menu

```
========================================
           MAIN MENU
========================================
1. Create New Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Display All Accounts
6. Exit
========================================
```

---

## 📖 Documentation

### Creating an Account

1. Select option `1` from the main menu
2. Enter a unique account number
3. Provide account holder name
4. Set a secure password
5. Enter initial deposit amount

> **⚠️ Important**: Remember your password! It's required for all transactions.

### Making Transactions

<details>
<summary><b>💰 Deposit Money</b></summary>

- Select option `2`
- Enter account number
- Authenticate with password
- Enter deposit amount
- Confirm transaction

</details>

<details>
<summary><b>💸 Withdraw Money</b></summary>

- Select option `3`
- Enter account number
- Authenticate with password
- Enter withdrawal amount
- System checks balance and processes

</details>

<details>
<summary><b>📊 Check Balance</b></summary>

- Select option `4`
- Enter account number
- Authenticate with password
- View account details

</details>

---

## 🗂️ Data Storage

Account data is stored in **`accounts.dat`** binary file with the following structure:

| Field | Type | Description |
|-------|------|-------------|
| `accNum` | `int` | Unique account number |
| `name` | `char[50]` | Account holder name |
| `password` | `char[20]` | Account password |
| `balance` | `float` | Current balance |

---

## 🛠️ Build Commands

| Command | Description |
|---------|-------------|
| `make` | Compile the project |
| `make run` | Compile and run |
| `make clean` | Remove compiled files |

---

## 🔒 Security Notice

> **⚠️ Educational Project Warning**
> 
> This is an educational project. For production use:
> - ❌ Don't store passwords in plain text
> - ✅ Use password hashing (bcrypt, argon2)
> - ✅ Implement proper encryption
> - ✅ Add transaction logging
> - ✅ Implement proper error handling

---

## 🐛 Known Issues

- [ ] Passwords stored in plain text
- [ ] No transaction history
- [ ] Limited error recovery

---

## 🚧 Future Enhancements

- [ ] Add transaction history
- [ ] Implement password hashing
- [ ] Add account deletion feature
- [ ] Create backup/restore functionality
- [ ] Add interest calculation
- [ ] Implement account types (Savings/Current)

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. 🍴 Fork the repository
2. 🌿 Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. 💾 Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. 📤 Push to the branch (`git push origin feature/AmazingFeature`)
5. 🔀 Open a Pull Request

---

## 📝 License

```
MIT License

Copyright (c) 2024 Your Name

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction.
```

---

## 📧 Contact

**Dulshan Dissanayaka** - [LinkedIn](https://www.linkedin.com/in/dulshan-dissanayaka/)

**E-mail** - [Personal](dulshandissanayaka480@gmail.com)

**Whatsapp** - [Dulshan Dissanayaka](https://wa.link/1w5wfe)

**Project Link**: [Bank Management System](https://github.com/dulshantd/Bank-management-project)

---

## 🙏 Acknowledgments

- Inspired by real banking systems
- Built for educational purposes
- Thanks to the C programming community

---

<div align="center">

### ⭐ Star this repository if you found it helpful!

**Made with ❤️ and C**

![Footer](https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer)

</div>
