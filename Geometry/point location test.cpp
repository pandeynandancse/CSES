// concept of orientation

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    long long t,x1, y1,x2,y2,x3,y3,ans;
    cin>>t;
    while(t--){
        cin >> x1 >> y1>> x2 >> y2>> x3 >> y3;
        // x1-x3
        // y2-y3
        // x2-x3
        // y1-y3
        ans = (x1-x3) * (y2-y3) - (x2-x3) * (y1-y3);
        // cout<<ans<<"\n";
        if(ans>0) cout<<"LEFT"<<"\n";
        if(ans<0) cout<<"RIGHT"<<"\n";
        if(ans==0) cout<<"TOUCH"<<"\n";
        
    }
    
    
    return 0;
}
