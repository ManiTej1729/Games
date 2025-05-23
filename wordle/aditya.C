#include <bits/stdc++.h>
using namespace std;

void dijekstra(vector<pair<long long int, long long int>> adj[], long long int distance[], long long int direct[], long long int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    distance[1] = 0;
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            if (it.first + dist <= distance[it.second])
            {
                // cout << "For node " << it.second << " " << it.first + dist << distance[it.second];
                if (distance[it.second] != LLONG_MAX)
                {
                    direct[it.second] = 0;
                }
                distance[it.second] = dist + it.first;
                pq.push({distance[it.second], it.second});
            }
        }
    }
}

int main()
{
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<pair<long long int, long long int>> adj[n + 1];
    vector<long long int> fiberadj[n + 1];

    long long int a, b, c;
    for (long long int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    for (long long int i = 0; i < k; i++)
    {
        cin >> b >> c;
        adj[1].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, 1));
        fiberadj[b].push_back(c);
    }
    long long int direct[n + 1];
    long long int distance[n + 1];
    for (long long int i = 1; i <= n; i++)
    {
        distance[i] = LLONG_MAX;
        direct[i] = 1;
        sort(adj[i].begin(), adj[i].end());
    }
    dijekstra(adj, distance, direct, n);
    // for(long long int i = 1; i <= n; i++){
    //     cout << distance[i] << " ";
    // }
    long long int count = 0;
    for (long long int i = 2; i <= n; i++)
    {
        long long int tracker = -1;
        for (auto it : fiberadj[i])
        {
            if (tracker != -1 && it != tracker)
            {
                count--;
                tracker = -1;
            }
            if (it > distance[i])
            {
                count++;
            }
            else
            {
                if (direct[i] == 0)
                {
                    long long int countFiberAdj = std::count(fiberadj[i].begin(), fiberadj[i].end(), it);
                    long long int countAdj = std::count_if(adj[1].begin(), adj[1].end(), [&](const auto &pair)
                                                 { return pair.first == it && pair.second == i; });
                    if (countAdj != countFiberAdj)
                    {
                        count++;
                    }
                    else
                    {
                        tracker = it;
                        count++;
                    }
                }
            }
        }
        if (tracker != -1)
        {
            count--;
            tracker = -1;
        }
    }
    cout << count;
}