// BISMILLAH
// RABBI JIDNI ILMA
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define vll vector<long long>
#define pll pair<long long, long long>
#define f first
#define s second
#define up upper_bound
#define lp lower_bound
#define pq priority_queue
#define inf 1e10
#define minf -1e15
#define pi 3.14159265
#define mod 1000000007
#define N 1000000
vector<int> visited(10000, 1);
void DFS(vector<int> vec[], int p,int n)
{
    
    cout<<p<<" ";
    visited[p]=0;
    for(int i=0;i<vec[p].size();i++)
    {
        if(visited[vec[p][i]]==1)
        {
            
            DFS(vec,vec[p][i],n);
        }
    }
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec[n+1];
    for (int i = 0; i < n; i++)
    {
        int num1, num2;
        cin >> num1>>num2;
        vec[num1].pb(num2);
        vec[num2].pb(num1);
    }
    int p;
    cin>>p;
    DFS(vec,p,n);
}
