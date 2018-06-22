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
#define INF 1000000007
#define MOD 163577857
#define MAX 100005
#define MAX6 1000001
#define nw cout<<endl
#define PRINT(v) for(int i=0;i!=v.size();i++)cout<<v[i]<<" "
using namespace std;
int dp[101][101],M;
ll solve(int n,int m){
    if(!n){
        if(!m)return 1;
        return 0;
    }
    if(dp[n][m]!=-1)return dp[n][m];
    ll ans;
    ans=((solve(n-1,m)*(M-m))%INF+(solve(n-1,m-1)*m)%INF)%INF;
    return dp[n][m]=ans;
}
int main(){
    freopen("A-large-practice.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T,y;cin>>T;
    loop1(t,T){
        int n,m;

        cin>>m>>n;
        M=m;
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",t,solve(n,m));
    }
}


