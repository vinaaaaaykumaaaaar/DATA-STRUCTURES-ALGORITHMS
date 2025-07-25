# Binary Search Patterns & Questions for FAANG Interviews

## Core Patterns to Master

### 1. **Standard Binary Search**
- Finding exact element in sorted array
- Template: `left = 0, right = n-1, while (left <= right)`

### 2. **Lower Bound (First Occurrence)**
- Find first position where condition is true
- Template: `left = 0, right = n, while (left < right)`

### 3. **Upper Bound (Last Occurrence)**
- Find last position where condition is true
- Template: `left = 0, right = n, while (left < right)`

### 4. **Search Space Reduction**
- Binary search on answer/value space
- Template: `left = min_answer, right = max_answer`

### 5. **Peak Finding**
- Finding local maximum/minimum
- Template: Compare with neighbors

### 6. **Rotated Array Search**
- Search in rotated sorted arrays
- Template: Identify which half is sorted

---

## BASIC (Must Know - Foundation)

### 1. **Binary Search (LC 704)**
- Standard binary search implementation
- **Pattern**: Standard Binary Search

### 2. **Search Insert Position (LC 35)**
- Find position to insert target
- **Pattern**: Lower Bound

### 3. **First Bad Version (LC 278)**
- Find first bad version using API
- **Pattern**: Lower Bound

### 4. **Sqrt(x) (LC 69)**
- Integer square root
- **Pattern**: Search Space Reduction

---

## EASY

### 1. **Find First and Last Position (LC 34)**
- Find start and end indices of target
- **Pattern**: Lower Bound + Upper Bound

### 2. **Valid Perfect Square (LC 367)**
- Check if number is perfect square
- **Pattern**: Search Space Reduction

### 3. **Intersection of Two Arrays (LC 349)**
- Find common elements using binary search
- **Pattern**: Standard Binary Search

### 4. **Peak Index in Mountain Array (LC 852)**
- Find peak in mountain array
- **Pattern**: Peak Finding

### 5. **Search in Rotated Sorted Array II (LC 81)**
- Search with duplicates allowed
- **Pattern**: Rotated Array Search

---

## MEDIUM

### 1. **Search in Rotated Sorted Array (LC 33)**
- Classic rotated array search
- **Pattern**: Rotated Array Search

### 2. **Find Minimum in Rotated Sorted Array (LC 153)**
- Find minimum element in rotated array
- **Pattern**: Rotated Array Search

### 3. **Search a 2D Matrix (LC 74)**
- Search in row and column sorted matrix
- **Pattern**: Standard Binary Search (treat as 1D)

### 4. **Search a 2D Matrix II (LC 240)**
- Search in sorted matrix (different constraints)
- **Pattern**: Modified Binary Search

### 5. **Koko Eating Bananas (LC 875)**
- Find minimum eating speed
- **Pattern**: Search Space Reduction

### 6. **Capacity to Ship Packages (LC 1011)**
- Find minimum ship capacity
- **Pattern**: Search Space Reduction

### 7. **Find Peak Element (LC 162)**
- Find any peak element
- **Pattern**: Peak Finding

### 8. **Single Element in Sorted Array (LC 540)**
- Find single non-duplicate element
- **Pattern**: Modified Binary Search on indices

### 9. **Time Based Key-Value Store (LC 981)**
- Binary search on timestamps
- **Pattern**: Lower Bound/Upper Bound

### 10. **Online Election (LC 911)**
- Find leader at given time
- **Pattern**: Upper Bound

### 11. **Random Pick with Weight (LC 528)**
- Weighted random selection using prefix sums
- **Pattern**: Upper Bound

### 12. **Magnetic Force Between Two Balls (LC 1552)**
- Maximize minimum distance
- **Pattern**: Search Space Reduction

### 13. **Split Array Largest Sum (LC 410)**
- Minimize largest sum after splitting
- **Pattern**: Search Space Reduction

### 14. **Find Right Interval (LC 436)**
- Find next interval for each interval
- **Pattern**: Lower Bound

---

## HARD

### 1. **Median of Two Sorted Arrays (LC 4)**
- Find median in O(log(min(m,n))) time
- **Pattern**: Search Space Reduction on smaller array

### 2. **Find Minimum in Rotated Sorted Array II (LC 154)**
- With duplicates, worst case O(n)
- **Pattern**: Rotated Array Search with duplicates

### 3. **Count of Range Sum (LC 327)**
- Count subarrays with sum in range
- **Pattern**: Binary search with merge sort/segment tree

### 4. **Russian Doll Envelopes (LC 354)**
- 2D version of Longest Increasing Subsequence
- **Pattern**: Binary search for LIS

### 5. **Max Sum of Rectangle No Larger Than K (LC 363)**
- 2D Kadane with binary search
- **Pattern**: Search Space Reduction with TreeSet

### 6. **Find K-th Smallest Pair Distance (LC 719)**
- Kth smallest among all pair distances
- **Pattern**: Search Space Reduction

### 7. **Swim in Rising Water (LC 778)**
- Find minimum time to reach destination
- **Pattern**: Search Space Reduction

### 8. **Kth Smallest Element in Sorted Matrix (LC 378)**
- Find kth smallest in row/column sorted matrix
- **Pattern**: Search Space Reduction

### 9. **Aggressive Cows (GFG)**
- Place cows to maximize minimum distance
- **Pattern**: Search Space Reduction

### 10. **Allocate Minimum Pages (GFG)**
- Minimize maximum pages allocated
- **Pattern**: Search Space Reduction

---

## Key Implementation Templates

### Standard Binary Search
```
left = 0, right = n-1
while (left <= right):
    mid = left + (right - left) // 2
    if arr[mid] == target: return mid
    elif arr[mid] < target: left = mid + 1
    else: right = mid - 1
```

### Lower Bound (First True)
```
left = 0, right = n
while (left < right):
    mid = left + (right - left) // 2
    if (condition(mid)): right = mid
    else: left = mid + 1
```

### Upper Bound (Last True)
```
left = 0, right = n
while (left < right):
    mid = left + (right - left + 1) // 2
    if (condition(mid)): left = mid
    else: right = mid - 1
```

### Search Space Reduction
```
left = min_possible, right = max_possible
while (left < right):
    mid = left + (right - left) // 2
    if (canAchieve(mid)): right = mid
    else: left = mid + 1
```

## Practice Strategy

1. **Master Basic Pattern**: Start with standard binary search
2. **Bound Patterns**: Practice lower/upper bound extensively
3. **Rotated Arrays**: Learn to identify sorted halves
4. **Search Space**: Practice "binary search on answer" problems
5. **Edge Cases**: Handle duplicates, empty arrays, single elements
6. **Time Complexity**: Always aim for O(log n) solutions

## Common Pitfalls to Avoid

- Integer overflow in mid calculation: Use `left + (right - left) // 2`
- Infinite loops: Choose correct mid formula for upper bound
- Off-by-one errors: Be careful with `<=` vs `<` and boundary updates
- Not handling edge cases: Empty arrays, single elements, all same elements