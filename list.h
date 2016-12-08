#ifndef LIST_H
#define LIST_H


class List
{
    typedef struct _Node{
        int vertex;
        struct _Node *next;

        _Node()
        {
            next = 0;
        }

        _Node(int data)
        {
            vertex = data;
            next = 0;
        }
    } Node;

public:
    List()
    {
        head = new Node;
    }
    ~List();
    void Add(int data)
    {
        head->next = new Node(data);
    }
    void Link(List &a, List &b);


    void InitTrans()
    {
        cur = head->next;
    }
    int GetNextVertex()
    {
        if (cur) {
            int temp = cur->vertex;
            cur = cur->next;
            return temp;
        } else
            return -1;
    }


private:
    void Clear();

    Node *head;
    Node *cur;
};

#endif // LIST_H
