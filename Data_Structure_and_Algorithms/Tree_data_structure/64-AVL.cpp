#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->key = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *root = NULL;

// the right child node is always larger than or equal the parent node.
Node *insert(Node *n, int x)
{
    if (n == NULL)
        return new Node(x);
    if (x < n->key)
        n->left = insert(n->left, x);
    else
        n->right = insert(n->right, x);
}

bool isLeafNode(Node *l)
{
    return (l->left == NULL && l->right == NULL);
}

// Post-order traversal
int degreeTree(Node *node)
{
    if (node == NULL)
        return -1;
    return 1 + max(degreeTree(node->left), degreeTree(node->right));
}

int isAVLTree(Node *node)
{
    if (node == NULL)
        return true;
    if (abs(degreeTree(node->left) - degreeTree(node->right)) > 1)
        return false;
    return isAVLTree(node->left) && isAVLTree(node->right);
}

int main()
{
    // input
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        root = insert(root, tmp);
    }
    // print
    if (isAVLTree(root))
        cout << "true";
    else
        cout << "false";
    return 0;
}