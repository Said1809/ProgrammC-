#include <iostream>
#include <string>

struct Node {
std::string data;
Node* next;
};

class Stack {
private:
Node* top;

public:
Stack() : top(nullptr) {}

void push(std::string value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    
    Node* temp = top;
    top = top->next;
    delete temp;
}

void print() {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int countStrings() {
    int count = 0;
    Node* current = top;
    while (current != nullptr) {
        if (current->data.length() >= 3) {
            count++;
        }
        current = current->next;
    }
    return count;
}
};

int main() {
Stack stack;

stack.push("Student");
stack.push("of");
stack.push("the");
stack.push("OSAT");

std::cout << "Stack content: ";
stack.print();

stack.pop();
stack.push("ONAT");

std::cout << "Updated stack content: ";
stack.print();

int count = stack.countStrings();
std::cout << "Number of strings with at least three characters: " << count << std::endl;

return 0;
}
