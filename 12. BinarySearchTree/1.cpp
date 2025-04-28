 Node* addRec(Node* root, T value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->pLeft = addRec(root->pLeft, value);
    } else if (value > root->value || value == root->value) {
        root->pRight = addRec(root->pRight, value);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->pLeft != nullptr) {
        root = root->pLeft;
    }
    return root;
}

Node* deleteRec(Node* root, T value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->value) {
        root->pLeft = deleteRec(root->pLeft, value);
    } else if (value > root->value) {
        root->pRight = deleteRec(root->pRight, value);
    } else {
        if (root->pLeft == nullptr) {
            Node* temp = root->pRight;
            delete root;
            return temp;
        } else if (root->pRight == nullptr) {
            Node* temp = root->pLeft;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->pRight);

        root->value = temp->value;

        root->pRight = deleteRec(root->pRight, temp->value);
    }

    return root;
}
void add(T value) {
    root = addRec(root, value);
}

void deleteNode(T value) {
    root = deleteRec(root, value);
}