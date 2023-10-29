#include <bits/stdc++.h>
using namespace std;
pair <int , int> nooonbinary(vector<int> v, int k){
    int left = 0;
    int right = v.size()-1;
    while(left <= right){
        int middle = (right+left)/2;

        if(v[middle] <= k){
            pair <int , int> p;
            // right = middle;
            int cnt = 0, sum = 0;
            for(int i = left; i <= right; ++i){
                if(v[i] <= k){
                    cnt++;
                    sum+=v[i];
                }
            }
            p.first = cnt;
            p.second = sum;
            return p;
        }
        else if(v[middle] >  k) right = middle-1;
    }
}

int main(){
    int n, k; cin >> n;
    vector <int> v;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cin >> k;
    for(int i = 0; i < k; ++i){
        int x; cin >> x;
        cout << nooonbinary(v, x).first << ' ' << nooonbinary(v, x).second << "\n";
    }
}