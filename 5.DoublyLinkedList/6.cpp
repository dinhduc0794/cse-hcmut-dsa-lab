struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* reverse(ListNode* head, int a, int b) {
    // ko reverse, tra ve danh sach ban dau
    if (a == b) return head;

    ListNode dummy(0);
    dummy.right = head;     //dung node ao dummy de quan li head
    ListNode* before = &dummy;
    // duyet den node thu a
    for (int i = 1; i < a ; i++){
        before = before->right;
    }
    ListNode* curr = before->right;
    ListNode* prev = nullptr;
    // dao nguoc danh sach tu a den b
    for (int i = a; i <= b; i++){
        ListNode* next = curr->right;
        curr->right = prev;
        curr->left = next;
        prev = curr;
        curr = next;
    }
    // gắn danh sách con từ a->b sau khi đã đảo vào danh sách ban đầu
    before->right->right = curr;
    if (curr != nullptr){
        curr->left = before->right;
    }
    before->right = prev;
    if (prev != nullptr){
        prev->left = before;
    }
    return dummy.right; //head
}