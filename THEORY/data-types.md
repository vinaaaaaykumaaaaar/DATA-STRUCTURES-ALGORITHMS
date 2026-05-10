# Data Types & Variables in C++

> Foundational reference for FAANG-level interview preparation. Every DSA problem starts here — picking the wrong type costs correctness (overflow) or performance (cache misses).

---

## Table of Contents

1. [Introduction to Variables](#1-introduction-to-variables)
2. [Fundamental Data Types](#2-fundamental-data-types)
3. [Derived Data Types](#3-derived-data-types)
4. [Type Modifiers](#4-type-modifiers)
5. [Type Conversion and Casting](#5-type-conversion-and-casting)
6. [Constants and Literals](#6-constants-and-literals)
7. [Best Practices for DSA](#7-best-practices-for-dsa)

---

## 1. Introduction to Variables

A **variable** is a named storage location in memory that holds a value. In C++, every variable must be declared with a specific data type before use.

**Syntax:**
```cpp
data_type variable_name = initial_value;
```

### Key Properties

| Property | Description |
|---|---|
| Name (identifier) | Symbolic name for the storage location |
| Type | Determines memory layout and operations allowed |
| Value | The actual data stored |
| Address | Physical location in memory (`&var`) |

### Naming Rules
- Must start with a **letter or underscore**, followed by letters, digits, or underscores.
- C++ is **case-sensitive** — `count` and `Count` are different variables.
- Cannot use reserved keywords (`int`, `for`, `class`, etc.).
- Identifiers starting with `_` followed by a capital letter, or containing `__`, are reserved for the implementation.

### Declaration vs Definition vs Initialization

```cpp
extern int x;     // declaration  — tells compiler x exists somewhere
int x;            // definition   — allocates memory (default value: indeterminate for locals)
int x = 42;       // copy-initialization
int x(42);        // direct-initialization
int x{42};        // uniform/brace-initialization (C++11, prevents narrowing)
```

> **Interview tip:** Brace initialization (`int x{42}`) is the **safest** — it prohibits implicit narrowing conversions like `int x{3.14};` which would silently truncate.

---

## 2. Fundamental Data Types

Fundamental (primitive) data types are the building blocks of all data in C++. The sizes below are typical for most **64-bit systems**, though the C++ standard only guarantees *minimum* sizes.

### 2.1 Integer Types

Used to store whole numbers (no decimal point).

| Type | Typical Size | Range (signed) | Format Specifier |
|---|---|---|---|
| `short` | 2 bytes | −32,768 to 32,767 | `%hd` |
| `int` | 4 bytes | −2.1 × 10⁹ to 2.1 × 10⁹ | `%d` |
| `long` | 4 or 8 bytes | platform-dependent | `%ld` |
| `long long` | 8 bytes | −9.2 × 10¹⁸ to 9.2 × 10¹⁸ | `%lld` |

```cpp
int x = 42;                    // Most common integer type
short s = 100;
long l = 100000L;              // L suffix
long long ll = 9999999999LL;   // LL suffix — essential for large values
```

> **Critical FAANG pitfall:** If the problem says values can be up to 10⁹ and you sum n of them where n = 10⁵, the sum can reach 10¹⁴ — **use `long long`**. Forgetting this causes silent overflow.

### 2.2 Floating-Point Types

Used to store real numbers (with decimal points).

| Type | Size | Precision | Range |
|---|---|---|---|
| `float` | 4 bytes | ~6–7 significant digits | ±3.4 × 10³⁸ |
| `double` | 8 bytes | ~15–16 significant digits | ±1.7 × 10³⁰⁸ |
| `long double` | 8 / 12 / 16 bytes | ≥ double | platform-dependent |

```cpp
float f = 3.14f;          // f suffix mandatory
double d = 3.14159265;    // default for floating literals
long double ld = 3.14L;
```

> **Never compare floats with `==`.** Use an epsilon:
> ```cpp
> if (abs(a - b) < 1e-9) { /* equal */ }
> ```

### 2.3 Character Type

Used to store a single character, encoded as an integer (ASCII value).

```cpp
char c = 'A';        // stores ASCII 65
char digit = '7';    // stores ASCII 55, NOT the integer 7
int n = digit - '0'; // converts char '7' to int 7  (very common in interviews)
```

| Variant | Use |
|---|---|
| `char` | 1 byte — ASCII / system encoding |
| `signed char` | 1 byte — guaranteed signed |
| `unsigned char` | 1 byte — 0 to 255 |
| `wchar_t` | 2 or 4 bytes — wide chars |
| `char16_t` / `char32_t` | UTF-16 / UTF-32 (C++11) |

### 2.4 Boolean Type

Used to store a truth value. Size is 1 byte (not 1 bit).

```cpp
bool isValid = true;
bool isEmpty = false;
bool flag = (x > 0);        // implicit conversion from comparison
```

Any non-zero integer converts to `true`; zero converts to `false`.

### 2.5 The `void` Type

A special type representing the **absence of a value**. It cannot be used for regular variables but appears in two important contexts:
- Functions that return nothing — `void doSomething();`
- Generic pointers — `void* ptr;`

---

## 3. Derived Data Types

Derived types are built from fundamental types. They let you work with collections, indirection, and references.

### 3.1 Arrays

Fixed-size contiguous block of elements of the same type.

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int zeros[100] = {0};        // first 0, rest also 0
int len = sizeof(arr) / sizeof(arr[0]); // size (only for raw arrays in scope)
```

| Property | Detail |
|---|---|
| Memory | Contiguous |
| Size | Fixed at compile time |
| Access | O(1) random access via index |
| Bounds checking | **None** — out-of-bounds = undefined behavior |
| Decay | Array name decays to pointer when passed to functions |

> **Interview preference:** Use `std::vector` over raw arrays — same O(1) access plus dynamic size and bounds checking via `.at()`.

### 3.2 Pointers

A variable that stores the **memory address** of another variable.

```cpp
int x = 10;
int* p = &x;       // p holds address of x
cout << *p;        // dereference: prints 10
*p = 20;           // modifies x through p
```

| Operator | Meaning |
|---|---|
| `&x` | Address-of `x` |
| `*p` | Value at address `p` (dereference) |
| `p++` | Move to next element (pointer arithmetic) |
| `nullptr` | Null pointer constant (C++11, preferred over `NULL`) |

### 3.3 References

An **alias** for an existing variable. Must be initialized at declaration and cannot be reseated.

```cpp
int x = 10;
int& ref = x;      // ref IS x
ref = 20;          // x is now 20
```

| Pointers vs References |  |
|---|---|
| Can be `nullptr` | Reference must bind to something |
| Can be reassigned | Reference is fixed once bound |
| Needs `*` to dereference | Used like the original variable |
| Used for: dynamic memory, optional binding | Used for: clean function parameters, range-for |

### 3.4 Function Types

Functions themselves have types and can be stored / passed.

```cpp
int add(int a, int b) { return a + b; }
int (*fp)(int, int) = add;      // function pointer
auto f = [](int x){ return x*x; }; // lambda
```

### 3.5 User-Defined Derived Types

| Type | Use |
|---|---|
| `struct` | Group related data (public by default) |
| `class` | Same as struct, but private by default; enables OOP |
| `union` | All members share the same memory |
| `enum` / `enum class` | Named integral constants (`enum class` is type-safe, C++11) |

```cpp
struct Point { int x, y; };
enum class Color { Red, Green, Blue };
```

---

## 4. Type Modifiers

Modifiers alter the meaning, size, or sign of fundamental types.

### 4.1 Sign Modifiers

| Modifier | Effect |
|---|---|
| `signed` | Default for most integer types — allows negative values |
| `unsigned` | Only non-negative; doubles the positive range |

```cpp
unsigned int u = 4'000'000'000U; // fits — int would overflow
unsigned char b = 200;           // 0 to 255
```

> **FAANG trap:** Mixing `signed` and `unsigned` in comparisons causes implicit conversion to `unsigned`. The loop `for (int i = v.size() - 1; i >= 0; i--)` is fine, but `if (i < v.size())` with negative `i` is buggy because `v.size()` is `size_t` (unsigned).

### 4.2 Size Modifiers

`short` and `long` adjust storage size:
```cpp
short int   ss;     // ≥ 2 bytes
long int    ll;     // ≥ 4 bytes
long long   lll;    // ≥ 8 bytes
```

### 4.3 Type Qualifiers

| Qualifier | Meaning |
|---|---|
| `const` | Value cannot be modified after initialization |
| `constexpr` | Evaluated at compile time (C++11) |
| `volatile` | Tells compiler not to optimize reads/writes (hardware, multithreading) |
| `mutable` | Member can be modified even in a `const` object |
| `static` | Local: keeps value across calls. Global: file-scope only. Member: shared across instances |

```cpp
const int MAX = 100;
constexpr int N = 1 << 20;     // compile-time constant
static int counter = 0;        // retains value across function calls
```

### 4.4 Fixed-Width Integer Types (`<cstdint>`)

Use these when you need **guaranteed** size — critical for competitive programming.

| Type | Size | Range |
|---|---|---|
| `int8_t` / `uint8_t` | 1 byte | ±127 / 0–255 |
| `int16_t` / `uint16_t` | 2 bytes | ±32K / 0–65K |
| `int32_t` / `uint32_t` | 4 bytes | ±2.1B / 0–4.2B |
| `int64_t` / `uint64_t` | 8 bytes | ±9.2 × 10¹⁸ / 0–1.8 × 10¹⁹ |
| `size_t` | platform | Unsigned, used for sizes/indices |
| `ptrdiff_t` | platform | Signed difference of pointers |

```cpp
#include <cstdint>
int64_t bigSum = 0;     // explicit width — safer than 'long long'
```

---

## 5. Type Conversion and Casting

### 5.1 Implicit Conversion (Coercion)

The compiler converts automatically. Can be dangerous if it narrows.

```cpp
int i = 10;
double d = i;          // safe: int → double
int x = 3.7;           // truncates to 3 (no error, no warning by default)
```

**Promotion order (smallest → largest):**
`bool → char → short → int → unsigned int → long → long long → float → double → long double`

### 5.2 Explicit Conversion (Casting)

#### C-Style Cast (avoid in modern C++)
```cpp
int x = (int)3.7;
```

#### C++ Casts (preferred — safer, more intent-revealing)

| Cast | Use |
|---|---|
| `static_cast<T>(x)` | Compile-time, safe conversions between related types |
| `dynamic_cast<T>(x)` | Runtime, safe down-casting in polymorphic class hierarchies |
| `const_cast<T>(x)` | Add/remove `const` qualifier |
| `reinterpret_cast<T>(x)` | Bit-level reinterpretation — **dangerous** |

```cpp
double d = 3.14;
int i = static_cast<int>(d);         // explicit, clear intent

int a = 5, b = 2;
double avg = static_cast<double>(a) / b;  // 2.5, not 2
```

### 5.3 Common Conversion Idioms in DSA

```cpp
// char digit ↔ int
int n = '7' - '0';                   // 7
char c = 3 + '0';                    // '3'

// string ↔ int
int x = stoi("123");
long long y = stoll("9999999999");
string s = to_string(42);

// string ↔ double
double d = stod("3.14");

// lowercase ↔ uppercase
char up = toupper('a');              // 'A'
char lo = tolower('B');              // 'b'
```

---

## 6. Constants and Literals

### 6.1 Literals

A literal is a **value written directly** in code.

| Literal | Example | Type |
|---|---|---|
| Integer | `42`, `0xFF`, `0b1010`, `077` | `int` |
| Unsigned | `42U` | `unsigned int` |
| Long | `42L` / `42LL` | `long` / `long long` |
| Floating | `3.14`, `2.5e10` | `double` |
| Float | `3.14f` | `float` |
| Character | `'A'`, `'\n'`, `'\0'` | `char` |
| String | `"hello"` | `const char*` |
| Boolean | `true`, `false` | `bool` |
| Pointer | `nullptr` | `nullptr_t` |
| Digit separator (C++14) | `1'000'000` | for readability |

### 6.2 Constants

```cpp
const int MAX_N = 1e5 + 5;        // runtime constant
constexpr int LIMIT = 1 << 30;    // compile-time constant
#define PI 3.14159                // macro (avoid in modern C++)
```

> **Prefer `constexpr` > `const` > `#define`.** `constexpr` enables compile-time evaluation, has type safety, and respects scope — `#define` has none of these.

### 6.3 Escape Sequences in Characters / Strings

| Sequence | Meaning |
|---|---|
| `\n` | Newline |
| `\t` | Tab |
| `\\` | Backslash |
| `\'` `\"` | Single / double quote |
| `\0` | Null character (string terminator) |
| `\r` | Carriage return |

---

## 7. Best Practices for DSA

### 7.1 Choosing the Right Numeric Type

| Scenario | Type to use |
|---|---|
| Default integer | `int` |
| Sum / product that may exceed 2 × 10⁹ | `long long` |
| Array indexing | `int` (or `size_t` if comparing with `.size()`) |
| Need guaranteed 64-bit | `int64_t` |
| Need bit manipulation | `unsigned long long` |
| Real numbers in geometry | `double` (avoid `float`) |
| Boolean flags | `bool` |

### 7.2 Overflow Awareness

```cpp
int a = 1e9, b = 1e9;
long long c = a + b;            // BUG: a+b overflows BEFORE assignment
long long c = (long long)a + b; // FIX: cast one operand first
long long c = 1LL * a + b;      // common idiom
```

### 7.3 Constants for Algorithm Limits

```cpp
const int INF = 1e9;                       // safe "infinity" for int
const long long LLINF = 1e18;              // safe for long long
const int MOD = 1e9 + 7;                   // common modulus in problems
const double EPS = 1e-9;                   // float comparison tolerance
```

> **Never use `INT_MAX` directly in additions** — `INT_MAX + 1` overflows. Use a safe value like `1e9` so `INF + INF` still fits in `int`.

### 7.4 Initialize Everything

```cpp
int x;          // BAD — indeterminate value, undefined behavior to read
int x = 0;      // GOOD
int x{};        // GOOD — zero-initializes

vector<int> v(n, 0);                  // GOOD
vector<vector<int>> g(n, vector<int>(m, 0)); // 2D grid
```

### 7.5 Use `auto` Wisely

```cpp
auto it = v.begin();                   // GOOD — verbose type avoided
auto x = 42;                           // OK
auto val = m[key];                     // OK if m's value_type is clear
auto sum = 0;                          // CAREFUL — deduces int, not long long
```

### 7.6 Prefer References for Large Objects

```cpp
void process(const vector<int>& v);    // no copy
void modify(string& s);                // no copy, mutates caller's
void byValue(vector<int> v);           // copies — only if you need a copy
```

### 7.7 Common Type Pitfalls (Interview Checklist)

- [ ] `int * int` overflow — cast to `long long` first.
- [ ] Negative index from `(int)v.size() - 1` when vector is empty wraps to huge `size_t`.
- [ ] `char - '0'` for digit-to-int; forget and you compare ASCII values.
- [ ] `1 << 31` is undefined for `int` — use `1LL << 31`.
- [ ] `double` precision loss with integers above 2⁵³.
- [ ] `cin >> str` stops at whitespace — use `getline(cin, str)` for full lines.
- [ ] `pow(a, b)` returns `double` — use a loop or fast exponentiation for integers.

### 7.8 Memory Footprint Reference

| Type | Size | Used for |
|---|---|---|
| `bool`, `char` | 1 B | Flags, characters, byte arrays |
| `short` | 2 B | Rarely — only when memory is tight |
| `int` | 4 B | Default integer |
| `float` | 4 B | Avoid — prefer `double` |
| `long long`, `double` | 8 B | Large integers / precise reals |
| `long double` | 8–16 B | Extra precision (rarely needed) |
| Pointer | 8 B (64-bit) | All pointer types |

### 7.9 Numeric Limits (`<limits>`)

```cpp
#include <limits>
int mx = numeric_limits<int>::max();          // 2147483647
int mn = numeric_limits<int>::min();          // -2147483648
long long llmx = numeric_limits<long long>::max();
double dmx = numeric_limits<double>::infinity();
```

---

## Quick Reference Card

```cpp
// ── Safe integer arithmetic ──
long long product = 1LL * a * b;

// ── Compile-time constant ──
constexpr int N = 1e5 + 5;

// ── Initialize 2D grid ──
vector<vector<int>> dp(n, vector<int>(m, -1));

// ── Char ↔ digit ──
int d = c - '0';
char c = d + '0';

// ── String ↔ number ──
int n = stoi(s);
string s = to_string(n);

// ── Safe binary-search midpoint ──
int mid = lo + (hi - lo) / 2;

// ── Float equality ──
if (fabs(a - b) < 1e-9) { /* equal */ }

// ── Sentinel values ──
const int INF = 1e9;
const long long LLINF = 1e18;
const int MOD = 1e9 + 7;
```

---

*End of Notes — Mastering data types prevents 90% of silent bugs in interview problems. When in doubt, use `long long`; when comparing floats, use epsilon; when initializing, do it explicitly.*
