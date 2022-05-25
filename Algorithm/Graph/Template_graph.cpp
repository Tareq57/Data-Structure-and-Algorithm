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
bool marked[N];
vll power(ll n,ll p)
{
  ll pow=1;
  vll vec;
  for(ll i=0;i<p;i++)
  {
    vec.pb(pow);
    pow*=n;
  }
  return vec;
 
}
ll ceil(ll a,ll b)
{
  ll p=a/b;
  if(a%b)
  p++;
  return p;
}
vll Child[100];
vll Parent[100];


//BFS

// void BFS(ll p,ll n)    //Runtime O(V+E)
// {
//     vll visited(n+1,0);
//     queue<ll>q;
//     q.push(p);
//     visited[p]=1;
//     while(!q.empty())
//     {
//         ll x=q.front();
//         q.pop();
//         cout<<x<<" ";
//         for(ll i=0;i<Child[x].size();i++)
//         {
//             ll child=Child[x][i]; 
//             if(visited[child]==0)
//             {
//                 q.push(child);
//                 visited[child]=1;
//             }
//         }
//     }

// }

//DFS

vll vis(1000,0);
void DFS(ll p,stack<ll>& st)    //Runtime O(V+E)
{
    //cout<<p<<" ";
    vis[p]=1;
    
    for(ll i=0;i<Child[p].size();i++)
    {
        ll child=Child[p][i];
        if(vis[child]==0)
        {
            DFS(child,st);
        }
    }
    st.push(p);
    
}



//Undirected Cycle

// bool undirected_cycle(ll p,ll n)    //Runtime O(V+E)
// {
//     vll visited(n+1,0);
//     queue<ll>q;
//     q.push(p);
//     visited[p]=1;
//     while(!q.empty())
//     {
//         ll x=q.front();
//         q.pop();
//         for(ll i=0;i<Child[x].size();i++)
//         {
//             ll child=Child[x][i]; 
//             if(visited[child]==0)
//             {
//                 q.push(child);
//                 visited[child]=1;
//                 Parent[child]=x;
//             }
//             else
//             {
//                 if(Parent[child]!=x)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;

// }

// //Directed Cycle--->

// bool directed_cycle(ll n)
// {
//     queue<ll>q;
//     ll cnt=0;
//     vll visited(n+1,0);
//     for(ll i=1;i<=n;i++)
//     {
//         if(Parent[i].size()==0){
//             q.push(i);
//             cnt++;
//             visited[i]=1;
//         }
//     }
//     while(!q.empty())
//     {
//         ll x=q.front();
//         q.pop();
//         for(ll i=0;i<Child[x].size();i++)
//         {
//             ll child=Child[x][i];
//             Parent[child].pop_back();
//             if(Parent[child].size()==0 and visited[child]==0)
//             {
//                 q.push(child);
//                 visited[child]=1;
//                 cnt++;
//             }
//         }
//     }
//     if(cnt<n)
//     return true;
//     else return false;
// }


//Topological Sort

// void topological_sort(ll n)
// {
//      queue<ll>q;
//     ll cnt=0;
//     vll res;
//     vll visited(n+1,0);
//     for(ll i=1;i<=n;i++)
//     {
//         if(Parent[i].size()==0){
//             q.push(i);
//             cnt++;
//             visited[i]=1;
//         }
//     }
//     while(!q.empty())
//     {
//         ll x=q.front();
//         res.pb(x);
//         q.pop();
//         for(ll i=0;i<Child[x].size();i++)
//         {
//             ll child=Child[x][i];
//             Parent[child].pop_back();
//             if(Parent[child].size()==0 and visited[child]==0)
//             {
//                 q.push(child);
//                 visited[child]=1;
//                 cnt++;
//             }
//         }
//     }
//     if(cnt<n)cout<<-1<<endl;
//     else
//     for(auto p:res)cout<<p<<" ";
//     cout<<endl;
// }


//PATH--->


// void Path(ll src, ll des, ll n)   //Runtime O(V+E)
// {
//     vll visited(n+1,0);
//     queue<ll>q;
//     visited[src]=1;
//     q.push(src);
//     ll res=-1;
//     while(!q.empty())
//     {
//         ll x=q.front();
//         q.pop();
//         for(ll i=0;i<Child[x].size();i++)
//         {
//             ll child=Child[x][i];
//             if(child==des)
//             {
//                 res=child;
//                 break;
//             }
//             if(visited[child]==0)
//             {
//                 visited[child]=1;
//                 q.push(child);
//             }
//         }
//     }
//     if(res==-1)
//     cout<<-1<<endl;
//     else
//     {
//         vll path;
//         while(des!=src)
//         {
//             path.pb(des);
//             des=Parent[des];
//         }
//         path.pb(des);
//         reverse(path.begin(),path.end());
//         for(ll i=0;i<path.size();i++)cout<<path[i]<<" ";
//     }
// }
vll res;
void DFS_util(ll p,vll new_Child[])
{
    //cout<<p<<" ";
    vis[p]=1;
    res.pb(p);
    for(ll i=0;i<new_Child[p].size();i++)
    {
        ll child=new_Child[p][i];
        if(vis[child]==0)
        {
            DFS_util(child,new_Child);
        }
    }
    
}
void SCC(ll n)
{
    stack<ll>st;
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==0)
        DFS(i,st);
    }
    for(ll i=0;i<=n;i++)vis[i]=0;
    // Transpose
    vll new_child[n+1];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<Child[i].size();j++)
        {
            new_child[Child[i][j]].pb(i);
        }
    }
    while(!st.empty())
    {
        ll x=st.top();
        st.pop();
        if(vis[x]!=0)
        continue;
        DFS_util(x,new_child);
        if(res.size()<=1){
            res.clear();
            continue;
        }
        for(ll i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        res.clear();
    }
    
}
int main()
{
    //start
    ll n;
    cin>>n;
    ll ed;
    cin>>ed;
    // for(ll i=0;i<=n;i++)vis[i]=0;


    for(ll i=1;i<=ed;i++)
    {
        ll num1,num2;
        cin>>num1>>num2;
        Child[num1].pb(num2);
        Parent[num2].pb(num1);
    }
    SCC(n);
}