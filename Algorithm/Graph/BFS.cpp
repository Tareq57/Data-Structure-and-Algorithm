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
void BFS(vector<int> vec[], int p,int n)
{
    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(p);
    visited[p] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
         cout << x << " ";
        for (int i = 0; i < vec[x].size(); i++)
        {
            if (visited[vec[x][i]] == 0)
            {
                q.push(vec[x][i]);
                visited[vec[x][i]] = 1;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec[n + 1];
    for (int i = 0; i < n; i++)
    {
        int num1, num2;
        cin >> num1>>num2;
        vec[num1].pb(num2);
        vec[num2].pb(num1);
    }
    int p;
    cin>>p;
    BFS(vec,p,n);
}
