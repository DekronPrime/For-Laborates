#include <iostream>
#include <Windows.h>
using namespace std;

template<class T>
class List {
private:

    template<class T>
    class Node {
    public:
        T data;
        Node* next;

        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node<T>* head;
    int size;

public:
    
    List();
    ~List();

    T& operator[](int index);

    int getSize() { return size; }

    void addtoEnd(T data);
    void addtoStart(T data);
    void deleteFirst();
    void deleteLast();
};

template<class T>
List<T>::List() {
    this->size = 0;
    this->head = nullptr;
}

template<class T>
List<T>::~List() {
    cout << "\nDestructor";
    while (size) {
        deleteFirst();
    }
}

template<class T>
T& List<T>::operator[](int index) {
    
    Node<T>* current = this->head;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return current->data;
        }
        current = current->next;
        count++;
    }
}

template<class T>
void List<T>::addtoEnd(T data) {
    if (head == nullptr) {
        this->head = new Node<T>(data);
    }

    else {
        Node<T>* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(data);
    }

    size++;
}

template<class T>
void List<T>::addtoStart(T data) {
    head = new Node<T>(data, head);
    size++;
}

template<class T>
void List<T>::deleteFirst() {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template<class T>
void List<T>::deleteLast() {
    Node<T>* previous = this->head;
    Node<T>* current = this->head;
    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;
    size--;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Гордійчук Володимир. " << endl;
    cout << "Індивідуальне завдання. Варіант 4. " << endl << endl;

    List<int> obj1;
    obj1.addtoEnd(9);
    obj1.addtoEnd(16);
    obj1.addtoEnd(0);
    obj1.addtoStart(1);
    cout << "Початковий масив: ";
    for (int i = 0;i < obj1.getSize();i++) {
        cout << obj1[i] << " ";
    }
    cout << endl << "deleteLast:";
    obj1.deleteLast();
    cout << endl << "deleteFirst:" << endl;
    obj1.deleteFirst();
    cout << "Кінцевий масив: ";
    for (int i = 0;i < obj1.getSize();i++) {
        cout << obj1[i] << " ";
    }
    cout << endl << "==============================" << endl;
    List<double> obj2;
    obj2.addtoEnd(4.7);
    obj2.addtoStart(0.2);
    obj2.addtoEnd(-7.0);
    obj2.addtoStart(3.6);
    cout << "Початковий масив: ";
    for (int i = 0;i < obj2.getSize();i++) {
        cout << obj2[i] << " ";
    }
    cout << endl << "deleteLast:";
    obj2.deleteLast();
    cout << endl << "deleteFirst:" << endl;
    obj2.deleteFirst();
    cout << "Кінцевий масив: ";
    for (int i = 0;i < obj2.getSize();i++) {
        cout << obj2[i] << " ";
    }
    cout << endl << "==============================" << endl;
    List<char> obj3;
    obj3.addtoEnd('p');
    obj3.addtoStart('m');
    obj3.addtoEnd('l');
    obj3.addtoStart('e');
    obj3.addtoEnd('a');
    obj3.addtoStart('T');
    obj3.addtoEnd('t');
    obj3.addtoEnd('e');
    cout << "Початковий масив: ";
    for (int i = 0;i < obj3.getSize();i++) {
        cout << obj3[i] << " ";
    }
    cout << endl << "deleteLast:";
    obj3.deleteLast();
    cout << endl << "deleteFirst:" << endl;
    obj3.deleteFirst();
    cout << "Кінцевий масив: ";
    for (int i = 0;i < obj3.getSize();i++) {
        cout << obj3[i] << " ";
    }
    cout << endl;
    return 0;
}