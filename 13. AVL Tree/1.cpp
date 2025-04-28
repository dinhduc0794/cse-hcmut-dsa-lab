// x la node ben trai cua root, y la node ben phai cua root

Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    if (root == nullptr) return nullptr;
    Node* x = root->pLeft;
    root->pLeft = x->pRight;
    x->pRight = root;
    
    return x;
}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
    if (root == nullptr) return nullptr;
    Node* y = root->pRight; 
    root->pRight = y->pLeft;
    y->pLeft = root;
    
    return y;
}