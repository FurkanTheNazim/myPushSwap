*This project has been created as part of the 42 curriculum by mahmmous.*

# Push_Swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations with the minimum number of moves.

## Description

Push_swap is an algorithmic challenge where you must sort a stack of integers using only two stacks (A and B) and a limited set of operations. The goal is to find the most efficient sequence of operations to sort the stack in ascending order.

The program takes a list of integers as arguments and outputs the sequence of operations needed to sort them. The first argument represents the top of stack A.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack A |
| `sb` | Swap first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B to A |
| `pb` | Push top of A to B |
| `ra` | Rotate A upward (first becomes last) |
| `rb` | Rotate B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (last becomes first) |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` and `rrb` simultaneously |

## Instructions

### Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage

```bash
# Multiple arguments
./push_swap 4 67 3 87 23

# Single string argument
./push_swap "4 67 3 87 23"

# Test with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Test with random numbers
ARG=$(shuf -i 1-500 -n 5 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

### Error Handling

The program displays `Error` on stderr for:
- Non-integer arguments
- Numbers exceeding INT limits
- Duplicate numbers
- Empty strings

## Algorithm

The program uses different strategies based on input size:

| Size | Algorithm | Description |
|------|-----------|-------------|
| 2-3 | Optimal sort | Optimal moves |
| 4-5 | Selection sort | Push smallest to B, sort 3, push back |
| 6+ | Radix sort (LSD) | Bit manipulation based sorting |

### Performance

| Elements | Average Operations |
|----------|-------------------|
| 3 | ≤3 |
| 5 | ≤12 |
| 100 | ~1100 |
| 500 | ~6800 |

## Resources

### Documentation & References
- [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)
- [Push_swap Tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- 42 Project Subject PDF
- Peer support and code reviews from 42 Istanbul peers

### AI Usage
AI was used for debugging assistance and documentation formatting. All code was written and tested by the author.
