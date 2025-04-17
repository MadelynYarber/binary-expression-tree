# Binary Expression Tree
A C++ project that constructs a binary expression tree from a postfix expression. It supports expression validation, recursive printing, deep copy, and traversal.

---
## Features
- Builds BET from postfix expressions
- Recursively prints:
  - Infix expressions (with proper parentheses)
  - Postfix expressions
- Counts total and leaf nodes
- Supports copy constructor and assignment operator
- Graceful error handling for malformed input

---
## Build and Run

```bash
make
./proj4_driver

## Example
Input: 3 4 + 5 *
Infix: ( 3 + 4 ) * 5
Postfix: 3 4 + 5 *
Nodes: 5 | Leaves: 3
