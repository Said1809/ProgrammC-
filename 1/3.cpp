#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> inStack;
    std::stack<int> outStack;

public:
    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int front = outStack.top();
        outStack.pop();
        return front;
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << q.pop() << std::endl; // Output: 1
    std::cout << q.pop() << std::endl; // Output: 2

    q.push(4);
    std::cout << q.pop() << std::endl; // Output: 3
    std::cout << q.pop() << std::endl; // Output: 4

    return 0;
}

Задание 4
1.1 Создать линейный однонаправленный список из вещественных чисел. Удалить из списка элемент перед положительным первым элементом
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
