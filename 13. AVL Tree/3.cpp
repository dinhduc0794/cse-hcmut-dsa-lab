//Helping functions

// x la node ben trai cua root, y la node ben phai cua root

int getBalance(Node* root) {
    if (root == nullptr) return 0;
    return getHeightRec(root->pLeft) - getHeightRec(root->pRight);
}

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

Node* insertRec(Node* subroot, const T &val){
    if (subroot == nullptr){
        Node* pNew = new Node(val);
        return pNew;
    }
    if (val < subroot->data){
        subroot->pLeft = insertRec(subroot->pLeft, val);
    }
    else{
        subroot->pRight = insertRec(subroot->pRight, val);
    }
    
    int balance = getBalance(subroot);

    
    if (balance > 1){
        // left of left
        if (val < subroot->pLeft->data){
            return rotateRight(subroot);
        }
        //right of left
        else{
            // xoay trai truoc roi xoay phai
            subroot->pLeft = rotateLeft(subroot->pLeft);
            return rotateRight(subroot);
        }
    }
    else if (balance < -1){
        // left of right
        if (val < subroot->pRight->data){
            subroot->pRight = rotateRight(subroot->pRight);  
            return rotateLeft(subroot); 
        }
        //right of right
        else{
            // xoay phai roi xoay trai
            return rotateLeft(subroot);  
        }
    }
    return subroot;
}

void insert(const T &value){
    //TODO
    root = insertRec(root, value);
}
