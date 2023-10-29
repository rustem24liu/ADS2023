#include <bits/stdc++.h>
using namespace std;
bool check(vector <int> v, int f, int middle){
    int sum_f = 0;
    for(int i = 0; i < v.size(); ++i){
        sum_f += (v[i] + middle-1)/middle;
    }
    return sum_f <= f;
}


int main()
{   
    int n, x, m; cin >> n >> m;
    vector <int> v;
    for(int i = 0; i < n; ++i){
        cin >> x;
        v.push_back(x);
    }
    int left = 1;
    int right = 1e9;
    while(right-left > 1){
        int middle = (right+left)/2;
        if(check(v, m, middle)) right = middle;
        else left = middle;
    }
    cout << right;

}
