
```text
1️⃣ Project Overview
2️⃣ Input Parsing & Validation
3️⃣ Stack Structure & Operations
4️⃣ Sorting Strategy
  • Early Exit
  • Small Case Optimization
  • Value Compression
  • Bitwise Sorting

## 1️⃣ Project Overview
```

This implementation of push_swap is structured in three main stages: (1) input parsing, (2) stack operations, and (3) sorting strategy.

This project goes far beyond implementing a sorting algorithm. It requires understanding:

- Linked list memory management

- Bitwise operations

- Algorithmic stability

Rather than comparing values directly, the solution works at the binary level, progressively organizing elements bit by bit. What initially seems like a restrictive problem becomes an exercise in algorithmic elegance and structural thinking. Despite the stressful moments, I really enjoyed working on this project.


## 2️⃣ Input Parsing & Validation

The program validates all input arguments before building the stack:

Accepts multiple arguments or quoted strings.

Checks that each token:

Has a valid integer format.

Fits within the int range.

Is not duplicated.

On invalid input, prints Error and exits.

Valid integers are stored in stack A using a singly linked list.

This ensures that the algorithm always works with safe and consistent data.

## 3️⃣ Stack Structure & Operations

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

## 4️⃣ Sorting Strategy — Binary Radix Sort

Before launching the sorting algorithm, the program checks whether stack A is already sorted.
If so, it exits immediately without printing any operations.
This prevents unnecessary computation and guarantees optimal behavior in trivial cases.
For small input sizes (≤ 3 and ≤ 5), specialized minimal-operation sorting strategies are used instead of radix sort. These tailored solutions reduce the total number of operations and ensure optimal performance for simple cases.

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

## 📂 Project Structure

```text
push_swap_git/
├── includes/
│   └── push_swap.h          # Declaraciones de estructuras y prototipos
│
├── src/
│   ├── main.c                 # entry point: init stack + parse + call push_swap()
│   ├── parse_args.c           # argument parsing (argv -> tokens)
│   ├── parse_utils.c          # helpers for parsing (split/free/etc.)
│   ├── parse_validate.c       # token validation (format, int range, duplicates)
│   ├── stack_build.c          # stack build + utils (add, search, free, is_sorted)
│   ├── moves_swap.c           # sa / sb / ss
│   ├── moves_push.c           # pa / pb
│   ├── moves_rotate.c         # ra / rb / rr
│   ├── moves_rev_rotate.c     # rra / rrb / rrr
│   ├── small_sort.c           # sort_2 / sort_3 / sort_5
│   ├── compress.c             # helpers for compress (value -> index)
│   ├── radix.c                # radix sort algorithm
│   ├── stack_build.c          # has_value / stack_add_back / free_stack / is_sorted / new_node
│   └── push_swap.c            #
├── libft/
│   ├── Makefile
│   ├── libft.h
│   └── *.c                    # your custom libft functions
└── Makefile                 # Script de compilación del proyecto
```

The codebase is modular:

Parsing logic is separated from stack construction.

Stack operations are grouped by type.

Sorting logic is isolated in push_swap.c.


