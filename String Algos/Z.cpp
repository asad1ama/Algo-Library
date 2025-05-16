template <class P, class Q>
class String
{
public:
    vector<P> Z(Q &a)
    {
        int n = size(a);
        vector<P> z(n);
        for (int i = 1, l = 0, r = 0; i < n; i++)
        {
            if (i <= r)
                z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < n and a[i + z[i]] == a[z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
                r = z[i] + i - 1, l = i;
        }
        return z;
    }
    vector<P> KMP(Q &a)
    {
        int n = size(a);
        vector<P> p(n);
        for (int i = 1; i < n; i++)
        {
            int j = p[i - 1];
            while (j > 0 and a[i] != a[j])
                j = p[j - 1];
            p[i] = (j += (a[i] == a[j]));
        }
        return p;
    }
};