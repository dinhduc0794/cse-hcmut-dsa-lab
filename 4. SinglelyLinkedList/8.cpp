class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
	void partition(int k);
};

// void LinkedList::partition(int k) {
//     Node *p = head;
//     Node *r ;
//     Node *h = new Node;
//     int dau = 0;
//     while(p!=nullptr) {
//         if(p->value < k && dau != 0) {
//             Node *q = new Node;
//             q->value = p->value;
//             q->next = nullptr;
//             r->next = q;
//             r = q;
//         }
//         if(p->value < k && dau == 0) {
//             h->value = p->value;
//             h->next = nullptr;
//             r = h;
//             dau = 1;
//         }
//          p = p->next;
//     }
//     p=head;
//     while(p!=nullptr) {
//         if(p->value == k && dau != 0) {
//             Node *q = new Node;
//             q->value = p->value;
//             q->next = nullptr;
//             r->next = q;
//             r = q;
//         }
//         if(p->value == k && dau == 0) {
//             h->value = p->value;
//             h->next = nullptr;
//             r = h;
//             dau = 1;
//         }
//          p = p->next;
//     }
//     p=head;
//     while(p!=nullptr) {
//         if(p->value > k && dau != 0) {
//             Node *q = new Node;
//             q->value = p->value;
//             q->next = nullptr;
//             r->next = q;
//             r = q;
//         }
//         if(p->value > k && dau == 0) {
//             h->value = p->value;
//             h->next = nullptr;
//             r = h;
//             dau = 1;
//         }
//          p = p->next;
//     }
    
//     head = h;
//     tail = r;

// }


void LinkedList::partition(int k) {
    Node* current = head;
    Node* smaller_head = nullptr; // Danh sách con chứa các nút có giá trị < k
    Node* smaller_tail = nullptr; // Con trỏ cuối của danh sách con smaller
    Node* equal_head = nullptr;   // Danh sách con chứa các nút có giá trị = k
    Node* equal_tail = nullptr;   // Con trỏ cuối của danh sách con equal
    Node* greater_head = nullptr; // Danh sách con chứa các nút có giá trị > k
    Node* greater_tail = nullptr; // Con trỏ cuối của danh sách con greater

    while (current != nullptr) {
        if (current->value < k) {
            // Thêm nút vào danh sách con smaller
            if (smaller_head == nullptr) {
                smaller_head = current;
                smaller_tail = current;
            } else {
                smaller_tail->next = current;
                smaller_tail = current;
            }
        } else if (current->value == k) {
            // Thêm nút vào danh sách con equal
            if (equal_head == nullptr) {
                equal_head = current;
                equal_tail = current;
            } else {
                equal_tail->next = current;
                equal_tail = current;
            }
        } else {
            // Thêm nút vào danh sách con greater
            if (greater_head == nullptr) {
                greater_head = current;
                greater_tail = current;
            } else {
                greater_tail->next = current;
                greater_tail = current;
            }
        }
        current = current->next;
    }

    // Kết nối các danh sách con lại với nhau
    if (smaller_head != nullptr) {
        head = smaller_head;
        smaller_tail->next = equal_head;
    } else if (equal_head != nullptr) {
        head = equal_head;
    } else {
        head = greater_head;
    }

    if (equal_head != nullptr) {
        equal_tail->next = greater_head; // Nối danh sách con equal với danh sách con greater
    }

    // Đặt tail trỏ đến phần tử cuối của danh sách con greater (nếu có)
    if (greater_tail != nullptr) {
        tail = greater_tail;
    } else if (equal_tail != nullptr) {
        tail = equal_tail;
    } else {
        tail = smaller_tail;
    }

    // Đảm bảo tail trỏ đến nullptr để kết thúc danh sách
    if (tail != nullptr) {
        tail->next = nullptr;
    }
}