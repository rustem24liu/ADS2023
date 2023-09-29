#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cin >> m;
    vector <int> v;
    vector <int> v2;
    for(int i = 0; i < n; ++i){
        v.push_back(m-arr[i]);
        v2.push_back(m-arr[i]);
    }
    
    for(int i = 0; i < n; ++i){
        if(v[i] < 0){
            v[i] = -v[i];
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        if(abs(v[0]) == abs(v2[i])){
            cout << i;
            break;
        }
        // cout << v[i] << ' ';
        // cout << v2[i] << ' ';
    }
    
    
}