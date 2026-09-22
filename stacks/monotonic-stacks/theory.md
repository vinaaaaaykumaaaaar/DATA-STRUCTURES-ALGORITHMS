### Introduction to Monotonic Stack

A monotonic stack is a special type of stack data structure where elements are kept in either increasing or decreasing order. The main idea is to maintain this order while pushing and popping elements, which helps solve a wide range of problems efficiently.

#### Understanding Monotonic Stack

A monotonic stack is a stack that maintains its elements in a fixed order either increasing or decreasing.

When a new element is pushed, it is compared with the top of the stack. If the order is violated, elements are popped until the property is restored, and then the new element is pushed.

This way, the stack always stays ordered, and since each element is pushed and popped at most once, the overall operations run in linear time.

#### Types of Monotonic Stack:
Monotonic Stacks can be broadly classified into two types:

- Monotonic Increasing Stack
- Monotonic Decreasing Stack