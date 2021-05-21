#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValid(string s){
    stack<char> stk;
    int n = s.size(); 
    for(auto c : s){
        if(c == '(') stk.push(')');
        else if(c == '[') stk.push(']');
        else if(c == '{') stk.push('}');
        else{
            if(!stk.empty() && stk.top() == c) stk.pop();
            else return false;
        }
    }
    return stk.empty();
}

main(){
    int TC = 1;
    cin >> TC;
    string s;
    while(TC--){
        cin >> s;
        cout << isValid(s) << '\n';
    }
}