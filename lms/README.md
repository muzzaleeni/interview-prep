# Library Management System

## Overview
Design a library management system to handle basic operations such as adding books, issuing books to members, returning books, and managing member information. The system should support different types of books (e.g., reference books, regular books) and members (e.g., students, faculty).

## Core OOP Principles
- **Encapsulation:** Hide the internal state of books, members, and transactions.
- **Inheritance:** Create a base class for `Book` and derive different types of books. Create a base class for `Member` and derive different types of members.
- **Polymorphism:** Use virtual functions to handle different behaviors for various types of books and members.
- **Abstraction:** Provide interfaces for book and member management.

## Design Patterns
- **Factory Pattern:** To create objects of different types of books and members.
- **Singleton Pattern:** To manage the single instance of the library system.
- **Observer Pattern:** To notify members when a reserved book becomes available.

## Components

### 1. Book Management
#### Classes:
- **Book (Base Class)**
  - `string title`
  - `string author`
  - `string isbn`
  - `bool isAvailable`
  - Virtual function: `void displayInfo()`
- **RegularBook (Derived Class)**
  - Overrides `displayInfo()`
- **ReferenceBook (Derived Class)**
  - Overrides `displayInfo()`

#### Patterns:
- **Factory Pattern:** To create different types of books.

### 2. Member Management
#### Classes:
- **Member (Base Class)**
  - `string name`
  - `string memberId`
  - Virtual function: `void displayInfo()`
- **Student (Derived Class)**
  - Overrides `displayInfo()`
- **Faculty (Derived Class)**
  - Overrides `displayInfo()`

#### Patterns:
- **Factory Pattern:** To create different types of members.

### 3. Library System
#### Classes:
- **Library (Singleton)**
  - `vector<Book*> books`
  - `vector<Member*> members`
  - `vector<Transaction> transactions`
  - Functions: `void addBook(Book* book)`, `void addMember(Member* member)`, `void issueBook(string isbn, string memberId)`, `void returnBook(string isbn, string memberId)`
  - Singleton instance: `static Library* getInstance()`

#### Patterns:
- **Singleton Pattern:** To manage a single instance of the library.

### 4. Transactions
#### Classes:
- **Transaction**
  - `string transactionId`
  - `Book* book`
  - `Member* member`
  - `Date issueDate`
  - `Date returnDate`

### 5. Notification System
#### Classes:
- **EmailNotification**
  - `update()`


#### Patterns:
- **Observer Pattern:** To notify members about book availability.

## Implementation Steps

1. **Define Base Classes and Derived Classes for Books and Members:**
   - Implement base class `Book` with derived classes `RegularBook` and `ReferenceBook`.
   - Implement base class `Member` with derived classes `Student` and `Faculty`.

2. **Create the Library Class:**
   - Implement the `Library` class as a singleton.
   - Implement functions to add books, add members, issue books, and return books.

3. **Implement the Factory Pattern:**
   - Create factory classes for books and members to instantiate different types.

4. **Implement the Observer Pattern:**
   - Define the `Notification` system and implement observers for email and SMS notifications.

5. **Manage Transactions:**
   - Implement the `Transaction` class to record book issues and returns.

