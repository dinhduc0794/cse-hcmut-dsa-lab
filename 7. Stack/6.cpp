/*
A Maze is given as 5*5 binary matrix of blocks and there is a rat initially at the upper left most block i.e., maze[0][0] and the rat wants to eat food which is present at some given block in the maze (fx, fy). In a maze matrix, 0 means that the block is a dead end and 1 means that the block can be used in the path from source to destination. The rat can move in any direction (not diagonally) to any block provided the block is not a dead end.

Your task is to implement a function with following prototype to check if there exists any path so that the rat can reach the food or not:
bool canEatFood(int maze[5][5], int fx, int fy);

Template:

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
  
        // Initially direction
        // set to 0
        dir = 0;
    }
};

Some suggestions: 
- X : x coordinate of the node
- Y : y coordinate of the node
- dir : This variable will be used to tell which all directions we have tried and which to choose next. We will try all the directions in anti-clockwise manner starting from up.

If dir=0 try up direction.
If dir=1 try left direction.
If dir=2 try down direction.
If dir=3 try right direction.
*/

#include<bits/stdc++.h>

using namespace std;

bool canEatFood(int maze[5][5], int fx, int fy) {
    bool visited[5][5];
    memset(visited, true, sizeof(visited));
    int i = 0, j = 0;
    int n = 5, m = 5;
    stack<node> st;
     
    node temp(i, j);
    st.push(temp);
    
    while (!st.empty()) {
        temp = st.top();
        int d = temp.dir;
        i = temp.x, j = temp.y;
 
        temp.dir++;
        st.pop();
        st.push(temp);
 
        // den dc toa do 
        if (i == fx && j == fy) {
            return true;
        }
 
        // check tren
        if (d == 0) {
            if (i - 1 >= 0 && maze[i - 1][j] && visited[i - 1][j]) {
                node temp1(i - 1, j);
                visited[i - 1][j] = false;
                st.push(temp1);
            }
        }
 
        // check trai
        else if (d == 1) {
            if (j - 1 >= 0 && maze[i][j - 1] && visited[i][j - 1]) {
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                st.push(temp1);
            }
        }
 
        // check duoi
        else if (d == 2) {
            if (i + 1 < n && maze[i + 1][j] && visited[i + 1][j]) {
                node temp1(i + 1, j);
                visited[i + 1][j] = false;
                st.push(temp1);
            }
        }
        
        // check phai
        else if (d == 3) {
            if (j + 1 < m && maze[i][j + 1] && visited[i][j + 1]) {
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                st.push(temp1);
            }
        }
 
        // neu ko tim thay thi quay lai
        else {
            visited[temp.x][temp.y] = true;
            st.pop();
        }
    }
 
    // ko tim dc thuc an
    return false;
}
