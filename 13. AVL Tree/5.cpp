//Helping functions

Node* minValueNode(Node* root){
    if(root->pLeft == NULL) return root;
    return root->pLeft;
}

int getBalance(Node* root) {
    if (root == nullptr) return 0;
    return getHeightRec(root->pLeft) - getHeightRec(root->pRight);
}

Node* deleteNode(Node* root, const T &val) { 
    if (root == NULL) 
        return root; 
 
    if (val < root->data ) 
        root->pLeft = deleteNode(root->pLeft, val); 
 
    else if(val > root->data ) 
        root->pRight = deleteNode(root->pRight, val); 
 
    else{ 
        // node co 1 con hoac node la
        if( (root->pLeft == NULL) || (root->pRight == NULL) ) { 
            Node *temp = root->pLeft ? root->pLeft : root->pRight; 
 
            // node la node la
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // node co 1 con 
            *root = *temp; // Copy the val
            free(temp); 
        } 
        else{ // node co 2 con
            // successor (smallest in the right subtree) 
            Node* temp = minValueNode(root->pRight); 
 
            // Copy the inorder successor's 
            // data to this node 
            root->data = temp->data; 
 
            // Delete the inorder successor 
            root->pRight = deleteNode(root->pRight, temp->data); 
        } 
    } 
    if (root == NULL) return root; 
    
    int balance = getBalance(root);

    
    if (balance > 1){
        // left of left
        if (val < root->pLeft->data){
            return rotateRight(root);
        }
        //right of left
        else{
            // xoay trai truoc roi xoay phai
            root->pLeft = rotateLeft(root->pLeft);
            return rotateRight(root);
        }
    }
    else if (balance < -1){
        // left of right
        if (val < root->pRight->data){
            root->pRight = rotateRight(root->pRight);  
            return rotateLeft(root); 
        }
        //right of right
        else{
            // xoay phai roi xoay trai
            return rotateLeft(root);  
        }
    }
 
    return root; 
} 

void remove(const T &value){
    //TODO
    root = deleteNode(root,value);
}