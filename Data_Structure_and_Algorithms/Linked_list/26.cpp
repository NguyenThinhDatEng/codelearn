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

auto getValue(Node *head, int k)
{
    Node *p = head;
    while (k-- != 0)
    {
        p = p->next;
    }
    return p->data;
}

void deleteAt(Node **head, int k)
{
    // store head node
    Node *p = *head;

    // delete at the head of list
    if (k == 0)
    {
        *head = p->next; // change head
        delete p;        // free old node
        return;
    }
    // other
    while (--k > 0)
    {
        p = p->next;
    }
    Node *prev = p->next;
    p->next = p->next->next; // delete node
    delete prev;             // free memory
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
    int k; // an index 0 <= k < n
    cin >> k;
    // algorithm
    int value = getValue(head, k);
    p = head;
    Node *q = p->next;
    int i = 0;
    while (p != NULL)
    {
        // cout << "i = " << i << endl;
        if (p->data > value)
        {
            deleteAt(&head, i);
            p = q;
        }
        else
        {
            p = p->next;
            i++;
        }
        // printList(head);
        cout << endl;
        if (q)
            q = p->next;
    }

    printList(head);

    return 0;
}