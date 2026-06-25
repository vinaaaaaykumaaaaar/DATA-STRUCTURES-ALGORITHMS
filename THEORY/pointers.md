# Pointers in C++

A focused guide — just enough to be fluent with pointers for DSA problems
(linked lists, trees, graphs) and FAANG interviews. No rabbit holes.

---

## What is a pointer?

A **pointer is a variable that stores a memory address** — instead of holding a
value directly, it holds the *location* of a value.

Every variable lives somewhere in memory, and that location has an address. A
pointer just remembers that address so you can reach the value later.

```cpp
int x = 42;     // a normal variable holding the value 42
int* p = &x;    // a pointer holding the ADDRESS of x
```

```
        x                         p
   ┌──────────┐              ┌──────────┐
   │    42    │              │  0x7ffe  │ ──┐
   └──────────┘              └──────────┘   │
   address: 0x7ffe                          │
        ▲                                    │
        └────────────────────────────────────┘
              p "points to" x
```

That's the entire idea. Everything else is syntax around it.

---

## The two core operators

These two symbols are 90% of pointer syntax. Learn them cold.

| Symbol | Name        | Meaning                                  |
|--------|-------------|------------------------------------------|
| `&`    | address-of  | "give me the address of this variable"   |
| `*`    | dereference | "give me the value at this address"      |

```cpp
int x = 42;
int* p = &x;     // & : p now holds the address of x

cout << p;       // prints an address, e.g. 0x7ffe
cout << *p;      // prints 42      → * follows the pointer to the value
*p = 100;        // writes THROUGH the pointer → x is now 100
cout << x;       // prints 100
```

> **Mental model:** `&` packs a value's location into a pointer.
> `*` unpacks the pointer back into the value.

---

## Declaring a pointer

```cpp
int*    p;     // pointer to an int
double* q;     // pointer to a double
char*   c;     // pointer to a char
ListNode* n;   // pointer to a struct/class (used everywhere in DSA)
```

The type before the `*` is the type of the thing being pointed *at*. A pointer
to `int` and a pointer to `double` are different types — they can't mix.

> **Style note:** `int* p` and `int *p` are identical to the compiler.
> Pick one and stay consistent. This guide uses `int* p`.

---

## The null pointer

A pointer that points to **nothing** should be set to `nullptr`. This is the
single most important safety habit in pointer code.

```cpp
int* p = nullptr;    // points to nothing — explicit and safe

if (p != nullptr) {  // always check before using
    cout << *p;
}
if (p) { ... }       // shorthand — non-null is "truthy"
```

> Use `nullptr`, **never** `NULL` or `0`, in modern C++.

**Dereferencing a null (or dangling) pointer is the #1 cause of crashes.**
Linked-list and tree problems live or die on this check:

```cpp
while (node != nullptr) {   // stop before falling off the end
    cout << node->val;
    node = node->next;
}
```

---

## `->` : the arrow operator

When a pointer points to a `struct` or `class`, you reach its members with `->`
instead of `.`. This is *the* operator you'll use in every linked-list and tree
problem.

```cpp
struct ListNode {
    int val;
    ListNode* next;
};

ListNode* node = ...;

(*node).val;     // works, but ugly: dereference, then access member
node->val;       // identical, and idiomatic  →  ALWAYS use this
node->next;      // the pointer to the next node
```

> `node->val` is just shorthand for `(*node).val`. Same thing, cleaner.

---

## Pointers vs. references

Both let you refer to another variable, but they behave differently. Interviews
love asking the distinction.

| Aspect            | Pointer (`int* p`)            | Reference (`int& r`)        |
|-------------------|-------------------------------|-----------------------------|
| Can be null?      | Yes (`nullptr`)               | No — must bind on creation  |
| Can be reseated?  | Yes — point it elsewhere      | No — bound for life         |
| Needs `*` to read | Yes (`*p`)                    | No — used like the variable |
| Syntax to access  | `p->member`                   | `r.member`                  |
| Main DSA use      | Nodes, dynamic memory         | Clean function parameters   |

```cpp
int x = 10;

int* p = &x;    // pointer:   p can be reassigned, can be null
*p = 20;        // change x through the pointer

int& r = x;     // reference: r IS x, forever
r = 30;         // change x directly — no * needed
```

**Rule of thumb:** use a **reference** when you just need to share/modify a
variable. Use a **pointer** when it can be null or needs to move between objects
(i.e. almost all node-based data structures).

---

## Why pointers matter for DSA

Pointers are what make dynamic, node-based structures possible. A linked list is
*nothing but* nodes connected by pointers:

```
head
 │
 ▼
┌─────┬───┐   ┌─────┬───┐   ┌─────┬───┐
│  1  │ ●─┼──▶│  2  │ ●─┼──▶│  3  │ ●─┼──▶ nullptr
└─────┴───┘   └─────┴───┘   └─────┴───┘
 val  next     val  next     val  next
```

Each `next` is a pointer to the following node. The last one points to
`nullptr`, which is how you know the list ends.

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```

Traversing the list = "keep following the pointers until you hit null":

```cpp
ListNode* cur = head;
while (cur != nullptr) {
    cout << cur->val << " ";
    cur = cur->next;        // move the pointer forward
}
```

Trees and graphs are the same idea with more pointers per node
(`left`/`right`, or a list of neighbors).

---

## Heap allocation: `new` and `delete`

To build a list at runtime, you create nodes on the **heap** with `new`. It
returns a pointer to the freshly allocated object.

```cpp
ListNode* node = new ListNode(5);   // allocate on heap, get a pointer back
node->val;                          // 5
node->next = new ListNode(10);      // chain another node

delete node->next;                  // free that node's memory
delete node;                        // free this one too
node = nullptr;                     // avoid a dangling pointer
```

| Action          | What it does                                        |
|-----------------|-----------------------------------------------------|
| `new T(args)`   | Allocates a `T` on the heap, returns a `T*`         |
| `delete p`      | Frees the single object `p` points to               |
| `delete[] p`    | Frees an array allocated with `new T[n]`             |

> **Interview reality:** in a 40-minute interview you usually *don't* free memory
> — focus on correctness. But you should *know* that every `new` logically pairs
> with a `delete`, and be ready to mention it. It signals you understand
> ownership.

---

## Stack vs. heap (the 30-second version)

| | **Stack** | **Heap** |
|---|---|---|
| Created by   | normal local variables    | `new`                       |
| Lifetime     | freed automatically at `}` | lives until you `delete`    |
| Speed        | very fast                  | slower                      |
| Use in DSA   | loop counters, the pointer *variables* themselves | the *nodes* they point to |

```cpp
void f() {
    int x = 5;                    // x lives on the stack, gone after f()
    ListNode* p = new ListNode(5); // p is on the stack...
                                   // ...but *p (the node) is on the heap
}   // ← x and the pointer p vanish here; the heap node LEAKS if not deleted
```

This is *why* linked-list nodes use `new`: they must outlive the function that
created them.

---

## The classic traps (memorize these)

These are the bugs that cost you the interview. Recognize each on sight.

**1. Dereferencing null**
```cpp
ListNode* p = nullptr;
p->val;            // 💥 crash — there's no node to read
```
Always guard: `if (p) p->val;`

**2. Reading uninitialized pointers (wild pointers)**
```cpp
int* p;            // points at garbage — undefined behavior
*p = 5;            // 💥 may crash, may corrupt memory silently
```
Fix: initialize to `nullptr` (or a real address) at declaration.

**3. Dangling pointer (using memory after delete)**
```cpp
delete p;
p->val;            // 💥 p still holds the old address, but it's freed
```
Fix: set `p = nullptr;` right after `delete`.

**4. Losing the only pointer to a node (memory leak)**
```cpp
ListNode* a = new ListNode(1);
a = new ListNode(2);   // the first node is now unreachable — leaked forever
```
Fix: keep a pointer to anything you allocated until you `delete` it.

**5. Falling off the end during traversal**
```cpp
while (cur->next->next) { ... }   // 💥 if cur->next is null, this crashes
```
Fix: check each link before stepping: `while (cur && cur->next)`.

---

## Pointer-to-pointer (`**`) — know it exists

Occasionally you'll see `ListNode**`. It's a pointer to a pointer — used when a
function needs to change *which node a pointer points to*, not just the node's
contents.

```cpp
void advance(ListNode** pp) {
    *pp = (*pp)->next;   // modifies the caller's actual pointer
}
```

> You rarely *need* this in interviews — a reference (`ListNode*&`) is cleaner
> and does the same job. Just don't panic if you see `**` in someone's solution.

---

## Quick reference card

```cpp
int x = 42;
int* p = &x;          // & : take address      → p points to x
int  v = *p;          // * : read through       → v == 42
*p = 7;               // * : write through      → x == 7
p = nullptr;          // empty pointer          → points to nothing
if (p) { ... }        // null check before use

ListNode* n = new ListNode(5);   // heap-allocate a node
n->val;                          // -> : member access through pointer
n->next = nullptr;               // end-of-list marker
delete n;  n = nullptr;          // free, then clear

ListNode* cur = head;            // standard traversal
while (cur) { cur = cur->next; } // follow pointers to the end
```

| Operator | Read it as                          |
|----------|-------------------------------------|
| `&x`     | "address of x"                      |
| `*p`     | "the value p points to"             |
| `p->m`   | "the member m of what p points to"  |
| `nullptr`| "points to nothing"                 |

---

## What to actually master

For DSA and interviews, you're ready once you can do all of these without
thinking:

- [ ] Read `&`, `*`, and `->` instantly and explain each.
- [ ] Declare a node `struct` with a `next` pointer.
- [ ] Traverse a linked list with a `while (cur)` loop.
- [ ] Always null-check before dereferencing.
- [ ] Explain pointer vs. reference in one sentence.
- [ ] Know that `new` allocates on the heap and returns a pointer.
- [ ] Spot the five classic traps above in someone else's code.

Everything beyond this (function pointers, smart pointers, pointer arithmetic on
arrays, `const` placement rules) is *nice to know* but **not required** to crush
linked-list, tree, and graph problems. Come back to those only if a specific
problem demands it.

---

*Pointers feel scary for about a week, then become invisible. Draw the boxes and
arrows every single time you're stuck — pointer bugs are almost always "which
arrow is pointing where right now."*
