# Practical 14: Maze Robot - DFS

## Problem Statement
Model the maze as a graph and use DFS to visit all locations, displaying the visiting order; the robot goes deep, then backtracks.

## Concepts Used
Graph, adjacency matrix, Depth First Search

## Approach
Recursive DFS visiting unvisited neighbours in increasing order; marks the treasure location when reached; reports unreachable locations.

## Complexity
| Time | Space |
|------|-------|
| O(V^2) with adjacency matrix | O(V^2) matrix + O(V) stack |

## How to Run
```bash
gcc -Wall -std=c11 -o maze_dfs maze_dfs.c
./maze_dfs < input.txt
```

## Sample Input (`input.txt`)
```
7 7
0 1
0 2
1 3
1 4
2 5
2 6
4 6
0 5
```

## Sample Output
```
Enter number of locations and paths: Enter 7 paths (u v):
Enter entrance location and treasure location: 
--- Maze adjacency matrix ---
    0  1  2  3  4  5  6 
 0  0  1  1  0  0  0  0 
 1  1  0  0  1  1  0  0 
 2  1  0  0  0  0  1  1 
 3  0  1  0  0  0  0  0 
 4  0  1  0  0  0  0  1 
 5  0  0  1  0  0  0  0 
 6  0  0  1  0  1  0  0 

--- DFS exploration ---
Robot visits location 0
Robot visits location 1
Robot visits location 3
Robot visits location 4
Robot visits location 6
Robot visits location 2
Robot visits location 5   <-- TREASURE FOUND!

Order of visit: 0 -> 1 -> 3 -> 4 -> 6 -> 2 -> 5
Treasure was found at location 5.
```
