#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    string arr[n];
    deque <string> dq;
    for(int i = 0; i < n ;++i){
        cin >> arr[i];
        dq.push_front(arr[i]);
    }
    for(int i = 0; i < m; ++i){
        string c = dq.back();
        dq.pop_back();
        dq.push_front(c);
    }
    while(!dq.empty()){
        cout << dq.back() << ' ';
        dq.pop_back();
    }
    
}