#include "../inc/ford-fulkerson.h"


Graph FordFulkerson::Run(Graph g)
{
    while(GetPath(g,0,4)) {
        AugmentPath(g,0,4);
    }

    g.ApplyToV([](int a) -> int { return 0; });

    return g;
}

void FordFulkerson::AugmentPath(Graph &g, const int source, const int sink)
{
    int x = sink;
    int min = g.E[g.V[x]][x];

    while (g.V[x] != x)
    {
        int u = x;
        int v = g.V[x];

        if ( min > g.E[v][u] ) {
            min = g.E[v][u];
        }

        x = g.V[x];
    }

    x = sink;

    while (g.V[x] != x) {

        int u = x;
        int v = g.V[x];

        g.E[v][u] -= min;
        g.E[u][v] += min;

        x = g.V[x];
    }
}

bool FordFulkerson::GetPath(Graph &g, const int source, const int sink)
{
    g.ApplyToV( [](int a) -> int { return -1; });

    std::queue<int> q;

    q.push(source);
    g.V[source] = source;

    while(!q.empty()) {
        const int u = q.front();
        q.pop();

        for (int v = 0; v < g.VertexCount; ++v)
        {
            if ( g.E[u][v] != 0 && g.V[v] == -1 ) {
                q.push(v);
                g.V[v] = u;

                if (v == sink) {
                    return true;
                }
            }
        }
    }

    return false;
}