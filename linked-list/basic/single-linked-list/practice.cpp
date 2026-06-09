/*
Singly Linked List — full implementation with its core properties.

A singly linked list is a chain of nodes where each node stores a value and a
pointer to the next node. The list is identified by its `head` pointer; an
empty list has `head == nullptr`.

perations implemented below:
  - insert_at_head / insert_at_tail / insert_at_position
  - delete_at_head / delete_at_tail / delete_at_position / delete_value
  - search                       (does the list contain a value?)
  - length                       (number of nodes)
  - is_empty                     (head == nullptr)
  - get_at                       (value at index)
  - reverse                      (in-place reversal)
  - print_list                   (forward traversal)
  - clear                        (delete every node, free memory)

Time/space complexity is noted on each function.
*/

#include <iostream>
using namespace std;

// ---------- Node -------------------------------------------------------------