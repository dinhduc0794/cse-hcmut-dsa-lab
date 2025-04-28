T getMin() {
    Node* current = root;
    while (current->pLeft != nullptr) {
        current = current->pLeft;
    }
    return current->value;
}

T getMax() {
    Node* current = root;
    while (current->pRight != nullptr) {
        current = current->pRight;
    }
    return current->value;
}