#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next; // a pointer
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *makeNode(int data)
{
    Node *tmp = new Node(data);
    return tmp;
}

void append(Node *p, int data)
{
    Node *tmp = new Node(data);
    p->next = tmp;
}

void printList(Node *head, int n, int k)
{
    Node *p = head;
    while (k-- > 0)
    {
        p = p->next;
    }

    while (n-- > 0)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    // input
    int n;
    cin >> n;

    // get data to the head of list
    int tmp;
    cin >> tmp;
    Node *head = new Node(tmp);

    // get data to list
    Node *p = head;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        append(p, tmp);
        p = p->next;
    }
    // append tail with head of list
    p->next = head;

    // input
    int k; // number of rotations  0 <= k < n
    cin >> k;
    printList(head, n, k);

    return 0;
}