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

void addTail(Node **tail, int x)
{
    Node *tmp = new Node(x);
    (*tail)->next = tmp;
    tmp->prev = *tail;
    *tail = tmp;
}

void deleteAt(Node **head, Node **tail, int n, int k)
{
    // store head or tail node
    Node *p;
    p = *head;

    // delete at the head of list
    if (k == 0)
    {
        p->next->prev = NULL;
        *head = p->next; // change head
        delete p;        // free old node
        return;
    }
    // delete at the tail of list
    if (k == n - 1)
    {
        p = *tail;
        p->prev->next = NULL;
        *tail = p->prev; // change tail
        delete p;        // free old node
        return;
    }
    // other
    while (--k > 0)
    {
        p = p->next;
    }
    Node *tmp = p->next;
    p->next = tmp->next;
    tmp->next->prev = p;
    delete tmp;
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
    int k; // an index 0 <= k < n
    cin >> k;
    deleteAt(&head, &tail, n, k);
    printList(head);

    return 0;
}