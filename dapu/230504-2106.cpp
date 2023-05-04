#include "comm.h"


class Solution
{
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k)
    {
        int n = fruits.size();
        vector<int> summ(n+1, 0);
        vector<int> idxs(n,   0);
        for (int i = 0; i < n; ++i)
        {
            summ[i+1] = summ[i] + fruits[i][1];
            idxs[i]   = fruits[i][0];
        }
        int ret = 0;
        for (int x = 0; x <= k/2; ++x)
        {
            int y = k - 2 * x;
            int l = startPos - x;
            int r = startPos + y;
            int s = lower_bound(idxs.begin(), idxs.end(), l) - idxs.begin();
            int e = upper_bound(idxs.begin(), idxs.end(), r) - idxs.begin();
            ret = max(ret, summ[e]-summ[s]);
            l = startPos - y;
            r = startPos + x;
            s = lower_bound(idxs.begin(), idxs.end(), l) - idxs.begin();
            e = upper_bound(idxs.begin(), idxs.end(), r) - idxs.begin();
            ret = max(ret, summ[e]-summ[s]);
        }
        return ret;
    }
};
