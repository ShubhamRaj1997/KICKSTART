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
int sides[40];
int tile_finised=0;

void recur(int a,int b){
    if(a<b)swap(a,b);
    if(a==0 || b==0) return ;
    /// max_size tile that can be fitted is b
    int tile=(int)log2(b);
    while(tile>=0 && sides[tile]==0)tile--;
    if(tile==-1)return ;
    /// found tile
    tile_finised++;
    sides[tile]--;
    int x=1<<tile;
    recur(a-x,b); /// remove from larges side
    recur(b-x,x);
}

int main(){
    freopen("D-large-practice.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int T,y;cin>>T;
    loop1(t,T){
        tile_finised=0;
        memset(sides,0,sizeof(sides));
        int n,m;cin>>n>>m;
        loop(i,n){
            cin>>y;sides[y]++;
        }
        int tiles_bought=0;
        for(;tile_finised<n;){
            tiles_bought++;
            recur(m,m);
        }
        printf("Case #%d: %d\n",t,tiles_bought);
    }
}
