#include <iostream>
#include <string>

using namespace std;

// Order class representing an order
class Order {
public:
    string user_id;
    string symbol;
    int quantity;
    double price;
    Order* next;

    Order(const string& uid, const string& sym, int qty, double pr)
        : user_id(uid), symbol(sym), quantity(qty), price(pr), next(nullptr) {}
};

// Queue class representing a queue of orders. You may either use Array or LinkedList to implement the Queue.
class Queue {
private:
    // Put your code below.
    Order* front;   // Pointer to the front of the queue
    Order* rear;    // Pointer to the rear of the queue
    int counter;    // Number of orders in the queue

public:
    Queue();
    ~Queue();
    bool IsEmpty() const;
    bool Enqueue(const string& user_id, const string& symbol, int quantity, double price);
    bool Dequeue();
    void DisplayQueue() const;
};

Queue::Queue() {
    // Put your code below.
    front = rear = nullptr;
    counter = 0;
}

// Destructor: delete the queue.
Queue::~Queue() {
    // Put your code below.
    while (!IsEmpty()) {
        Dequeue();
    }

}


// Check if the queue is empty.
bool Queue::IsEmpty() const {
    // Put your code below.
    return front == nullptr;

}

bool Queue::Enqueue(const string& user_id, const string& symbol, int quantity, double price) {
    // Put your code below.
    Order* newOrder = new Order(user_id, symbol, quantity, price);
    if (IsEmpty()) {
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }
    counter++;
    return true;




}

bool Queue::Dequeue() {
    // Put your code below.
    if (IsEmpty()) {
        return false;
    }
    Order* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    counter--;
    return true;


}

void Queue::DisplayQueue() const {
    // Put your code below.
    Order* current = front;
    while (current != nullptr) {
        cout << "Order - User ID: " << current->user_id 
             << ", Symbol: " << current->symbol 
             << ", Quantity: " << current->quantity 
             << ", Price: " << current->price << endl;
        current = current->next;
    }


}

int main() {
    // Create a queue of orders
    Queue askQueue, bidQueue;

    // Enqueue the asks
    askQueue.Enqueue("user1", "AAPL", 10, 217.0);
    askQueue.Enqueue("user1", "AAPL", 5, 218.0);
    askQueue.Enqueue("user1", "GOOG", 8, 169.0);

    // Enqueue the bids
    bidQueue.Enqueue("user2", "AAPL", 15, 217.0);
    bidQueue.Enqueue("user2", "GOOG", 10, 170.0);

    // Display the ask orders
    cout << "Ask orders:" << endl;
    askQueue.DisplayQueue();

    // Display the bid orders
    cout << "Bid orders:" << endl;
    bidQueue.DisplayQueue();

    // Dequeue an order
    askQueue.Dequeue();

    // Display the updated queue
    cout << "\nUpdated orders in the queue:" << endl;
    askQueue.DisplayQueue();

    return 0;
}
