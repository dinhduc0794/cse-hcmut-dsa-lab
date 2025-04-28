template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};


template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    this->pList = pList;
    // Nếu begin là true, iterator sẽ được đặt ở đầu danh sách (nếu danh sách không rỗng)
    if(begin == true) {
        if(this->pList != nullptr) {
            index = 0;
            current = this->pList->head;
        }
        // danh sach rong thi index = -1
        else {
            current = nullptr;
            index = -1;
        }
    }
    //nếu begin = false, nó sẽ được đặt ở cuối danh sách (nếu danh sách không rỗng). 
    else {
        current = nullptr;
        if(this->pList != nullptr) {
            index = this->pList->count;
        } 
        else index = 0;
        
    }
    
    
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
    
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    if(current == nullptr) throw out_of_range("Segmentation fault!");
    else if(current == pList->head) {
        pList->head = current->next;
        delete current;
        current = nullptr;
        index = -1;
        pList->count--;
    }
    else {
        Node *a = pList->head;
        while(a->next != current) {
            a = a->next;
        }
        if(current == pList->tail) {
            a->next = nullptr;
            delete current;
            current = a;
            index--;
            pList->count--;
        }
        else {
            a->next = current->next;
            delete current;
            current = a;
            index--;
            pList->count--;
        }
    }  
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    if(current == nullptr) throw out_of_range("Segmentation fault!");
    else this->current->data = e;
    
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    if(current == nullptr) throw out_of_range("Segmentation fault!");
    else return this->current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    return this->current != iterator.current && this->index != iterator.index;
    
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    if(this->index == -1 ) {
        current = pList->head;
        index++;
    }
    else if(this->index == this->pList->count - 1) {
        current = nullptr;
        index++;
    }
    else if(this->index == this->pList->count) throw out_of_range("Segmentation fault!");
    else {
        this->current = this->current->next;
        index++;
    }
    return *this;
    
    
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    if(this->index==-1)
    {
        current=pList->head;
        index++;
    }
    else if(this->index==this->pList->count-1)
    {
        current=nullptr;
        index++;
    }
    else if(this->index==this->pList->count)  std::out_of_range("Segmentation fault!");
    else{
         this->current=this->current->next;
         index++;
    }
    return *this;
}