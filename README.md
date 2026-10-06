*This project has been created as part of the 42 curriculum by syazdanp, ncuotto-.*

## Description
**Push_swap** is a highly efficient algorithmic project in the 42 school curriculum. The primary goal is to sort a given stack of unique integers (Stack A) using an auxiliary empty stack (Stack B) and a strictly limited set of stack manipulation instructions (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). 

The challenge lies not only in achieving a sorted state but in minimizing the total operation count. To maximize performance across varying input sizes, our implementation utilizes a dynamic, adaptive framework that analyzes data disorder before executing a specialized sorting algorithm.

## Instructions

### Compilation & Installation
The project compiles into an executable using the provided `Makefile`. It automatically handles the internal compilation of dependency libraries (`libft`).

To compile the program, run the following command at the root of the repository:
```bash
make
```

To clean intermediate object files and force a full recompilation:
```bash
make re
```

### Execution
Run the program by providing a list of unique space-separated integers as arguments. The program will output the exact sequence of operations to `stdout`:
```bash
./push_swap 5 2 8 1 3
```

### Advanced Diagnostics (Benchmark Mode)
Our framework includes a diagnostic benchmark flag. Appending `--bench` directs the program to print advanced analytical metrics (such as individual operation breakdowns and the initial disorder metric) to `stderr`:
```bash
./push_swap --bench 5 2 8 1 3
```

You can also bypass the adaptive controller and manually force a specific sorting routine:
```bash
./push_swap --simple 5 2 8 1 3
```

## Algorithm Selection & Justification

Our architecture utilizes an **Adaptive Strategy Framework** that evaluates the size of the stack and its initial statistical disorder to pick the optimal sorting routine:

### 1. Small Stacks (Size <= 5) — `SIMPLE` Strategy
- **Justification**: Stacks of size 2, 3, 4, or 5 have small permutation sets. Utilizing complex partitioning routines on small sets introduces unnecessary rotational overhead.
- **Mechanism**: 
  - Stacks of size 2 and 3 are handled by hardcoded mathematical conditional checks (`sort_two` and `sort_three`) that analyze relative node index values, resolving sorting in a maximum of 1 and 2 operations respectively.
  - Stacks of size 4 and 5 find the absolute minimum index, rotate it to the top using the shortest path (`ra` or `rra`), push it to Stack B (`pb`), sort the remaining elements, and push them back (`pa`). This guarantees sorting 5 elements in **9 operations**, well below the 42 school limit of 12 moves.

### 2. Medium Stacks — `MEDIUM` Strategy
- **Justification**: Activated dynamically when the stack size grows or initial disorder is moderately balanced. It bridges the gap between pure cost-analysis and structural chunking without the overhead of heavy pre-sorting calculations.
- **Mechanism**: Splits elements by sorting chunks based on pre-calculated square root boundaries (\(O(N \sqrt{N})\) complexity), pushing selected node ranges into Stack B, and smoothly restoring them into Stack A in optimal descending rank order.

### 3. Large Stacks (Size >= 100) — `COMPLEX` Strategy
- **Justification**: For sets of 100 to 500 random elements, a pure comparative search is highly inefficient. An \(O(N \log N)\) block-partitioning approach is required to achieve the highest possible scores on the evaluation scale.
- **Mechanism**: Employs an optimized chunk-sorting or bit-index mapping mechanism (such as Radix or K-Sort logic). Elements are grouped by index bit-ranges, pushed systematically into Stack B, and efficiently back-sorted into Stack A using structural lookahead logic to minimize costly full stack rotations.

## File Breakdown & Code Architecture

### Core Setup & Utilities
* **`main.c`**: Starts the program, initializes structures, validates token flags, and executes the optimal sorting roadmap based on stack size.
* **`parse_utils.c`**: Validates input string collections, checks for dangerous integer overflows, and rejects duplicate values to protect memory arrays.
* **`disorder.c`**: Measures stack chaos and returns a precise statistical disorder score used by the main adaptive routing framework.
* **`bench.c`**: Tracks project optimization metrics and outputs raw operation totals and analytics directly to the standard error stream.

### Stack Infrastructure
* **`stack.c`**: Handles primary memory allocation. It creates new isolated nodes and sets their base values safely.
* **`stack.utils.c`**: Manages structural data traversal. It fetches the bottom element, appends new nodes, and clears stacks to avoid leaks.
* **`stack_utils_2.c`**: Validates active states. It calculates the live item count, checks sorting statuses, and calculates relative index ranks.

### Rules & Operations
* **`op_push.c`**: Implements the `pa` and `pb` commands, transferring top elements seamlessly from one stack array to the other.
* **`op_swap.c`**: Implements the `sa`, `sb`, and `ss` commands, swapping the first two nodes at the top of the selected stack instantly.
* **`op_rotate.c`**: Implements the `ra`, `rb`, and `rr` commands, shifting the top element down to the absolute bottom of the stack.
* **`op_reverse_rotate.c`**: Implements the `rra`, `rrb`, and `rrr` commands, bringing the bottom node back up to the absolute top of the stack.

### Algorithmic Sorting Strategies
* **`sort_utils.c`**: Contains the tiny sort logic engines. It manages 2-element arrays and resolves 3-element sequences in a maximum of 2 moves.
* **`sort_simple.c`**: Coordinates sorting for lists of 4 and 5 items, isolating minimum indices into Stack B and resolving the stack in under 12 moves.
* **`sort_medium.c`**: Manages medium-sized arrays by splitting indexes into pre-calculated square root chunks before safely merging them back.
* **`sort_complex.c`**: Handles large arrays up to 500 items, using binary bit-mapping or high-efficiency chunk ranges to minimize heavy total rotations.

## Resources

### Classic References
- **42 Push_swap Subject Manual**: Standard specifications for stack instruction behavior.
- **Algorithmic Sorting Efficiencies**: Standard references on Big O notation complexities for O(N²), \(O(N \sqrt{N})\), and \(O(N \log N)\) sorting distributions.
- **Radix & Chunk Sorting Tutorials**: General computer science concepts regarding non-comparative integer sorting structures.

### AI Usage Declaration
Artificial Intelligence (Large Language Model) was used during this project strictly as a code-quality peer assistant for the following tasks:
- **Norminette Refactoring**: Identifying and resolving formatting errors such as line count limits (`TOO_MANY_LINES` in `main.c` and `parse_utils.c`), structural alignment issues (`MISALIGNED_VAR_DECL`), and cleaning illegal in-scope comments (`WRONG_SCOPE_COMMENT`).
- **Debugging & Linker Analysis**: Diagnosing architecture `arm64` compiler linking errors (`Undefined symbols`) by ensuring missing structural compilation files (`bench.c`, `sort_medium.c`, `disorder.c`) were appropriately mapped into the `Makefile` source tree.
- **Algorithmic Review**: Conceptual auditing of the `sort_three` logic inside `sort_utils.c` to prevent redundant logical comparisons and guarantee optimal instruction results.
