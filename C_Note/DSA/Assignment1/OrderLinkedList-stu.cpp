#include <iostream>
#include <string>

using namespace std;

class Order {
public:
    string user_id;
    string symbol;
    int quantity;
    double price;
    Order* next;

    Order(const string &uid, const string &sym, int qty, double pr)
        : user_id(uid), symbol(sym), quantity(qty), price(pr), next(NULL) {}
};

class LinkedList {
private:
    Order* head;

public:
    LinkedList() : head(NULL) {}
    ~LinkedList();
    void display() const;
    void append(const string& user_id, const string& symbol, int quantity, double price);
    bool insert(int index, const string& user_id, const string& symbol, int quantity, double price);
    int getSize() const;
    bool search(const string& symbol) const;
    bool remove(int index);
};

// Delete all the linkedlist nodes.
LinkedList::~LinkedList() {
    Order* current = head;
    // Traverse the list and delete each node
    while (current != NULL) {
        Order* tmp = current;
        current = current->next;
        delete tmp;
    }
    head = NULL;
    cout << "The Linked list has been deleted." << endl;
}

void LinkedList::display() const {
    Order* current = head;
    while (current != NULL) {
        // Print the order details
        cout << "Order - User ID: " << current->user_id 
             << ", Symbol: " << current->symbol 
             << ", Quantity: " << current->quantity 
             << ", Price: ";
        //cout.setf(ios::fixed);    // set fixed floating format(optional)
        //cout.precision(0);        // set precision(optional)
        cout << current->price << endl;
        current = current->next;
    }
}

// Append a new order to the end of the list
void LinkedList::append(const string& user_id, const string& symbol, int quantity, double price) {
    Order* newOrder = new Order(user_id, symbol, quantity, price);
    if (head == NULL) {
        head = newOrder;
    } else {
        // Traverse the list to find the last node
        Order* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newOrder;
    }
}

// Insert a new order at a specific position in the list. Suppose the first element in the list has index 0.
bool LinkedList::insert(int index, const string& user_id, const string& symbol, int quantity, double price) {
    if (index < 0){
        return false;
    }
    Order* newOrder = new Order(user_id, symbol, quantity, price);
    // Insert at the beginning
    if (index == 0) {
        newOrder->next = head;
        head = newOrder;
        return true;
    }

    Order* current = head;
    int i = 0;
    // Find the previous node of the node to be inserted
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    // If the index is greater than the number of nodes
    if (current == NULL) {
        delete newOrder;  // Clear the memory
        return false;
    }

    newOrder->next = current->next;
    current->next = newOrder;
    return true;
}

// Get the size (number of orders) in the list
int LinkedList::getSize() const {
    int count = 0;
    Order* current = head;
    // Traverse the list
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Search for an order with a specific symbol in the list
bool LinkedList::search(const string& symbol) const {
    Order* current = head;
    while (current != NULL) {
        if (current->symbol == symbol) return true;
        current = current->next;
    }
    return false;
}

// Remove an order at a specific position in the list
bool LinkedList::remove(int index) {
    if (index < 0 || head == NULL) {
        return false;
    }
    // Remove the first element
    if (index == 0) {
        Order* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }


    Order* current = head;
    int i = 0;
    // Find the previous node of the node to be deleted
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    // If the index is greater than the number of nodes
    if (current == NULL || current->next == NULL) {
        return false;
    }
    Order* tmp = current->next;
    current->next = current->next->next;
    delete tmp;
    return true;
}

//You can change the main function as you wish to test your implementation
int main() {
    LinkedList orders;

    // Example usage
    orders.append("user1", "AAPL", 10, 150.0);
    orders.insert(0, "user1", "AAPL", 5, 160.0);
    orders.append("user1", "GOOGL", 8, 200.0);

    cout << "Orders in the list:" << endl;
    orders.display();

    cout << "Size of the list: " << orders.getSize() << endl;

    if (orders.search("AAPL")) {
        cout << "AAPL order found in the list." << endl;
    }

    if (orders.remove(1)) {
        cout << "Order removed from the list." << endl;
    }

    cout << "Orders after removing one item:" << endl;
    orders.display();

    return 0;
}
