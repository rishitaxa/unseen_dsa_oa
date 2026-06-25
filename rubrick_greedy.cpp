/*# Balanced Suffix Rearrangement

Rubrik apne storage engine mein strings ko metadata signatures ki tarah use karta hai. Har signature string S ke liye ek balance rule define kiya gaya hai.

Aapko ek string S aur ek integer K diya gaya hai. String ke characters ko rearrange karke ek nayi string T banani hai.

T valid tab hogi jab T ke har suffix mein present kisi bhi do distinct characters ki frequencies ka difference K se zyada na ho.

Agar multiple valid rearrangements possible hon, to lexicographically smallest rearrangement print karo. Agar koi valid rearrangement exist nahi karta, to -1 print karo.

## Input Format

* First line contains T, number of test cases.
* For each test case:

  * First line contains N and K.
  * Second line contains string S.

## Output Format

For each test case, print:

* Lexicographically smallest valid rearrangement of S, or
* -1 if no valid rearrangement exists.

## Example

Input:
1
7 2
abcbcac

Output:
abcabcc

## Story to Code (Hinglish)

Observation: Har suffix mein frequencies balanced rehni chahiye. Jab hum answer left se right build karte hain, to kisi character ko choose karne ke baad bachi hui frequencies future suffix ko represent karti hain.

Greedy approach use karo: Har position par lexicographically smallest character try karo jise lene ke baad remaining frequencies ka max-min difference K se zyada na ho. Jo pehla valid character mile, usse answer mein add kar do.
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 

int main() {
    
    ll t;
    cin>>t;
    while(t--){
        ll n,K; cin>>n>>K; 
        unordered_map <char,ll> k; 
        string s;cin>>s; 
        ll maxi = -1e18 ; 
        ll mini = 1e18 ;
        ll good = 0 ; 
        for(ll i=0;i<=n-1;i++){
            k[s[i]]++;
        }
        
        for(auto itr=k.begin();
                    itr!=k.end();itr++){
                        ll y = itr->second; 
                        maxi = max(maxi,y);
                        mini = min(mini,y);
                    }
                    
        
        
        
        if(maxi-mini<=K){
            good = 1; 
        }
        
        if(good==0){
            cout<<"-1"; 
        }else{
        	
        	
        	
        	 string answer =""; 
        ll i = 0;  
        while(i<=n-1){
            char c='a';
            char ans='.';
            //cout<<k['a']<<" "<<k['b']<<" "<<k['c']<<"\n";
            while(c<='z'){
                if(k.find(c)!=k.end() && k[c]>=1){
                	
                	
                    k[c]--;
                    
                    
                    ll mi = 1e18; 
                    ll ma = -1e18;
                    
                    for(auto itr=k.begin();
                    itr!=k.end();itr++){
                        ll y = itr->second; 
                        mi=min(mi,y); 
                        ma=max(ma,y); 
                    }
                    k[c]++;
                    
                    
                    
                    if(ma-mi<=K){
                        ans = c ; 
                        c='z'; c++;
                    }
                }
            c++;}
            
            answer.push_back(ans); 
            k[ans]--;
            i++;}
       
        	
        	
        	
        	cout<<answer;
        	
        	
        	
        	
        	
        	
        	
        	
        	
        }
        cout<<"\n";
    
    }

    return 0; 
}
