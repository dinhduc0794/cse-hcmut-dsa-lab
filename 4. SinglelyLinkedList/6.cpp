#include<bits/stdc++.h>

using namespace std;


class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);
}

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    LLNode dummy_head;
    LLNode* current = &dummy_head;
    int carry = 0;
    while (l0 || l1 || carry) {
        int sum = carry;
        if (l0) {
            sum += l0->val;
            l0 = l0->next;
        }
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        carry = sum / 10;
        current->next = new LLNode(sum % 10);
        current = current->next;
    }
}
