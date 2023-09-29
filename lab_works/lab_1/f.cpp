#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 2; i < 10000; ++i){
        bool ok = true;
        for(int j = 2; j < i; ++j){
            if(i%j == 0){
                ok = false;
            }
        }
        if(ok){
            v.push_back(i);
        }
    }   
    if(n == 1){
        cout << 2;
    }else cout << v[n-1];
}