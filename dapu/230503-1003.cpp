#include "comm.h"


class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;
        if (s.size() % 3)
            return false;
        int idx = 1;
        stack<char> S;
        S.push(s[0]);
        while (idx < s.size())
        {
            if (s[idx] == 'c')
            {
                if (S.size() < 2)
                    return false;
                char prev = S.top();
                if (prev != 'b')
                    return false;
                S.pop();
                prev = S.top();
                if (prev != 'a')
                    return false;
                S.pop();
            }
            else
                S.push(s[idx]);
            idx += 1;
        }
        return S.empty();
    }
};
