# uva_116

This problem named "Unidirectional TSP" can be solved by dynamic programming. Using input matrix “mat”, we can build a m·n array “DP”, where DP[i][j] indicates the shortest path length from the last column to mat[i][j]. And the last column of DP is initialized by mat’s. The recursion equation is shown as:    

  DP[i][j]=mat[i][j]+min⁡(DP[(i-1)%m][j+1],DP[i][j+1],DP[(i+1)%m][j+1])
  
And the smallest value in DP’s first column is the shortest path length. Note the set of shortest paths from left to right is always the same as the one from right to left. We can take the position mat[i][0] as the starting point, where DP[i][0] has the smallest value in DP’s first column with the smallest i. Next, we choose the position with the lexicographically smallest value in DP[(i-1)%m][1],DP[i][1],DP[(i+1)%m][1] as the next point. By continuing the above iteration, we can get the lexicographically shortest path.
