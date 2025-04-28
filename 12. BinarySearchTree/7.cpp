int kthSmallestUtil(BSTNode* root, int& k) {
    if (root == nullptr) {
        return -1;
    }

    int leftValue = kthSmallestUtil(root->left, k);

    if (k == 0) {
        return leftValue;
    }

    if (--k == 0) {
        return root->val;
    }

    return kthSmallestUtil(root->right, k);
}

int kthSmallest(BSTNode* root, int k) {
    return kthSmallestUtil(root, k);
}