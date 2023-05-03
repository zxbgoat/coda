#include "comm.h"

class Solution
{
public:
    vector<int> PowerfulIntegers(int x, int y, int bound)
    {
        if (bound==0 || bound==1)
            return {};
        set<int> ret;
        if (x == 1 && y == 1)
            return {2};
        if (x < y) swap(x, y);
        int i = 0, parx = pow(x, i);
        while (parx <= bound)
        {
            if (y == 1)
            {
                if (parx+1 <= bound)
                    ret.insert(parx+1);
            }
            else
            {
                int j = 0, pary = pow(y, j);
                while (pary <= bound-parx)
                {
                    ret.insert(parx + pary);
                    j += 1;
                    pary = pow(y, j);
                }
            }
            i += 1;
            parx = pow(x, i);
        }
        return vector<int>(ret.begin(), ret.end());
    }
};

class Solution0
{
public:
    /*
     *  A wrong solution, as in the line 50 and line 52,
     *  the statement before the first simicolon in the for
     *  syntax, will only be executed onece, so the parx and
     *  pary will be stable, and the loop will never break.
     */
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        if (bound==0 || bound==1)
            return {};
        set<int> ret;
        for (int i=0, parx=pow(x,i); parx < bound; ++i)
        {
            if (y == 1)
            {
                if (parx+1 < bound)
                    ret.insert(parx+1);
                break;
            }
            for (int j=0, pary=pow(y,j); pary <= bound-parx; ++j)
                ret.insert(parx+pary);
        }
        }
        return vector<int>(ret.begin(), ret.end());
};

int main()
{
    Solution solu;
    vector<int> ret = solu.PowerfulIntegers(2, 3, 10);
    for (auto r: ret)
        cout << r << " ";
}
