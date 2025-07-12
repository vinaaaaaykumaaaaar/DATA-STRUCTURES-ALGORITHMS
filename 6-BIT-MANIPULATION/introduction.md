# Complete Bit Manipulation Guide for MAANG

## Table of Contents
1. [Fundamentals](#fundamentals)
2. [Basic Operations](#basic-operations)
3. [Essential Bit Tricks](#essential-bit-tricks)
4. [Common Patterns](#common-patterns)
5. [Problem Categories](#problem-categories)
6. [Practice Problems by Difficulty](#practice-problems-by-difficulty)
7. [Interview Tips](#interview-tips)

---

## Fundamentals

### Binary Number System
- **Decimal to Binary**: Divide by 2, collect remainders
- **Binary to Decimal**: Sum of (bit × 2^position)
- **Example**: 13 = 1101₂ = 1×2³ + 1×2² + 0×2¹ + 1×2⁰

### Bitwise Operators
```
& (AND)    : 1 & 1 = 1, others = 0
| (OR)     : 0 | 0 = 0, others = 1  
^ (XOR)    : same bits = 0, different = 1
~ (NOT)    : flips all bits
<< (Left)  : multiply by 2^n
>> (Right) : divide by 2^n
```

### Two's Complement (Negative Numbers)
- **Formula**: ~n + 1 = -n
- **Example**: -5 = ~5 + 1 = ~(101) + 1 = 010 + 1 = 011 (in 3-bit)

---

## Basic Operations

### Check if Bit is Set
```python
def is_bit_set(num, i):
    return (num & (1 << i)) != 0
```

### Set a Bit
```python
def set_bit(num, i):
    return num | (1 << i)
```

### Clear a Bit
```python
def clear_bit(num, i):
    return num & ~(1 << i)
```

### Toggle a Bit
```python
def toggle_bit(num, i):
    return num ^ (1 << i)
```

### Count Set Bits
```python
def count_set_bits(num):
    count = 0
    while num:
        count += num & 1
        num >>= 1
    return count

# Brian Kernighan's Algorithm - O(set bits)
def count_set_bits_optimized(num):
    count = 0
    while num:
        num &= num - 1  # Removes rightmost set bit
        count += 1
    return count
```

---

## Essential Bit Tricks

### Power of 2 Operations
```python
# Check if power of 2
def is_power_of_2(n):
    return n > 0 and (n & (n - 1)) == 0

# Next power of 2
def next_power_of_2(n):
    n -= 1
    n |= n >> 1
    n |= n >> 2
    n |= n >> 4
    n |= n >> 8
    n |= n >> 16
    return n + 1
```

### XOR Properties
```python
# XOR of number with itself is 0
a ^ a = 0

# XOR with 0 gives the number itself
a ^ 0 = a

# XOR is commutative and associative
a ^ b ^ c = a ^ c ^ b

# Find single number in array where all others appear twice
def single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    return result
```

### Bit Manipulation with Masks
```python
# Clear rightmost set bit
def clear_rightmost_set_bit(n):
    return n & (n - 1)

# Get rightmost set bit
def get_rightmost_set_bit(n):
    return n & (-n)

# Check if two numbers have opposite signs
def opposite_signs(a, b):
    return (a ^ b) < 0
```

---

## Common Patterns

### Pattern 1: Single Number Problems
**When all elements appear k times except one**
```python
def single_number_k_times(nums, k):
    # Use k counters for each bit position
    # Implementation depends on k value
    pass
```

### Pattern 2: Subset Generation
```python
def generate_subsets(nums):
    n = len(nums)
    subsets = []
    
    for mask in range(1 << n):  # 2^n subsets
        subset = []
        for i in range(n):
            if mask & (1 << i):
                subset.append(nums[i])
        subsets.append(subset)
    
    return subsets
```

### Pattern 3: Bit Manipulation in DP
```python
def traveling_salesman_dp(dist):
    n = len(dist)
    dp = {}
    
    def solve(mask, pos):
        if mask == (1 << n) - 1:
            return dist[pos][0]
        
        if (mask, pos) in dp:
            return dp[(mask, pos)]
        
        ans = float('inf')
        for city in range(n):
            if mask & (1 << city) == 0:
                new_ans = dist[pos][city] + solve(mask | (1 << city), city)
                ans = min(ans, new_ans)
        
        dp[(mask, pos)] = ans
        return ans
    
    return solve(1, 0)
```

---

## Problem Categories

### Category 1: Basic Bit Operations
**Problems:**
- Number of 1 Bits
- Power of Two
- Reverse Bits
- Hamming Distance

**Example - Hamming Distance:**
```python
def hamming_distance(x, y):
    xor = x ^ y
    distance = 0
    while xor:
        distance += xor & 1
        xor >>= 1
    return distance
```

### Category 2: XOR-based Problems
**Problems:**
- Single Number (I, II, III)
- Find the Duplicate Number
- Missing Number

**Example - Missing Number:**
```python
def missing_number(nums):
    n = len(nums)
    xor_all = 0
    xor_nums = 0
    
    for i in range(n + 1):
        xor_all ^= i
    
    for num in nums:
        xor_nums ^= num
    
    return xor_all ^ xor_nums
```

### Category 3: Bit Manipulation with Arrays
**Problems:**
- Subsets
- Maximum XOR of Two Numbers
- Bitwise AND of Numbers Range

**Example - Maximum XOR:**
```python
def find_maximum_xor(nums):
    max_xor = 0
    mask = 0
    
    for i in range(31, -1, -1):
        mask |= (1 << i)
        prefixes = {num & mask for num in nums}
        
        temp = max_xor | (1 << i)
        for prefix in prefixes:
            if temp ^ prefix in prefixes:
                max_xor = temp
                break
    
    return max_xor
```

### Category 4: Advanced Bit Manipulation
**Problems:**
- Counting Bits
- Sum of Two Integers
- Divide Two Integers

**Example - Add Without Plus:**
```python
def get_sum(a, b):
    # 32-bit integer limit
    MASK = 0xFFFFFFFF
    MAX_INT = 0x7FFFFFFF
    
    while b:
        carry = (a & b) << 1
        a = (a ^ b) & MASK
        b = carry & MASK
    
    return a if a <= MAX_INT else ~(a ^ MASK)
```

---

## Practice Problems by Difficulty

### Easy (Master these first)
1. **Number of 1 Bits** - Count set bits
2. **Power of Two** - Check if number is power of 2
3. **Reverse Bits** - Reverse bits of 32-bit integer
4. **Hamming Distance** - Count different bits between two numbers
5. **Missing Number** - Find missing number using XOR
6. **Single Number** - Find unique number in array
7. **Complement of Base 10 Integer** - Flip bits within significant bits

### Medium (Build your skills)
1. **Single Number II** - Unique number when others appear 3 times
2. **Single Number III** - Two unique numbers when others appear twice
3. **Subsets** - Generate all subsets using bit manipulation
4. **Counting Bits** - Count set bits for range 0 to n
5. **Maximum XOR of Two Numbers** - Find maximum XOR in array
6. **Bitwise AND of Numbers Range** - AND of all numbers in range
7. **Find the Duplicate Number** - Find duplicate using bit manipulation
8. **Sum of Two Integers** - Add without using + operator

### Hard (MAANG interview level)
1. **Divide Two Integers** - Division using bit manipulation
2. **Maximum XOR With an Element From Array** - Advanced XOR problems
3. **Minimum XOR Sum of Two Arrays** - Optimize XOR sum
4. **Find XOR of All Subsets** - Advanced subset XOR problems
5. **Count Number of Maximum Bitwise-OR Subsets** - Complex counting
6. **Shortest Path Visiting All Nodes** - TSP with bitmask DP
7. **Partition to K Equal Sum Subsets** - Bitmask DP optimization

---

## Interview Tips

### Time Complexity Analysis
- **Bit operations**: O(1) for basic operations
- **Counting bits**: O(log n) naive, O(number of set bits) optimized
- **Generating subsets**: O(2^n × n)
- **Bitmask DP**: O(2^n × n) typically

### Space Optimization
- Use bit manipulation to reduce space from O(n) to O(1)
- Bitmask can represent states compactly
- XOR properties help eliminate extra space

### Common Interview Patterns
1. **"Find the unique element"** → Think XOR
2. **"Generate all subsets"** → Think bitmask iteration
3. **"Optimize DP with small constraints"** → Think bitmask DP
4. **"Count/check bits"** → Think Brian Kernighan's algorithm
5. **"Without using operators"** → Think bit manipulation

### Debug Tips
- Always trace through examples with small numbers
- Convert to binary to visualize operations
- Use print statements to see intermediate bit patterns
- Test edge cases: 0, 1, negative numbers, maximum values

### Practice Strategy
1. **Week 1-2**: Master basic operations and easy problems
2. **Week 3-4**: Solve medium problems, understand XOR patterns
3. **Week 5-6**: Tackle hard problems, learn bitmask DP
4. **Week 7-8**: Mixed practice, time yourself, mock interviews

### Key Formulas to Remember
- `n & (n-1)` → removes rightmost set bit
- `n & (-n)` → isolates rightmost set bit
- `n | (n-1)` → sets all bits to the right of rightmost set bit
- `~n & (n+1)` → isolates rightmost unset bit
- `(n >> i) & 1` → gets i-th bit
- `n | (1 << i)` → sets i-th bit
- `n & ~(1 << i)` → clears i-th bit

Start with the easy problems and gradually work your way up. Focus on understanding the patterns rather than memorizing solutions. Practice explaining your approach clearly, as this is crucial for MAANG interviews!