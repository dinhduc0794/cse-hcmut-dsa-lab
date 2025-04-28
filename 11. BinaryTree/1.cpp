// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int countTwoChildrenNodeHelper(Node *node) {
    if (!node) return 0;

    int count = 0;

    if (node->pLeft && node->pRight) count++;

    count += countTwoChildrenNodeHelper(node->pLeft);
    count += countTwoChildrenNodeHelper(node->pRight);

    return count;
}

int countTwoChildrenNode() {
    return countTwoChildrenNodeHelper(root);
}
// STUDENT ANSWER END