#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//DP
struct activity{
    int start;
    int finish;
    int value;
};
bool comp(activity a,activity b){
    return a.finish<b.finish;
}

int main(){
    int m;
    cin>>m;
    for(int a=0;a<m;++a){
        int n;
        cin>>n;
        vector<activity>acts=vector<activity>(n);
        for(int i=0;i<n;++i){
            cin>>acts[i].start>>acts[i].finish>>acts[i].value;
        }
        sort(acts.begin(),acts.end(),comp);//按结束时间升序排列
        vector<int>ans=vector<int>(n+1);
        ans[0]=acts[0].value;
        ans[n]=0;
        for(int i=1;i<n;++i){
            int cur=n;//前面活动均冲突时比较活动i和最大值i-1
            for(int j=i-1;j>=0;--j){//寻找acts[i]前面第一个和它不冲突的活动
                if(acts[j].finish<=acts[i].start){
                    cur=j;
                    break;
                }
            }
            ans[i]=max(ans[i-1],acts[i].value+ans[cur]);
        }
        // for(int i=0;i<n;++i)cout<<ans[i]<<' ';
        // cout<<endl;
        cout<<ans[n-1]<<endl;
    }
    return 0;
}