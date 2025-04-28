

template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (head == nullptr || head == tail) return;
    bool swapped;
    Node* ptr;
    Node* lptr = nullptr;
    bool check = 0;
    do {
        if (check) printList(); 
        check = 1;
        swapped = false;
        ptr = head;
        
        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                T temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
                
            }
            ptr = ptr->next;
        }

        lptr = ptr;
        //printList();
    } while (swapped);
}