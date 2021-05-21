#include <iostream>
using namespace std;

bool isValid(string s){
    int cnt = 0;
    for(auto c : s){
        if(c == '(') ++cnt;
        else{
            if(cnt <= 0) return false;
            --cnt;
        }
    }
    return cnt == 0;
}

main(){
    int TC = 0;
    cin >> TC;
    string s;
    while(TC--){
        cin >> s;
        cout << isValid(s) << '\n';
    }
}