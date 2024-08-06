#include <string>
#include <iostream>
#include <vector>
#include <memory>

using Date = std::string;

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

    Book(std::string title, std::string author, std::string isbn, bool canBeBorrowed) : title(title), author(author), isbn(isbn), canBeBorrowed(canBeBorrowed), isAvailable(true)  {}

    std::string status() {
        if (isAvailable && canBeBorrowed) {
            return "This book can be issued and borrowed.";
        }
        else if (isAvailable && !canBeBorrowed) {
            return "This book can be issued, but not borrowed.";
        }
        else if (isAvailable && canBeBorrowed) {
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
    RegularBook(std::string title, std::string author, std::string isbn) : Book(title, author, isbn, true) {}

    void displayInfo() override {
        Book::displayInfo();  
        std::cout << "This is a regular book type that can be borrowed. In case of late returns, there is an occuring fee.\n\n";      
    }
};

class ReferenceBook : public Book {
public:
    ReferenceBook(std::string title, std::string author, std::string isbn) : Book(title, author, isbn, false) {}

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
    Member(std::string name, int memberId, std::string email) : name(name), memberId(memberId), email(email) {}

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
    Transaction(int transactionId, Book* book, Member* member, Date issueDate, Date returnDate) : transactionId(transactionId), book(book), member(member), issueDate(issueDate), returnDate(returnDate) {}

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
    static std::unique_ptr<Library> library;
    std::vector<std::unique_ptr<Book>> books;
    std::vector<std::unique_ptr<Member>> members;
    std::vector<Transaction> transactions;

    Library() {}

public:
    static Library* getInstance() {
        if (!library) {
            library.reset(new Library());
        }
        return library.get();
    }

    void addBook(std::unique_ptr<Book> book) {
        books.push_back(std::move(book));
    }

    void addMember(std::unique_ptr<Member> member) {
        members.push_back(std::move(member));
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


class BookFactory {
public:
    virtual std::unique_ptr<Book> createBook() = 0;
};

class RegularBookFactory : public BookFactory {
public:
    std::unique_ptr<Book> createBook(std::string title, std::string author, std::string isbn) {
        return std::unique_ptr<RegularBook>(new RegularBook(title, author, isbn));
    }
};

class ReferenceBookFactory : public BookFactory {
public:
    std::unique_ptr<Book> createBook(std::string title, std::string author, std::string isbn) {
        return std::unique_ptr<ReferenceBook>(new ReferenceBook(title, author, isbn));
    }
};

class MemberFactory {
public:
    virtual std::unique_ptr<Member> createMember() = 0;
};

class StudentMemberFactory : public MemberFactory {
    std::unique_ptr<Member> createMember(std::string name, int memberId, std::string email, int year, std::string major) {
        return std::unique_ptr<Student>(new Student(name, memberId, email, year, major));
    }
};

class FacultyMemberFactory : public MemberFactory {
    std::unique_ptr<Member> createMember(std::string name, int memberId, std::string email, std::string department, std::string position) {
        return std::unique_ptr<Faculty>(new Faculty(name, memberId, email, department, position));
    }
};

