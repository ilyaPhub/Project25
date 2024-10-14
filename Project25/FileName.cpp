#include <iostream>
using namespace std;

class Laptop
{
private:
    char brand[50];
    char model[50];
    double price;

public:
    Laptop(const char* b = "", const char* m = "", double p = 0.0) : price(p) {
        for (int i = 0; i < 50; ++i) {
            brand[i] = b[i];
            model[i] = m[i];
            if (b[i] == '\0' && m[i] == '\0') break;
        }
    }

    Laptop(const Laptop& other) : price(other.price) {
        for (int i = 0; i < 50; ++i) {
            brand[i] = other.brand[i];
            model[i] = other.model[i];
        }
        cout << "Викликано конструктор копіювання для Laptop." << endl;
    }

    Laptop& operator=(const Laptop& other) {
        if (this != &other) {
            for (int i = 0; i < 50; ++i) {
                brand[i] = other.brand[i];
                model[i] = other.model[i];
            }
            price = other.price;
        }
        return *this;
    }

    void print() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: $" << price << endl;
    }
};

int main()
{
    Laptop laptop1("Dell", "XPS 13", 999.99);
    cout << "Laptop 1: ";
    laptop1.print();

    Laptop laptop2 = laptop1;
    cout << "Laptop 2 (копія): ";
    laptop2.print();

    Laptop laptop3;
    laptop3 = laptop1;
    cout << "Laptop 3 (після присвоєння): ";
    laptop3.print();

    return 0;
}
