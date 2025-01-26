#include <stdexcept>
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class Stack {
    Node<T>* top;
    int size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(T value) {
        top = new Node<T>(value, top);
        size++;
    }

    T pop() {
        if (top == nullptr) {
            throw std::underflow_error("Stack is empty - is not possible to remove element");
        }
        T val = top->data;
        Node<T>* oldtop = top;
        top = top->next;
        delete oldtop;
        size--;
        return val;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack size: " << stack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    stack.pop();
    std::cout << "Stack size after pop: " << stack.getSize() << std::endl;

    stack.pop();
    stack.pop();
    std::cout << "Is stack empty after pops? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
