#include<iostream>
#include<vector>
using namespace std;
//time=O(n^2)
//space=O(n^2)
int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<int>height=vector<int>(n);
        for(int i=0;i<n;++i)cin>>height[i];
        //cost为拦截对应导弹后共有多少其他导弹因此无法被拦截，list为对应无法被拦截的导弹下标
        vector<int>cost=vector<int>(n);
        vector<vector<int>>list=vector<vector<int>>(n);
        for(int i=0;i<n;++i){
            list[i]=vector<int>(n-1);
            for(int j=0;j<n-1;++j)list[i][j]=-1;//initialize
        }

        //cost[i]=比i早到且高度小于i的导弹数+比i晚到且高度大于i的导弹数
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(height[j]<height[i]){
                    list[i][cost[i]]=j;
                    ++cost[i];
                }
            }
            for(int j=i+1;j<n;++j){
                if(height[j]>height[i]){
                    list[i][cost[i]]=j;
                    ++cost[i];
                }
            }
        }
        //贪心 每次选择拦截cost最小的导弹blocked=1，之后
        //（1）减小因其而无法被拦截的导弹的cost（下一轮拦截）
        //（2）遍历list将下一轮拦截的导弹 不需要？
        //int count=0;
        int remain=n;
        int first_turn_block=0;
        vector<bool>blocked=vector<bool>(n);
        //while(remain>0){
            //++count;
            vector<bool>visited=vector<bool>(n);
            while(true){
                int target=0;
                int temp=2147483647;
                for(int i=0;i<n;++i){
                    if(!blocked[i]&&!visited[i]&&cost[i]<temp){
                        target=i;
                        temp=cost[i];
                    }
                }
                blocked[target]=true;
                --remain;
                ++first_turn_block;
                for(int i=0;i<n-1;++i){
                    if(list[target][i]!=-1&&!blocked[list[target][i]]){
                        --cost[list[target][i]];
                        visited[list[target][i]]=true;
                    }
                }
                int turn_complete=true;
                for(int i=0;i<n;++i){
                    turn_complete=turn_complete&&(blocked[i]||visited[i]);
                }
                if(turn_complete)break;//存在既未拦截又未放到下一轮的导弹
            }
            //if(count==1)
            cout<<first_turn_block<<endl;
        //}
        //cout<<count<<endl;
    }
    return 0;
}