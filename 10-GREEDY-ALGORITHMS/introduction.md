# Complete Greedy Algorithms Guide for MAANG

## Table of Contents
1. [Fundamentals](#fundamentals)
2. [Greedy Strategy Design](#greedy-strategy-design)
3. [Core Patterns](#core-patterns)
4. [Problem Categories](#problem-categories)
5. [Classic Algorithms](#classic-algorithms)
6. [Practice Problems by Difficulty](#practice-problems-by-difficulty)
7. [Interview Tips](#interview-tips)

---

## Fundamentals

### What is Greedy Algorithm?
A greedy algorithm makes locally optimal choices at each step, hoping to find a global optimum. The key insight is that the locally optimal choice will lead to a globally optimal solution.

### Characteristics of Greedy Problems
1. **Greedy Choice Property**: A global optimum can be reached by making locally optimal choices
2. **Optimal Substructure**: An optimal solution contains optimal solutions to subproblems
3. **No Reconsideration**: Once a choice is made, it's never reconsidered

### When to Use Greedy?
- **Optimization problems** (maximize/minimize)
- **Scheduling problems**
- **Resource allocation**
- **Graph problems** (MST, shortest path)
- **Array/string problems** with specific patterns

### Greedy vs Other Approaches
```
Greedy: Make best local choice → Hope for global optimum
DP: Consider all possibilities → Guaranteed global optimum
Backtracking: Try all paths → Find all/optimal solutions
```

---

## Greedy Strategy Design

### Step-by-Step Approach
1. **Understand the problem**: What needs to be optimized?
2. **Identify greedy choice**: What local decision makes sense?
3. **Prove correctness**: Will local choices lead to global optimum?
4. **Implement**: Code the greedy strategy
5. **Analyze complexity**: Time and space analysis

### Common Greedy Strategies
```python
# 1. Sort first, then make greedy choices
def greedy_with_sorting(items):
    items.sort(key=lambda x: x.some_property)
    result = []
    for item in items:
        if is_valid_choice(item, result):
            result.append(item)
    return result

# 2. Use heap for dynamic best choice
import heapq
def greedy_with_heap(items):
    heap = []
    for item in items:
        heapq.heappush(heap, item)
    
    result = []
    while heap:
        best = heapq.heappop(heap)
        result.append(best)
    return result

# 3. Two-pointer technique
def greedy_two_pointers(arr):
    left, right = 0, len(arr) - 1
    result = []
    
    while left <= right:
        if condition(arr[left], arr[right]):
            result.append(arr[left])
            left += 1
        else:
            result.append(arr[right])
            right -= 1
    return result
```

---

## Core Patterns

### Pattern 1: Interval Scheduling
**Problem**: Select maximum number of non-overlapping intervals
**Strategy**: Sort by end time, greedily select earliest ending interval

```python
def interval_scheduling(intervals):
    # Sort by end time
    intervals.sort(key=lambda x: x[1])
    
    result = []
    last_end = float('-inf')
    
    for start, end in intervals:
        if start >= last_end:
            result.append([start, end])
            last_end = end
    
    return result

# Example: [[1,3], [2,4], [3,5], [4,6]]
# Output: [[1,3], [3,5]] or [[1,3], [4,6]]
```

### Pattern 2: Activity Selection with Weights
**Problem**: Maximize total value while selecting non-overlapping activities
**Strategy**: Sort by value/duration ratio or use weighted job scheduling

```python
def weighted_job_scheduling(jobs):
    # jobs = [(start, end, profit)]
    jobs.sort(key=lambda x: x[1])  # Sort by end time
    
    n = len(jobs)
    dp = [0] * n
    dp[0] = jobs[0][2]
    
    for i in range(1, n):
        # Include current job
        include_profit = jobs[i][2]
        latest_non_conflict = find_latest_non_conflict(jobs, i)
        if latest_non_conflict != -1:
            include_profit += dp[latest_non_conflict]
        
        # Exclude current job
        exclude_profit = dp[i-1]
        
        dp[i] = max(include_profit, exclude_profit)
    
    return dp[n-1]
```

### Pattern 3: Fractional Knapsack
**Problem**: Maximize value with weight constraint, items can be broken
**Strategy**: Sort by value/weight ratio, take highest ratio items first

```python
def fractional_knapsack(items, capacity):
    # items = [(value, weight)]
    # Sort by value/weight ratio
    items.sort(key=lambda x: x[0]/x[1], reverse=True)
    
    total_value = 0
    remaining_capacity = capacity
    
    for value, weight in items:
        if weight <= remaining_capacity:
            # Take entire item
            total_value += value
            remaining_capacity -= weight
        else:
            # Take fraction of item
            fraction = remaining_capacity / weight
            total_value += value * fraction
            break
    
    return total_value
```

### Pattern 4: Minimum Operations
**Problem**: Find minimum operations to achieve target
**Strategy**: Always make the operation that reduces problem size most

```python
def min_operations_to_zero(n):
    """Minimum operations to reduce n to 0: divide by 2 (if even) or subtract 1"""
    operations = 0
    while n > 0:
        if n % 2 == 0:
            n //= 2
        else:
            n -= 1
        operations += 1
    return operations

def min_operations_to_target(start, target):
    """Transform start to target using double or increment"""
    operations = 0
    while start < target:
        if target % 2 == 0:
            target //= 2
        else:
            target += 1
        operations += 1
    return operations + start - target
```

---

## Problem Categories

### Category 1: Array/String Greedy
**Common Problems:**
- Jump Game I & II
- Gas Station
- Candy Distribution
- Remove K Digits

**Example - Jump Game II:**
```python
def jump_game_ii(nums):
    """Minimum jumps to reach last index"""
    n = len(nums)
    if n <= 1:
        return 0
    
    jumps = 0
    current_end = 0
    farthest = 0
    
    for i in range(n - 1):
        farthest = max(farthest, i + nums[i])
        
        if i == current_end:
            jumps += 1
            current_end = farthest
            
            if current_end >= n - 1:
                break
    
    return jumps
```

**Example - Gas Station:**
```python
def can_complete_circuit(gas, cost):
    """Find starting gas station to complete circuit"""
    total_gas = sum(gas)
    total_cost = sum(cost)
    
    if total_gas < total_cost:
        return -1
    
    start = 0
    current_gas = 0
    
    for i in range(len(gas)):
        current_gas += gas[i] - cost[i]
        
        if current_gas < 0:
            start = i + 1
            current_gas = 0
    
    return start
```

### Category 2: Interval Problems
**Common Problems:**
- Meeting Rooms I & II
- Merge Intervals
- Insert Interval
- Non-overlapping Intervals

**Example - Meeting Rooms II:**
```python
def min_meeting_rooms(intervals):
    """Minimum meeting rooms needed"""
    if not intervals:
        return 0
    
    # Separate start and end times
    starts = sorted([i[0] for i in intervals])
    ends = sorted([i[1] for i in intervals])
    
    rooms = 0
    end_idx = 0
    
    for start in starts:
        if start >= ends[end_idx]:
            end_idx += 1
        else:
            rooms += 1
    
    return rooms
```

**Example - Non-overlapping Intervals:**
```python
def erase_overlap_intervals(intervals):
    """Minimum intervals to remove to make non-overlapping"""
    if not intervals:
        return 0
    
    # Sort by end time
    intervals.sort(key=lambda x: x[1])
    
    count = 0
    last_end = intervals[0][1]
    
    for i in range(1, len(intervals)):
        if intervals[i][0] < last_end:
            count += 1  # Remove current interval
        else:
            last_end = intervals[i][1]
    
    return count
```

### Category 3: Heap-based Greedy
**Common Problems:**
- Task Scheduler
- Reorganize String
- K Closest Points
- Top K Frequent Elements

**Example - Task Scheduler:**
```python
import heapq
from collections import Counter

def least_interval(tasks, n):
    """Minimum time to complete all tasks with cooling period"""
    if n == 0:
        return len(tasks)
    
    # Count frequencies
    counter = Counter(tasks)
    max_heap = [-count for count in counter.values()]
    heapq.heapify(max_heap)
    
    time = 0
    
    while max_heap:
        temp = []
        
        # Process up to n+1 tasks (including cooling)
        for _ in range(n + 1):
            if max_heap:
                temp.append(heapq.heappop(max_heap))
        
        # Add back tasks that still need to be done
        for count in temp:
            if count < -1:
                heapq.heappush(max_heap, count + 1)
        
        # Add time: either n+1 or remaining tasks
        time += (n + 1) if max_heap else len(temp)
    
    return time
```

### Category 4: Graph Greedy
**Common Problems:**
- Minimum Spanning Tree (Kruskal's, Prim's)
- Dijkstra's Algorithm
- Huffman Coding
- Fractional Knapsack

**Example - Kruskal's MST:**
```python
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        if self.rank[px] < self.rank[py]:
            px, py = py, px
        self.parent[py] = px
        if self.rank[px] == self.rank[py]:
            self.rank[px] += 1
        return True

def kruskal_mst(edges, n):
    """Find MST using Kruskal's algorithm"""
    edges.sort(key=lambda x: x[2])  # Sort by weight
    uf = UnionFind(n)
    mst = []
    total_weight = 0
    
    for u, v, weight in edges:
        if uf.union(u, v):
            mst.append((u, v, weight))
            total_weight += weight
            if len(mst) == n - 1:
                break
    
    return mst, total_weight
```

---

## Classic Algorithms

### 1. Dijkstra's Algorithm
```python
import heapq

def dijkstra(graph, start):
    """Single-source shortest path"""
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    pq = [(0, start)]
    
    while pq:
        current_dist, current = heapq.heappop(pq)
        
        if current_dist > distances[current]:
            continue
        
        for neighbor, weight in graph[current]:
            distance = current_dist + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return distances
```

### 2. Huffman Coding
```python
import heapq
from collections import Counter

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None
    
    def __lt__(self, other):
        return self.freq < other.freq

def huffman_coding(text):
    """Build Huffman tree and generate codes"""
    if not text:
        return {}
    
    # Count frequencies
    freq = Counter(text)
    
    # Build heap
    heap = [Node(char, freq) for char, freq in freq.items()]
    heapq.heapify(heap)
    
    # Build tree
    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        
        merged = Node(None, node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        
        heapq.heappush(heap, merged)
    
    # Generate codes
    root = heap[0]
    codes = {}
    
    def generate_codes(node, code):
        if node.char is not None:
            codes[node.char] = code
        else:
            generate_codes(node.left, code + '0')
            generate_codes(node.right, code + '1')
    
    generate_codes(root, '')
    return codes
```

### 3. Activity Selection
```python
def activity_selection(activities):
    """Classic activity selection problem"""
    # activities = [(start, end, id)]
    activities.sort(key=lambda x: x[1])  # Sort by end time
    
    selected = [activities[0]]
    last_end = activities[0][1]
    
    for i in range(1, len(activities)):
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]
    
    return selected
```

---

## Practice Problems by Difficulty

### Easy (Build Foundation)
1. **Assign Cookies** - Greedy assignment
2. **Lemonade Change** - Greedy change making
3. **Split Array into Consecutive Subsequences** - Greedy grouping
4. **Minimum Moves to Equal Array Elements** - Simple greedy choice
5. **Best Time to Buy and Sell Stock** - One-pass greedy
6. **Maximum Subarray** - Kadane's algorithm
7. **Two City Scheduling** - Cost optimization

### Medium (Core Skills)
1. **Jump Game II** - Minimum jumps with greedy
2. **Gas Station** - Circular array greedy
3. **Candy** - Two-pass greedy
4. **Task Scheduler** - Heap-based greedy
5. **Non-overlapping Intervals** - Interval greedy
6. **Partition Labels** - String partitioning
7. **Queue Reconstruction by Height** - Sorting + greedy insertion
8. **Minimum Number of Arrows** - Interval intersection
9. **Remove K Digits** - Stack-based greedy
10. **Reorganize String** - Heap-based arrangement

### Hard (MAANG Interview Level)
1. **Merge Intervals** - Advanced interval handling
2. **Insert Interval** - Interval insertion with merge
3. **Meeting Rooms II** - Resource allocation
4. **Minimum Window Substring** - Sliding window greedy
5. **Largest Rectangle in Histogram** - Stack + greedy
6. **Trapping Rain Water** - Two-pointer greedy
7. **Jump Game III** - BFS + greedy
8. **Minimum Cost to Connect Sticks** - Huffman-like problem
9. **Course Schedule III** - Complex scheduling
10. **Minimum Number of Taps** - Interval covering

---

## Interview Tips

### Identifying Greedy Problems
**Look for these keywords:**
- "Minimum/Maximum"
- "Optimal"
- "Least/Most"
- "Scheduling"
- "Allocation"
- "Non-overlapping"

### Common Greedy Strategies
1. **Sort first**: 80% of greedy problems need sorting
2. **Use heap**: For dynamic best choice
3. **Two pointers**: For array/string problems
4. **Stack**: For maintaining order while making greedy choices

### Proving Correctness
**Exchange Argument:**
1. Assume optimal solution differs from greedy
2. Show you can exchange elements to match greedy
3. Prove exchange doesn't worsen the solution

**Stay-Ahead Argument:**
1. Show greedy solution is always ahead of optimal
2. Prove this leads to better final result

### Time Complexity Patterns
- **Sorting-based**: O(n log n)
- **Heap-based**: O(n log n)
- **Two-pointer**: O(n)
- **Stack-based**: O(n)

### Common Mistakes
1. **Not proving correctness**: Always verify greedy choice is optimal
2. **Wrong sorting criteria**: Choose the right property to sort by
3. **Ignoring edge cases**: Empty arrays, single elements
4. **Overcomplicating**: Greedy should be simple and intuitive

### Interview Strategy
1. **Identify if problem is greedy**: Look for optimization + local choice
2. **Find the greedy choice**: What local decision makes sense?
3. **Sort if needed**: Most greedy problems need sorting
4. **Implement step by step**: Keep it simple
5. **Test with examples**: Verify correctness
6. **Analyze complexity**: Usually O(n log n) or O(n)

### Key Questions to Ask
- "What property should I optimize for?"
- "What's the greedy choice at each step?"
- "Do I need to sort the input?"
- "Can I prove this greedy choice is optimal?"

### Practice Schedule
- **Week 1**: Easy problems + understanding patterns
- **Week 2**: Medium problems + classic algorithms
- **Week 3**: Hard problems + complex scenarios
- **Week 4**: Mixed practice + interview simulation

Remember: Greedy algorithms are about making the locally optimal choice at each step. The key is identifying what that choice should be and proving it leads to a global optimum!