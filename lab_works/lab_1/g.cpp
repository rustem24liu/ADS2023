#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    for(int i = 2; i < n; ++i){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int x;
    cin >> x;
    vector <int> primes;
    vector <int> superprimes;
    for(int i = 2; i < 10000; ++i){
        if(isprime(i)){
            primes.push_back(i);
        }
    }
    for(int i = 2; i < 1000; ++i){
        if(isprime(i)){
            superprimes.push_back(primes[i-1]);
        }
    }
    cout << superprimes[x-1];
}