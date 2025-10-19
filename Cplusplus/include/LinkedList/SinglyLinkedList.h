/**
 * @brief Singly Linked List
 *
 * @details
 * A linked list, in its simplest form, is a collection of nodes that together form a linear ordering.
 * As in the children's game "Follow the Leader," each node stores a pointer, called next, to the next node of the list.
 * In addition, each node stores its associated element.
 * 
 * Example of a singly linked list:
 * [Head node][Link] -> [Node A][Link] -> [Node B][Link] -> [Tail Node][Link] -> Null
 * 
 * The next pointer inside a node is a link or pointer to the next node of the list.
 * Moving from one node to another by following a next reference is known as link hopping or pointer hopping.
 * The first and last nodes of a linked list are called the head and tail of the list, respectively.
 * Thus, we can link-hop through the list, starting at the head and ending at the tail.
 * We can identify the tail as the node having a null next reference.
 * The structure is called a singly linked list because each node stores a single link.
 * 
 * Like an array, a singly linked list maintains its elements in a certain order, as determined by the chain of next links.
 * Unlike an array, a singly linked list does not have a predetermined fixed size.
 * It can be resized by adding or removing nodes.
 */
#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H 1

/* Header */
// Project configuration
#include "ProjectConfiguration.h"

// C standard libraries:
#include <stdint.h>

// C++ standard libraries:
#include <cassert>

/* Macro */

/* Type */

namespace LinkedList
{

/**
 * @class Singly Linked List Node
 * 
 * @brief
 * A singly linked list node class to use for singly linked list
 * 
 * @details
 * Class T is the list element type
 */
template<class T>
class SinglyLinkedListNode
{
public:
    T element {};                            // Node element value
    SinglyLinkedListNode<T>* next = nullptr; // Next node in list

    // Constructor
    SinglyLinkedListNode() {};
    /**
     * @brief
     * Constructor
     * 
     * @param[in] v1 Node to be copied
     */
    SinglyLinkedListNode(const SinglyLinkedListNode<T>& v1);

    SinglyLinkedListNode<T>& operator=(const SinglyLinkedListNode<T>& v1);
};

/**
 * @class Singly Linked List
 * 
 * @brief
 * A singly linked list class uses dynamic memory allocation
 * 
 * @details
 * Class T is the list element type
 */
template<class T>
class SinglyLinkedList
{
public:
    // Constructor
    SinglyLinkedList();
    /**
     * @brief
     * A copy constructor in case of the shallow copy since this class allocates memory
     * 
     * @param[in] v1 Node to be copied
     */
    SinglyLinkedList(const SinglyLinkedList<T>& v1);
    // Destructor
    ~SinglyLinkedList();

    /**
     * @brief
     * Check whether the list is empty
     * 
     * @retval true  List is empty
     * @retval false List is not empty
     */
    bool empty() const;
    /**
     * @brief
     * Get the size of the list
     * 
     * @return Size of the list
     */
    uint32_t size() const;
    /**
     * @brief
     * Get front element
     * 
     * @return Front element via constant reference
     * 
     * @note
     * An error results if the list is empty
     */
    const T& front() const;
    /**
     * @brief
     * Return the element at @a index from the head
     * 
     * @param[in] index Index of the element in list
     * @return Element at @a index via constant reference
     * 
     * @note
     * An error results if the list is empty
     */
    const T& get(uint32_t index) const;

    /**
     * @brief
     * Add an element to the front of list
     * 
     * @param[in] e Element to be added
     */
    void addFront(const T& e);
    /**
     * @brief
     * Add an element at @a index from the head
     * 
     * @param[in] index Index of the list
     * @param[in] e     Element to be added
     * 
     * @note
     * If @a index exceeds the size of list, the element is added to the tail
     */
    void insert(uint32_t index, const T& e);
    // Remove an element from the front of list
    void removeFront();
    /**
     * @brief
     * Remove the element at @a index from the head
     * 
     * @param[in] index Index of the element in list
     */
    void remove(uint32_t index);
    // Remove all the elements
    void clear();

    /**
     * @brief
     * Reverse the elements of the list
     * 
     * @param[in] list List to be reversed
     */
    static void reverseList(SinglyLinkedList<T>& list)
    {
        SinglyLinkedList<T> firstReversedTemp, secondReversedTemp;

        while (! list.empty())
        {
            T element = list.front();
            list.removeFront();
            firstReversedTemp.addFront(element);
        }

        while (! firstReversedTemp.empty())
        {
            T element = firstReversedTemp.front();
            firstReversedTemp.removeFront();
            secondReversedTemp.addFront(element);
        }

        while (! secondReversedTemp.empty())
        {
            T element = secondReversedTemp.front();
            secondReversedTemp.removeFront();
            list.addFront(element);
        }
    }

    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& v1); // Overload the assignment operator in case of the shallow copy since this class allocates memory

private:
    SinglyLinkedListNode<T>* head = {}; // Pointer to the head of list
    uint32_t list_size            = {}; // The size of the list
};

/* Prototype */

/* Variable */

/* Function */

// Place template definitions to the header file to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]

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
    /** @todo add exception handle */

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
void SinglyLinkedList<T>::insert(uint32_t index, const T& e)
{
    if (index == 0)
    {
        addFront(e);
        return;
    }

    SinglyLinkedListNode<T>* u = new SinglyLinkedListNode<T>; // Create a new node for e
    assert(u != nullptr);
    u->element = e;

    if (list_size < index)
    {
        index = list_size; // Insert to the tail node
    }

    SinglyLinkedListNode<T>* previous = head;
    SinglyLinkedListNode<T>* current  = head->next;
    for (size_t i = 1; i < index; i++)
    {
        previous = current;
        current  = current->next;
    }

    // Link previous node <-> u node
    previous->next = u;
    // Link u node <-> current node
    u->next        = current;

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
void SinglyLinkedList<T>::remove(uint32_t index)
{
    assert(! empty());
    assert(index < list_size);

    if (index == 0)
    {
        removeFront();
        return;
    }

    SinglyLinkedListNode<T>* previous = head;
    SinglyLinkedListNode<T>* current  = head->next;
    for (size_t i = 1; i < index; i++)
    {
        previous = current;
        current  = current->next;
    }

    previous->next = current->next;
    delete current;
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

#endif /* _SINGLY_LINKED_LIST_H */
