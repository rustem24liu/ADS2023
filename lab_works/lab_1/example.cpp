#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    // cout << -1 << ' ';
    for(int i = 0; i < n; ++i){
        bool ok = false;
        for(int j = i-1; j >= 0; --j){
            if(arr[i]>=arr[j]){
                ok = true;
                cout << arr[j] << ' ';
                break;
            }
        }
        if(!ok) cout << -1 << ' ';
    }
}