#include <bits/stdc++.h>
using namespace std;
int main(){
    char x;
    deque <int> dq; 
    while(true){
        cin >> x;
    if(x == '+'){
        int n = 0;  
        cin >> n;
        dq.push_front(n);
   
    }
    else if(x == '-'){
        int n = 0;
        cin >> n;
        dq.push_back(n);
    }
    else if(x == '*' and dq.size() != 1 and dq.size() != 0){
        cout << dq.back() + dq.front() << endl;
        dq.pop_front();
        dq.pop_back();
    }
    else if(x == '*' and dq.size() == 1){
        cout << dq.back() + dq.front()<< endl;
        dq.pop_back();
    }
    else if(x == '*' and dq.size() == 0){
        cout << "error" << endl;
    }
    else if(x == '!'){
        return 0;
    }
    }
    
}