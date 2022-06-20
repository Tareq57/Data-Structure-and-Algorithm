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
#define inf 1e8
#define minf -1e15
#define pi 3.14159265
#define mod 1000000007
vector<pair<int, pii>> graph[10000];
vector<pii> res_net[10000];
int ss, tt;
int bfs(vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[ss] = -2;
    queue<int> q;
    q.push(ss);
    vector<int> vis(tt, 0);
    vis[ss] = 1;
    int flow = inf;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int des = graph[cur][i].f;
            if (vis[des] == 1)
                continue;
            vis[des] = 1;
            int fflow = graph[cur][i].s.f;
            flow = min(fflow, flow);
            if (des == tt)
            {
                parent[des] = cur;
                cout << "weldone" << endl;
                return flow;
            }
            q.push(des);
        }
    }
    return 0;
}
int maxflow()
{
    int flow = 0;
    vector<int> parent(tt);
    int new_flow = bfs(parent);
    while (new_flow)
    {
        flow += new_flow;
        int cur = tt;
        while (cur != ss)
        {
            int prev = parent[cur];
            graph[prev][cur].s.f += new_flow;
            cur = prev;
        }
    }

    return flow;
}
int residue_network(int max_flow)
{
    int mx_flow = 0, new_mx_flow = inf;

    while (new_mx_flow != 0 && max_flow > mx_flow)
    {
        for (int i = 0; i < tt; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                int src = i, des = graph[i][j].f;
                int cost = graph[src][j].s.s, flow = graph[src][j].s.f;
                // cout << "from " << src << "to" << des << " flow " << flow << " cost" << cost << endl;
                if (flow < cost)
                    res_net[src].pb(mp(des, cost - flow));
                if (flow > 0)
                    res_net[des].pb(mp(src, flow));
            }
        }
        new_mx_flow = maxflow();
        mx_flow = mx_flow + new_mx_flow;
        for (int i = 0; i < tt; i++)
        {
            res_net[i].clear();
        }
    }
    return mx_flow;
}

bool edmond_carp_algo(int x, int max_flow)
{

    // Let x wins the tournament
    int total_flow = residue_network(max_flow);
    if (total_flow > max_flow)
        return false;
    else
        return true;
}
int main()
{
    int n;
    cin >> n;
    ss = 0;
    tt = (n - 1) + (((n - 1) * (n - 2)) / 2) + 1;
    string team[n + 1];
    int w[n + 1], l[n + 1], r[n + 1], g[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> team[i] >> w[i] >> l[i] >> r[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int x = 1; x <= n; x++)
    {
        cout << "For Team " << team[x] << endl
             << endl;
        // creating graph
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (i != x)
            {
                int src = i;
                if (i > x)
                    src--;
                graph[src].pb(mp(tt, mp(0, w[x] + r[x] - w[i])));
                // cout << src << " " << w[x] + r[x] - w[i] << endl;
                // cout << "inner Loop: " << cout << "from " << src << "to" << graph[src][graph[src].size() - 1].f << " flow " << graph[src][graph[src].size() - 1].s.f << endl;
                if (w[x] + r[x] - w[i] < 0)
                {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok)
        {
            cout << team[x] << " is eliminated." << endl;
            for (int i = 0; i < tt; i++)
            {
                graph[i].clear();
            }
            continue;
        }

        int node = n, max_flow = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (i != x && j != x)
                {
                    graph[ss].pb(mp(node, mp(0, g[i][j])));
                    int src1 = i, src2 = j;
                    if (i > x)
                    {
                        src1--;
                    }
                    if (j > x)
                        src2--;
                    graph[node].pb(mp(src1, mp(0, inf)));
                    graph[node].pb(mp(src2, mp(0, inf)));
                    max_flow += g[i][j];
                    node++;
                }
            }
        }
        ok = edmond_carp_algo(x, max_flow);
        cout << ok << endl;
        if (!ok)
        {
            cout << team[x] << " is eliminated." << endl;
        }
        for (int i = 0; i < tt; i++)
        {
            graph[i].clear();
        }
    }
}
