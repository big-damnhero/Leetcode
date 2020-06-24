//https://leetcode.com/problems/minimum-cost-for-tickets/


class Solution {

public:
    int cost[3],n,dp[400];
    vector<int> ar;
    int f(int i )
    {
        if(i==n)
        {
            return 0;
        }
        int &res = dp[i];
        if(res!=-1)
            return res;
        res = f(i+1)+cost[0];
        int temp=i;
        while(temp<n and ar[temp]<ar[i]+7)
        {
            temp++;
        }
        res = min(res,cost[1]+f(temp));
        temp = i;
        while(temp<n and ar[temp]<ar[i]+30)
        {
            temp++;
        }
        
        res = min(res,cost[2]+f(temp));
        
        return res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        memset(dp,-1,sizeof(dp));
        ar = days;
        n = days.size();
        for(int i=0;i<3;i++)
            cost[i] = costs[i];
        
        return f(0);
        
    }
};
