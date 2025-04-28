#include<bits/stdc++.h>

using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();

    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T& e){
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e, NULL);
    if (head == NULL){
        head = newNode;
        tail = newNode;
    } 
    else{
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e){
    /* Insert an element into the list at given index. */
    if (index < 0 || index > count) return;
    Node* newNode = new Node(e, NULL);
    if (index == 0){
        newNode->next = head;
        head = newNode;
        if (tail == NULL){
            tail = newNode;
        }
    } 
    else{
        Node* temp = head;
        for (int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (index == count){
            tail = newNode;
        }
    }
    count++;
}

template<class T>
int SLinkedList<T>::size(){
    return count;
}

