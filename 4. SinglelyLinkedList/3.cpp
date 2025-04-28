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
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(const T& item);
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
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count || count == 0){
        return T();
    }
    if (index == 0){
        T removeVal = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return removeVal;
    }
    else{
        Node* prev = head;
        Node* temp = head->next;
        for (int i = 1; i < index; i++){
            if (temp == nullptr) return T();
            prev = temp;
            temp = temp->next;
        }
        T removeVal = temp->data;
        if (temp->next != nullptr){
            prev->next = temp->next;
            count--;
            delete temp;
        }
        else{
            tail = prev;
            prev->next = nullptr;
            delete temp;
            count--;
        }
        return removeVal;
    }
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (count == 0){
        return 0;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            if (temp->next->data == item){
                Node* deleteNode = temp->next;
                if (deleteNode->next == nullptr){
                    tail = temp;
                    delete deleteNode;
                    count--;
                }
                else{
                    temp->next = temp->next->next;
                    delete deleteNode;
                    count--;
                }
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* temp = head;
    while(temp != nullptr){
        Node* deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
    head = nullptr;
    count = 0;
}

int main(){
    	
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(9) == list.removeAt(9));

    // cout << list.toString();
    return 0;
}