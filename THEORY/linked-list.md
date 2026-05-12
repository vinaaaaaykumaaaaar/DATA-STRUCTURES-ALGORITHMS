# Linked Lists — Complete Reference

> A **linked list** is a linear data structure where elements (nodes) are stored in **non-contiguous memory**, each node pointing to the next via a reference. It is the foundational pointer-based data structure and a staple of FAANG interviews.

---

## Table of Contents

1. [Why Linked Lists?](#1-why-linked-lists)
2. [Node Structure](#2-node-structure)
3. [Types of Linked Lists](#3-types-of-linked-lists)
4. [Core Operations & Complexity](#4-core-operations--complexity)
5. [Singly Linked List — Full Implementation](#5-singly-linked-list--full-implementation)
6. [Doubly Linked List — Key Operations](#6-doubly-linked-list--key-operations)
7. [Circular Linked List](#7-circular-linked-list)
8. [Essential Algorithms & Patterns](#8-essential-algorithms--patterns)
9. [Classic Interview Problems](#9-classic-interview-problems)
10. [Learning Tips](#10-learning-tips)
11. [Interview Tips](#11-interview-tips)

---

## 1. Why Linked Lists?

| Aspect | Array | Linked List |
|---|---|---|
| Memory | Contiguous | Scattered (heap nodes) |
| Size | Fixed / amortized resize | Truly dynamic |
| Access by index | O(1) | O(n) |
| Insert at head | O(n) | **O(1)** |
| Insert at tail | O(1) amortized | O(1) with tail ptr, else O(n) |
| Insert at middle (known node) | O(n) shift | **O(1)** |
| Cache locality | Excellent | Poor (pointer chasing) |
| Memory overhead | None | 1–2 pointers per node |

> **When to use:** Frequent insertions/deletions at known positions, unknown size in advance, or when implementing stacks/queues/LRU caches.
> **When NOT to use:** Random access, numerical processing, tight memory budgets.

---

## 2. Node Structure

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};
```

For a **doubly linked list**:
```cpp
struct DListNode {
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};
```

---

## 3. Types of Linked Lists

### 3.1 Singly Linked List (SLL)
`head → A → B → C → nullptr`
- Each node has one pointer (`next`).
- Traversal is one-directional.
- Most common in interviews.

### 3.2 Doubly Linked List (DLL)
`nullptr ← A ⇄ B ⇄ C → nullptr`
- Each node has `prev` and `next`.
- Bidirectional traversal.
- Used in **LRU cache**, browser history, undo/redo.

### 3.3 Circular Linked List
`A → B → C → A → ...`
- Last node points back to head (singly or doubly).
- Useful for round-robin scheduling, circular buffers.

### 3.4 Circular Doubly Linked List
Combination of DLL and circular — used in OS process scheduling.

---

## 4. Core Operations & Complexity

| Operation | SLL | DLL |
|---|---|---|
| Access k-th element | O(k) | O(k) |
| Insert at head | O(1) | O(1) |
| Insert at tail (no tail ptr) | O(n) | O(n) |
| Insert at tail (with tail ptr) | O(1) | O(1) |
| Insert after given node | O(1) | O(1) |
| Insert before given node | **O(n)** (need prev) | **O(1)** |
| Delete head | O(1) | O(1) |
| Delete tail | O(n) | O(1) (with tail ptr) |
| Delete given node | O(n) (need prev) | O(1) |
| Search | O(n) | O(n) |
| Reverse | O(n) | O(n) |
| Length | O(n) | O(n) |

> **Space:** O(n) for n nodes. Each node = `data` + pointer(s) overhead.

---

## 5. Singly Linked List — Full Implementation

```cpp
class LinkedList {
private:
    ListNode* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Insert at head — O(1)
    void pushFront(int val) {
        head = new ListNode(val, head);
        size++;
    }

    // Insert at tail — O(n)
    void pushBack(int val) {
        if (!head) { head = new ListNode(val); size++; return; }
        ListNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new ListNode(val);
        size++;
    }

    // Insert at index — O(n)
    void insertAt(int idx, int val) {
        if (idx < 0 || idx > size) return;
        if (idx == 0) { pushFront(val); return; }
        ListNode* cur = head;
        for (int i = 0; i < idx - 1; i++) cur = cur->next;
        cur->next = new ListNode(val, cur->next);
        size++;
    }

    // Delete head — O(1)
    void popFront() {
        if (!head) return;
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }

    // Delete by value (first occurrence) — O(n)
    void remove(int val) {
        if (!head) return;
        if (head->val == val) { popFront(); return; }
        ListNode* cur = head;
        while (cur->next && cur->next->val != val) cur = cur->next;
        if (cur->next) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            size--;
        }
    }

    // Search — O(n)
    bool contains(int val) {
        for (ListNode* cur = head; cur; cur = cur->next)
            if (cur->val == val) return true;
        return false;
    }

    // Print — O(n)
    void print() {
        for (ListNode* cur = head; cur; cur = cur->next)
            cout << cur->val << " -> ";
        cout << "NULL\n";
    }

    // Destructor — prevent memory leaks
    ~LinkedList() {
        while (head) popFront();
    }
};
```

---

## 6. Doubly Linked List — Key Operations

```cpp
// Insert after a given node (O(1))
void insertAfter(DListNode* node, int val) {
    DListNode* fresh = new DListNode(val);
    fresh->next = node->next;
    fresh->prev = node;
    if (node->next) node->next->prev = fresh;
    node->next = fresh;
}

// Delete a given node (O(1))
void deleteNode(DListNode* node) {
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    delete node;
}
```

> The key advantage: deleting a node when you have a pointer to it is **O(1)** — no need to find the previous node.

---

## 7. Circular Linked List

```cpp
// Detect: tail->next == head (instead of nullptr)
// Insert at end (O(1) with tail pointer):
void pushBackCircular(ListNode*& tail, int val) {
    ListNode* fresh = new ListNode(val);
    if (!tail) { tail = fresh; tail->next = tail; return; }
    fresh->next = tail->next;
    tail->next = fresh;
    tail = fresh;
}
```

---

## 8. Essential Algorithms & Patterns

These patterns appear in **80% of linked list interview problems**. Master each.

### 8.1 The Dummy (Sentinel) Node

Avoids special-casing the head. Used in problems like merge, partition, remove duplicates.

```cpp
ListNode dummy(0);
dummy.next = head;
ListNode* prev = &dummy;
// ... operate using prev->next ...
return dummy.next;
```

### 8.2 Two Pointers — Fast & Slow (Floyd's Tortoise & Hare)

**Find middle:**
```cpp
ListNode* slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
return slow; // middle node (second middle if even length)
```

**Detect cycle:**
```cpp
ListNode* slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
}
return false;
```

**Find cycle start (Floyd's algorithm):**
```cpp
// After meeting, reset one pointer to head; move both at same speed.
ListNode* slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
        slow = head;
        while (slow != fast) { slow = slow->next; fast = fast->next; }
        return slow; // cycle start
    }
}
return nullptr;
```

### 8.3 Reverse a Linked List (Iterative — must memorize)

```cpp
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
```

### 8.4 Reverse a Linked List (Recursive)

```cpp
ListNode* reverse(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

### 8.5 Merge Two Sorted Lists

```cpp
ListNode* merge(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) { tail->next = a; a = a->next; }
        else                  { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}
```

### 8.6 Find N-th Node from End (Single Pass)

```cpp
ListNode* nthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    for (int i = 0; i < n; i++) {
        if (!fast) return nullptr;
        fast = fast->next;
    }
    ListNode* slow = head;
    while (fast) { fast = fast->next; slow = slow->next; }
    return slow;
}
```

### 8.7 Reverse in Groups of K

Combine reversal with traversal — common variant.

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cur = head;
    for (int i = 0; i < k; i++) {
        if (!cur) return head; // fewer than k left
        cur = cur->next;
    }
    ListNode* prev = reverseKGroup(cur, k);
    cur = head;
    for (int i = 0; i < k; i++) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
```

---

## 9. Classic Interview Problems

These come up repeatedly. Solve each from scratch at least twice.

| Problem | Technique | Difficulty |
|---|---|---|
| Reverse a linked list | Iterative / recursive | Easy |
| Detect cycle | Floyd's algorithm | Easy |
| Find cycle start | Floyd's + reset | Medium |
| Middle of linked list | Fast/slow pointer | Easy |
| Merge two sorted lists | Dummy + two pointers | Easy |
| Merge K sorted lists | Min-heap or divide & conquer | Hard |
| Remove N-th node from end | Two pointers (gap of n) | Medium |
| Palindrome linked list | Reverse second half | Easy |
| Intersection of two lists | Two pointers swap heads | Easy |
| Add two numbers (digits as list) | Carry-aware traversal | Medium |
| Reverse nodes in k-group | Recursive group-reverse | Hard |
| LRU Cache | Hashmap + DLL | Medium |
| Copy list with random pointer | Hashmap or interleaving | Medium |
| Flatten multilevel list | DFS + stack | Medium |
| Reorder list (L0→Ln→L1→Ln-1...) | Mid + reverse + merge | Medium |
| Partition list around value x | Two dummy lists | Medium |
| Sort linked list | Merge sort (O(n log n)) | Medium |

---

## 10. Learning Tips

### 10.1 Build Mental Visualizations
- **Draw on paper or whiteboard every time.** Linked list bugs are usually about which pointer is broken when.
- Use **arrows** for `next`, dots for `nullptr`, boxes for nodes.
- Trace each statement: redraw after `cur->next = X`.

### 10.2 Understand the "Three-Pointer Dance"
For reversal, merge, swap — you almost always need **`prev`, `cur`, `nxt`** (or analogues). Memorize the order:
1. Save `nxt = cur->next` (capture future first).
2. Modify `cur->next`.
3. Advance `prev = cur; cur = nxt`.

### 10.3 Master the Dummy Node Idiom
Every interviewer recognizes this. It removes 90% of edge-case branches.

### 10.4 Practice Operations Without Looking
Code the following from memory:
- Reverse iterative + recursive.
- Detect & find cycle start.
- Merge two sorted lists.
- Remove N-th from end in one pass.

If you can't, you're not yet ready for medium-hard interview problems.

### 10.5 Use Helper Functions
For complex problems (reorder list, palindrome check), break into:
- `findMiddle(head)`
- `reverse(head)`
- `merge(a, b)`

### 10.6 Always Test on These Cases
- `head == nullptr` (empty list)
- Single node
- Two nodes
- Even length
- Odd length
- Cycle present
- All identical values

### 10.7 Track Memory Manually
Practice `new` / `delete` correctly. In interview C++ you often don't free, but understanding ownership prevents bugs.

---

## 11. Interview Tips

### 11.1 Before Coding
- **Clarify input format.** Is the list head given? Is it sorted? Can it have cycles?
- **Ask about edge cases.** Can it be empty? Can values be negative?
- **State your approach in plain English** before writing — interviewers care about thought process.

### 11.2 During Coding
- **Always use a dummy node** when the head might change (deletion, merge, partition).
- **Name pointers semantically:** `prev`, `cur`, `nxt`, `slow`, `fast`, `tail` — not `p1`, `p2`, `p3`.
- **Check `null` before dereferencing.** Especially `fast->next->next` — verify both `fast` and `fast->next` are non-null.
- **Don't lose the head.** Save it before traversal if you'll return it.

### 11.3 Common Bugs to Avoid

| Bug | Fix |
|---|---|
| Dereferencing `nullptr` | Check before `cur->next` |
| Infinite loop (cycle accidentally created) | Set the disconnected node's `next = nullptr` |
| Forgetting to update `prev` after a swap | Trace through 2 iterations |
| Off-by-one in "n-th from end" | Move fast pointer `n` steps, not `n-1` |
| Returning `head` after head changed | Use dummy and return `dummy.next` |
| Memory leaks (not deleting removed nodes) | `delete tmp` after unlinking |

### 11.4 When Stuck
1. **Reverse the problem.** "What if I had a doubly linked list?" — sometimes points to needing a prev pointer or stack.
2. **Use a stack** when you need backward access in an SLL.
3. **Convert to array** if pure pointer manipulation is overkill (but mention the trade-off).
4. **Hashmap** for problems involving "seen nodes" (e.g., cycle detection without Floyd's, copy with random pointer).

### 11.5 Complexity Talking Points
- Time: usually O(n); reverse, find middle, merge are all O(n).
- Space: O(1) for in-place algorithms (reverse, cycle detection). O(n) when using a stack/hashmap.
- Mention space savings of Floyd's algorithm vs hashmap approach for cycle detection.

### 11.6 Signal Senior Thinking
- Bring up **memory ownership** (who frees the node?).
- Note that **doubly linked lists** trade O(n) memory for O(1) operations — relevant for **LRU caches**.
- Discuss **cache locality** disadvantage vs arrays — shows systems awareness.

### 11.7 Mental Templates to Walk In With

```cpp
// Template 1: Traverse
for (ListNode* cur = head; cur; cur = cur->next) { /* ... */ }

// Template 2: Dummy head
ListNode dummy(0);
dummy.next = head;
ListNode* prev = &dummy;
// ... mutate prev->next ...
return dummy.next;

// Template 3: Fast/slow
ListNode* slow = head, *fast = head;
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }

// Template 4: Reverse
ListNode* prev = nullptr;
while (cur) {
    ListNode* nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
}
```

---

## Quick Reference Card

| Pattern | When to Use |
|---|---|
| Dummy node | Head may change (insert/delete at head, merge, partition) |
| Fast & slow | Middle, cycle, n-th from end, palindrome |
| Three pointers | Reversal, in-place reordering |
| Hashmap of nodes | Random pointer copy, cycle detection (alt.) |
| Recursion | Reverse, k-group reverse, swap pairs |
| Stack | Need previous nodes in SLL |
| Two dummies | Partition, separating odd/even |

---

## Final Checklist Before Interview

- [ ] Can I reverse a list in <60 seconds, iteratively?
- [ ] Can I detect a cycle and find its start?
- [ ] Can I merge two sorted lists using a dummy node?
- [ ] Can I find the middle in one pass?
- [ ] Can I remove the n-th from end in one pass?
- [ ] Do I know when to use SLL vs DLL?
- [ ] Can I implement an LRU cache with hashmap + DLL?
- [ ] Do I check `nullptr` before every pointer dereference?
- [ ] Do I trace examples on paper before writing code?

---
*End of Notes — Linked lists are deceptively simple. Their difficulty lies in pointer discipline. Draw diagrams, trace pointers, use dummy nodes — and 90% of interview problems become routine.*
