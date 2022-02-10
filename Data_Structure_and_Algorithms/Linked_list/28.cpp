#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next; // a pointer
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *makeNode(int data)
{
    Node *tmp = new Node(data);
    return tmp;
}

void addHead(Node **head, int x)
{
    Node *tmp = new Node(x);
    tmp->next = *head;
    *head = tmp;
}

void addTail(Node **tail, int x)
{
    Node *tmp = new Node(x);
    (*tail)->next = tmp;
    tmp->prev = *tail;
    *tail = tmp;
}

void insertAt(Node **head, Node **tail, int n, int k, int x)
{
    if (k == 0)
    {
        addHead(head, x);
        return;
    }

    if (k == n)
    {
        addTail(tail, x);
        return;
    }

    int mid = n / 2;
    Node *tmp = new Node(x);
    Node *p;
    if (k > mid)
    {
        p = *tail;
        while (--k > mid)
        {
            p = p->prev;
        }
        tmp->prev = p->prev;
        tmp->next = p;
        p->prev->next = tmp;
        p->prev = tmp;
    }
    else
    {
        p = *head;
        while (++k < mid)
        {
            p = p->prev;
        }
        tmp->prev = p->prev;
        tmp->next = p;
        p->prev->next = tmp;
        p->prev = tmp;
    }
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

    // generate head and tail
    
    Node *head = new Node(1);
    Node *tail = head;

    // get data to list
    Node *p = head;
    int tmp;
    for (int i = 2; i <= n; i++)
    {
        addTail(&tail, i);
    }

    // algorithm
    printList(head);

    return 0;
}