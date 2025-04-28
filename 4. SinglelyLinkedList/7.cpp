#include<iostream>

using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
}

LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if (head == nullptr || head->next == nullptr) return head;
    LLNode* temp1 = head;
    int cnt = 0;
    while(temp1 != nullptr){
        temp1 = temp1->next;
        cnt++;
    }
    if (k > cnt) k = k%cnt;
    LLNode* temp = head;
    LLNode* head1 = head;
    for (int i = 0; i < cnt-k-1; i++){
        temp = temp->next;
    }
    LLNode* lastNode = temp;
    temp = temp->next;
    head = temp;
    lastNode->next = nullptr;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head1;
    return head;
}


// [0, 4, 2, 5, 1, 0, 6, 4, 8, 6]
[6, 0, 4, 2, 5, 1, 0, 6, 4, 8]