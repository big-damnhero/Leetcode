//https://leetcode.com/problems/coin-change/


class Solution {
public:
    int dp[105][10005],n;
    int f(int i,long sum,int amount,vector<int>& coins)
    {
        if(i==n and sum==amount)
            return 0;
        if(i>=n or sum>amount)
            return 1000000;
        int &res = dp[i][sum];
        if(res!=-1)
            return res;
        res =min(1+f(i,sum+coins[i],amount,coins), f(i+1,sum,amount,coins));
        
        return res;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        n = coins.size();
        
        memset(dp,-1,sizeof(dp));
        
        return f(0,0,amount,coins)<=10000?f(0,0,amount,coins):-1;
        
        
        
    }
};


//Top Down

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            dp[i] = 1e9;
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
        
        return dp[amount]==1e9?-1:dp[amount];
    }
};
