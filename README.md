Project Overview

This implementation of push_swap is structured in three main stages: (1) input parsing, (2) stack operations, and (3) sorting strategy.

This project goes far beyond implementing a sorting algorithm. It requires understanding:

- Linked list memory management

- Bitwise operations

- Algorithmic stability

Rather than comparing values directly, the solution works at the binary level, progressively organizing elements bit by bit. What initially seems like a restrictive problem becomes an exercise in algorithmic elegance and structural thinking. Despite the stressful moments, I really enjoyed working on this project.


1️⃣ Input Parsing & Validation

The program validates all input arguments before building the stack:

Accepts multiple arguments or quoted strings.

Checks that each token:

Has a valid integer format.

Fits within the int range.

Is not duplicated.

On invalid input, prints Error and exits.

Valid integers are stored in stack A using a singly linked list.

This ensures that the algorithm always works with safe and consistent data.

2️⃣ Stack Structure & Operations

Stacks are implemented as singly linked lists:

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int      size;
}   t_stack;

All mandatory operations were implemented:

Swap: sa, sb, ss

Push: pa, pb

Rotate: ra, rb, rr

Reverse rotate: rra, rrb, rrr

Each operation:

Updates pointers correctly.

Maintains stack size consistency.

Prints instructions only when executed.

3️⃣ Sorting Strategy — Binary Radix Sort

The chosen strategy is a binary radix sort, adapted to the limited set of allowed stack operations.

* Phase 1: Value Compression

All integers are converted into their relative ranks (from 0 to n-1).

This simplifies:

Large numbers

Negative values

Integer boundary issues

After compression, the problem becomes sorting numbers in a normalized range.

* Phase 2: Bitwise Sorting

The algorithm processes numbers bit by bit, starting from the least significant bit:

If the current bit is 0 → pb

If the current bit is 1 → ra

After processing all elements for a bit, everything from B is pushed back to A.

This is repeated for all necessary bit positions until the stack is fully sorted.

Time complexity: O(n log n).

📂 Project Structure
push_swap/
│
├── includes/
│   └── push_swap.h
│
├── src/
│   ├── main.c
│   ├── parse_args.c
│   ├── parse_utils.c
│   ├── parse_validate.c
│   ├── stack_build.c
│   ├── moves_swap.c
│   ├── moves_push.c
│   ├── moves_rotate.c
│   ├── moves_rev_rotate.c
│   └── push_swap.c
│
├── libft/
│   └── (custom standard library functions)
│
└── Makefile

The codebase is modular:

Parsing logic is separated from stack construction.

Stack operations are grouped by type.

Sorting logic is isolated in push_swap.c.


