//number of connected component using dfs


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<long long > comp ;

long long  components=0;

vector<long long> ans;


void dfs(long long i, vector<long long > &visited, vector<vector<long long >> &adj ){
    visited[i] = 1 ;
    comp.push_back(i);
    for(long long u : adj[i]) {
        if(! visited[u])
            dfs(u, visited, adj);
    }
    return;
}

int main() {
	long long m,n,a,b;
	cin>>n>>m;
	vector<long long> visited(n+1,0);
	vector<vector<long long >> adj(n+1);
	for(long long i=0; i<m;i++){
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	
	for(long long i=1; i<=n;i++){
	    if(!visited[i]) {
	        comp.clear();
	        components ++;
	        dfs(i,visited,adj);
	        for(long long c : comp) {
	            ans.push_back(c);
	           // cout<<c<<"  ";
	            break;
	        }
	        
	    }
	    
	}
	
	cout<<ans.size()-1<<"\n";
	for(long long i = 0; i<ans.size()-1; i++)
	{
	    cout<<ans[i]<<" "<<ans[i+1]<<"\n";
	}
	
	return 0;
}
