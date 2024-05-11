#include <iostream>

struct Node {
int data;
Node* next;
};

class LinkedList {
private:
Node* head;

public:
LinkedList() {
head = nullptr;
}

void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeFirstMultipleOf5() {
    if (head == nullptr) {
        return;
    }
    
    if (head->data % 5 == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void insert44BeforeMultiplesOf7() {
    Node* current = head;
    while (current != nullptr) {
        if (current->data % 7 == 0) {
            Node* newNode = new Node;
            newNode->data = 44;
            newNode->next = current;
            current = newNode;
        }
        current = current->next;
    }
}

void printList() {
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
list.insert(15);
list.insert(10);
list.insert(7);
list.insert(6);
list.insert(42);

scss
Copy code
list.removeFirstMultipleOf5();
list.insert44BeforeMultiplesOf7();

list.printList();

return 0;
}
