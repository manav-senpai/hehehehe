#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string key, value;
    node *left, *right;
    node() : key(""), value(""), left(NULL), right(NULL) {}
    node(string key, string value) : key(key), value(value), left(NULL), right(NULL) {}
};

class bst {
public:
    node *root;
    bst() : root(NULL) {}
    bool insert(string, string);
    string search(string);
    bool update(string, string);
    bool delete_key(string);
    void display(node *cur);
    node* findMin(node* cur);
};

bool bst::insert(string key, string value) {
    if (root == NULL) {
        root = new node(key, value);
        return true;
    }
    node *temp = root, *prev = NULL;
    while (temp != NULL) {
        prev = temp;
        if (key == temp->key) return false;
        temp = (key < temp->key) ? temp->left : temp->right;
    }
    if (key < prev->key)
        prev->left = new node(key, value);
    else
        prev->right = new node(key, value);
    return true;
}

string bst::search(string key) {
    node *temp = root;
    while (temp != NULL) {
        if (key == temp->key) return temp->value;
        temp = (key < temp->key) ? temp->left : temp->right;
    }
    return "";
}

bool bst::update(string key, string value) {
    node *temp = root;
    while (temp != NULL) {
        if (key == temp->key) {
            temp->value = value;
            return true;
        }
        temp = (key < temp->key) ? temp->left : temp->right;
    }
    return false;
}

node* bst::findMin(node* cur) {
    while (cur->left != NULL) cur = cur->left;
    return cur;
}

bool bst::delete_key(string key) {
    node **cur = &root, *temp;
    while (*cur != NULL) {
        if ((*cur)->key == key) {
            temp = *cur;
            if ((*cur)->left == NULL)
                *cur = (*cur)->right;
            else if ((*cur)->right == NULL)
                *cur = (*cur)->left;
            else {
                node *successor = findMin((*cur)->right);
                (*cur)->key = successor->key;
                (*cur)->value = successor->value;
                key = successor->key;
                cur = &((*cur)->right);
                continue;
            }
            delete temp;
            return true;
        }
        cur = (key < (*cur)->key) ? &((*cur)->left) : &((*cur)->right);
    }
    return false;
}

void bst::display(node *cur) {
    if (cur == NULL) return;
    display(cur->left);
    cout << cur->key << " : " << cur->value << endl;
    display(cur->right);
}

int main() {
    bst tree;
    int ch;
    string k, v, ans;
    do {
        cout << "--- MAIN MENU ---" << endl;
        cout << "1 -> Insert" << endl;
        cout << "2 -> Search" << endl;
        cout << "3 -> Update" << endl;
        cout << "4 -> Delete" << endl;
        cout << "5 -> Display Ascending" << endl;
        cout << "0 -> Exit" << endl;
        cout << "Choose an option (0-5): ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Key (word) to insert: ";
                cin >> k;
                cout << "Value (meaning): ";
                cin >> v;
                cout << (tree.insert(k, v) ? "Element insertion successful." : "Element already exists.") << endl;
                break;
            case 2:
                cout << "Key (word) to search: ";
                cin >> k;
                ans = tree.search(k);
                cout << (ans.empty() ? "Element does not exist." : "Value (meaning) is: " + ans) << endl;
                break;
            case 3:
                cout << "Key (word) to update: ";
                cin >> k;
                cout << "New value (meaning): ";
                cin >> v;
                cout << (tree.update(k, v) ? "Element updated." : "Element does not exist.") << endl;
                break;
            case 4:
                cout << "Key (word) to delete: ";
                cin >> k;
                cout << (tree.delete_key(k) ? "Element deletion successful." : "Element does not exist.") << endl;
                break;
            case 5:
                cout << "Data in ascending order:" << endl;
                tree.display(tree.root);
                break;
            case 0:
                cout << "\n// END OF CODE\n";
                break;
            default:
                cout << "Please choose a valid option (0-5)." << endl;
        }
    } while (ch != 0);
    return 0;
}

