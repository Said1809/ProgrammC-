#include <iostream>

struct Node {
double data;
Node* next;
Node(double d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
Node* head;

LinkedList() : head(nullptr) {}

void insert(double data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void removeFirst(double value) {
    if (head == nullptr) {
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
}

void display() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
};

int main() {
LinkedList list;
list.insert(10);
list.insert(5);
list.insert(10);
list.insert(15);

std::cout << "Original list:" << std::endl;
list.display();

// Remove first element with value 10
list.removeFirst(10);

std::cout << "List after removing first element with value 10:" << std::endl;
list.display();

return 0;
}
