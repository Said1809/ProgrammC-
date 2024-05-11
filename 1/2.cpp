#include <iostream>
#include <string>

struct Node {
std::string data;
Node* next;

Node(std::string str) : data(str), next(nullptr) {}
};

class Stack {
private:
Node* top;

public:
Stack() : top(nullptr) {}

void push(std::string str) {
    Node* newNode = new Node(str);
    if (top == nullptr) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

void pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty, cannot pop.\n";
        return;
    }
    
    Node* temp = top;
    top = top->next;
    delete temp;
}

void printStack() {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int countSingleCharStrings() {
    int count = 0;
    Node* current = top;
    while (current != nullptr) {
        if (current->data.length() == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}
};

int main() {
Stack stack;

Copy code
stack.push("abc");
stack.push("de");
stack.push("f");
stack.push("g");
stack.push("hi");
stack.push("jk");

std::cout << "Stack contents: ";
stack.printStack();

stack.pop();

std::cout << "Stack contents after popping one element: ";
stack.printStack();

int singleCharCount = stack.countSingleCharStrings();
std::cout << "Number of single character strings in the stack: " << singleCharCount << std::endl;

return 0;
}
