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
    freopen("B-large-practice.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T,y;cin>>T;
    loop1(t,T){
        int n;string dir;
        cin>>n>>dir;int matrix[n][n];

        loop(i,n){
            loop(j,n){
                cin>>matrix[i][j];
            }
        }
        if(dir=="up"){
            loop(col,n){
                vector<int> column;
                loop(row,n){
                    if(matrix[row][col])column.pb(matrix[row][col]);
                }
                int siz=column.size(),i=1,tot_size;
                vector<int> ans;
                int prev=-1;
                loop(i,siz){
                    if(prev==-1){
                        ans.pb(column[i]);
                        prev=column[i];
                    }
                    else if(prev==column[i]){
                        ans.pop_back();
                        ans.pb(2*column[i]);
                        prev=-1;
                    }
                    else{
                        prev=column[i];
                        ans.pb(prev);
                    }
                }
                tot_size=ans.size();
                loop(i,n){
                    if(i<tot_size)
                        matrix[i][col]=ans[i];
                    else
                        matrix[i][col]=0;
                }

            }
        }
        else if(dir=="down"){
                loop(col,n){
                    vector<int> column;
                    for(int row=n-1;row>=0;row--){
                        if(matrix[row][col])
                        column.pb(matrix[row][col]);
                    }

                    int siz=column.size(),i=1,tot_size;
                    vector<int> ans;
                    int prev=-1;
                    loop(i,siz){
                        if(prev==-1){
                            ans.pb(column[i]);
                            prev=column[i];
                        }
                        else if(prev==column[i]){
                            ans.pop_back();
                            ans.pb(2*column[i]);
                            prev=-1;
                        }
                        else{
                            prev=column[i];
                            ans.pb(prev);
                        }
                    }
                    tot_size=ans.size();
                    for(int i=0;i<n;i++){
                        if(i<tot_size){
                            matrix[n-1-i][col]=ans[i];
                        }
                        else
                        matrix[n-1-i][col]=0;
                    }

                }

        }
        else if(dir == "left"){
           loop(row,n){
                vector<int> ro;
                loop(i,n){
                    if(matrix[row][i])ro.pb(matrix[row][i]);
                }
                int siz=ro.size(),i=1,tot_size;
                vector<int> ans;
                int prev=-1;
                loop(i,siz){
                    if(prev==-1){
                        ans.pb(ro[i]);
                        prev=ro[i];
                    }
                    else if(prev==ro[i]){
                        ans.pop_back();
                        ans.pb(2*ro[i]);
                        prev=-1;
                    }
                    else{
                        prev=ro[i];
                        ans.pb(prev);
                    }
                }
                tot_size=ans.size();
                loop(i,n){
                    if(i<tot_size){
                        matrix[row][i]=ans[i];
                    }
                    else{
                        matrix[row][i]=0;
                    }
                }


           }
        }
        else{
            loop(row,n){
                vector<int> ro;
                for(int i=n-1;i>=0;i--){
                    if(matrix[row][i])ro.pb(matrix[row][i]);
                }
                int siz=ro.size(),i=1,tot_size;
                vector<int> ans;
                int prev=-1;
                loop(i,siz){
                    if(prev==-1){
                        ans.pb(ro[i]);
                        prev=ro[i];
                    }
                    else if(prev==ro[i]){
                        ans.pop_back();
                        ans.pb(2*ro[i]);
                        prev=-1;
                    }
                    else{
                        prev=ro[i];
                        ans.pb(prev);
                    }
                }
                tot_size=ans.size();
                loop(i,n){
                    if(i<tot_size){
                        matrix[row][n-1-i]=ans[i];
                    }
                    else{
                        matrix[row][n-1-i]=0;
                    }
                }


           }


        }
        printf("Case #%d:\n",t);


        loop(i,n)
        {
            loop(j,n){
                cout<<matrix[i][j]<<" ";
            }nw;
        }

    }
}
