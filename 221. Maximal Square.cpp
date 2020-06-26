//https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix[0].size();
        int ans[n+1][m+1];
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0 or matrix[i][j]=='0')
                    ans[i][j]=matrix[i][j]-'0';
                else
                    ans[i][j] = (matrix[i][j]=='1')+min(ans[i-1][j-1],min(ans[i-1][j],ans[i][j-1]));
                res = max(res,ans[i][j]*ans[i][j]);
                
            }
        }
        return res;
    }
};
