#include "list.h"



void List::Link(List &a, List &b)
{
    Clear();
    Node *cur1, *cur2;
    for (cur1 = head, cur2 = a.head->next; cur2; cur1 = cur1->next, cur2 = cur2->next)
        cur1->next = new Node(cur2->vertex);
    for (cur2 = b.head->next; cur2; cur1 = cur1->next, cur2 = cur2->next)
        cur1->next = new Node(cur2->vertex);
}


List::~List()
{
    Clear();
    delete head->next;
}

void List::Clear()
{
    Node *cur = head->next;
    while (cur) {
        head->next = cur->next;
        delete cur;
        cur = head->next;
    }
}

