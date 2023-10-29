#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int n;

bool check(vector<int> &v, int middle, int k ){
    int cnt= 1, sumi = 0;
    for(int i = 0; i < n; ++i){
        sumi+=v[i];
        if(sumi > middle){
            cnt++;
            if(cnt > k){
                return false;
            }
            sumi = v[i];
        }
       
    }
    return true;
}

int main(){
    int k; cin >> n >> k;

    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        v.push_back(x);
    }

    int answer = -1;
    int left = 0, right = 0;
    for(int i = 0; i < n; ++i){
        left = max(left, v[i]);
        right += v[i];
    }
    while(left <= right){
        int middle =  (left+right)/2;
        if(check(v, middle, k)){
            answer = middle;
            right = middle-1;
        }
        else {
            left = middle+1;
        }
    }
    cout << answer;
}