template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item); 
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count || count == 0){
        return T();
    }
    T remVal;
    if (index == 0){
        remVal = head->data;
        Node* temp = head;
        head = head->next;
        if (head != nullptr){
            head->previous = nullptr;
        } 
        else{
            tail = nullptr; 
        }
        delete temp;
    }
    else{
        Node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        remVal = temp->data;
        if (temp == tail){  //ptu cuoi
            tail = tail->previous;
        }
        temp->previous->next = temp->next;
        if (temp->next != nullptr){
            temp->next->previous = temp->previous;
        }
        delete temp;
    }
    count--;
    return remVal;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (count == 0) return 0;
    Node* temp = head;
    while(temp != nullptr){
        if (temp->data == item){
            // xoa dau
            if (temp == head){
                head = head->next;
                if (head != nullptr) head->previous = nullptr;
                else tail = nullptr;
            }
            // xoa cuoi
            else if (temp == tail){
                tail = tail->previous;
                tail->next = nullptr;
            }
            // xoa giua
            else{
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
            }
            delete temp;
            count--;
            return 1;
        }
        temp = temp->next;
    }
    return 0;  
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* temp = head;
    while (temp != nullptr){
        Node* delNode = temp;
        temp = temp->next;
        delete delNode;
    }
    tail = nullptr;
    head = nullptr;
    count = 0;
}