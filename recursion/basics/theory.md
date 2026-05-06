Recursion clicks when you stop seeing a function calling itself as magic and start seeing it as a stack of identical to-do notes.

Let's build that model with factorial, because its stack is a straight line, perfect for beginners.

## The 3 non-negotiable parts

Every correct recursive function has these, no exceptions:

1. **Base case** – the smallest problem you can answer without recursion. For factorial, `if (n <= 1) return 1`.
2. **Recursive case** – make the problem smaller and call yourself. `return n * factorial(n-1)`.
3. **Progress toward base** – `n-1` guarantees you will eventually hit 1. Without progress you overflow the stack.

If you have those three, the machine can do the rest.

## Mental model: trust the clone

Imagine you are `factorial(4)`. You do not compute 4! directly. You write a note: "I need 3! first, then I'll multiply by 4", and you hand it to a clone.

That clone does the same for 3, hands to another clone, and so on. The last clone gets `factorial(1)` and knows the answer is 1, no clone needed. Then answers flow back up, each person doing their one multiplication.

You never hold the whole calculation in your head. You only do one step and trust the clone below.

## Walkthrough: factorial(4) as a table

Here is exactly what the call stack looks like, moment by moment.

| Step | Running code | Call stack (top = active) | What this frame knows | What it is waiting for |
| --- | --- | --- |
| 1 | main() calls factorial(4) | factorial(4): n=4 | n=4 | result of factorial(3) |
| 2 | factorial(4) calls factorial(3) | factorial(3): n=3<br>factorial(4): n=4 | n=3 | result of factorial(2) |
| 3 | factorial(3) calls factorial(2) | factorial(2): n=2<br>factorial(3): n=3<br>factorial(4): n=4 | n=2 | result of factorial(1) |
| 4 | factorial(2) calls factorial(1) | factorial(1): n=1<br>factorial(2): n=2<br>factorial(3): n=3<br>factorial(4): n=4 | n=1 | hits base case |
| 5 | factorial(1) returns 1 | factorial(2): n=2<br>factorial(3): n=3<br>factorial(4): n=4 | — | — |
| 6 | factorial(2) computes 2*1 | factorial(3): n=3<br>factorial(4): n=4 | returns 2 | result of factorial(3) |
| 7 | factorial(3) computes 3*2 | factorial(4): n=4 | returns 6 | result of factorial(4) |
| 8 | factorial(4) computes 4*6 | main() | returns 24 | — |
| 9 | main() prints | (empty) | answer = 24 | done |

Read it top to bottom: steps 1 to 4 are the **going down** phase, pushing frames. Steps 5 to 8 are the **coming up** phase, popping frames. The stack never holds more than 4 frames at once.

## What is actually in each stack frame

Think of a frame as a small box the CPU creates on every call:

- parameter `n` (its own copy)
- return address (where to go back when done)
- space for local variables like `subResult`
- space for the return value

That is why in the tracing code `&n` prints a different address each time. They are separate boxes, not one variable being overwritten. Last In First Out, so the most recent call finishes first.

## The recursion tree for factorial

It is not bushy, it is a chain, which makes it ideal for learning:

```
factorial(4)
  calls factorial(3)
    calls factorial(2)
      calls factorial(1)
      returns 1
    returns 2
  returns 6
returns 24
```

Every node has exactly one child. More complex recursion like Fibonacci branches, but the stack idea is identical.

## How to think while writing recursion

Use this 3-question checklist instead of trying to simulate the whole stack:

1. What is my smallest input? Write the base case first.
2. If someone gave me the answer for n-1, can I build the answer for n with one operation? That is your recursive case.
3. Does my call move toward the base? Check it.

For factorial:
1. n=1 → 1
2. If I had (n-1)!, then n! = n * (n-1)!
3. Yes, n-1 is smaller

Do not trace more than two levels deep in your head. Trust the clone. The stack will handle the rest.

Want to strengthen the model? Run the tracing program for n=4, then cover the output and predict the next line using only the table above. When your prediction matches the machine, you have the mental model locked in.