#include "CircularlyDoublyLinkedList.h"

/* Header */

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace LinkedLists
{
template <class T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList()
    : cursor(nullptr)
{
};

template <class T>
CircularlyDoublyLinkedList<T>::~CircularlyDoublyLinkedList()
{
    while (!empty())
    {
        remove();
    }
};

template <class T>
bool CircularlyDoublyLinkedList<T>::empty() const
{
    // The empty state: chech whether the cursor is nullptr
    return (cursor == nullptr);
};

template <class T>
const T& CircularlyDoublyLinkedList<T>::front() const
{
    assert(!empty());
    return cursor->next->element;
};

template <class T>
const T& CircularlyDoublyLinkedList<T>::back() const
{
    assert(!empty());
    return cursor->element;
};

template <class T>
void CircularlyDoublyLinkedList<T>::advance()
{
    assert(!empty());
    cursor = cursor->next;
};

template <class T>
void CircularlyDoublyLinkedList<T>::retreat()
{
    assert(!empty());
    cursor = cursor->previous;
};

template <class T>
void CircularlyDoublyLinkedList<T>::add(const T& e)
{
    DoublyLinkedListNode<T>* u = new DoublyLinkedListNode<T>;   // Create a new node for e
    assert(u != nullptr);
    u->element = e;
    if (empty())    // List is empty
    {
        u->next = u;    // The u points to itself
        u->previous = u;
        cursor = u;     // The cursor points to u
    }
    else
    {
        DoublyLinkedListNode<T>* v = cursor->next;
        /** @note Link u in between cursor and v */
        // Link u node <-> v node
        u->next = v;
        v->previous = u;

        // Link cursor <-> u node
        u->previous = cursor;
        cursor->next = u;
    }
};

template <class T>
void CircularlyDoublyLinkedList<T>::remove()
{
    assert(!empty());
    DoublyLinkedListNode<T>* old = cursor->next;    // The node being removed
    if (old == cursor)  // Remove the only node
    {
        cursor = nullptr;   // The list is now empty
    }
    else
    {
        DoublyLinkedListNode<T>* v = old->next;
        // Link out the old node
        cursor->next = v;
        v->previous = cursor;
    }
    delete old; // Delete the old node
};

} /* namespace LinkedLists */
