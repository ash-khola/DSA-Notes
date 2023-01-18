// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Solution

// Simple recursion problem, just we need to maintain a path vector, and after each recursion call we have unvisit the cell (bacTracking) so that we can explore more paths

// T.C :- O(4^(N^2)) (because from each cell we can go in four different cells and there are N^2 cells, therefore (4*4*4*4*4*4....N^2 times))