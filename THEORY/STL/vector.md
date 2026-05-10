# Vectors in C++ STL — Complete Reference

> A `std::vector` is a **dynamic array**: a sequence container that stores elements in **contiguous memory** and grows automatically. It is the default container of choice for almost every array problem in interviews.

---

## 1. Header & Declaration

```cpp
#include <vector>
using namespace std;
```

### 1.1 Ways to Declare

```cpp
vector<int> v1;                     // empty vector
vector<int> v2(5);                  // size 5, default-initialized to 0
vector<int> v3(5, 7);               // size 5, all elements = 7
vector<int> v4 = {1, 2, 3, 4, 5};   // initializer list
vector<int> v5(v4);                 // copy constructor
vector<int> v6(v4.begin(), v4.end()); // range constructor
vector<int> v7(arr, arr + n);       // from C-style array
vector<vector<int>> grid(n, vector<int>(m, 0)); // 2D vector n x m, filled with 0
```

---

## 2. Internal Working (Critical for Interviews)

| Property | Detail |
|---|---|
| Memory layout | Contiguous (cache-friendly, supports pointer arithmetic) |
| Growth strategy | Doubling (typical: capacity × 2 when full; GCC uses ×2, MSVC uses ×1.5) |
| Amortized `push_back` | **O(1)** — reallocations are rare and amortize out |
| Worst-case `push_back` | O(n) — when reallocation + copy happens |
| Iterator invalidation | Any reallocation invalidates ALL iterators, pointers, references |
| `size()` vs `capacity()` | `size` = elements present; `capacity` = allocated slots |

```cpp
vector<int> v;
cout << v.capacity(); // grows: 0 → 1 → 2 → 4 → 8 → 16 ...
```

---

## 3. Element Access

| Method | Description | Complexity |
|---|---|---|
| `v[i]` | Access by index, no bounds check | O(1) |
| `v.at(i)` | Bounds-checked, throws `out_of_range` | O(1) |
| `v.front()` | First element | O(1) |
| `v.back()` | Last element | O(1) |
| `v.data()` | Raw pointer to underlying array | O(1) |

```cpp
v.front() = 10;     // modifiable
int* p = v.data();  // useful for C APIs
```

---

## 4. Capacity Methods

| Method | Description | Complexity |
|---|---|---|
| `v.size()` | Number of elements | O(1) |
| `v.empty()` | `true` if size == 0 | O(1) |
| `v.capacity()` | Allocated storage | O(1) |
| `v.reserve(n)` | Pre-allocate capacity ≥ n (avoids reallocations) | O(n) |
| `v.shrink_to_fit()` | Reduces capacity to size | O(n) |
| `v.max_size()` | Theoretical max possible | O(1) |

> **Interview tip:** When you know the final size in advance, call `v.reserve(n)` before pushing. This eliminates reallocation cost.

---

## 5. Modifiers

| Method | Description | Complexity |
|---|---|---|
| `v.push_back(x)` | Append at end | Amortized O(1) |
| `v.emplace_back(args...)` | Construct in place at end (faster, avoids copy) | Amortized O(1) |
| `v.pop_back()` | Remove last | O(1) |
| `v.insert(pos, x)` | Insert before iterator `pos` | O(n) |
| `v.insert(pos, n, x)` | Insert n copies of x | O(n) |
| `v.insert(pos, first, last)` | Insert range | O(n + range) |
| `v.emplace(pos, args...)` | Construct in place at pos | O(n) |
| `v.erase(pos)` | Remove element at pos | O(n) |
| `v.erase(first, last)` | Remove range | O(n) |
| `v.clear()` | Remove all (size → 0, capacity unchanged) | O(n) |
| `v.resize(n)` | Resize to n (default-fills or truncates) | O(\|n − size\|) |
| `v.resize(n, x)` | Resize, fill new with x | O(\|n − size\|) |
| `v.assign(n, x)` | Replace contents with n copies of x | O(n) |
| `v.assign(first, last)` | Replace with range | O(n) |
| `v.swap(other)` | Swap with another vector | O(1) |

```cpp
v.emplace_back(42);             // preferred over push_back for objects
v.erase(v.begin() + i);         // erase index i
v.erase(remove(v.begin(), v.end(), x), v.end()); // erase-remove idiom
```

---

## 6. Iterators

| Iterator | Direction |
|---|---|
| `v.begin()` / `v.end()` | Forward |
| `v.rbegin()` / `v.rend()` | Reverse |
| `v.cbegin()` / `v.cend()` | Const forward |
| `v.crbegin()` / `v.crend()` | Const reverse |

```cpp
for (auto it = v.begin(); it != v.end(); ++it) cout << *it;
for (auto it = v.rbegin(); it != v.rend(); ++it) cout << *it; // reverse
for (auto& x : v) x *= 2;       // range-based, modify in place
for (auto x : v) cout << x;     // read-only
```

### 6.1 Iterator Arithmetic
```cpp
auto it = v.begin() + 3;        // 4th element
int idx = it - v.begin();       // index from iterator
int dist = distance(v.begin(), it);
advance(it, 2);                 // moves it by 2
```

---

## 7. `<algorithm>` Functions Every Interviewer Expects You to Know

```cpp
#include <algorithm>
#include <numeric>
```

### 7.1 Sorting & Ordering

| Function | Use | Complexity |
|---|---|---|
| `sort(v.begin(), v.end())` | Ascending sort (introsort) | O(n log n) |
| `sort(v.begin(), v.end(), greater<int>())` | Descending | O(n log n) |
| `sort(v.begin(), v.end(), cmp)` | Custom comparator | O(n log n) |
| `stable_sort(...)` | Preserves equal-element order | O(n log n) |
| `partial_sort(b, mid, e)` | Sort first k smallest | O(n log k) |
| `nth_element(b, nth, e)` | Place k-th element correctly (quickselect) | O(n) avg |
| `is_sorted(b, e)` | Check if sorted | O(n) |
| `reverse(b, e)` | Reverse range | O(n) |
| `rotate(b, mid, e)` | Rotate so `mid` becomes first | O(n) |
| `next_permutation(b, e)` | Next lexicographic permutation | O(n) |
| `prev_permutation(b, e)` | Previous permutation | O(n) |

```cpp
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
nth_element(v.begin(), v.begin() + k, v.end()); // k-th smallest at index k
```

### 7.2 Searching

| Function | Use | Complexity |
|---|---|---|
| `find(b, e, x)` | Linear search | O(n) |
| `count(b, e, x)` | Count occurrences | O(n) |
| `binary_search(b, e, x)` | Returns bool, requires sorted | O(log n) |
| `lower_bound(b, e, x)` | First iterator ≥ x | O(log n) |
| `upper_bound(b, e, x)` | First iterator > x | O(log n) |
| `equal_range(b, e, x)` | Pair {lower, upper} | O(log n) |
| `min_element(b, e)` | Iterator to min | O(n) |
| `max_element(b, e)` | Iterator to max | O(n) |
| `minmax_element(b, e)` | Pair {min_it, max_it} | O(n) |

```cpp
auto it = lower_bound(v.begin(), v.end(), 5);
int idx = it - v.begin(); // index of first element >= 5
int cnt = upper_bound(v.begin(), v.end(), 5) - lower_bound(v.begin(), v.end(), 5);
```

### 7.3 Numeric (`<numeric>`)

| Function | Use | Complexity |
|---|---|---|
| `accumulate(b, e, init)` | Sum (or fold with custom op) | O(n) |
| `partial_sum(b, e, out)` | Prefix sums | O(n) |
| `adjacent_difference(b, e, out)` | Differences | O(n) |
| `iota(b, e, start)` | Fill with start, start+1, ... | O(n) |
| `inner_product(b1, e1, b2, init)` | Dot product | O(n) |
| `gcd(a, b)` / `lcm(a, b)` | C++17 | O(log min(a,b)) |

```cpp
long long sum = accumulate(v.begin(), v.end(), 0LL);  // use 0LL to avoid overflow
vector<int> prefix(n);
partial_sum(v.begin(), v.end(), prefix.begin());
iota(v.begin(), v.end(), 1); // {1, 2, 3, ..., n}
```

### 7.4 Modifying Sequence Operations

| Function | Use | Complexity |
|---|---|---|
| `fill(b, e, x)` | Fill with x | O(n) |
| `copy(b, e, out)` | Copy range | O(n) |
| `unique(b, e)` | Remove consecutive duplicates → new end | O(n) |
| `remove(b, e, x)` | Move x's to end → new end | O(n) |
| `remove_if(b, e, pred)` | Move matching to end | O(n) |
| `replace(b, e, old, new)` | Replace value | O(n) |
| `transform(b, e, out, f)` | Apply f, write to out | O(n) |
| `for_each(b, e, f)` | Apply f to each | O(n) |

> **Erase-Remove Idiom** (must-know):
```cpp
v.erase(remove(v.begin(), v.end(), 0), v.end());          // remove all 0s
v.erase(unique(v.begin(), v.end()), v.end());             // dedupe sorted vector
v.erase(remove_if(v.begin(), v.end(), [](int x){ return x % 2; }), v.end());
```

---

## 8. 2D Vectors (Matrices / Grids)

```cpp
int n = 4, m = 5;
vector<vector<int>> grid(n, vector<int>(m, 0));   // n × m, init 0
grid[i][j] = 7;
int rows = grid.size();
int cols = grid[0].size();

// Iterate
for (auto& row : grid)
    for (int& x : row)
        cout << x << ' ';
```

### Common 2D Idioms
```cpp
vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // memoization table
vector<vector<bool>> visited(n, vector<bool>(m, false));
```

---

## 9. Custom Comparators (Frequently Tested)

### 9.1 Lambda
```cpp
sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;  // tie-break: second descending
});
```

### 9.2 Comparator Function
```cpp
bool cmp(int a, int b) { return abs(a) < abs(b); }
sort(v.begin(), v.end(), cmp);
```

### 9.3 Functor (Class)
```cpp
struct Cmp {
    bool operator()(int a, int b) const { return a > b; }
};
sort(v.begin(), v.end(), Cmp());
```

> **Rule:** Comparator must define a **strict weak ordering**. `cmp(a, a)` MUST return `false`. Use `<` not `<=`.

---

## 10. Common Patterns for Array Problems

### 10.1 Two Pointers
```cpp
int l = 0, r = v.size() - 1;
while (l < r) {
    if (v[l] + v[r] == target) { /* ... */ }
    else if (v[l] + v[r] < target) l++;
    else r--;
}
```

### 10.2 Sliding Window
```cpp
int sum = 0, l = 0, best = 0;
for (int r = 0; r < v.size(); r++) {
    sum += v[r];
    while (sum > k) sum -= v[l++];
    best = max(best, r - l + 1);
}
```

### 10.3 Prefix Sum
```cpp
vector<long long> pre(n + 1, 0);
for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i];
// range sum [l..r]:  pre[r + 1] - pre[l]
```

### 10.4 Binary Search on Answer
```cpp
int lo = 1, hi = 1e9;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;     // avoid overflow
    if (check(mid)) hi = mid;
    else lo = mid + 1;
}
```

### 10.5 Sort + Greedy / Sweep
```cpp
sort(intervals.begin(), intervals.end()); // sorts by first element
```

---

## 11. Performance Pitfalls (FAANG-Level Awareness)

| Pitfall | Fix |
|---|---|
| Passing `vector` by value into functions | Pass by `const vector&` (avoid copy) |
| `push_back` in tight loop without `reserve` | `v.reserve(expected_size)` first |
| `v.insert(v.begin(), x)` repeatedly | Use `deque` or build reversed and reverse once |
| `v.erase(v.begin() + i)` in loop | Build a new filtered vector or use erase-remove idiom |
| Using `v[i]` after iterator invalidation | Re-acquire iterators after any mutation that may reallocate |
| `accumulate(v.begin(), v.end(), 0)` overflow | Use `0LL` for `long long` accumulation |
| `int mid = (lo + hi) / 2` overflow | Use `lo + (hi - lo) / 2` |
| Returning large vector by value | Modern C++ uses RVO/move — fine; do NOT return references to locals |

---

## 12. Pass-by-Reference vs Value

```cpp
void solve(const vector<int>& v);   // read-only, no copy   (preferred)
void modify(vector<int>& v);        // read-write, no copy
void byValue(vector<int> v);        // makes a copy — avoid for large data
```

---

## 13. Useful One-Liners (Cheat Sheet)

```cpp
// Sum
long long s = accumulate(v.begin(), v.end(), 0LL);

// Max / Min
int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());

// Index of max
int idx = max_element(v.begin(), v.end()) - v.begin();

// Sort descending
sort(v.rbegin(), v.rend());

// Reverse
reverse(v.begin(), v.end());

// Unique (after sort)
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// Count occurrences of x
int c = count(v.begin(), v.end(), x);

// Check if all / any / none
bool allPos = all_of(v.begin(), v.end(), [](int x){ return x > 0; });
bool anyNeg = any_of(v.begin(), v.end(), [](int x){ return x < 0; });
bool noneZero = none_of(v.begin(), v.end(), [](int x){ return x == 0; });

// Fill / Reset
fill(v.begin(), v.end(), 0);

// 1..n sequence
vector<int> v(n);
iota(v.begin(), v.end(), 1);

// Convert to set (dedupe + sort)
set<int> s(v.begin(), v.end());

// String → vector<char>
string str = "hello";
vector<char> v(str.begin(), str.end());
```

---

## 14. Comparison with Other Containers

| Operation | `vector` | `deque` | `list` | `array` |
|---|---|---|---|---|
| Random access | O(1) | O(1) | O(n) | O(1) |
| Insert/erase at end | O(1) amort. | O(1) | O(1) | — |
| Insert/erase at front | O(n) | O(1) | O(1) | — |
| Insert/erase at middle | O(n) | O(n) | O(1) | — |
| Memory | Contiguous | Chunked | Nodes | Contiguous, fixed |
| Cache friendliness | Best | Good | Poor | Best |

> **Default to `vector`.** Only switch when the problem specifically demands front insertions (`deque`) or stable iterators with O(1) middle insertion (`list`).

---

## 15. Quick Complexity Summary

| Operation | Complexity |
|---|---|
| Random access `v[i]` | O(1) |
| `push_back` / `pop_back` | Amortized O(1) |
| `front`/`back`/`size`/`empty` | O(1) |
| `insert`/`erase` (middle) | O(n) |
| `clear` | O(n) |
| `find` (linear) | O(n) |
| `binary_search` / `lower_bound` | O(log n) |
| `sort` | O(n log n) |
| `nth_element` | O(n) average |
| `reverse` | O(n) |
| `accumulate` | O(n) |

---

## 16. Interview-Ready Checklist

- [ ] Know `push_back` is **amortized** O(1), not strictly O(1).
- [ ] Use `reserve()` when final size is known.
- [ ] Master the **erase-remove idiom**.
- [ ] Use `lower_bound` / `upper_bound` for sorted-vector lookups.
- [ ] Always pass large vectors by `const&`.
- [ ] Know that `vector<bool>` is a special bit-packed type — prefer `vector<char>` or `deque<bool>` if you need real bool semantics.
- [ ] Beware iterator invalidation after mutation.
- [ ] Use `0LL` in `accumulate` to prevent overflow.
- [ ] Use `lo + (hi - lo) / 2` for binary search midpoint.
- [ ] Know `sort` is **introsort** (hybrid of quicksort + heapsort + insertion sort), guaranteeing O(n log n) worst case.

---
*End of Notes — `vector` is the workhorse of competitive C++. Master it, and 70%+ of array problems become mechanical.*
