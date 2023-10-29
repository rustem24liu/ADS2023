#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int ok(vector<int> &v, int l1, int r1, int l2, int r2, int size){
    int cnt=0;
    for(int i = 0; i < size; ++i){
        if(v[i] >= l1 and v[i] <= r1 || v[i] >= l2 and v[i] <= r2){
            cnt++;
        }
        }
        return cnt;
    }
    


int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int l1, r1, l2, r2;
    int answer=0;
    for(int i =0; i < k; ++i){
        cin >> l1 >> r1 >> l2 >> r2;
        cout << ok(v, l1, r1,l2, r2, n);
    }

}