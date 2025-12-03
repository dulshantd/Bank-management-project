Bank Management System in C

This is a simple console-based Bank Management System developed in the C programming language. It allows users to create bank accounts, secure them with passwords, and perform basic banking operations such as deposits, withdrawals, and balance inquiries. Account data is stored using binary files, making transactions persistent across sessions.

🔧 Features

Create a new bank account

Secure login using password authentication

Deposit money

Withdraw money

Check account balance

Display all registered accounts

Data persistence using binary files

🗂️ How It Works

Each account is stored as a struct in a binary file (accounts.dat).
Whenever a transaction occurs, the program:

Reads all accounts

Updates the target account

Saves data to a temporary file

Replaces the original file
