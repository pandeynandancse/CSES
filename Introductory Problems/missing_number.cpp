#include <iostream>

using namespace std;

int main() {

	//n=5
	// 2 + 3 + 1  + 5 = 11
	// n*n+1 /2  > 5*6/2 = 15 > 1+ 2  +3 + 4 + 5
  // 15-11 = 4

 	long long int  n,data,sum=0;
	cin>>n;

    for(long long int i=0; i<n-1;i++){
        cin>>data;
        sum = sum + data;
        
    }
    
    cout<<( (n*(n+1))/2) - sum; // gives missing numbeer
	return 0;
}
