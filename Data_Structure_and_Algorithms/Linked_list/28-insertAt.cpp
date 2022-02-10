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
    if (k > n)
        return;
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
    if (k >= mid) // if k >= n / 2, browse list from tail
    {
        p = *tail;
        while (++k < n)
        {
            p = p->prev;
        }
        // change next pointer and prev pointer of 3 node involved
        tmp->prev = p->prev;
        tmp->next = p;
        p->prev->next = tmp;
        p->prev = tmp;
    }
    else // if k < n / 2, browse list from head
    {
        p = *head;
        while (++k < mid)
        {
            p = p->next;
        }
        // change next pointer and prev pointer of 3 node involved
        tmp->prev = p;
        tmp->next = p->next;
        p->next->prev = tmp;
        p->next = tmp;
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
    int tmp;
    cin >> tmp;
    Node *head = new Node(tmp);
    Node *tail = head;

    // get data to list
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        addTail(&tail, tmp);
    }

    // input
    int k, x; // insert x at k index    0 <= k <= n
    cin >> k >> x;
    insertAt(&head, &tail, n, k, x);

    // algorithm
    printList(head);

    return 0;
}