#include <iostream>
using namespace std;
int binary_search_decrease(int arr[], int target, int size){
	int left = 0, right = size-1;
	while(left <= right){
		int middle = (left+right)/2;
		if(arr[middle] == target){
			return middle;
		}
		else if(arr[middle] > target){
			left = middle+1;
		}
		else{
			right = middle-1;
		}
	}
	return -1;
}

int binary_search_increase(int arr[], int target, int size){
	int left = 0, right = size-1;
	while(left <= right){
		int middle = (left+right)/2;
		if(arr[middle] == target){
			return middle;
		}
		else if(arr[middle] > target){
			right = middle-1;
		}
		else{
			left = middle+1;
		}
	}
	return -1;
}

int main(){
	int n, m, k, index;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; ++i) cin >> arr[i];
	cin >> m >> k;
	int arr2[m][k];
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < k; ++j ){
			cin >> arr2[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(j%2 == 0) index = binary_search_decrease(arr2[j], arr[i], k);
			else index = binary_search_increase(arr2[j], arr[i], k);
			if(index != -1){
				cout << j << ' ' << index << endl;
				break;
			}
			else if(index == -1 && j == m-1){
				cout << -1 << endl;
				break;
			}
		}
		// if(index != )
		// cout << index << endl;
	}
	
} 
