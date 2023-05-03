#include "comm.h"


class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int>& managers, vector<int>& infotimes)
    {
        
    }
};


class Solution0
{
private:
    void tranverse(vector<vector<int>>& mat, int node, int time)
    {
        bool isleaf = true;
        for (int i = 0; i < employnum; ++i)
            if (mat[node][i] != -1)
                isleaf = false;
        if (isleaf)
        {
            if (time > totatime)
                totatime = time;
            return;
        }
        for (int i = 0; i < employnum; ++i)
        {
            if (mat[node][i] != -1)
                tranverse(mat, i, time+mat[node][i]);
        }
    }

private:
    int totatime = 0;
    int employnum = 0;

public:
    int numOfMinutes(int n, int headID, vector<int>& managers, vector<int>& infotimes)
    {
        vector<vector<int>> timemat(n, vector<int>(n, -1));
        for (int employee = 0; employee < n; ++employee)
        {
            if (employee == headID) continue;
            int manager  = managers[employee];
            int infotime = infotimes[manager];
            timemat[manager][employee] = infotime;
        }

        employnum = n;
        tranverse(timemat, headID, 0);
        return totatime;
    }
};


int main()
{
    Solution sol;
    vector<int> managers {2, 2, -1, 2, 2, 2};
    vector<int> infotimes{0, 0,  1, 0, 0, 0};
    cout << "Need time: " << sol.numOfMinutes(6, 2, managers, infotimes);
    return 0;
}
