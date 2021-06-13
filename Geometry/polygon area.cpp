#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,long long >> adj;

int main() {
	// your code goes here
	long long n,a,b,f,s,sum=0;
    long long sum2=0;
	cin>>n;

	for(long long i=0;i<n;i++){
	    cin >>a>>b;
	    adj.push_back({a,b});
	} 

	//add first cordinate at last of vector also 
	// Steps to get polygon area : https://www.wikihow.com/Calculate-the-Area-of-a-Polygon
	f = adj[0].first;
	s = adj[0].second;
	adj.push_back({f,s});
	
	for(long long i=0;i<n;i++){
	    sum = sum + (adj[i].first * adj[i+1].second) ;
	    sum2 = sum2 + (adj[i].second * adj[i+1].first) ;
	}
	
	cout << abs(sum-sum2);
	
	return 0;
}
