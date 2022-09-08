// hashTableUsingLinkedList.cpp 

#include <iostream>

using namespace std;

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
    bool search(int key);
    void Delete(int key);
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

bool hashtable::search(int key)
{
    Node* p=ht[hash(key)];

    while (p)
    {
        if (p->data == key)
            return 1;
        p = p->next;
    }
    return 0;
}

void hashtable::Delete(int key)
{
    int i = hash(key);

   Node* p= ht[i];

   if (!p)
       return;

   //first node in that location
   if (p->data == key)
   {
       ht[i] = p->next;
       delete p;
       return;
   }

    Node* q = nullptr;

    while (p && p->data!=key)
    {
        q = p;
        p = p->next;
          
    }
    if (p->data == key)
    {
        q->next = p->next;
        delete p;
    }
    
}


int main()
{

    hashtable h;
    int a[] = { 16, 12, 25, 39, 6, 122, 5, 68, 75 };

    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n;i++)
        h.insert(a[i]);


    cout<<h.search(122);
    
    h.Delete(75);

    return 0;
}
