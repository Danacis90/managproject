#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    string phone;
    Customer* next;
};

struct Shop {
    string name;
    string location;
    string phone;
    Shop* next;
};

void showCustomerList(Customer* head) {
    cout << "\n--- Customer List ---\n";
    if (!head) {
        cout << "No customers to show.\n";
        return;
    }
    while (head) {
        cout << "Name: " << head->name << ", Phone: " << head->phone << endl;
        head = head->next;
    }
}

void showShopList(Shop* head) {
    cout << "\n--- Shop List ---\n";
    if (!head) {
        cout << "No shops to show.\n";
        return;
    }
    while (head) {
        cout << "Shop Name: " << head->name
             << ", Location: " << head->location
             << ", Phone: " << head->phone << endl;
        head = head->next;
    }
}

void deleteCustomerByPhone(Customer*& head, const string& phone) {
    Customer* temp = head;
    Customer* prev = NULL;

    while (temp && temp->phone != phone) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Customer not found.\n";
        return;
    }

    if (!prev)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Customer deleted successfully.\n";
}

void deleteShopByPhone(Shop*& head, const string& phone) {
    Shop* temp = head;
    Shop* prev = NULL;

    while (temp && temp->phone != phone) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Shop not found.\n";
        return;
    }

    if (!prev)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Shop deleted successfully.\n";
}

void searchCustomer(Customer* head) {
    string name;
    cout << "\nEnter customer name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    while (head) {
        if (head->name == name) {
            cout << "Customer Found: " << head->name << ", Phone: " << head->phone << endl;
            found = true;
            break;
        }
        head = head->next;
    }

    if (!found)
        cout << "Customer not found.\n";
}

void searchShop(Shop* head) {
    string name;
    cout << "\nEnter shop name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    while (head) {
        if (head->name == name) {
            cout << "Shop Found: " << head->name
                 << ", Location: " << head->location
                 << ", Phone: " << head->phone << endl;
            found = true;
            break;
        }
        head = head->next;
    }

    if (!found)
        cout << "Shop not found.\n";
}

void quitProgram() {
    cout << "Exiting the system. Goodbye!\n";
}

Customer* createCustomerList() {
    Customer* head = new Customer;
    head->name = "Ali Ahmed";
    head->phone = "0501234567";
    head->next = new Customer;
    head->next->name = "Sara Omar";
    head->next->phone = "0509876543";
    head->next->next = NULL;
    return head;
}

Shop* createShopList() {
    Shop* head = new Shop;
    head->name = "City Electronics";
    head->location = "Downtown";
    head->phone = "0551234567";
    head->next = new Shop;
    head->next->name = "Fresh Market";
    head->next->location = "Old Street";
    head->next->phone = "0557654321";
    head->next->next = NULL;
    return head;
}

void deleteCustomerList(Customer* head) {
    while (head) {
        Customer* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteShopList(Shop* head) {
    while (head) {
        Shop* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Customer* customers = createCustomerList();
    Shop* shops = createShopList();

    int choice;
    do {
        cout << "\n=== Management System Menu ===\n";
        cout << "7. Delete customer by phone\n";
        cout << "8. Delete shop by phone\n";
        cout << "9. Show customer list\n";
        cout << "10. Show shop lists\n";
        cout << "11. Search for a specific customer details\n";
        cout << "12. Search for a specific shop details\n";
        cout << "13. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 7: {
            string phone;
            cout << "Enter phone number of customer to delete: ";
            cin.ignore();
            getline(cin, phone);
            deleteCustomerByPhone(customers, phone);
            break;
        }
        case 8: {
            string phone;
            cout << "Enter phone number of shop to delete: ";
            cin.ignore();
            getline(cin, phone);
            deleteShopByPhone(shops, phone);
            break;
        }
        case 9:
            showCustomerList(customers);
            break;
        case 10:
            showShopList(shops);
            break;
        case 11:
            searchCustomer(customers);
            break;
        case 12:
            searchShop(shops);
            break;
        case 13:
            quitProgram();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 13);

    deleteCustomerList(customers);
    deleteShopList(shops);

    return 0;
}
