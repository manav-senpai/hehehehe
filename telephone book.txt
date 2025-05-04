#include <iostream>
#include <unordered_map>
using namespace std;

class TelephoneBook {
private:
    unordered_map<string, string> phoneBook;

public:
    void insertContact(string name, string number) {
        phoneBook[name] = number;
        cout << "Contact added: " << name << " -> " << number << endl;
    }

    void searchContact(string name) {
        if (phoneBook.find(name) != phoneBook.end()) {
            cout << "Phone Number of " << name << ": " << phoneBook[name] << endl;
        } else {
            cout << "Contact not found!" << endl;
        }
    }

    void deleteContact(string name) {
        if (phoneBook.erase(name)) {
            cout << "Contact deleted: " << name << endl;
        } else {
            cout << "Contact not found!" << endl;
        }
    }

    void displayContacts() {
        if (phoneBook.empty()) {
            cout << "Phone book is empty!" << endl;
            return;
        }
        cout << "Telephone Book:" << endl;
        for (auto &entry : phoneBook) {
            cout << entry.first << " -> " << entry.second << endl;
        }
    }
};

int main() {
    TelephoneBook tb;
    int choice;
    string name, number;

    do {
        cout << "\n1. Insert Contact\n2. Search Contact\n3. Delete Contact\n4. Display Contacts\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone Number: ";
                cin >> number;
                tb.insertContact(name, number);
                break;

            case 2:
                cout << "Enter Name to Search: ";
                cin >> name;
                tb.searchContact(name);
                break;

            case 3:
                cout << "Enter Name to Delete: ";
                cin >> name;
                tb.deleteContact(name);
                break;

            case 4:
                tb.displayContacts();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
	return 0;
}
