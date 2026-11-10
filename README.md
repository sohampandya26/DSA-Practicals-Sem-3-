# Data Structures and Algorithms - Practical File (25CAMJ204)

All 15 practicals of **25CAMJ204: Data Structures and Algorithms** solved in **C**, each in its own folder with source code, sample input, sample output and a README explaining the problem, approach and complexity.

| | |
|---|---|
| **Author** | Soham Hasamukhbhai Pandya |
| **University** | Kadi Sarva Vishwavidyalaya |
| **Programme** | B.E. Semester 3 - Computer Engineering |
| **Subject** | 25CAMJ204 - Data Structures and Algorithms (A.Y. 2026-27) |
| **Language** | C (C11, tested with GCC) |

## Practical Index

| No. | Practical | Topic / Concept | Folder |
|----|-----------|-----------------|--------|
| 1 | Find the topper using `findTopper()` | Arrays & functions | [practical_01_find_topper](practical_01_find_topper) |
| 2 | Employee annual bonus (10%) | Structure passed to a function | [practical_02_structure_bonus](practical_02_structure_bonus) |
| 3 | Library books with price > Rs. 500 | Array of structures | [practical_03_library_books](practical_03_library_books) |
| 4 | Hospital patient records | Pointer to structure | [practical_04_hospital_records](practical_04_hospital_records) |
| 5 | Student list (add begin/middle/end, remove, display, search) | Singly linked list | [practical_05_linked_list_students](practical_05_linked_list_students) |
| 6 | Cup counter (max 5) | Stack | [practical_06_stack_cups](practical_06_stack_cups) |
| 7 | Infix to postfix `(A+B)*(C+D/E)-(F+G*H)` | Stack applications | [practical_07_infix_to_postfix](practical_07_infix_to_postfix) |
| 8 | Tower of Hanoi | Recursion | [practical_08_tower_of_hanoi](practical_08_tower_of_hanoi) |
| 9 | Ice cream truck line (max 5) | Circular queue | [practical_09_queue_icecream](practical_09_queue_icecream) |
| 10 | Find a book by ID | Linear search | [practical_10_linear_search](practical_10_linear_search) |
| 11 | Guest list check | Binary search | [practical_11_binary_search](practical_11_binary_search) |
| 12 | Patient IDs insert/search | Binary search tree | [practical_12_bst_patients](practical_12_bst_patients) |
| 13 | Company hierarchy traversals | Tree traversals (pre/in/post) | [practical_13_tree_traversals](practical_13_tree_traversals) |
| 14 | Robot exploring a maze | Graph + DFS | [practical_14_dfs_maze](practical_14_dfs_maze) |
| 15 | Sorting case study (5 algorithms x 5 arrays) | Bubble, Selection, Insertion, Merge, Quick | [practical_15_sorting_case_study](practical_15_sorting_case_study) |

## Project Structure

```
DSA-Practicals/
|-- README.md
|-- LICENSE
|-- Makefile
|-- .gitignore
|-- practical_01_find_topper/
|   |-- find_topper.c      # source code
|   |-- input.txt          # sample input
|   |-- output.txt         # sample output
|   `-- README.md          # problem, approach, complexity
|-- practical_02_structure_bonus/ ...
`-- practical_15_sorting_case_study/
    |-- sorting_study.c
    |-- results.csv        # generated timing / comparison data
    ...
```

## How to Build and Run

Requires **GCC** (Linux, macOS, or Windows with MinGW / WSL).

```bash
# build every practical into ./bin
make

# run one practical interactively
./bin/find_topper

# run with the provided sample input
./bin/find_topper < practical_01_find_topper/input.txt

# rebuild everything and regenerate all output.txt files
make run

# remove build artefacts
make clean
```

Without `make`, compile a single file directly:
```bash
gcc -Wall -std=c11 -o topper practical_01_find_topper/find_topper.c
```

## Complexity Summary

| Structure / Algorithm | Operation | Time | Space |
|---|---|---|---|
| Array | access / search | O(1) / O(n) | O(n) |
| Singly linked list | insert begin / end / delete / search | O(1) / O(n) / O(n) / O(n) | O(n) |
| Stack, Circular queue | push, pop, enqueue, dequeue | O(1) | O(n) |
| Infix to postfix | conversion | O(n) | O(n) |
| Tower of Hanoi | moves | O(2^n) | O(n) |
| Linear search | search | O(n) | O(1) |
| Binary search | search (sorted data) | O(log n) | O(1) |
| BST | insert / search | avg O(log n), worst O(n) | O(n) |
| Tree traversal | pre / in / post | O(n) | O(h) |
| DFS (adjacency matrix) | traversal | O(V^2) | O(V^2) |
| Bubble, Selection, Insertion sort | sort | O(n^2) | O(1) |
| Merge sort | sort | O(n log n) | O(n) |
| Quick sort | sort | avg O(n log n), worst O(n^2) | O(log n) avg |

## Practical 15 - Case Study Results

Sample run (time in microseconds, averaged over repetitions; comparisons are machine independent). Your times will differ by machine, but the pattern should stay the same.

| Array | Bubble | Selection | Insertion | Merge | Quick |
|---|---|---|---|---|---|
| A1: small random (10) | 0.18 us / 45 | 0.14 / 45 | **0.05** / 33 | 0.11 / 24 | 0.06 / 31 |
| A2: random (100) | 16.93 / 4944 | 12.61 / 4950 | 1.35 / 2668 | 1.32 / 553 | **0.66** / 736 |
| A3: random (1000) | 1775 / 498419 | 1212 / 499500 | 127 / 257842 | 35.3 / 8705 | **21.5** / 10893 |
| A4: nearly sorted (1000) | 420 / 498174 | 1158 / 499500 | **15.2** / 24194 | 15.5 / 5285 | 23.8 / 30650 |
| A5: reverse sorted (1000) | 3246 / 499500 | 1166 / 499500 | 287 / 499500 | **15.7** / 4932 | 363 / 499500 |

**Interpretation**

- **Tiny inputs (n=10):** all algorithms finish in well under a microsecond; the simple insertion sort wins because it has almost no overhead.
- **Random data (n=100, 1000):** the O(n log n) algorithms (Quick, Merge) are far ahead - roughly 50-80x faster than Bubble at n=1000. Quick sort is usually fastest thanks to in-place, cache-friendly partitioning.
- **Nearly sorted data:** insertion sort is very fast (about 24k comparisons, close to O(n)) because each element is already near its place. Selection sort does not benefit at all - it always makes n(n-1)/2 comparisons. Bubble sort's early exit helps only partly here because the 50 shuffled elements still need many passes.
- **Reverse sorted data:** this is the worst case for Bubble, Insertion and for Quick sort with a last-element pivot (all hit 499,500 comparisons, i.e. O(n^2)). Merge sort stays at O(n log n) regardless of input order.
- **Takeaway:** Merge sort gives guaranteed O(n log n) at the cost of O(n) extra memory; Quick sort is fastest on average but needs a good pivot (random / median-of-three) to avoid its worst case; Insertion sort is best for small or nearly sorted data; Selection and Bubble sort are mainly of teaching value.

## Course Outcomes Covered

- **CO1** - ADTs, structures, linked lists, complexity analysis (Practicals 1-5)
- **CO2** - Stack and queue applications (Practicals 6, 7, 8, 9)
- **CO3** - Searching and sorting techniques (Practicals 10, 11, 15)
- **CO4** - Trees and graphs (Practicals 12, 13, 14)
- **CO5** - Real-world problem solving with suitable data structures (all practicals)

## Uploading to GitHub

```bash
cd DSA-Practicals
git init
git add .
git commit -m "Add DSA practicals (25CAMJ204) with README and sample outputs"
git branch -M main
git remote add origin https://github.com/<your-username>/DSA-Practicals.git
git push -u origin main
```

## License
Released under the [MIT License](LICENSE).
