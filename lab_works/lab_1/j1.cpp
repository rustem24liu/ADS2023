#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a;
    int b;
    deque <int> dq;
    while (cin>>a){   
        if(a=='!'){
            break;
        }   
        else if (a=='*' && dq.empty()){
            cout<<"error" << '\n';
            // break;
        }
        else if(a=='+'){
            cin>>b;
            dq.push_front(b);
        }
        else if(a=='-'){
            cin>>b;
            dq.push_back(b);
        }
        else if(a=='*' && dq.size()!=1){
            cout<<dq.front()+dq.back() << '\n';
            dq.pop_back();
            dq.pop_front();
        }
        else if(a=='*' && dq.size()==1){
            cout << dq.front()+dq.back() << '\n';
            dq.pop_back();
        }
      

    }
    // if (dq.empty()){
    //     cout<<"error";

    // }
    


}