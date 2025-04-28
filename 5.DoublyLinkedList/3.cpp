template <class T>
class DLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
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
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

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
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};

/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{
   this->pList = pList;
   if ( begin )
   {
       current = pList -> head; 
       index = 0 ; 
   }
   else
   {
       current = nullptr;
       index = pList->size();
   }
}
template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    if ( *this != iterator )
    {
        this->pList = iterator.pList;
        this->current = iterator.current;
        this->index = iterator.index;
    }
    return *this ; 
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current != nullptr)
    {
        current->data = e;
    }
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    if (current != nullptr)
    {
        return current->data;
    } 
    static T default_value; 
    return default_value;
}
template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    if (current != nullptr)
    {
        Node* nodeToRemove = current;
        if (current->previous != nullptr)
        {
            current->previous->next = current->next;
        }
        else
        {
            pList->head = current->next;
        }
        if (current->next != nullptr)
        {
            current->next->previous = current->previous;
        }
        else
        {
            pList->tail = current->previous;
        }
        current = current->previous ; 
        delete nodeToRemove;
        pList->count--;
    }
   
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
   return this->current != iterator.current; 
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    if (current != nullptr)
    {
        current = current->next;
        index++;
    }
    else 
    {
        current =pList->head ;  
        index = 0 ; 
    }
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    Iterator temp = *this;
    if (current != nullptr)
    {
        current = current->next;
        index++;
    }
    else
    {
        current =pList->head ;  
        index = 0 ;
    }
    return temp;
}