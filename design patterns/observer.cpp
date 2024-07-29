/* In a stock market application, investors (observers) want
 to be notified whenever the price of a stock (subject) changes.
 The Observer pattern allows the stock to notify all registered
 investors about price changes. */

#include <iostream>
#include <vector>
#include <algorithm>

class Investor {
public:
    virtual void update(float price) = 0;
};

class Stock {
private:
    std::vector<Investor*> investors;
    float price;

public:
    void attach(Investor* investor) {
        investors.push_back(investor);
    }

    void detach(Investor* investor) {
        investors.erase(std::remove(investors.begin(), investors.end(), investor), investors.end());
    }

    void setPrice(float newPrice) {
        price = newPrice;
        notify();
    }

    void notify() {
        for (Investor* investor : investors) {
            investor->update(price);
        }
    }
};

class ConcreteInvestor : public Investor {
public:
    void update(float price) override {
        std::cout << "Stock price updated to: " << price << std::endl;
    }
};

int main() {
    Stock stock;
    ConcreteInvestor investor1, investor2;

    stock.attach(&investor1);
    stock.attach(&investor2);

    stock.setPrice(100.5);
    stock.setPrice(101.0);

    return 0;
}