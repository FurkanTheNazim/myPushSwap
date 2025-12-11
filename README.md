# Push_Swap

A sorting algorithm project for 42 School. Sorts a stack of integers using a limited set of operations with the minimum number of moves.

## About

Push_swap takes a list of integers and outputs the most efficient sequence of operations to sort them using two stacks (A and B).

## Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile
```

## Usage

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack A |
| `sb` | Swap first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B to A |
| `pb` | Push top of A to B |
| `ra` | Rotate A (first becomes last) |
| `rb` | Rotate B |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (last becomes first) |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` and `rrb` simultaneously |

## Algorithm

- **3 elements**: Optimal sorting
- **≤5 elements**: Selection sort variant
- **>5 elements**: Radix sort (LSD)

## Performance

| Elements | Operations | Score |
|----------|------------|-------|
| 3 | ≤3 | ✓ |
| 5 | ≤12 | ✓ |
| 100 | ~1100 | 3/5 |
| 500 | ~6800 | 4/5 |
