/* In a networked environment where multiple users send print jobs 
to a single printer, a printer spooler manages the print queue. 
The spooler ensures that only one instance of the printer management 
system exists, controlling access to the shared resource (the printer). */

#include <iostream>
#include <string>

class PrinterSpooler {
private:
    static PrinterSpooler* instance;
    PrinterSpooler() {}

public:
    static PrinterSpooler* getInstance() {
        if (!instance) {
            instance = new PrinterSpooler();
        }
        return instance;
    }

    void printDocument(const std::string& document) {
        std::cout << "Printing: " << document << std::endl;
    }
};

PrinterSpooler* PrinterSpooler::instance = nullptr;

int main() {
    PrinterSpooler* spooler = PrinterSpooler::getInstance();
    spooler->printDocument("Report.pdf");
    return 0;
}