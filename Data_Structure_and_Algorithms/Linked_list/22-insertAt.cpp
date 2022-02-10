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

void insertAt(Node **head, int k, int x)
{
    Node *tmp = new Node(x);
    if (k == 0)
    {
        tmp->next = *head;
        *head = tmp;
        return;
    }
    // k > 0
    Node *p = *head;
    while (--k > 0)
    {
        p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
    // p = p->next->next;
    // cout << "p = " << p->data << endl;
}

void printList(Node *head)
{
    Node *p = head;
    while (p != NULL)
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

    // input
    int k; // an index
    int x; // a value
    cin >> k >> x;
    insertAt(&head, k, x);

    printList(head);

    return 0;
}