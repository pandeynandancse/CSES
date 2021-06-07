#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	long long int n;

	//reading input from user
	cin>>n;

	//print the given number
	cout<<n<<" ";


	while(n!=1){

		// n is odd  
	    if(n&1) n = (n*3)+1;

	    //if n is even
	    else n = n /2;

	    //output the current n
	    cout<<n<<" ";
	}
	return 0;
}
