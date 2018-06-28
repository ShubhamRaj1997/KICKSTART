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

int main(){
    freopen("A-large-practice.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T,y;cin>>T;
    loop1(t,T){
        string s;
        cin>>s;
        int n=s.length();
        int a[n]={0},b[n]={0};
        char ans[50+1];

        loop(i,n){
            a[i]=s[i]-'A';b[i]=-1;
        }

        bool got=1;
        b[1]=a[0];
        b[n-2]=a[n-1];
        if(n==2){
            printf("Case #%d: ",t);
            cout<<s[1]<<s[0];nw;continue;
        }
        for(int i=3;i<n;i+=2){
            b[i]=(a[i-1]-b[i-2]+26)%26;
        }
        for(int i=n-4;i>=0;i-=2){
            b[i]=(a[i+1]-b[i+2]+26)%26;

        }
        loop(i,n){
            if(b[i]==-1){
                got=0;break;
            }
            ans[i]='A'+b[i];
        }
        printf("Case #%d: ",t);
        if(got){
            loop(i,n)
                cout<<ans[i];
        }
        else
            cout<<"AMBIGUOUS";
        nw;
    }
}


