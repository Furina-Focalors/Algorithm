#include<iostream>
#include<vector>

using namespace std;

/*
    动态规划
    维护dp[n+1][2]，dp[i][0]表示以节点i为根，节点i染成黑色时的最优解；dp[i][1]表示表示以节点i为根，节点i染成白色时的最优解
    初始条件：dp[leaf][0]=1,dp[leaf][1]=0
    状态转移：
    dp[root][0]=1+sum(dp[child][1]) 根节点为黑色时，所有子节点只能为白色
    dp[root][1]=sum(max(dp[child][0],dp[child][1])) 根节点为白色时，子节点可以是任意颜色，取最大
    结果：max(dp[root][0],dp[root][1])
*/

void solve(vector<vector<int>>& adj,vector<vector<int>>& dp,int root) {
    
    dp[root][0] = 1;  
    dp[root][1] = 0;
    
    int size=adj[root].size();
    for(int i = 0; i < size; ++i) {

        solve(adj,dp,adj[root][i]);
        
        dp[root][0] += dp[adj[root][i]][1];
        dp[root][1] += max(dp[adj[root][i]][0], dp[adj[root][i]][1]);
    }
}

int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;++a){
        int n;
        cin>>n;
        vector<vector<int>>adj=vector<vector<int>>(n+1);
        vector<vector<int>>dp=vector<vector<int>>(n+1);
        vector<bool>hasParent=vector<bool>(n+1);
        for(int i=1;i<=n-1;++i){
            dp[i]=vector<int>(2);
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            hasParent[v]=true;
        }
        dp[n]=vector<int>(2);

        int root = 0;
        for(int i = 1; i <= n; ++i) {
            if(!hasParent[i]) {
                root = i;
                break;
            }
        }

        solve(adj,dp,root);

        cout << max(dp[root][0], dp[root][1]) << endl;
    }
    return 0;
}