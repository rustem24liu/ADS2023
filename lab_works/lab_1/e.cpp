#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> dq1;
    deque <int> dq2;
    int x, c;
    for(int i = 0; i < 5; ++i){
        cin >> x;
        dq1.push_front(x);
    }
    for(int i = 0; i < 5; ++i){
        cin >> c;
        dq2.push_front(c);
    }
    int cnt = 0;
    while(!dq1.empty() && !dq2.empty() && cnt <= 1000000){
        cnt++;
        int a = dq1.back();
        int b = dq2.back();
        dq1.pop_back();
        dq2.pop_back();

        if(a == 0 && b == 9){
            dq1.push_front(a);
            dq1.push_front(b);
        }
        else if(a == 9 && b == 0){
            dq2.push_front(a);
            dq2.push_front(b);
        }

        else if(a > b){
            dq1.push_front(a);
            dq1.push_front(b);
        }
        else if(a < b){
            dq2.push_front(a);
            dq2.push_front(b);
        }
    }
    if(dq1.empty()) cout << "Nursik" << ' ' << cnt;
    else if(dq2.empty()) cout << "Boris" << " " << cnt;
    else if(cnt >= 1000000) cout << "blin nichya";
}