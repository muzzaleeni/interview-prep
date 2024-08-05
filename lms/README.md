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
