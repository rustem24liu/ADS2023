#include <iostream>
using namespace std;
bool ok(int arr[], int target, int size){
    int left = 0;
    int right = size-1;
    while(left <= right){
        int middle = (left+right)/2;
        if(arr[middle] == target){
            return true;
        }
        else if(arr[middle] > target){
            right= middle-1;
        }
        else{
            left = middle+1;
        }
    }
    return false;

}
int main(){
    int n, k; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cin >> k;
    if(ok(arr, k, n)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }



}