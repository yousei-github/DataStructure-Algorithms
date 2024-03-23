/* Header */
#include "LinkedList/CircularlyDoublyLinkedList.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace LinkedList
{
template<class T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList()
: cursor(nullptr), list_size(0)
{
}

template<class T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList(const CircularlyDoublyLinkedList<T>& v1)
{
    DoublyLinkedListNode<T>* node = v1.cursor;
    for (size_t i = 0; i < v1.list_size; i++)
    {
        add(node->element);
        node = node->previous;
    }
}

template<class T>
CircularlyDoublyLinkedList<T>::~CircularlyDoublyLinkedList()
{
    while (! empty())
    {
        remove();
    }
};

template<class T>
bool CircularlyDoublyLinkedList<T>::empty() const
{
    // The empty state: check whether the cursor is nullptr
    return (cursor == nullptr);
};

template<class T>
uint32_t CircularlyDoublyLinkedList<T>::size() const
{
    return list_size;
}

template<class T>
const T& CircularlyDoublyLinkedList<T>::front() const
{
    assert(! empty());
    return cursor->next->element;
}

template<class T>
const T& CircularlyDoublyLinkedList<T>::back() const
{
    assert(! empty());
    return cursor->element;
}

template<class T>
const T& CircularlyDoublyLinkedList<T>::get(uint32_t index) const
{
    assert(! empty());

    DoublyLinkedListNode<T>* node = cursor->next;
    for (size_t i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node->element;
}

template<class T>
void CircularlyDoublyLinkedList<T>::advance()
{
    assert(! empty());
    cursor = cursor->next;
}

template<class T>
void CircularlyDoublyLinkedList<T>::retreat()
{
    assert(! empty());
    cursor = cursor->previous;
}

template<class T>
void CircularlyDoublyLinkedList<T>::add(const T& e)
{
    DoublyLinkedListNode<T>* u = new DoublyLinkedListNode<T>; // Create a new node for e
    assert(u != nullptr);
    u->element = e;
    if (empty()) // List is empty
    {
        u->next     = u; // The u points to itself
        u->previous = u;
        cursor      = u; // The cursor points to u
    }
    else
    {
        DoublyLinkedListNode<T>* v = cursor->next;
        /** @note Link u in between cursor and v */
        // Link u node <-> v node
        u->next                    = v;
        v->previous                = u;

        // Link cursor <-> u node
        u->previous                = cursor;
        cursor->next               = u;
    }
    list_size++;
}

template<class T>
void CircularlyDoublyLinkedList<T>::remove()
{
    assert(! empty());
    DoublyLinkedListNode<T>* old = cursor->next; // The node being removed
    if (old == cursor)                           // Remove the only node
    {
        cursor = nullptr; // The list is now empty
    }
    else
    {
        DoublyLinkedListNode<T>* v = old->next;
        // Link out the old node
        cursor->next               = v;
        v->previous                = cursor;
    }
    delete old; // Delete the old node
    list_size--;
}

template<class T>
void CircularlyDoublyLinkedList<T>::addFront(const T& e)
{
    add(e);
}

template<class T>
void CircularlyDoublyLinkedList<T>::addBack(const T& e)
{
    DoublyLinkedListNode<T>* u = new DoublyLinkedListNode<T>; // Create a new node for e
    assert(u != nullptr);
    u->element = e;
    if (empty()) // List is empty
    {
        u->next     = u; // The u points to itself
        u->previous = u;
        cursor      = u; // The cursor points to u
    }
    else
    {
        DoublyLinkedListNode<T>* v = cursor->next;
        /** @note Link u in between cursor and v */
        // Link u node <-> v node
        u->next                    = v;
        v->previous                = u;

        // Link cursor <-> u node
        u->previous                = cursor;
        cursor->next               = u;

        cursor                     = u; // The cursor points to u
    }
    list_size++;
}

template<class T>
void CircularlyDoublyLinkedList<T>::removeFront()
{
    remove();
}

template<class T>
void CircularlyDoublyLinkedList<T>::removeBack()
{
    assert(! empty());
    DoublyLinkedListNode<T>* old = cursor; // The node being removed
    if (cursor->next == cursor)            // Remove the only node
    {
        cursor = nullptr; // The list is now empty
    }
    else
    {
        DoublyLinkedListNode<T>* v = old->next;
        // Link out the old node
        cursor->previous->next     = v;
        v->previous                = cursor->previous;

        cursor                     = cursor->previous; // The cursor points to the previous node
    }
    delete old; // Delete the old node
    list_size--;
}

template<class T>
void CircularlyDoublyLinkedList<T>::clear()
{
    while (! empty())
    {
        remove();
    }
}

template<class T>
CircularlyDoublyLinkedList<T>& CircularlyDoublyLinkedList<T>::operator=(const CircularlyDoublyLinkedList<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        clear(); // Delete old data

        DoublyLinkedListNode<T>* node = v1.cursor;
        for (size_t i = 0; i < v1.list_size; i++)
        {
            add(node->element);
            node = node->previous;
        }
    }

    return *this; // Allow to chain together assignments
}

} /* namespace LinkedList */
