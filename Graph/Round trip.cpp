// cycle detection algorithm

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<vector<long long>> adj;
vector<bool> visited;
vector<long long> parent;

long long cycle_start, cycle_end;
bool dfs(long long v, long long par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (long long u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle() {
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    cycle_start = -1;

    for (long long v = 1; v < n+1; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<long long> cycle;
        cycle.push_back(cycle_start);
        for (long long v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout<<cycle.size()<<"\n";
        // cout << "Cycle found: ";
        for (long long v : cycle)
            cout << v << " ";
        cout << endl;
    }
}


int main() {
    // your code goes here
    
    cin >> n >> m;
    adj.resize(n+1);
    
    for(long long i = 0; i < m; ++i)
    {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    find_cycle();
    
    return 0;
}
