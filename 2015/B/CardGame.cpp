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
int a[101];
int dp[101][101];
int n,K;
int solve(int i, int j){
    if(j<i)return 0;
    if(j-i<2){
        return j-i+1;}
    if(dp[i][j]!=-1)return dp[i][j];
    int ret = 1+solve(i+1,j);
    for(int k=i+1;k<=j;k++){
        if(a[k]-a[i]==K){
            for(int l=k+1;l<=j;l++){
                if(a[l]-a[k]==K){
                    if(solve(i+1,k-1)==0 && solve(k+1,l-1)==0)
                        ret=min(ret,solve(l+1,j));
                }
            }
        }
    }
    return dp[i][j]=ret;

}
int main(){
    freopen("C-large-practice.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T,y;cin>>T;
    loop1(t,T){
        cin>>n>>K;
        loop1(i,n)cin>>a[i];
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",t,solve(1,n));
    }
}


