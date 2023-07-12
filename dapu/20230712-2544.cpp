#include "comm.h"

class Solution
{
public:
    int alternateDigitSum(int n)
    {
        stack<int> vals;
        while (n)
        {
            vals.push(n%10);
            n /= 10;
        }
        int sum = 0;
        bool flag = true;
        while (vals.size())
        {
            int val = vals.top();
            sum += flag ? val : val*-1;
            vals.pop();
            flag = !flag;
        }
        return sum;
    }
};