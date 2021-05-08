

#include <cassert>
#include "Stack.h"
#include "string"

using namespace std;

template<class ItemType>
Stack<ItemType>::Stack()
{
    topPtr = NULL;
}


template<class ItemType>
Stack<ItemType>::~Stack() {
    while (!isEmpty())
        pop();
}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const {
    return topPtr == NULL;
}

template<class ItemType>
bool Stack<ItemType>::push( ItemType newItem) {

    Node *newPtr = new Node;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;

}

template<class ItemType>
bool Stack<ItemType>::pop() {
    if (isEmpty())
        return false;
    else {
        Node *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}


template<class ItemType>
ItemType Stack<ItemType>::peek() const {
    assert(!isEmpty());
    return topPtr->item;
} // end getTop

template class Stack<double>;
template class Stack<char>;
