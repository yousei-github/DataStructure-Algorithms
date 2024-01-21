/* Header */
#include "LinkedList/SinglyLinkedList.h"

/* Macro */

/* Type */

/* Prototype */

/* Variable */

/* Function */

namespace LinkedList
{

template<class T>
SinglyLinkedListNode<T>::SinglyLinkedListNode(const SinglyLinkedListNode<T>& v1)
{
    element = v1.element;
    next    = v1.next;
}

template<class T>
SinglyLinkedListNode<T>& SinglyLinkedListNode<T>::operator=(const SinglyLinkedListNode<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        element = v1.element;
        next    = v1.next;
    }

    return *this; // Allow to chain together assignments
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
: head(nullptr), list_size(0)
{
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& v1)
{
    for (size_t i = 0; i < v1.list_size; i++)
    {
        addFront(v1.get(v1.list_size - i - 1));
    }
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    clear();
}

template<class T>
bool SinglyLinkedList<T>::empty() const
{
    // The empty state: check whether the head pointer points nullptr
    return (head == nullptr);
}

template<class T>
uint32_t SinglyLinkedList<T>::size() const
{
    return list_size;
}

template<class T>
const T& SinglyLinkedList<T>::front() const
{
    assert(! empty());
    return head->element;
}

template<class T>
const T& SinglyLinkedList<T>::get(uint32_t index) const
{
    assert(! empty());
    assert(index < list_size);

    SinglyLinkedListNode<T>* node = head;
    for (size_t i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node->element;
}

template<class T>
void SinglyLinkedList<T>::addFront(const T& e)
{
    SinglyLinkedListNode<T>* u = new SinglyLinkedListNode<T>; // Create a new node for e
    assert(u != nullptr);
    u->element = e;

    // Link u node <-> old head node
    u->next    = head;
    // The u node is now the head
    head       = u;

    list_size++;
}

template<class T>
void SinglyLinkedList<T>::removeFront()
{
    assert(! empty());
    SinglyLinkedListNode<T>* oldHead = head;          // Save current head
    head                             = oldHead->next; // Skip over old head
    delete oldHead;
    list_size--;
}

template<class T>
void SinglyLinkedList<T>::clear()
{
    while (! empty())
    {
        removeFront();
    }
}

template<class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        clear(); // Delete old data

        for (size_t i = 0; i < v1.list_size; i++)
        {
            addFront(v1.get(v1.list_size - i - 1));
        }
    }

    return *this; // Allow to chain together assignments
}

} /* namespace LinkedList */
