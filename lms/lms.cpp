#include <string>
#include <iostream>

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

int main() {
    RegularBook book1("abc", "ABC", "0151");
    ReferenceBook book2("abcd", "ABCD", "0152");
    book1.displayInfo();
    book2.displayInfo();
}
