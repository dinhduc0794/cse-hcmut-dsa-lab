// STUDENT ANSWER BEGIN

bool findRec(Node* root, T value) {
    if (root == nullptr) return false;

    if (value == root->value) return true;
    else if (value < root->value) return findRec(root->pLeft, value);
    else return findRec(root->pRight, value);
}


bool find(T value) {
    return findRec(root, value);
}


T sumRec(Node* root, T l, T r) {
    if (root == nullptr) return 0;

    T sum = 0;
    if (root->value >= l && root->value <= r) sum += root->value;

    if (root->value > l) sum += sumRec(root->pLeft, l, r);
    if (root->value < r) sum += sumRec(root->pRight, l, r);

    return sum;
}


T sum(T l, T r) {
    return sumRec(root, l, r);
}

// STUDENT ANSWER END