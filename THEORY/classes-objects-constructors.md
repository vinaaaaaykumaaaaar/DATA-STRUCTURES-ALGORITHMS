# Classes, Objects & Constructors in C++

A focused guide — just enough OOP to design and implement your own data
structures (stacks, linked lists, trees) and handle FAANG interviews. No deep
inheritance or template theory.

---

## The one-sentence idea

A **class is a blueprint** that bundles *data* and the *functions that operate on
it* into a single type. An **object** is one concrete thing built from that
blueprint.

```
   class Stack          ──blueprint──▶   object s1   (its own data)
   (defined once)                         object s2   (its own data)
```

You write the class once; you can make as many objects as you want, each with
its own independent copy of the data.

---

## Class vs. object

| Term       | What it is                          | Analogy                  |
|------------|-------------------------------------|--------------------------|
| **Class**  | The definition / template           | The architect's blueprint |
| **Object** | A variable of that class type       | An actual built house     |

```cpp
class Stack { ... };   // the blueprint (no memory used yet)

Stack s1;              // an object — real memory, its own data
Stack s2;              // a second, fully independent object
```

---

## Anatomy of a class

A class has two kinds of members:

- **Data members** — the variables (the *state*).
- **Member functions** (methods) — the functions that act on that state (the
  *behavior*).

```cpp
class Counter {
public:
    int count;             // data member  (state)

    void increment() {     // member function (behavior)
        count++;
    }
    int get() {
        return count;
    }
};
```

```cpp
Counter c;          // make an object
c.count = 0;        // access a data member with .
c.increment();      // call a member function with .
cout << c.get();    // prints 1
```

> Use `.` to reach a member of an **object**.
> Use `->` when you have a **pointer** to an object (`Counter* p; p->get();`).
> Same relationship you saw with pointers.

---

## `public` vs. `private` — encapsulation

Access specifiers control who can touch each member. This is the heart of good
data-structure design: hide the internals, expose a clean interface.

| Specifier   | Who can access it                          |
|-------------|--------------------------------------------|
| `public`    | Anyone — the outside world                 |
| `private`   | Only the class's own member functions      |

```cpp
class Stack {
private:
    int data[100];     // hidden — users can't poke at the array directly
    int topIndex;

public:
    void push(int x);  // the clean interface users are allowed to call
    int  pop();
    bool empty();
};
```

> **Why hide?** If `data` and `topIndex` are private, no outside code can put the
> stack into an invalid state. Users *must* go through `push`/`pop`, which keep
> everything consistent. This is **encapsulation** — a favorite interview talking
> point.

---

## `struct` vs. `class`

They are **almost identical** in C++. The only real difference:

| | `struct` | `class` |
|---|---|---|
| Default access | `public`  | `private` |

```cpp
struct Node {        // members public by default
    int val;
    Node* next;
};

class Stack {        // members private by default
    int data[100];   // ← private automatically
};
```

> **Convention:** use `struct` for simple data bags with no hidden state (like a
> linked-list `Node`), and `class` for things with real behavior and invariants
> to protect (like the `Stack` itself). The `ListNode` you've seen is a `struct`
> for exactly this reason.

---

## Constructors

A **constructor** is a special function that runs **automatically when an object
is created**. Its job: put the object into a valid initial state. It has the
**same name as the class** and **no return type**.

```cpp
class Stack {
private:
    int data[100];
    int topIndex;

public:
    Stack() {           // constructor — same name as class, no return type
        topIndex = -1;  // start empty
    }
};

Stack s;   // constructor runs HERE, automatically → topIndex is -1
```

Without a constructor, `topIndex` would hold garbage and your stack would be
broken from the start. **Constructors guarantee a clean starting point.**

### The three constructors you'll actually use

**1. Default constructor** — takes no arguments.
```cpp
Stack() {
    topIndex = -1;
}
```

**2. Parameterized constructor** — takes arguments to initialize with data.
```cpp
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {     // build a node holding value x
        val = x;
        next = nullptr;
    }
};

ListNode* n = new ListNode(5);   // creates a node with val=5, next=null
```

**3. You can have both** — C++ picks the right one by the arguments
(overloading).
```cpp
struct ListNode {
    int val;
    ListNode* next;

    ListNode()      { val = 0; next = nullptr; }   // default
    ListNode(int x) { val = x; next = nullptr; }   // parameterized
};

ListNode a;        // calls ListNode()      → val = 0
ListNode b(7);     // calls ListNode(7)     → val = 7
```

---

## Member initializer list (the `:` syntax)

You'll see constructors written with a colon before the body. This is the
**member initializer list** — the preferred, idiomatic way to set up members.

```cpp
ListNode(int x) : val(x), next(nullptr) {}
//              ▲─────────────────────▲ ▲▲
//              initializer list       empty body
```

It's equivalent to assigning inside the body, but cleaner and slightly faster
(it *initializes* members directly instead of default-constructing then
assigning):

```cpp
// these two do the same thing:
ListNode(int x) : val(x), next(nullptr) {}     // ✅ idiomatic
ListNode(int x) { val = x; next = nullptr; }   // works, but less preferred
```

> This is the form used in virtually every interview solution and on LeetCode.
> Learn to read and write it fluently:
> `Stack() : topIndex(-1) {}`

---

## Destructors

A **destructor** runs **automatically when an object is destroyed** (goes out of
scope, or is `delete`d). Its job: clean up — most importantly, free any heap
memory the object allocated with `new`.

Name it the class name with a `~` prefix. No arguments, no return type.

```cpp
class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {                  // destructor — frees every node
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};
```

```
constructor  ──▶  object is alive, you use it  ──▶  destructor
 (set up)              (push, pop, traverse)        (free memory)
```

> **Rule of thumb:** if your class uses `new` anywhere, it almost certainly needs
> a destructor with the matching `delete`, or it leaks memory. Mentioning this in
> an interview signals you understand ownership.

---

## The `this` pointer

Inside any member function, `this` is a pointer to **the object the function was
called on**. You mostly need it when a parameter name clashes with a member
name.

```cpp
class Counter {
    int count;
public:
    Counter(int count) {
        this->count = count;   // this->count = the member; count = the parameter
    }
};
```

> You won't reach for `this` constantly, but it shows up in self-referential
> structures and disambiguation. Just know `this->member` means "this object's
> member."

---

## Putting it together: a complete Stack

Everything above, in one real data structure. Read it top to bottom — it's the
template you'll reuse.

```cpp
class Stack {
private:
    int data[1000];      // hidden internal storage
    int topIndex;        // index of the top element

public:
    // Constructor — start empty
    Stack() : topIndex(-1) {}

    // Add to the top — O(1)
    void push(int x) {
        data[++topIndex] = x;
    }

    // Remove from the top — O(1)
    int pop() {
        return data[topIndex--];
    }

    // Look at the top without removing — O(1)
    int top() {
        return data[topIndex];
    }

    // Is the stack empty?
    bool empty() {
        return topIndex == -1;
    }

    // How many elements?
    int size() {
        return topIndex + 1;
    }
};
```

```cpp
Stack s;
s.push(10);
s.push(20);
cout << s.top();    // 20
s.pop();
cout << s.top();    // 10
cout << s.empty();  // 0 (false)
```

> This is exactly how you'd implement a stack, queue, linked list, or any
> structure from scratch: **private data, public methods, a constructor to
> initialize, a destructor if you use `new`.**

---

## Quick reference card

```cpp
class Name {
private:
    int x;                          // data member (hidden)

public:
    Name() : x(0) {}                // default constructor (init list)
    Name(int v) : x(v) {}           // parameterized constructor
    ~Name() { /* free heap here */ } // destructor

    int  get()      { return x; }   // member function
    void set(int v) { x = v; }
};

Name a;             // object → default constructor runs
Name b(5);          // object → parameterized constructor runs
a.set(10);          // call a method with .
Name* p = &a;
p->get();           // call a method through a pointer with ->
```

| Concept              | Syntax                          | Purpose                       |
|----------------------|---------------------------------|-------------------------------|
| Class                | `class Foo { ... };`            | Blueprint                     |
| Object               | `Foo f;`                        | An instance                   |
| Data member          | `int x;`                        | State                         |
| Member function      | `int get() { ... }`             | Behavior                      |
| Constructor          | `Foo() : x(0) {}`               | Auto-init on creation         |
| Destructor           | `~Foo() { ... }`                | Auto-cleanup on destruction   |
| `private` / `public` | access specifier                | Encapsulation                 |
| `this`               | `this->x`                       | Pointer to current object     |

---

## What to actually master

You're ready to implement any data structure once you can, without thinking:

- [ ] Define a class with private data and public methods.
- [ ] Write a default and a parameterized constructor.
- [ ] Use the member initializer list: `Foo() : x(0) {}`.
- [ ] Write a destructor that `delete`s everything the class `new`ed.
- [ ] Explain `public` vs. `private` and why encapsulation matters.
- [ ] Know when to use `struct` (data bag) vs. `class` (behavior + invariants).
- [ ] Access members with `.` on objects and `->` through pointers.
- [ ] Implement a `Stack` (or `Queue`) class from a blank file.

Skip for now (not needed to build core data structures): inheritance &
polymorphism, copy/move constructors, operator overloading, templates,
`virtual` functions. Reach for them only when a specific problem or a generic
(`template<typename T>`) container demands it.

---

*Classes are just a clean way to keep data and the code that guards it in one
place. Every data structure you build — stack, queue, linked list, tree, heap,
hash map — is the same recipe: private state, a constructor to set it up, public
methods to use it safely, and a destructor to clean up.*
