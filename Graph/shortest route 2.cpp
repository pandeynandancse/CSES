// floyyd warshall alsgorithm

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


const long long  nax = 501;
const long long inf = 1e15;
long long dp[501][501];

void floyydWarshall(long long n)
{
    //make diagonals zero > becasue self distance is zero
    for(long long i=1 ; i<=n ;i++ ) dp[i][i] = 0;
    
    for(long long i=1 ; i<=n ;i++ )
        for(long long j=1; j<=n ; j++ )
            for(long long k=1; k<=n ; k++ )
                dp[j][k] = min( dp[j][k] , dp[j][i] + dp[i][k] );
    return ;
    
}


 int main() {
    long long  n,m,q,a,b,c,src,dest;
    cin>>n>>m>>q;
    
    //initialize matrix with infinte/max for all nodes present in graph
    for(long long i=1 ; i<=n ;i++ )
        for(long long j=1; j<=n ; j++ )
            dp[i][j] = inf;
            
    //adjacency matrix representation        
    for(long long i=0;i<m;i++){
        cin>>a>>b>>c;
        dp[a][b] = min(dp[a][b],c);
        dp[b][a] = min(dp[b][a],c);
    }
    
    floyydWarshall(n);
    
    //find shortest distance between queried node
    for(long long i=0; i<q; i++){
        cin >> src>>dest;
        if( dp[src][dest] != inf ) 
            cout << dp[src][dest] << "\n";
        else 
            cout << "-1\n";
    }
   
    return 0;
}