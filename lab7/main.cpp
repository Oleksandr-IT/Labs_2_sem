#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Product {
public:
    int id;
    string name;
    double price;

    Product(int id, string name, double price)
        : id(id), name(name), price(price) {}

    void show() const {
        cout << id << " " << name << " " << price << endl;
    }
};

class Customer {
public:
    string name;
    bool isBlacklisted = false;

    Customer(string name) : name(name) {}
};

class Order {
public:
    Customer* customer;
    vector<Product> products;
    bool isPaid = false;

    Order(Customer* c) : customer(c) {}

    void addProduct(const Product& p) {
        products.push_back(p);
    }

    double total() const {
        double sum = 0;
        for (auto& p : products)
            sum += p.price;
        return sum;
    }

    void pay() {
        if (customer->isBlacklisted) {
            cout << "Клієнт у чорному списку!\n";
            return;
        }
        isPaid = true;
        cout << "Замовлення оплачене. Разом = " << total() << endl;
    }
};

class StoreManager {
public:
    vector<Product> products;

    void addProduct(int id, string name, double price) {
        products.push_back(Product(id, name, price));
    }

    void showProducts() {
        for (auto& p : products)
            p.show();
    }

    void registerSale(Order& order) {
        if (order.isPaid) {
            cout << "Продаж зареєстровано!\n";
        } else {
            cout << "Замовлення не оплачене!\n";
        }
    }

    void addToBlacklist(Customer& c) {
        c.isBlacklisted = true;
        cout << c.name << " додано в чорний список\n";
    }

    void saveProducts(const string& filename) {
        ofstream fout(filename);

        if (!fout) {
            throw runtime_error("Неможливо відкрити файл для запису!");
        }

        for (auto& p : products) {
            fout << p.id << " " << p.name << " " << p.price << endl;
        }

        fout.close();
    }

    void loadProducts(const string& filename) {
        ifstream fin(filename);

        if (!fin) {
            throw runtime_error("Неможливо відкрити файл для прочитання!");
        }

        products.clear();

        int id;
        string name;
        double price;

        while (fin >> id >> name >> price) {
            products.push_back(Product(id, name, price));
        }

        fin.close();
    }

    void saveCustomers(const vector<Customer>& customers, const string& filename) {
        ofstream fout(filename);

        if (!fout) {
            throw runtime_error("Неможливо відкрити файл з клієнтами!");
        }

        for (auto& c : customers) {
            fout << c.name << " " << c.isBlacklisted << endl;
        }

        fout.close();
    }

    void loadCustomers(vector<Customer>& customers, const string& filename) {
        ifstream fin(filename);

        if (!fin) {
            throw runtime_error("Неможливо відкрити файл з клієнтами!");
        }

        customers.clear();

        string name;
        bool black;

        while (fin >> name >> black) {
            Customer c(name);
            c.isBlacklisted = black;
            customers.push_back(c);
        }

        fin.close();
    }
};

int main() {
    StoreManager manager;
    vector<Customer> customers;
    vector<Order> orders;

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;

    do {
        cout << "\n===== Меню інтернет-магазину =====\n";
        cout << "1. Додати товар\n";
        cout << "2. Показати товари\n";
        cout << "3. Створити клієнта\n";
        cout << "4. Створити замовлення\n";
        cout << "5. Додати товар в замовлення\n";
        cout << "6. Оплатити замовлення\n";
        cout << "7. Зареєструвати продаж\n";
        cout << "8. Додати клієнта у 'чорний список'\n";
        cout << "9. Зберегти дані\n";
        cout << "10. Завантажити дані\n";
        cout << "0. Вихід\n";
        cout << "Вибір: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int id;
            string name;
            double price;

            cout << "Введіть id, назву, ціну: ";
            cin >> id >> name >> price;

            manager.addProduct(id, name, price);
            break;
        }

        case 2:
            manager.showProducts();
            break;

        case 3: {
            string name;
            cout << "Введіть ім'я клієнта: ";
            cin >> name;
            customers.push_back(Customer(name));
            break;
        }

        case 4: {
            if (customers.empty()) {
                cout << "Клієнтів немає!\n";
                break;
            }

            int idx;
            cout << "Виберіть індекс клієнта (0-" << customers.size()-1 << "): ";
            cin >> idx;

            if (idx >= 0 && idx < customers.size()) {
                orders.push_back(Order(&customers[idx]));
                cout << "Замовлення створено. ID: " << orders.size()-1 << endl;
            } else {
                cout << "Некоректний індекс!\n";
            }
            break;
        }

        case 5: {
            if (orders.empty() || manager.products.empty()) {
                cout << "Нема замовлень або товару!\n";
                break;
            }

            int oid, pid;
            cout << "Замовлення ID: ";
            cin >> oid;
            cout << "Товар індекс: ";
            cin >> pid;

            if (oid >= 0 && oid < orders.size() &&
                pid >= 0 && pid < manager.products.size()) {
                orders[oid].addProduct(manager.products[pid]);
            } else {
                cout << "Некоректний ввід!\n";
            }
            break;
        }

        case 6: {
            int oid;
            cout << "Замовлення ID: ";
            cin >> oid;

            if (oid >= 0 && oid < orders.size()) {
                orders[oid].pay();
            } else {
                cout << "Некоректний ID!\n";
            }
            break;
        }

        case 7: {
            int oid;
            cout << "Замовлення ID: ";
            cin >> oid;

            if (oid >= 0 && oid < orders.size()) {
                manager.registerSale(orders[oid]);
            } else {
                cout << "Некоректний ID!\n";
            }
            break;
        }

        case 8: {
            int cid;
            cout << "Клієнт ID: ";
            cin >> cid;

            if (cid >= 0 && cid < customers.size()) {
                manager.addToBlacklist(customers[cid]);
            } else {
                cout << "Некоректний ID!\n";
            }
            break;
        }

        case 9: {
            try {
                manager.saveProducts("products.txt");
                manager.saveCustomers(customers, "customers.txt");
                cout << "Дані збережено!\n";
            } catch (exception& e) {
                cout << e.what() << endl;
            }
            break;
        }

        case 10: {
            try {
                manager.loadProducts("products.txt");
                manager.loadCustomers(customers, "customers.txt");
                cout << "Дані завантажено!\n";
            } catch (exception& e) {
                cout << e.what() << endl;
            }
            break;
        }

        case 0:
            cout << "Вихід...\n";
            break;

        default:
            cout << "Помилка у виборі!\n";
        }

    } while (choice != 0);

    return 0;
}