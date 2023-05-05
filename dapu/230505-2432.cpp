#include "comm.h"

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>>& logs)
    {
        int maxtime = 0;
        int maxid = 501;
        for (int i = 0; i < logs.size(); ++i)
        {
            int time = i ? logs[i][1]-logs[i-1][1] : logs[i][1];
            if (time > maxtime)
            {
                maxtime = time;
                maxid = logs[i][0];
            }
            else if (time == maxtime)
            {
                int id = logs[i][0];
                maxid = id < maxid ? id : maxid;
            }
        }
        return maxid;
    }
};
