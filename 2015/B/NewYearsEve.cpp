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
double dp[401][401][401];
int main(){
    freopen("B-small-practice.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T,y;cin>>T;
    loop1(t,T){
        int B,L,N;cin>>B>>L>>N;
        memset(dp,0,sizeof(dp));
        dp[1][1][1]=B*3;
        loop1(l,L){
            loop1(row,l){
                for(int i=row;i>=1;i--){
                    int j=row-i+1;
                    if(dp[l][i][j]>=1){
                        double overflow=(dp[l][i][j]-1.0)/3.0;
                        dp[l+1][i][j]+=overflow;
                        dp[l+1][i+1][j]+=overflow;
                        dp[l+1][i][j+1]+=overflow;
                        dp[l][i][j]=1.0;
                    }
                }

            }
        }
        double ans;
        /// find Nth glass :)
        for(int row=1;row<=L;row++){
            for(int i=row;i>=1;i--){
                int j=row-i+1;
                N--;
                if(N==0){
                   ans=dp[L][i][j];
                   break;
                }
            }
        }


        printf("Case #%d: %.7f\n",t,ans*250.0);
    }
}


