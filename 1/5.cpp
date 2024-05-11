#include <iostream>

struct Node {
    double data;
    Node* next;
    Node(double d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(double value) {
        Node* newNode = new Node(value);
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

    void insertPositiveAfterNegative() {
        Node* current = head;
        while (current != nullptr) {
            if (current->data < 0 && current->next != nullptr && current->next->data > 0) {
                Node* newNode = new Node(current->next->data);
                newNode->next = current->next;
                current->next = newNode;
                current = newNode->next;
            } else {
                current = current->next;
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
    list.insert(-2);
    list.insert(3);
    list.insert(-1);
    list.insert(-5);
    list.insert(7);
    list.insert(10);

    std::cout << "Original list: ";
    list.display();

    list.insertPositiveAfterNegative();

    std::cout << "List after inserting positive after negative: ";
    list.display();

    return 0;
}
