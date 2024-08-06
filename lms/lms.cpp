#include <string>
#include <iostream>
#include <vector>

typedef std::string Date;

int transactions_count;
Date current_date;

class Book {
protected:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;
    bool canBeBorrowed;
    std::vector<Member*> subscribers;

public:
    void add(Member* member) {
        subscribers.push_back(member);
    }
    void remove(Member* member) {
        for (auto it = subscribers.begin(); it != subscribers.end(); ) {
            if ((*it)->getMemberId() == member->getMemberId()) {
                it = subscribers.erase(it); 
            } else {
                ++it; 
            }
        }
    }
    void notify() {
        for (Member*& subscriber : subscribers) {
            subscriber->update();
        }
    }

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
        isAvailable = true;
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

    int getMemberId() {
        return memberId;
    }

    virtual void displayInfo() {
        std::cout << "Name: " << name << "\n"
                  << "Member ID: " << memberId << "\n\n";
    }

    void update() {
        std::cout << "Member with " << memberId << " id got notified\n\n";
    }
};

class Student : public Member {
private:
    int year;
    std::string major;

public:
    Student(std::string name, int memberId, std::string email, int year, std::string major) : Member(name, memberId, email) {
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

class Transaction {
private:
    int transactionId;
    Book* book;
    Member* member;
    Date issueDate;
    Date returnDate;

public:
    Transaction(int transactionId, Book* book, Member* member, Date issueDate, Date returnDate) {
        this->transactionId = transactionId;
        this->book = book;
        this->member = member;
        this->issueDate = issueDate;
        this->returnDate = returnDate;
    }

    Book* getBook() {
        return book;
    }

    Member* getMember() {
        return member;
    }

    void displayInfo() {
        std::cout << "Transaction ID:" << transactionId << "\n";
        book->displayInfo();
        member->displayInfo();
        std:: cout << "Issue date: " << issueDate << "\n"
                   << "Return date: " << returnDate << "\n\n";
    }
};

class Library {
private:
    static Library* library;
    std::vector<Book*> books;
    std::vector<Member*> members;
    std::vector<Transaction> transactions;

public:
    static Library* getInstance() {
        if (library == nullptr) {
            library = new Library();
        }
        return library;
    }

    void addBook(Book* book) {
        books.push_back(book);
    }

    void addMember(Member* member) {
        members.push_back(member);
    }
    
    void issueBook(Book* book, Member* member) {
        transactions.push_back(Transaction(transactions_count, book, member, current_date, ""));
        book->setAvailability(false);
    }

    void returnBook(Book* book, Member* member) {
        for (auto it = transactions.begin(); it != transactions.end(); ) {
            if (it->getBook() == book && it->getMember() == member) {
                it = transactions.erase(it); 
            } else {
                ++it; 
            }
        }
        book->setAvailability(true);
    }
};

class Factory {
public:
    virtual Book* createBook() = 0;
    virtual Member* createMember() = 0;
};

class BookFactory : public Factory {
public:
    virtual Book* createBook() = 0;
};

class RegularBookFactory : public BookFactory {
public:
    RegularBook* createBook(std::string title, std::string author, std::string isbn) {
        return new RegularBook(title, author, isbn);
    }
};

class ReferenceBookFactory : public BookFactory {
public:
    ReferenceBook* createBook(std::string title, std::string author, std::string isbn) {
        return new ReferenceBook(title, author, isbn);
    }
};

class MemberFactory : public Factory {
public:
    virtual Member* createMember() = 0;
};

class StudentMemberFactory : public MemberFactory {
    Student* createMember(std::string name, int memberId, std::string email, int year, std::string major) {
        return new Student(name, memberId, email, year, major);
    }
};

class FacultyMemberFactory : public MemberFactory {
    Faculty* createMember(std::string name, int memberId, std::string email, std::string department, std::string position) {
        return new Faculty(name, memberId, email, department, position);
    }
};

