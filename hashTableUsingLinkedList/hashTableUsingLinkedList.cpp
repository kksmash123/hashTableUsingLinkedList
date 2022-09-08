// hashTableUsingLinkedList.cpp 

#include <iostream>


class Node
{
public:
    int data;
    Node* next;
};


class hashtable 
{
public:
    Node** ht;
    hashtable();
    int hash(int key);
    void insert(int key);
    int search(int key);
};


hashtable::hashtable()
{
    ht = new Node * [10];
    for (int i = 0;i < 10;i++)
        ht[i] = nullptr;
}

int hashtable::hash(int key)
{
    return key % 10;
}

void hashtable::insert(int key)
{
    //getting the location to insert
    int i = hash(key);

    //create a node
    Node* t = new Node;
    t->data = key;
    t->next = nullptr;

    //check insert at crt position

    if (ht[i] == nullptr)
    {
        ht[i] = t;
        return;
    }

    Node* cur =ht[i], * prev=nullptr;
    //insert before first node
    if (cur->data > key)
    {
        t->next = cur;
        ht[i] = t;
        return;
    }

    // Traverse to find the position
    while (cur && cur->data<key)
    {
        prev = cur;
        cur = cur->next;
    }
    t->next = prev->next;
    prev->next = t;

}



int main()
{

    hashtable h;
    int a[] = { 16, 12, 25, 39, 6, 122, 5, 68, 75 };

    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n;i++)
        h.insert(a[i]);



    return 0;
}
