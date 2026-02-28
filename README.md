This implementation of push_swap is structured in three main stages: input parsing, stack operations, and sorting strategy.

1️⃣ Input Parsing & Validation

The program validates all input arguments before building the stack:

Supports both multiple arguments and quoted strings.

Verifies that each token:

Is a valid integer format.

Fits within the int range.

Is not duplicated.

On any invalid input, the program prints Error and exits.

The validated integers are stored in stack A using a linked list structure.

2️⃣ Stack Structure & Operations

Stacks are implemented using singly linked lists:

t_node represents each element.

t_stack stores the pointer to the top node and the current size.

All mandatory operations were implemented:

Swap: sa, sb, ss

Push: pa, pb

Rotate: ra, rb, rr

Reverse rotate: rra, rrb, rrr

Each operation updates pointers and stack sizes correctly and prints the corresponding instruction only when executed.

3️⃣ Sorting Strategy (Radix Sort)

The chosen strategy is a binary Radix Sort, adapted to the constraints of the project.

The process works in two phases:

Value compression
All integers are converted into their relative ranks (from 0 to n-1).
This simplifies the problem by working with a normalized range of values.

Bitwise radix sorting
The algorithm processes numbers bit by bit, starting from the least significant bit:

If the current bit is 0, the value is pushed to stack B.

If the bit is 1, the value is rotated within stack A.
After each bit pass, all elements are pushed back to stack A.

This process is repeated for all necessary bit positions, resulting in a fully sorted stack.
