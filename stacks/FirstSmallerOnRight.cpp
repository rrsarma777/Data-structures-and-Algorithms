#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Brute-force approch
// Complexity : N^2, 1
void solve(vector<int>& ar, vector<int>& br){
    int n = ar.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n - 1; j++){
            if(ar[i] > ar[j]){
                br[i] = ar[j];
                break;
            }
        }
    }
}

// Optimal approach
// Complexity N, N
// Here in stack each element atmost performs 3 operations(push, pop, top/peek).
// So for 'N' elements operations will be '3N'
// So the overall time complexity is 'N' only.
void solve1(vector<int>& ar, vector<int>& br){
    stack<int> stk;
    int n = ar.size();
    for(int i = 0; i < n; i++){
        while(!stk.empty() && ar[i] < ar[stk.top()]){
            br[stk.top()] = ar[i];
            stk.pop();
        }
        stk.push(i);
    }
}

//Optimal approach-2
// Complexity N, N
void solve2(vector<int>& ar, vector<int>& br){
    // As it is filled with -1s(Used for other approaches). So we replaced with 0s.
    fill(br.begin(), br.end(), 0);
    stack<int> stk;
    int n = ar.size();
    for(int i = n - 1; i >= 0; i--){
        while(!stk.empty() && stk.top() >= ar[i]){
            stk.pop();
        }
        br[i] = stk.empty() ? -1 : stk.top();
        stk.push(ar[i]);
    }
}
//Test case : 5 8 5
main(){
    int n;
    cin >> n;
    vector<int> ar(n), br(n, -1);
    for(int i = 0; i < n; i++) cin >> ar[i];
    solve1(ar, br);
    for(int i = 0; i < n; i++) cout << br[i] << ' ';
    cout << '\n';
}