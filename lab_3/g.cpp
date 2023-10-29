#include <bits/stdc++.h>
using namespace std;
int binarysearch(int arr[], int size, int f){
    int left = 1;
    int maxi = 0;
    for(int i = 0; i < size; ++i){
        maxi = max(maxi, arr[i]); // maxi = 34
    }
    int right = maxi+1; // right = 35, left = 1
    int answer = -1;
    while(left+1 < right){
        int middle = (right+left)/2; // middle = 18
        int sum_f = 0;
        for(int i = 0; i < size; ++i){
            sum_f += (arr[i] + middle-1) / middle; // [sum_f] = 7    ,   sum_f = (10+17)/18 + (34+17)/17 + (14+17)/18 + (6+17)/18+(20+17)/18;
        }
        if(sum_f <= f){
            right = middle-1;
            answer = right;
        }
        else if(sum_f > f){
            left = middle;
        }
    }
    return answer;
}

int main(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << binarysearch(arr, n, m);

}