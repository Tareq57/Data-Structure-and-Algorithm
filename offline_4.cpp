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
#define pii pair<int, int>
#define f first
#define s second
#define up upper_bound
#define lp lower_bound
#define pq priority_queue
#define pdi pair<ll, pll>
#define inf 1e7
#define minf -1e15
#define pi 3.14159265
#define mod 1000000007
vector<int> graph[1000];
int capacity[1000][1000], flow[1000][1000];
string team[1000];
int w[1000], l[1000], r[1000], g[1000][1000];
int ss, tt;
int bfs(vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[ss] = -2;
    queue<pii> q;
    q.push(mp(ss, INT_MAX));

    while (!q.empty())
    {
        int cur = q.front().f;
        int fflow = q.front().s;
        q.pop();

        for (int next : graph[cur])
        {
            if (parent[next] == -1 && flow[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(fflow, flow[cur][next]);
                if (next == tt)
                    return new_flow;
                q.push(mp(next, new_flow));
            }
        }
    }

    return 0;
}

int edmond_carp_algo(int x)
{
    int fflow = 0;
    vector<int> parent(tt + 1);
    int new_flow;

    while (new_flow = bfs(parent))
    {
        fflow += new_flow;
        int cur = tt;
        while (cur != ss)
        {
            int prev = parent[cur];
            flow[prev][cur] -= new_flow;
            flow[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return fflow;
}
void dfs(int p, int n, vector<bool> &visited)
{
    visited[p] = true;
    for (int i = 0; i < n; i++)
        if (flow[p][i] && !visited[i])
            dfs(i, n, visited);
}
void print(int x, int n)
{
    cout << team[x] << " is Eliminated." << endl;
    cout << "They can win at most " << w[x] << "+" << r[x] << " = " << w[x] + r[x] << " games" << endl;
    vector<int> reachable;
    vector<bool> visited(tt + 1, false);
    dfs(ss, tt, visited);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            reachable.pb(i);
            total += w[i];
        }
    }
    int remaining = 0;
    for (int i = 0; i < reachable.size(); i++)
    {
        for (int j = i + 1; j < reachable.size(); j++)
        {
            remaining += g[reachable[i]][reachable[j]];
        }
    }
    for (int i = 0; i < reachable.size(); i++)
    {
        cout << team[reachable[i]];
        if (i + 1 < reachable.size())
            cout << ",";
    }
    double avg = ((double)(total + remaining)) / reachable.size();
    cout << " have won a total of " << total << " games." << endl;
    cout << "They play each other " << remaining << " times." << endl;
    cout << "So on average, each team wins " << total + remaining << "/" << reachable.size() << " = " << avg << " games." << endl
         << endl;
}
int main()
{

    int n;
    cin >> n;
    ss = (n - 1) + (((n - 1) * (n - 2)) / 2) + 1;
    tt = (n - 1) + (((n - 1) * (n - 2)) / 2) + 2;

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        cin >> team[i] >> w[i] >> l[i] >> r[i];
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != x)
            {
                graph[i].pb(tt);
                flow[i][tt] = w[x] + r[x] - w[i];
                capacity[i][tt] = w[x] + r[x] - w[i];
                if (w[x] + r[x] - w[i] < 0)
                {
                    ok = false;
                    cout << team[x] << " is Eliminated." << endl;
                    cout << "They can win at most " << w[x] << "+" << r[x] << " = " << w[x] + r[x] << " games" << endl;
                    cout << team[i];
                    cout << " have won a total of " << w[i] << " games." << endl;
                    cout << "They play each other " << 0 << " times." << endl;
                    cout << "So on average, each team wins " << w[i] << "/" << 1 << " = " << w[i] << " games." << endl
                         << endl;
                    break;
                }
            }
        }
        if (ok == false)
            continue;

        int fflow = 0, node = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i != x && j != x)
                {
                    graph[ss].pb(node);
                    flow[ss][node] = g[i][j];
                    capacity[ss][node] = g[i][j];
                    graph[node].pb(i);
                    graph[node].pb(j);
                    flow[node][i] = inf;
                    flow[node][j] = inf;
                    capacity[node][i] = inf;
                    capacity[node][j] = inf;
                    fflow += g[i][j];
                    node++;
                }
            }
        }

        int max_flow = edmond_carp_algo(x);
        if (max_flow < fflow)
        {
            print(x, n);
        }

        for (int i = 0; i <= tt; i++)
        {
            graph[i].clear();
            for (int j = 0; j <= tt; j++)
            {
                flow[i][j] = 0;
                capacity[i][j] = 0;
            }
        }
    }
}
