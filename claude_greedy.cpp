/*Link - https://leetcode.com/discuss/post/8261885/anthropic-claude-swe-interview-ctc-350k-pw0qe/ 

P1 :- Selection of subset of rows in optimal fashion 

P2 :- Given s1,s2,s3,s4,s5,....,sm -> find maximum value of the M-equations ; 

Brute Force - Way :- O(M^2) 


Eq(1) -> T - M*s1

Eq(M) -> s[m]*M - T 

Claim :- Answer is Max(Eq(1),Eq(M)) -> the middle equations don’t matter because the f(i) is a valley graph 

We will prove it by EAL(Exchange Argument Lemma) 

-> We come up with formula of f(i) as shown in the video recording 

-> F(i+1) - F(i) ⇒ (2*i - M)*(A[i+1]-A[i]) 
(A[i+1]>=A[i]) 

-> F(i+1) - F(i) => (2*i-M)*(Positive_value) 

C-1 : If i < M/2; 

-> F(i+1) - F(i) => -ve
-> F(i+1) - F(i) <=0 
-> F(i+1) <= F(i) 

C-2 : If i > M/2; 

-> F(i+1) - F(i) => +ve 
-> F(i+1)>=F(i)

—-----------------------------------------------------------------
How to decide which subset of rows should be selected? 

-> We cannot directly decide it 

-> All we know is that final answer is :- max(T-M*s1,sm*M-T) 

-> Let us assume a case -> that there exists a matrix where after selecting a subset of rows best answer is T-M*s1 (Assume T-M*s1>sm*M-T)
 

-> In this case ; we will only select those rows ; 

-> a1 + a2 + a3 + ……. + am - m*a1 >= 0 

-> Still while doing this -> you need know which sj is supposed to the smallest 

-> We will do this algorithm assuming that what if s1 was the smallest value -> we do the algorithm for this case and find the answer 

-> Now assume what if the final best answer has s2 as the smallest sum column value of the subset of rows selected -> so find the answer for this case..

-> and so on……. 

TC :- O(N*M*M)

Optimization :- Pre-calculate the sum of each row 

—----------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    vector<long long> rowSum(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            rowSum[i] += a[i][j];
        }
    }

    long long ans = 0;

    // Case 1 : column j is the minimum column
    for (int j = 0; j < m; j++) {
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            long long contrib = rowSum[i] - 1LL * m * a[i][j];

            if (contrib > 0)
                cur += contrib;
        }

        ans = max(ans, cur);
    }

    // Case 2 : column j is the maximum column
    for (int j = 0; j < m; j++) {
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            long long contrib = 1LL * m * a[i][j] - rowSum[i];

            if (contrib > 0)
                cur += contrib;
        }

        ans = max(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}

/*Interview explanation (very short)
The function over sorted column sums is valley-shaped, so only the two boundary equations matter.
Hence answer is max(T - M*smin, M*smax - T).
Fix a column j as the minimum column and compute each row's contribution rowSum - M*a[i][j].
Fix a column j as the maximum column and compute each row's contribution M*a[i][j] - rowSum.
For a fixed column, rows are independent, so include only rows with positive contribution. Take the maximum over all columns.

Complexity: O(N * M) per pass, total O(2 * N * M) = O(N * M).
(The extra M from the explanation disappears because each column is processed once and each row once.)*/