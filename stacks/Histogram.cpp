// Max rectangular section sum(parallel to X-axis) in a Histogram.

#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

void nearerSmallAtLeft(vector<int>& ar, vector<int>& p1){
    int n = ar.size();
    stack<int> stk;
    for(int i=n-1; i>=0; i--){
        while(!stk.empty() && ar[stk.top()] > ar[i]){
            p1[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
}

void nearerSmallAtRight(vector<int>& ar, vector<int>& p2){
    int n = ar.size();
    stack<int> stk;
    for(int i=0; i<n; i++){
        while(!stk.empty() && ar[i] < ar[stk.top()]){
            p2[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
}

main(){
    int n;
    cin >> n;
    vector<int> ar(n), p1(n, -1), p2(n, n);
    for(int i=0; i<n; i++) cin >> ar[i];
    nearerSmallAtLeft(ar, p1);
    nearerSmallAtRight(ar, p2);
    int max_sum = INT_MIN;
    for(int i=0; i<n; i++){
        int cnt = p2[i] - p1[i] - 1;
        max_sum = max(max_sum, (ar[i] * cnt));
    }
    cout << max_sum << '\n';
}