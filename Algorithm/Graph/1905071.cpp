//BISMILLAH
//RABBI JIDNI ILMA
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ull  unsigned long long
#define vll  vector <long long>
#define pll pair <long long,long long>
#define f first
#define s second
#define up upper_bound
#define lp lower_bound
#define pq priority_queue
#define inf 1e10
#define minf -1e15
#define pi 3.14159265
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);
#define N 1000000
ll dist[101][101];
void matrix_multiplication(ll n)
{
   for(ll p=1;p<=n;p++)
   {
       for(ll q=1;q<=n;q++)
       {
           for(ll i=1;i<=n;i++)
           {
               if(dist[p][i]!=inf && dist[i][q]!=inf)
               {
                   dist[p][q]=min(dist[p][q],dist[p][i]+dist[i][q]);
               }
           }
       }
   }
}
int main()
{
    ll n,ed;
    cin>>n>>ed;
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            dist[i][j]=inf;
        }
    }
    for(ll i=0;i<ed;i++)
    {
        ll src,des,cost;
        cin>>src>>des>>cost;
        dist[src][des]=cost;
    }
    for(ll i=1;i<=n;i++)dist[i][i]=0;
    matrix_multiplication(n);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(dist[i][j]==inf)
            cout<<"INF ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}