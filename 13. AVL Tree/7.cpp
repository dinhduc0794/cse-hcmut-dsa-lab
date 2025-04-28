bool searchHelper(Node* node, const T &val){
    if (node == nullptr) return false;
    if (val == node->data) return true;
    else if (val < node->data) return searchHelper(node->pLeft, val);
    else return searchHelper(node->pRight, val);
}

bool search(const T &val){
    return searchHelper(root, val);
}

void printInorderHelper(Node* node){
    if (node == nullptr) return;
    printInorderHelper(node->pLeft);
    cout << node->data << " ";
    printInorderHelper(node->pRight);
}

void printInorder(){
    printInorderHelper(root);
}