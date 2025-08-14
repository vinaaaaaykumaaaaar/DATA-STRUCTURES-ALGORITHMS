# Essential C++ STL Algorithms for FAANG Interviews

## 1. Sorting Algorithms

### `sort()`
```cpp
#include <algorithm>
#include <vector>

vector<int> arr = {5, 2, 8, 1, 9};
sort(arr.begin(), arr.end());              // Ascending: {1, 2, 5, 8, 9}
sort(arr.begin(), arr.end(), greater<int>()); // Descending: {9, 8, 5, 2, 1}

// Custom comparator
sort(arr.begin(), arr.end(), [](int a, int b) {
    return a > b; // Descending order
});
```

### `stable_sort()`
```cpp
// Maintains relative order of equal elements
stable_sort(arr.begin(), arr.end());
```

### `partial_sort()`
```cpp
// Sort only first k elements
partial_sort(arr.begin(), arr.begin() + 3, arr.end()); // Sort first 3 elements
```

### `nth_element()`
```cpp
// Find kth smallest element (0-indexed)
nth_element(arr.begin(), arr.begin() + k, arr.end());
// arr[k] will be the kth smallest element
```

## 2. Binary Search Algorithms

### `binary_search()`
```cpp
vector<int> sorted_arr = {1, 3, 5, 7, 9};
bool found = binary_search(sorted_arr.begin(), sorted_arr.end(), 5); // true
```

### `lower_bound()` and `upper_bound()`
```cpp
// lower_bound: first position where element can be inserted
auto it1 = lower_bound(sorted_arr.begin(), sorted_arr.end(), 5);

// upper_bound: last position where element can be inserted
auto it2 = upper_bound(sorted_arr.begin(), sorted_arr.end(), 5);

// Get index
int index1 = it1 - sorted_arr.begin();
int index2 = it2 - sorted_arr.begin();
```

### `equal_range()`
```cpp
// Returns pair of lower_bound and upper_bound
auto range = equal_range(sorted_arr.begin(), sorted_arr.end(), 5);
int count = range.second - range.first; // Count of element 5
```

## 3. Heap Operations

### `make_heap()`, `push_heap()`, `pop_heap()`
```cpp
vector<int> heap = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
make_heap(heap.begin(), heap.end()); // Max heap by default

// Add element
heap.push_back(15);
push_heap(heap.begin(), heap.end());

// Remove max element
pop_heap(heap.begin(), heap.end());
heap.pop_back();
```

### `sort_heap()`
```cpp
sort_heap(heap.begin(), heap.end()); // Converts heap to sorted array
```

## 4. Permutation Algorithms

### `next_permutation()` and `prev_permutation()`
```cpp
vector<int> arr = {1, 2, 3};
do {
    // Process current permutation
    for(int x : arr) cout << x << " ";
    cout << "\n";
} while(next_permutation(arr.begin(), arr.end()));

// For previous permutations
while(prev_permutation(arr.begin(), arr.end())) {
    // Process permutation
}
```

## 5. Search Algorithms

### `find()`, `find_if()`, `find_if_not()`
```cpp
vector<int> arr = {1, 2, 3, 4, 5};

// Find specific value
auto it = find(arr.begin(), arr.end(), 3);

// Find with condition
auto it2 = find_if(arr.begin(), arr.end(), [](int x) { return x > 3; });

// Find first element NOT satisfying condition
auto it3 = find_if_not(arr.begin(), arr.end(), [](int x) { return x < 3; });
```

### `search()` and `search_n()`
```cpp
vector<int> text = {1, 2, 3, 4, 5, 3, 4};
vector<int> pattern = {3, 4};

// Find subsequence
auto it = search(text.begin(), text.end(), pattern.begin(), pattern.end());

// Find n consecutive occurrences of value
auto it2 = search_n(text.begin(), text.end(), 2, 3); // Find 2 consecutive 3s
```

## 6. Set Operations (on sorted ranges)

### `set_union()`, `set_intersection()`, `set_difference()`
```cpp
vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2 = {3, 4, 5, 6, 7};
vector<int> result;

// Union
set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));

// Intersection
result.clear();
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));

// Difference (v1 - v2)
result.clear();
set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));
```

## 7. Transformation Algorithms

### `transform()`
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
vector<int> result(arr.size());

// Square each element
transform(arr.begin(), arr.end(), result.begin(), [](int x) { return x * x; });

// Binary transform (add two arrays)
vector<int> arr2 = {1, 1, 1, 1, 1};
transform(arr.begin(), arr.end(), arr2.begin(), result.begin(), plus<int>());
```

### `reverse()`
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
reverse(arr.begin(), arr.end()); // {5, 4, 3, 2, 1}
```

### `rotate()`
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
rotate(arr.begin(), arr.begin() + 2, arr.end()); // {3, 4, 5, 1, 2}
```

## 8. Modifying Operations

### `remove()`, `remove_if()`, `unique()`
```cpp
vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5};

// Remove specific value (doesn't actually remove, returns new end)
auto new_end = remove(arr.begin(), arr.end(), 3);
arr.erase(new_end, arr.end());

// Remove with condition
new_end = remove_if(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });
arr.erase(new_end, arr.end());

// Remove consecutive duplicates (array must be sorted)
sort(arr.begin(), arr.end());
new_end = unique(arr.begin(), arr.end());
arr.erase(new_end, arr.end());
```

### `replace()`, `replace_if()`
```cpp
vector<int> arr = {1, 2, 3, 2, 5};

// Replace all occurrences of 2 with 9
replace(arr.begin(), arr.end(), 2, 9);

// Replace with condition
replace_if(arr.begin(), arr.end(), [](int x) { return x < 3; }, 0);
```

## 9. Numeric Operations (from `<numeric>`)

### `accumulate()`, `partial_sum()`, `adjacent_difference()`
```cpp
#include <numeric>

vector<int> arr = {1, 2, 3, 4, 5};

// Sum of all elements
int sum = accumulate(arr.begin(), arr.end(), 0);

// Product of all elements
int product = accumulate(arr.begin(), arr.end(), 1, multiplies<int>());

// Partial sums
vector<int> prefix_sums(arr.size());
partial_sum(arr.begin(), arr.end(), prefix_sums.begin());

// Adjacent differences
vector<int> diffs(arr.size());
adjacent_difference(arr.begin(), arr.end(), diffs.begin());
```

### `iota()`
```cpp
vector<int> arr(10);
iota(arr.begin(), arr.end(), 1); // Fill with 1, 2, 3, ..., 10
```

## 10. Min/Max Operations

### `min_element()`, `max_element()`, `minmax_element()`
```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9};

auto min_it = min_element(arr.begin(), arr.end());
auto max_it = max_element(arr.begin(), arr.end());

// Get both min and max in one pass
auto [min_it2, max_it2] = minmax_element(arr.begin(), arr.end());

int min_val = *min_it;
int max_val = *max_it;
```

## 11. Partitioning

### `partition()`, `stable_partition()`, `is_partitioned()`
```cpp
vector<int> arr = {1, 2, 3, 4, 5, 6};

// Partition even numbers to the left
auto pivot = partition(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });

// Check if already partitioned
bool partitioned = is_partitioned(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });

// Find partition point
auto partition_point_it = partition_point(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });
```

## 12. Useful Predicates

### `all_of()`, `any_of()`, `none_of()`
```cpp
vector<int> arr = {2, 4, 6, 8};

bool all_even = all_of(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });
bool any_odd = any_of(arr.begin(), arr.end(), [](int x) { return x % 2 == 1; });
bool none_negative = none_of(arr.begin(), arr.end(), [](int x) { return x < 0; });
```

## Interview Tips & Common Patterns

### 1. Two Pointers with STL
```cpp
// Find pair with sum k
vector<int> arr = {1, 2, 3, 4, 5, 6};
sort(arr.begin(), arr.end());
auto left = arr.begin(), right = arr.end() - 1;
while(left < right) {
    int sum = *left + *right;
    if(sum == target) return true;
    else if(sum < target) left++;
    else right--;
}
```

### 2. Sliding Window Maximum
```cpp
// Use with deque for O(n) solution
deque<int> dq; // stores indices
for(int i = 0; i < arr.size(); i++) {
    // Remove indices outside window
    while(!dq.empty() && dq.front() <= i - k) dq.pop_front();
    
    // Remove smaller elements
    while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
    
    dq.push_back(i);
    if(i >= k - 1) result.push_back(arr[dq.front()]);
}
```

### 3. Custom Comparators for Complex Objects
```cpp
struct Point {
    int x, y;
};

// Sort by distance from origin
sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
    return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
});
```

### 4. Quick Selection for Kth Element
```cpp
// Find kth largest element
nth_element(arr.begin(), arr.begin() + k - 1, arr.end(), greater<int>());
int kth_largest = arr[k - 1];
```

## Time Complexities Summary

- `sort()`: O(n log n)
- `binary_search()`, `lower_bound()`, `upper_bound()`: O(log n)
- `nth_element()`: O(n) average
- `next_permutation()`: O(n)
- `reverse()`: O(n)
- `unique()`: O(n)
- `partition()`: O(n)
- `min_element()`, `max_element()`: O(n)

## Pro Tips for Interviews

1. **Always consider STL first** - Don't reinvent the wheel
2. **Know time complexities** - Critical for optimization discussions
3. **Practice with custom comparators** - Very common in interviews
4. **Understand iterator invalidation** - Important for correctness
5. **Combine algorithms** - Many problems require chaining multiple algorithms
6. **Use range-based algorithms** - More readable and less error-prone