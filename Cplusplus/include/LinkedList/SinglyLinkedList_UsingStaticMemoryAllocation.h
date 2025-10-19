/**
 * @brief Singly Linked List Using Static Memory Allocation
 *
 * @details
 * Implementing a linked list without dynamic memory allocation.
 * It requires pre-allocating a fixed-size pool of nodes and managing them manually.
 *
 * This approach is common in embedded systems or scenarios where dynamic memory allocation is restricted or undesirable.
 */
#ifndef _SINGLY_LINKED_LIST_USING_STATIC_MEMORY_ALLOCATION_H
#define _SINGLY_LINKED_LIST_USING_STATIC_MEMORY_ALLOCATION_H 1

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
 * @class Static Singly Linked List Node
 * 
 * @brief
 * A singly linked list node class to use for static singly linked list
 * 
 * @details
 * Class T is the list element type
 */
template<class T>
class StaticSinglyLinkedListNode
{
public:
    T element {};             // Node element value
    uint32_t next_index = {}; // Index of the next node in the array

    // Constructor
    StaticSinglyLinkedListNode() {};
    /**
     * @brief
     * Constructor
     * 
     * @param[in] v1 Node to be copied
     */
    StaticSinglyLinkedListNode(const StaticSinglyLinkedListNode<T>& v1);

    StaticSinglyLinkedListNode<T>& operator=(const StaticSinglyLinkedListNode<T>& v1);
};

/**
 * @class Static Singly Linked List
 * 
 * @brief
 * A singly linked list class uses static memory allocation
 * 
 * @details
 * Class T is the list element type
 */
template<class T>
class StaticSinglyLinkedList
{
public:
    // Array index
    enum class ArrayIndex : uint32_t
    {
        END_NODE_INDEX = UINT32_MAX
    };

    /**
     * @brief
     * Constructor
     * 
     * @param[in] pool Array of all linked list nodes prepared by the user
     */
    StaticSinglyLinkedList(StaticSinglyLinkedListNode<T>* const pool);
    // Destructor
    ~StaticSinglyLinkedList();

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
     * Get front node
     * 
     * @return Front node via constant reference
     * 
     * @note
     * An error results if the list is empty
     */
    const StaticSinglyLinkedListNode<T>& front() const;
    /**
     * @brief
     * Return the node at @a index from the head
     * 
     * @param[in] index Index of the node in list
     * @return Node at @a index via constant reference
     * 
     * @note
     * An error results if the list is empty
     */
    const StaticSinglyLinkedListNode<T>& get(uint32_t index) const;
    /**
     * @brief
     * Get the index of head of list in the array
     * 
     * @return Index of head of list in the array
     */
    uint32_t headIndex() const;
    /**
     * @brief
     * Add a node to the front of list
     * 
     * @param[in] source Source list to which the node to be added previously belonged
     * @param[in] e      Element to be added
     */

    void addFront(StaticSinglyLinkedList<T>& source, const T& e);
    /**
     * @brief
     * Add a node to the front of list
     * 
     * @param[in] u      Node to be added
     * @param[in] uIndex Index of the node to be added in array
     * @param[in] e      Element to be added
     */
    void addFront(StaticSinglyLinkedListNode<T>& u, const uint32_t& uIndex, const T& e);
    /**
     * @brief
     * Remove a node from the front of list
     * 
     * @param[out] node      Node removed
     * @param[out] nodeIndex Index of the removed node in array
     */
    void removeFront(StaticSinglyLinkedListNode<T>*& node, uint32_t& nodeIndex);
    /**
     * @brief
     * Remove the node at @a index from the head
     * 
     * @param[in]  index     Index of the node in list
     * @param[out] node      Node removed
     * @param[out] nodeIndex Index of the removed node in array
     */
    void remove(uint32_t index, StaticSinglyLinkedListNode<T>*& node, uint32_t& nodeIndex);
    /**
     * @brief
     * Remove all the nodes
     * 
     * @attention
     * User has to manually clear the list before calling destructor
     * 
     * @param[in] destination Destination list to which the removed nodes are added
     */
    void clear(StaticSinglyLinkedList<T>& destination);

    /**
     * @brief
     * Initialize the node pool
     * 
     * @param[in] pool   Array of all linked list nodes prepared by the user
     * @param[in] length Number of nodes of the array
     */
    static StaticSinglyLinkedList<T> initializePool(StaticSinglyLinkedListNode<T>* const pool, uint32_t length)
    {
        assert(0 < length);

        for (size_t index = 0; index < (length - 1); index++)
        {
            pool[index].next_index = index + 1;
        }

        // Last node points to UINT32_MAX (end of free list)
        pool[length - 1].next_index = static_cast<uint32_t>(ArrayIndex::END_NODE_INDEX);

        StaticSinglyLinkedList<T> freeList(pool);
        freeList.head_index = 0;
        freeList.list_size  = length;

        return freeList;
    }

    /**
     * @brief
     * Reverse the elements of the list
     * 
     * @param[in] pool Array of all linked list nodes prepared by the user
     * @param[in] list List to be reversed
     */
    static void reverseList(StaticSinglyLinkedListNode<T>* const pool, StaticSinglyLinkedList<T>& list)
    {
        StaticSinglyLinkedList<T> firstReversedTemp(pool), secondReversedTemp(pool);

        while (! list.empty())
        {
            StaticSinglyLinkedListNode<T> node = list.front();
            firstReversedTemp.addFront(list, node.element);
        }

        while (! firstReversedTemp.empty())
        {
            StaticSinglyLinkedListNode<T> node = firstReversedTemp.front();
            secondReversedTemp.addFront(firstReversedTemp, node.element);
        }

        while (! secondReversedTemp.empty())
        {
            StaticSinglyLinkedListNode<T> node = secondReversedTemp.front();
            list.addFront(secondReversedTemp, node.element);
        }
    }

private:
    StaticSinglyLinkedListNode<T>* array = {}; // Array storing all nodes
    uint32_t head_index                  = {}; // Index of the head of list in the array
    uint32_t list_size                   = {}; // The size of the list
};

/* Prototype */

/* Variable */

/* Function */

// Place template definitions to the header file to solve the compiling problem in C++ programming, which is ["undefined reference to" template class]

template<class T>
StaticSinglyLinkedListNode<T>::StaticSinglyLinkedListNode(const StaticSinglyLinkedListNode<T>& v1)
{
    element    = v1.element;
    next_index = v1.next_index;
}

template<class T>
StaticSinglyLinkedListNode<T>& StaticSinglyLinkedListNode<T>::operator=(const StaticSinglyLinkedListNode<T>& v1)
{
    if (this != &v1) // Avoid self-assignment
    {
        element    = v1.element;
        next_index = v1.next_index;
    }

    return *this; // Allow to chain together assignments
}

template<class T>
StaticSinglyLinkedList<T>::StaticSinglyLinkedList(StaticSinglyLinkedListNode<T>* const pool)
: array(pool), head_index(static_cast<uint32_t>(ArrayIndex::END_NODE_INDEX)), list_size(0)
{
}

template<class T>
StaticSinglyLinkedList<T>::~StaticSinglyLinkedList()
{
}

template<class T>
bool StaticSinglyLinkedList<T>::empty() const
{
    // The empty state: check whether the head index is UINT32_MAX
    return (head_index == static_cast<uint32_t>(ArrayIndex::END_NODE_INDEX));
}

template<class T>
uint32_t StaticSinglyLinkedList<T>::size() const
{
    return list_size;
}

template<class T>
const StaticSinglyLinkedListNode<T>& StaticSinglyLinkedList<T>::front() const
{
    assert(! empty());
    /** @todo add exception handle */

    StaticSinglyLinkedListNode<T>* node = array + head_index;

    return *node;
}

template<class T>
const StaticSinglyLinkedListNode<T>& StaticSinglyLinkedList<T>::get(uint32_t index) const
{
    assert(! empty());
    assert(index < list_size);

    StaticSinglyLinkedListNode<T>* node = array + head_index;
    for (size_t i = 0; i < index; i++)
    {
        node = array + node->next_index;
    }

    return *node;
}

template<class T>
uint32_t StaticSinglyLinkedList<T>::headIndex() const
{
    return head_index;
}

template<class T>
void StaticSinglyLinkedList<T>::addFront(StaticSinglyLinkedList<T>& source, const T& e)
{
    if (source.empty())
    {
        assert(false);
    }

    StaticSinglyLinkedListNode<T>* u = {}; // Create a new node for e
    uint32_t u_index                 = static_cast<uint32_t>(ArrayIndex::END_NODE_INDEX);
    source.removeFront(u, u_index);

    u->element    = e;
    // Link u node <-> old head node
    u->next_index = head_index;
    // The u node is now the head
    head_index    = u_index;

    list_size++;
}

template<class T>
void StaticSinglyLinkedList<T>::addFront(StaticSinglyLinkedListNode<T>& u, const uint32_t& uIndex, const T& e)
{
    u.element    = e;
    // Link u node <-> old head node
    u.next_index = head_index;
    // The u node is now the head
    head_index   = uIndex;

    list_size++;
}

template<class T>
void StaticSinglyLinkedList<T>::removeFront(StaticSinglyLinkedListNode<T>*& node, uint32_t& nodeIndex)
{
    assert(! empty());

    const uint32_t oldHead_index = head_index;
    node                         = array + head_index; // Save current head
    head_index                   = node->next_index;   // Skip over old head
    nodeIndex                    = oldHead_index;
    list_size--;
}

template<class T>
void StaticSinglyLinkedList<T>::remove(uint32_t index, StaticSinglyLinkedListNode<T>*& node, uint32_t& nodeIndex)
{
    assert(! empty());
    assert(index < list_size);

    if (index == 0)
    {
        removeFront(node, nodeIndex);
        return;
    }

    StaticSinglyLinkedListNode<T>* previous = array + head_index;
    uint32_t current_index                  = previous->next_index;
    StaticSinglyLinkedListNode<T>* current  = array + current_index;
    for (size_t i = 1; i < index; i++)
    {
        previous      = current;
        current_index = current->next_index;
        current       = array + current_index;
    }

    previous->next_index = current->next_index;
    node                 = array + current_index;
    nodeIndex            = current_index;
    list_size--;
}

template<class T>
void StaticSinglyLinkedList<T>::clear(StaticSinglyLinkedList<T>& destination)
{
    while (! empty())
    {
        StaticSinglyLinkedListNode<T>* node = array + head_index;
        destination.addFront(*this, node->element);
    }
}

} /* namespace LinkedList */

#endif /* _SINGLY_LINKED_LIST_USING_STATIC_MEMORY_ALLOCATION_H */
