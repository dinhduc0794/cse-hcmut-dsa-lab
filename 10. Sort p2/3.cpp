ListNode* mergeLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* current = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return dummy.next;
}

ListNode* mergeSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr;

    ListNode* sortedFirstHalf = mergeSortList(head);
    ListNode* sortedSecondHalf = mergeSortList(secondHalf);

    return mergeLists(sortedFirstHalf, sortedSecondHalf);
}