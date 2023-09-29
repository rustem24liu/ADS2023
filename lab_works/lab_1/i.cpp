#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    deque <int> dq1, dq2;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'K') dq1.push_back(i);
        else dq2.push_back(i);
    }
    while(!dq1.empty() && !dq2.empty()){
        int a = dq1.front();
        int b = dq2.front();
        dq1.pop_front();
        dq2.pop_front();
        if(a > b){
            dq2.push_back(a+n);
        }
        else{
            dq1.push_back(b+n);
        }
    }
    if(dq1.empty()){
        cout << "SAKAYANAGI";
    }
    else cout << "KATSURAGI";
}