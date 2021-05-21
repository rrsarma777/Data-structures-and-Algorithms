#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

// Brute-force 
// Complexity : (N - K + 1) * K, 1
void solve(vector<int>& ar, int k){
    int n = ar.size();
    for(int i=0; i<n-k+1; i++){
        int j = i, tmp = k, max_of_window = INT_MIN;
        while(tmp--){
            max_of_window = max(max_of_window, ar[j++]); 
        }
        cout << max_of_window << ' ';
    }
    cout << '\n';
}

// Optimal
//Complexity : N, NlogN
void solve1(vector<int>& ar, int k){
    int n = ar.size();
    map<int, int> window;
    int prev, x = 0;
    for(int i=0; i<n; i++){
        prev = ar[x++];
        if(i == 0){
            int j = i;
            while(j < k) window[ar[j++]]++;
            i = j - 1; 
        }
        else window[ar[i]]++;
        cout << window.rbegin()->first << ' ';
        --window[prev];
        if(window[prev] == 0) window.erase(prev);
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int i=0; i<n; i++) cin >> ar[i];
    solve1(ar, k);
}
