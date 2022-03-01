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

// Pre-order traversal
int count = 0;
void number_of_leftNodes(Node *node)
{
    if (node != NULL)
    {
        if (node->left == NULL && node->right == NULL)
        {
            count++;
            return;
        }
        // cout << node->key << " ";
        number_of_leftNodes(node->left);
        number_of_leftNodes(node->right);
    }
}

// Way 02
/*
bool isLeafNode(Node *l)
{
    return (l->left == NULL && l->right == NULL);
}

int countLeafNode(Node *t)
{
    if (t == NULL)
        return 0;
    if (isLeafNode(t))
        return 1;
    return countLeafNode(t->left) + countLeafNode(t->right);
}
*/

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
    number_of_leftNodes(root);
    cout << count;

    // cout << countLeafNode(root);
    return 0;
}