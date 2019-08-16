// 207. Course Schedule
// BFS
class Solution {
 public:
  typedef vector<vector<int>> graph;
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    graph g(numCourses);
    for (auto p : prerequisites) {
      g[p.second].push_back(p.first);
    }
    vector<int> degrees(numCourses, 0);
    for (auto a : g) {
      for (int i : a) {
        degrees[i]++;
      }
    }

    for (int i = 0; i < numCourses; i++) {
      int j = 0;
      for (; j < numCourses; j++) {  // find vertex in = 0
        if (degrees[j] == 0) break;
      }
      if (j == numCourses) {  // cycle
        return false;
      }
      degrees[j]--;  // remove node
      for (int v : g[j]) {
        degrees[v]--;
      }
    }
    return true;
  }
};
// 64. Minimum Path Sum
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> path_sum(grid.size(),
                                 vector<int>(grid[0].size(), INT_MAX));
    path_sum[0][0] = grid[0][0];
    for (int i = 1; i < grid[0].size(); i++) {
      path_sum[0][i] = path_sum[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < grid.size(); i++) {
      path_sum[i][0] = path_sum[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < grid.size(); i++) {
      for (int j = 1; j < grid[0].size(); j++) {
        path_sum[i][j] =
            min(path_sum[i - 1][j], path_sum[i][j - 1]) + grid[i][j];
      }
    }
    return path_sum[grid.size() - 1][grid[0].size() - 1];
  }
};

// 62. Unique Paths
// 
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> path(m, vector<int>(n, INT_MAX));
    path[0] = vector<int>(n, 1);
    for (int i = 0; i < m; i++) {
      path[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        path[i][j] = path[i - 1][j] + path[i][j - 1];
      }
    }
    return path[m - 1][n - 1];
  }
};
// 63. Unique Paths II
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<long>> path(m+1, vector<long>(n+1, 0)); // long
    path[0][1]= 1; // initallization without 111111 by add one extra line and row
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (!obstacleGrid[i-1][j-1]) {
         path[i][j] = path[i - 1][j] + path[i][j - 1];
      }
    }
    }
    return path[m ][n];
  }
};