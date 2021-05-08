//
// Created by Hammad Khan Musakhel on 5/22/20.
//

#ifndef HW4_STACK_H
#define HW4_STACK_H

#include "string"
using namespace std;


template<class ItemType>
class Stack {
private:
    struct Node{
        ItemType item;
        Node* next;
    };
    Node* topPtr;

public:

    ~Stack();
    Stack();
    bool isEmpty() const;
    bool pop();
    bool push(ItemType newItem);
    ItemType peek() const;
}; // end Stack


#endif //HW4_STACK_H
