#ifndef NODE_H
#define NODE_H


typedef int Item;

struct Node{
    Item data;
    Node *next;
    Node *ant;

    Node(const Item& a, Node *ptr, Node *ptrb){
        data=a;
        next=ptr;
        ant=ptrb;
    }
};





#endif