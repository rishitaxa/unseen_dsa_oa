/*PROBLEM STORY

- There are N employees.
- Employee i originally sits at position i.
- A[i] = productivity of employee i.
- We can rearrange all employees exactly once.
- Each employee gets one seat and each seat gets one employee.

Contribution of an employee:

If employee originally at position i is moved to position j,

Contribution = A[i] * |i - j|

Total Score:

Σ A[i] * |i - final_position(i)|

Goal:
Maximize the total score.

STORY TO CODE 
1. Sort all employees in decreasing order of productivity.

2. Let dp[l][r] = maximum score after placing the first (l+r)
   highest-productivity employees,
   where l seats are occupied from the left
   and r seats are occupied from the right.

3. Current employee:
      k = l + r
      (value, pos) = v[k]

4. Two choices:
   a) Place at leftmost free seat (l+1)
      dp[l+1][r] =
      max(dp[l+1][r],
          dp[l][r] + value * abs(pos-(l+1)))

   b) Place at rightmost free seat (N-r)
      dp[l][r+1] =
      max(dp[l][r+1],
          dp[l][r] + value * abs(pos-(N-r)))

5. Base Case:
      dp[0][0] = 0

   Answer:
      max(dp[l][N-l]) for all l

   Complexity:
      O(N²)
      
INPUT
3
5 2 8
OUTPUT
26
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);

    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<pair<long long,int>> v;

    for(int i=0;i<N;i++) {
        v.push_back({A[i], i + 1}); // value, original position
    }

    sort(v.rbegin(), v.rend());

    vector<vector<long long>> dp(
        N + 1,
        vector<long long>(N + 1, -1)
    );

    dp[0][0] = 0;

    for(int l=0;l<=N;l++) {

        for(int r=0;r<=N;r++) {

            if(dp[l][r] == -1) continue;

            int k = l + r;

            if(k == N) continue;

            auto [val, pos] = v[k];

            // place on left
            dp[l+1][r] = max(
                dp[l+1][r],
                dp[l][r] +
                1LL * val * abs(pos - (l + 1))
            );

            // place on right
            dp[l][r+1] = max(
                dp[l][r+1],
                dp[l][r] +
                1LL * val * abs(pos - (N - r))
            );
        }
    }

    long long ans = 0;

    for(int l=0;l<=N;l++) {
        ans = max(ans, dp[l][N-l]);
    }

    cout << ans << '\n';
}