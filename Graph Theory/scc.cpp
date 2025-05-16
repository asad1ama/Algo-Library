struct DirectedGraph
{
    int n;
    vector<vector<int>> g, gr;
    vector<bool> used;
    vector<int> ord, comp;

    vector<int> compOf;
    int nc;

    vector<int> indegree, source;

    DirectedGraph(int _n) : n(_n)
    {
        nc = 0;
        compOf = vector<int>(n);
        g = vector<vector<int>>(n);
        gr = vector<vector<int>>(n);
        indegree = vector<int>(n);
        source = vector<int>(n);
    }

    void add_edge(int i, int j)
    {
        g[i].push_back(j);
        gr[j].push_back(i);
    }

    void init()
    {
        for (int i = 0; i < n; ++i)
        {
            sort(begin(g[i]), end(g[i]));
            sort(begin(gr[i]), end(gr[i]));
            g[i].erase(unique(begin(g[i]), end(g[i])), end(g[i]));
            gr[i].erase(unique(begin(gr[i])), end(gr[i]));
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j : g[i])
            {
                ++indegree[j];
            }
        }
        for (int i = 0; i < n; ++i)
            source[i] = indegree[i] == 0;
    }

    void dfs1(int v)
    {
        used[v] = true;
        for (auto a : g[v])
        {
            if (!used[a])
                dfs1(a);
        }
        ord.push_back(v);
    }

    void dfs2(int v)
    {
        used[v] = true;
        comp.push_back(v);
        for (auto a : gr[v])
        {
            if (!used[a])
                dfs2(a);
        }
    }

    void findSCCs()
    {
        ord.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
                dfs1(i);
        }
        used.assign(n, false);
        for (int i = 0; i < n; ++i)
        {
            int v = ord[n - 1 - i];
            if (!used[v])
            {
                dfs2(v);
                for (int a : comp)
                {
                    compOf[a] = nc;
                }
                nc++;
                comp.clear();
            }
        }
    }

    pair<DirectedGraph, vector<int>> createCondensationGraph()
    {
        findSCCs();
        DirectedGraph ret(nc);
        for (int i = 0; i < n; ++i)
        {
            int c = compOf[i];
            for (int j : g[i])
            {
                int d = compOf[j];
                if (c != d)
                {
                    ret.add_edge(c, d);
                }
            }
        }
        ret.init();
        return {ret, compOf};
    }
};