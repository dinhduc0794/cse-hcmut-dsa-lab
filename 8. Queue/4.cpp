/*
Research queue which is implemented in C library at http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.

Using queue, complete function bool isBipartite(vector<vector<int>> graph) to determine if a graph is bipartite or not (the graph can be disconnected). In caat https://en.wikipedia.org/wiki/Bipartite_graph.

You can use below liberaries in this question.

#include <iostream>
#include <vector>
#include <queue>
*/

#include<bits/stdc++.h>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);  

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {  
            color[i] = 0;      

            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  
                        q.push(v);
                    } 
                    else if (color[v] == color[u]) {
                        return false;  
                    }
                }
            }
        }
    }

    return true;  
}