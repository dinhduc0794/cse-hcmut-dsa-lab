/*Given a n*m grid where each cell in the grid can have a value of 0, 1 or 2, which has the following meaning:
1. Empty cell
2. This cell contains a fresh apple
3. This cell contains a rotten apple
After 1 second, the cell with rotten apple will rot all fresh apples in all the cells adjacent to it (i.e the cells (x+1, y), (x-1, y), (x, y+1), (x, y-1))
Determine the minimum time (in seconds) required to rot all apples. If this cannot be done, return -1.
Note: iostream, vector, and queue are already included.

Constraint:
1 <= n, m <= 500

Hint: Have you ever heard about breadth-first-search?

Example 1:
Input: grid = {{2,2,0,1}}
Output: -1
Explanation:
The grid is
2 2 0 1
The apple at (0, 3) cannot be rotten

Example 2:
Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation:
The grid is
0 1 2
0 1 2
2 1 1
Apples at positions (0,2), (1,2), (2,0)
will rot apples at (0,1), (1,1), (2,2) and (2,1) after 1 second.
*/

#include<bits/stdc++.h>

using namespace std;

int secondsToBeRotten(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int freshAp = 0;
    queue<pair<int, int>> rottenAp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                freshAp++;
            } else if (grid[i][j] == 2) {
                rottenAp.push({i, j});
            }
        }
    }

    int time = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!rottenAp.empty()) {
        int size = rottenAp.size();

        for (int i = 0; i < size; i++) {
            int x = rottenAp.front().first;
            int y = rottenAp.front().second;
            rottenAp.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    freshAp--;
                    rottenAp.push({nx, ny});
                }
            }
        }

        if (!rottenAp.empty()) {
            time++;
        }
    }

    if (freshAp == 0) return time;
    else return -1;
}