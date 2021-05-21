#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// O(N^3) approach.
int bruteforce(vector<int>& ar) {
	int n = ar.size();
	int max_sum = INT_MIN;
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			int sum_so_far = 0;
			for(int k = i; k <= j; ++k){
				sum_so_far += ar[k];
			}
			max_sum = max(max_sum, sum_so_far);
		}
	}
	return max_sum;
}

// O(N^2) approach.
int bruteforce(vector<int>& ar) {
	int n = ar.size();
	int max_sum = INT_MIN;
	for(int i = 0; i < n; ++i) {
		int sum_so_far = 0;
		for(int j = i; j < n; ++j) {
			sum_so_far += ar[j];
			max_sum = max(max_sum, sum_so_far);
		}
	}
	return max_sum;
}

// Kadane's algorithm. O(n)
int solve(vector<int>& ar) {
	int n = ar.size();
	int max_sum = INT_MIN;
	int sum_so_far = 0;
	for(int i = 0; i < n; ++i) {
		sum_so_far += ar[i];
		max_sum = max(max_sum, sum_so_far);
		if(sum_so_far < 0) sum_so_far = 0;
	}
	return max_sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for(int& x : ar) cin >> x;
	cout << bruteforce(ar) << '\n';
	cout << solve(ar) << '\n';
}
