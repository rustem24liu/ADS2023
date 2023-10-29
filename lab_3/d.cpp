#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int moonbinary(int target){
    int left = 0;
    int right = v.size()-1;
    int res = -1;
    while(left <= right){
        int middle = (right+left)/2;
        if(v[middle] <= target) {
        res = middle;
        left = middle+1;
        }
        else right = middle-1;
    }
    if(res == -1) return 0;
    return res+1;
}

int answer(int l, int r){
    return moonbinary(r) - moonbinary(l-1);
}
int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; ++i){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;  
        if(r2 < l1 || r1 < l2){
            int res = answer(l1, r1) + answer(l2, r2);
            cout << res << endl;
        }
        else{
            int mini = min(l1, l2);
            int maxi = max(r1, r2);
            cout << answer(mini, maxi) << endl;
        }
    }
}