#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n;
    vector <int> v;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        v.push_back(x);
    }
    cin >> k;
    for(int i = 0; i < k; ++i){
        int x; cin >> x;
        int res = 0;
        int sum = 0;
        for(int j = 0; j < v.size(); ++j){
            if(x>=v[j]){
                res +=1;
                sum+=v[j];
            }
        }
        cout << res << ' ' << sum << endl;
    }
}