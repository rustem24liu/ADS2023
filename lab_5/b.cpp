#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    priority_queue<long long, vector <long long>, less<long long>> p;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;                                                                                                           
        p.push(x);
    }
    while(p.size() > 1){
        long long a = p.top();
        p.pop();
        long long b = p.top();
        p.pop();
        if(a != b){
            p.push(abs(abs(b)-abs(a)));
            // cout << p.top() << ' ';
        }
        // else if(a == b){

        // }

        // cout << a << " " << b << endl;
            }
    if(p.empty()){
        cout << 0 << ' ';
    }
    else{
    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }
    
    
    
    }
}