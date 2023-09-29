#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, c;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; ++i){
        cin >> c;
        if(!v.empty()){
            bool ok = false;
            for(int j = v.size()-1; j >= 0; --j){
                if(c >= v[j]){
                    cout << v[j] << ' ';
                    ok = true;
                    break;
                }
            }
            if(!ok){
                cout << -1 << ' ';
            }
        }
        else{
            cout << -1 << ' ';
        }
        v.push_back(c);
    }
}