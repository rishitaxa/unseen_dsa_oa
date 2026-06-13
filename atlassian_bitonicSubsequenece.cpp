/*A subsequence is called a bitonic subsequence if it is first increasing and then decreasing.
find the number of non-empty bitonic subsequences in an array.*/
/*tc- o(nlogn) or o(n)*/
/*-> How many mountain sequences are possible whose peak is a[i]? 
-> Calculate this for each i from 1 to N
-> We can differentiate the subsets based on what their peak is -> Count all the mountain subsets whose peak is a[1](Not possible)
-> Count all the mountain subsets whose peak is a[2]
-> Count all the mountain subsets whose peak is a[3]
-> Count all the mountain subsets whose peak is a[n](Not possible) 
-> A mountain subset whose peak is index “i” is formed of two parts. Left part & right part 
-> Left decreasing part & right decreasing part 
-> All mountain subsequences have some element(a[i]) as their peak 
-> x = number of left decreasing subsequences ending at index “i” 
-> y = number of right decreasing subsequences starting at index “i” 

-> answer = (x-1)*(y-1) if a[i] is considered as the peak of the mountain sequences being calculated. 

-> dp[i] = number of left-decreasing subsequences ending at index “i”

-> dp2[i] = number of right-decreasing subsequences starting at index “i” 

TC :- O(N^2)
—-----------------------------------------------------------------

Optimization :- 

DP[number] -> count of decreasing subsequences from the left→ right part such that last element of all those subsets is “number” 

If a[i1] ⇒ number;
& a[i2] => number; 
 
dp[i1] + dp[i2] = DP[number] 

If a[k] = g ; 
-> dp[k] = DP[g-1] + DP[g-2] + ….. + DP[1] 

DP2[number] -> count of decreasing subsequences from the right->left part such that last element of all those subsets is “number” 
TC :- O(200*N) ⇒ O(N) with a big constant 

*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<long long> dp(N + 1, 0);
    vector<long long> dp2(N + 1, 0);
    long long DP[201] = {0};
    long long DP2[201] = {0};
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = 1; j <= A[i] - 1; j++) {
            dp[i] += DP[j];
        }
        int number = A[i];
        DP[number] += dp[i];
    }
    for (int i = N; i >= 1; i--) {
        dp2[i] = 1;
        for (int j = 1; j <= A[i] - 1; j++) {
            dp2[i] += DP2[j];
        }
        int number = A[i];
        DP2[number] += dp2[i];
    }
    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        answer += (dp[i] - 1) * (dp2[i] - 1);
    }
    cout << answer << '\n';
    return 0;
}
/*input n = 5 
array = 1 2 3 2 1
output = 11 */
