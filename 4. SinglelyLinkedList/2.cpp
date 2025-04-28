template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList() { };
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
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



template<class T>
T SLinkedList<T>::get(int index) {
    if (index < 0 || index >= count || count == 0){
        return T();
    }
    Node* temp = head;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= count || count == 0) return;
    if (index == 0){
        head->data = e;
    }
    else{
        Node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        temp->data = e;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (count == 0) return -1;
    Node* temp = head;
    for (int i = 0; i < count; i++){
        if (temp->data == item){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
   Node* temp = head;
    for (int i = 0; i < count; i++){
        if (temp->data == item){
            return true;
        }
        temp = temp->next;
    } 
    return false;   
}

// int main(){
//     SLinkedList<int> list;
//     int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
//     int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
//     int expvalues[]= {8,  15, 2,  4,  7, 10,  40,  6};

//     for (int idx = 0; idx < 8; idx++){
//     list.add(index[idx], values[idx]);
//     }

//     assert( list.size() == 8 );

//     for (int idx = 0; idx < 8; idx++){
//         assert( list.get(idx) == expvalues[idx] );
//     }

//     cout << list.toString();
// }

