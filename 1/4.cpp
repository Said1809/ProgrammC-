#include <iostream>

struct Node {
double data;
Node* next;
};

class LinkedList {
private:
Node* head;
public:
LinkedList() {
head = nullptr;
}

void addNode(double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
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

void removeBeforePositive() {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "List is empty or has only one element." << std::endl;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data <= 0) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void displayList() {
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

list.addNode(-2);
list.addNode(3);
list.addNode(-5);
list.addNode(10);
list.addNode(-7);

std::cout << "Original list: ";
list.displayList();

list.removeBeforePositive();

std::cout << "List after removing element before positive: ";
list.displayList();

return 0;
}
