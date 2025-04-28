#include<bits/stdc++.h>

using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
}

LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    LLNode* prev = nullptr;
    LLNode* curr = head;
    LLNode* next;
    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    int arr[] = {13, 88, 60, 7, 192};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead);
    newhead->clear();
}
