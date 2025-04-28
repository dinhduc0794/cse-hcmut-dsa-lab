vector<int> levelAlterTraverse(BSTNode* root) {
    vector<int> result;

    if (root == nullptr) {
        return result;
    }

    queue<BSTNode*> q;
    stack<int> s;
    bool leftToRight = true;

    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            BSTNode* current = q.front();
            q.pop();

            if (leftToRight) {
                result.push_back(current->val);
            } else {
                s.push(current->val);
            }

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        leftToRight = !leftToRight;
    }

    return result;
}