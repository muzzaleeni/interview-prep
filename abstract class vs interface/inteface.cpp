/* Use an interface when you need to define a contract for unrelated classes to implement, 
without providing any shared behavior or implementation details. */

#include <string>

class ILogger {
public:
    virtual void log(const std::string& message) = 0; // Pure virtual function
};

class FileLogger : public ILogger {
public:
    void log(const std::string& message) override {
        // Implementation for logging to a file
    }
};

class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override {
        // Implementation for logging to the console
    }
};