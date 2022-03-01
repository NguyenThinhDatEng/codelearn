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
int degree = 0;
void degreeTree(Node *node, int currentDegree)
{
    if (node != NULL)
    {
        degreeTree(node->left, currentDegree + 1);
        degreeTree(node->right, currentDegree + 1);
        if (isLeafNode(node))
        {
            degree = max(degree, currentDegree);
            return;
        }
    }
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
    degreeTree(root, 0);
    cout << degree;
    return 0;
}