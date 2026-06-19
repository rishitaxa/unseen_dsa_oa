/*Stripe's analytics team is analyzing relationships between values stored in an array. You are given an array A of N non-negative integers and a non-negative integer K. Your task is to determine the number of pairs of indices (i, j) such that 1 ≤ i < j ≤ N and the following condition holds:

3(Ai | Aj) − (Ai & Aj) − Ai − Aj + (Ai ⊕ Aj)²
− ((Ai | Aj) − (Ai & Aj))²

* (Ai ⊕ Aj) + (Ai & Aj) + (Ai | Aj)
  = K + Aj + 2(Ai ⊕ Aj)

where:

* (Ai | Aj) denotes the bitwise OR operation.
* (Ai & Aj) denotes the bitwise AND operation.
* (Ai ⊕ Aj) denotes the bitwise XOR operation.

For each test case, output the total number of valid pairs satisfying the above equation.
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     ll t;
     cin>>t;
     while(t--)
     {
        ll x;
        cin>>x;
        ll k;
        cin>>k;

        vector<ll>a(n+1,0);
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        unordered_map<ll,ll>mp;
        k[a[n]]++;
        ll ans=0;
        for(ll i=n-1;i>=1;i--)
        {
            int y = k-a[i];
            if(y>=0)
            {
                 ll aj =(a[i]^y);
                 ans += ans+k[aj];
            }
            k[a[i]]++;
        }
        cout<<ans<<endl;
     }
}