// Provided by:   ____________David Wassman__________
// Email Address: ____________dmwassman@mail.fhsu.edu________
// FILE: link.h
// PROVIDES: A toolkit of 14 functions for manipulating linked lists. Each
// node of the list contains a piece of data and a pointer to the next node.
// The type of the data is defined as Node::Item in a typedef statement.
// The complete type definitions used by the toolkit are:
//
//   struct Node                   Item may be any of the C++ built-in types
//   {                             (int, char, etc.), or a class with a default
//       typedef _____ Item;       constructor, an assignment operator,
//       Item data;                and a test for equality (x == y).
//       Node *link;
//   };
//
// FUNCTIONS in the linked list toolkit:
//   size_t list_length(Node* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list. The list itself is unaltered.
//
//   void list_head_insert(Node*& head_ptr, const Node::Item& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   void list_insert(Node* previous_ptr, const Node::Item& entry)
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   Node* list_search(Node* head_ptr, const Node::Item& target)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned. The list itself is unaltered.
//
//   Node* list_locate(Node* head_ptr, size_t position)
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned. The list itself is unaltered.
//
//   void list_head_remove(Node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   void list_remove(Node* previous_ptr)
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.
//
//   void list_clear(Node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   void list_copy(Node* source_ptr, Node*& head_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr is the head pointer for
//     a new list that contains the same items as the list pointed to by
//
//   size_t list_occurrences(Node* head_ptr, const Node::Item& target)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The return value is the count of the number of times
//     target appears as the data portion of a node on the linked list.
//     The linked list itself is unchanged.
//
//   void list_tail_attach(Node*& head_ptr, const Node::Item& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the tail of the linked list; if this happens to be the first node of
//     the linked list, then head_ptr now points to this node (otherwise
//     head_ptr is unchanged).
//
//   void list_tail_remove(Node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The tail node has been removed and returned to the heap;
//     if the list is now empty, then head_ptr is null; otherwise head_ptr
//     is unchanged.
//
//   Node* list_copy_front(Node* source_ptr, size_t n)
//     Precondition: source_ptr is the head pointer of a linked list
//     Postcondition: The value returned is the head pointer for
//     a new list that contains copies of the first n nodes from the list
//     that source_ptr points to. If there less than n nodes in source list,
//     just copy all nodes and done

// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler before any changes are made to the list that head_ptr points
//   to : list_head_insert, list_insert, list_copy, list_piece, list_tail_attach,
//   list_copy_front

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h> // Provides size_t
namespace FHSULINKEDLIST
{
    struct Node
    {
        typedef int Item;
        Item data;
        Node *link;
    };
    
    // FUNCTIONS for the linked list toolkit
    size_t list_length(const Node* head_ptr);
    void list_head_insert(Node*& head_ptr, const Node::Item& entry);
    void list_insert(Node* previous_ptr, const Node::Item& entry);
    Node* list_search(Node* head_ptr, const Node::Item& target);
    Node* list_locate(Node* head_ptr, size_t position);
    void list_head_remove(Node*& head_ptr);
    void list_remove(Node* previous_ptr);
    void list_clear(Node*& head_ptr);
    void list_copy(Node* source_ptr, Node*& head_ptr);
    size_t list_occurrences(Node* head_ptr, const Node::Item& target);
    void list_tail_attach(Node*& head_ptr, const Node::Item& entry);
    void list_tail_remove(Node*& head_ptr);
    Node* list_copy_front(Node* source_ptr, size_t n);
}

#endif

