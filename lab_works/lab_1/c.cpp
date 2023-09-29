#include <bits/stdc++.h>
using namespace std;
int main(){
    stack <char> s1, s2;
    string ss1, ss2;
    cin >> ss1 >> ss2;
    int l1 = ss1.size();
    int l2 = ss2.size();
    string ans1, ans2;
    s1.push(ss1[0]);
    s2.push(ss2[0]);
    for(int i = 1; i < l1; ++i){
        if(ss1[i] != '#'){
            s1.push(ss1[i]);
        }
        else if(ss1[i] == '#'){
            s1.pop();
        }
    }
    for(int i = 1; i < l2; ++i){
        if(ss2[i] != '#'){
            s2.push(ss2[i]);
        }
        else if(ss2[i] == '#'){
            s2.pop();
        }
    }


    while(!s1.empty()){
        ans1 += s1.top();
        // cout << s1.top() << " ";
        s1.pop();
    }
    while(!s2.empty()){
        ans2+= s2.top();
        // cout << s2.top() << " ";
        s2.pop();
    }
    if(ans1 == ans2){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}