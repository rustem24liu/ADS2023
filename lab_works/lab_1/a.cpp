#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    deque <int> dq;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        int b = a;
        while(a > 0){
            dq.push_front(a);
            int z = b;
            while(z > 0){
                int c = dq.back();
                dq.pop_back();
                dq.push_front(c);
                z--;
            }
            b--;
            a--;
            // dq.push_front(a);
        }

    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
    }
}