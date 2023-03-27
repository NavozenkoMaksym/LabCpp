#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
class Node {
public:
    Node<T>* next;
    T data;
    Node(T data) {
        this->next = nullptr;
        this->data = data;
    }
};

template <typename T>
class List {
public:
    Node<T>* head;
    List() {
        this->head = nullptr;
    }
    void operator+(T item) {
        Node<T>* newNode = new Node<T>(item);
        if (this->head == nullptr) {
            this->head = newNode;
        }
        else {
            Node<T>* currentNode = this->head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }
    void operator--(int i) {
        if (this->head == nullptr) {
            return;
        }
        Node<T>* currentNode = this->head;
        Node<T>* previousNode = nullptr;
        while (currentNode->next != nullptr) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        if (previousNode == nullptr) {
            this->head = nullptr;
        }
        else {
            previousNode->next = nullptr;
        }
        delete currentNode;
    }
    bool operator!=(const List<T>& other) {
        Node<T>* currentNode1 = this->head;
        Node<T>* currentNode2 = other.head;
        while (currentNode1 != nullptr && currentNode2 != nullptr) {
            if (currentNode1->data != currentNode2->data) {
                return true;
            }
            currentNode1 = currentNode1->next;
            currentNode2 = currentNode2->next;
        }
        if (currentNode1 == nullptr) {
            if (currentNode2 != nullptr) return true;
        }
        else {
            if (currentNode2 == nullptr) return true;
        }
        return false;
    }
    void print() {
        Node<T>* currentNode = this->head;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List<int> a, b;
    a + 12;
    a + 11;
    a + -14;
    a + 90;
    cout << "a" << endl;
    a.print();
    a--;
    cout << "a--" << endl;
    a.print();
    b + 12;
    b + 11;
    cout << "b" << endl;
    b.print();
    if (a != b) {
        cout << "Списки не рівні";
    }
    else {
        cout << "Списки рівні";
    }
}