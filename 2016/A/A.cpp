#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define loop(i,n) for(int i=0;i<n;i++)
#define loop1(i,n) for(int i=1;i<=n;i++)
#define revloop(i,n) for(int i=n-1;i>=0;i--)
#define revloop1(i,n) for(int i=n;i>=1;i--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vpii vector< pair<int,int> >
#define ff first
#define ss second
#define print(x) printf("%.9Lf\n",x)
#define MOD 1000000007
#define MAX 200005
#define MAX6 500000
#define MAX3 1005
#define nw cout<<endl
#define lc 2*node+1
#define rc 2*node+2
#define PRINT(v) for(int i=0;i!=v.size();i++)cout<<v[i]<<" "
#define modInverse(x) power(x,MOD-2)
using namespace std;
ll dp[65];
bool rec(int sn,ll k){
    if(k<dp[sn-1]){
        return rec(sn-1,k);
    }
    if(k==dp[sn-1])
        return 0;
    return !rec(sn-1,1LL*2*dp[sn-1]-k);
}
int main(){
    int T,x,y,k;
    freopen("A-large-practice.in","r",stdin);
    freopen("A.out","w",stdout);
    dp[0]=0;
    for(int i=1;i<61;i++){
        dp[i]=(dp[i-1]*2+1);
    }
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        ll k;cin>>k;k--;
        for(int i=0;i<61;i++){
            if(dp[i]>k){
               printf("Case #%d: %d\n",tc,rec(i,k));
               break;
            }
        }

    }

}
