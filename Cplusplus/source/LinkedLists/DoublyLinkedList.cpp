#include "LinkedLists/DoublyLinkedList.h"

/* Header */

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace LinkedLists
{

template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(const DoublyLinkedListNode<T>& v1)
{
    element  = v1.element;
    previous = v1.previous;
    next     = v1.next;
}

template<class T>
DoublyLinkedListNode<T>& DoublyLinkedListNode<T>::operator=(const DoublyLinkedListNode<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        element  = v1.element;
        previous = v1.previous;
        next     = v1.next;
    }

    return *this; // Allow to chain together assignments
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    // Create sentinels
    header  = new DoublyLinkedListNode<T>;
    trailer = new DoublyLinkedListNode<T>;
    assert((header != nullptr) && (trailer != nullptr));

    // Have sentinels point to each other
    header->next      = trailer;
    trailer->previous = header;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& v1)
{
    // Create sentinels
    header  = new DoublyLinkedListNode<T>;
    trailer = new DoublyLinkedListNode<T>;
    assert((header != nullptr) && (trailer != nullptr));

    // Have sentinels point to each other
    header->next                  = trailer;
    trailer->previous             = header;

    DoublyLinkedListNode<T>* node = v1.trailer->previous;
    for (size_t i = 0; i < v1.list_size; i++)
    {
        add(header->next, node->element);
        node = node->previous;
    }
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (! empty())
    {
        removeFront(); // Remove all but sentinels
    }

    // Remove the sentinels
    delete header;
    delete trailer;
}

template<class T>
bool DoublyLinkedList<T>::empty() const
{
    // The empty state: check whether the trailer follows immediately after the header
    return (header->next == trailer);
}

template<class T>
uint32_t DoublyLinkedList<T>::size() const
{
    return list_size;
}

template<class T>
const T& DoublyLinkedList<T>::front() const
{
    assert(! empty());
    return header->next->element;
}

template<class T>
const T& DoublyLinkedList<T>::back() const
{
    assert(! empty());
    return trailer->previous->element;
}

template<class T>
const T& DoublyLinkedList<T>::get(uint32_t index) const
{
    assert(! empty());
    assert(index < list_size);

    DoublyLinkedListNode<T>* node = header->next;
    for (size_t i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node->element;
}

template<class T>
void DoublyLinkedList<T>::addFront(const T& e)
{
    add(header->next, e); // Use the protected add(...) function
}

template<class T>
void DoublyLinkedList<T>::addBack(const T& e)
{
    add(trailer, e); // Use the protected add(...) function
}

template<class T>
void DoublyLinkedList<T>::removeFront()
{
    assert(! empty());
    remove(header->next);
}

template<class T>
void DoublyLinkedList<T>::removeBack()
{
    assert(! empty());
    remove(trailer->previous);
}

template<class T>
void DoublyLinkedList<T>::clear()
{
    while (! empty())
    {
        removeFront();
    }
}

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        clear(); // Delete old data

        DoublyLinkedListNode<T>* node = v1.trailer->previous;
        for (size_t i = 0; i < v1.list_size; i++)
        {
            add(header->next, node->element);
            node = node->previous;
        }
    }

    return *this; // Allow to chain together assignments
}

template<class T>
void DoublyLinkedList<T>::add(DoublyLinkedListNode<T>* v, const T& e)
{
    DoublyLinkedListNode<T>* u = new DoublyLinkedListNode<T>; // Create a new node for e
    assert(u != nullptr);
    u->element                         = e;

    DoublyLinkedListNode<T>* vPrevious = v->previous;
    /** @note Link u in between v and v->previous */
    // Link u node <-> v node
    u->next                            = v;
    v->previous                        = u;

    // Link v->previous node <-> u node
    u->previous                        = vPrevious;
    vPrevious->next                    = u;

    list_size++;
}

template<class T>
void DoublyLinkedList<T>::remove(DoublyLinkedListNode<T>* v)
{
    assert(! empty());
    DoublyLinkedListNode<T>* u = v->previous; // Predecessor
    DoublyLinkedListNode<T>* w = v->next;     // Successor

    // Unlink v from list
    u->next                    = w;
    w->previous                = u;
    delete v;
    list_size--;
}

} /* namespace LinkedLists */
