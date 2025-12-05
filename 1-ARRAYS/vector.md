## VECTORS

Think about vectors in c++ as a contiguous , dynamically growing array with strong guarantees about memory layout and performance.

### What is a vector fundamentally ?

At the system layer , a std::vector<T> is 

- A pointer to a contiguous block of memory (T* data)
- A size (size_t size)
- A capacity (size_t capacity) - how much memory is reserved before needing to reallocate
- An allocator (usually default unless overridden)

A mental model 

```txt
vector = {buffer_start , size , capacity }
```

This design gives two critical properties:

- A. Fash random access 
- B. Amortized constant-time append

### What is the Growth Strategy ?

When a vector goes beyond capacity , it 
- Allocates a new buffer (usually 2X capacity)
- Moves or copies all existing elements
- Frees the old buffer 
- Adds the new element

This means: 
- Occasional O(n) cost
- But amortized cost remains same O(1)
