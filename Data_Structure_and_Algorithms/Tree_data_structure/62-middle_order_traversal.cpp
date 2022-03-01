#include <iostream>

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

Node *insert(Node *n, int x)
{
    if (n == NULL)
        return new Node(x);
    if (x > n->key)
        n->right = insert(n->right, x);
    else
        n->left = insert(n->left, x);
}

// middle order traversal
void printTree(Node *node)
{
    if (node != NULL)
    {
        printTree(node->left);
        cout << node->key << " "; 
        printTree(node->right);
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
    printTree(root);
    return 0;
}