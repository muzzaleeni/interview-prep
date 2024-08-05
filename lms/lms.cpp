#include <string>
#include <iostream>
#include <vector>

class Book {
protected:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;
    bool canBeBorrowed;

public:
    virtual void displayInfo() {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "ISBN: " << isbn << "\n"
                  << status() << "\n\n";   
    }

    Book(std::string title, std::string author, std::string isbn) {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        setAvailability(true);
    }

    std::string status() {
        if (isAvailable && canBeBorrowed) {
            return "This book can be issued and borrowed.";
        }
        else if (isAvailable && !canBeBorrowed) {
            return "This book can be issued, but not borrowed.";
        }
        else if (isAvailable && !canBeBorrowed) {
            return "This book can't be issued, but can be borrowed.";
        }
        else {
            return "This book can't be issued nor borrowed.";
        }
    }

    void setAvailability(bool availability) {
        isAvailable = availability;
    }
};

class RegularBook : public Book {
public:
    RegularBook(std::string title, std::string author, std::string isbn) : Book(title, author, isbn) {
        canBeBorrowed = true;
    };

    void displayInfo() override {
        Book::displayInfo();  
        std::cout << "This is a regular book type that can be borrowed. In case of late returns, there is an occuring fee.\n\n";      
    }
};

class ReferenceBook : public Book {
public:
    ReferenceBook(std::string title, std::string author, std::string isbn) : Book(title, author, isbn) {
        canBeBorrowed = false;
    };

    void displayInfo() override {
        Book::displayInfo();
        std::cout << "This is a reference book type that can only be used inside the library.\n\n";
    }
};

class Member {
protected:
    std::string name;
    int memberId;
    std::string email;

public:
    Member(std::string name, int memberId, std::string email) {
        this->name = name;
        this->memberId = memberId;
        this->email = email;
    }

    virtual void displayInfo() {
        std::cout << "Name: " << name << "\n"
                  << "Member ID: " << memberId << "\n\n";
    }
};

class Student : public Member {
private:
    int year;
    std::string major;

public:
    Student(std::string name, int memberId, std::string email, int year, std:: string major) : Member(name, memberId, email) {
        this->year = year;
        this->major = major;
    };

    void displayInfo() {
        Member::displayInfo();
        std::cout << "This is a student studying "
                  << major << "in year " << year << "\n\n";
    }
};

class Faculty : public Member {
private:
    std::string department;
    std::string position;

public:
    Faculty(std::string name, int memberId, std::string email, std::string department, std:: string position) : Member(name, memberId, email) {
        this->department = department;
        this->position = position;
    };

    void displayInfo() {
        Member::displayInfo();
        std::cout << "This is a faculty member from "
                  << department << "department working as a " << position << "\n\n";
    }
};

class Library {
private:
    static Library* library;
    std::vector<Book*> books;
    std::vector<Member*> members;
    // TODO: std::vector<Transaction> transactions;

public:
    static Library* getInstance() {
        if (library == nullptr) {
            library = new Library();
        }
        return library;
    }

    void addBook(Book* book);

    void addMember(Member* member);
    
    void issueBook(std::string isbn, std::string memberId);

    void returnBook(std::string isbn, std::string memberId);
};
