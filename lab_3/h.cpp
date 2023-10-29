#include <bits/stdc++.h>
using namespace std;
int nonbinary(int array[], int k, int size){
    int left = 0;
    int right = size-1;
    while(left <= right){ 
        // int middle = left+(right-left)/2;
        int middle = (right+left)/2;
        if(array[middle] >= k) right = middle-1;
        else left = middle + 1;
    }
    return left;
}

int main(){
    int n, m; cin >> n >> m;
    vector <int> v;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int ans[n];
    ans[0] = v[0];
    for(int i = 1; i < n; ++i){
        ans[i] = v[i] + ans[i-1];
    }

    for(int i = 0; i < m; ++i){
        int k;
        cin >> k;
        cout << nonbinary(ans, k, n)+1 << "\n";
    }
}